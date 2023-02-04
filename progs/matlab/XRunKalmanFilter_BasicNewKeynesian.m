%% Illustration of log-likelihood computations with Kalman filter for Basic New Keynesian Model
clear all;
modelname = 'BasicNewKeynesian';

%% Preprocessing of model, this creates script files with dynamic Jacobians, which can be evaluated numerically to compute the policy function
MODEL = feval(str2func([modelname '_preprocessing']));

%% Calibrate parameters
PARAM.BETA     = 0.99;
PARAM.RHO_A    = 0.9;
PARAM.RHO_Z    = 0.5;
PARAM.RHO_NU   = 0.5;
PARAM.SIGMA    = 1;
PARAM.VARPHI   = 5;
PARAM.PHI_PIE  = 1.5;
PARAM.PHI_Y    = 0.5/4;
PARAM.PIESTAR  = 1;
PARAM.THETA    = 3/4;
PARAM.EPSILON  = 9;
MODEL.Sigma_u  = [1 0 0;
                  0 1 0;
                  0 0 1];
MODEL.Sigma_e  = zeros(3,3); % no measurement errors

%% Options
OPT.datafile = 'BasicNewKeynesianSimdat.mat';
OPT.first_obs = 1;
OPT.nobs = 500;


%% Set up data matrix and selection matrix H
load(OPT.datafile,'DATA');
% create data matrix corresponding to MODEL.varobs_idx_DR
DATAMAT = nan(OPT.nobs,MODEL.varobs_nbr);
for j=1:MODEL.varobs_nbr
    DATAMAT(:,j) = DATA.(MODEL.varobs{j});
end
DATAMAT = DATAMAT(OPT.first_obs:OPT.nobs,:);
% create selection matrix H
MODEL.varobs_selection_matrix = zeros(MODEL.varobs_nbr,MODEL.endo_nbr);
for j=1:MODEL.varobs_nbr
    MODEL.varobs_selection_matrix(j,MODEL.varobs_idx_DR(j)) = 1;
end

% Check stochastic singularity
if MODEL.varobs_nbr > (MODEL.exo_nbr + nnz(diag(MODEL.Sigma_e)))
    error('Stochastic Singularity: You have more observables than shocks+measurement errors.')
end

%% Compute log-likelihood
log_likelihood = dsge_loglikelihood(DATAMAT,PARAM,MODEL);
fprintf('The value of the log-likelihood function computed dsge_kalman_filter.m (own implementation) is: %12.10f.\n',log_likelihood);

%% Compare to Herbst Schorfheide kalman.m function
[SOL,error_indicator] = get_first_order_perturbation_solution(MODEL,PARAM);
if ~error_indicator
    [liki,measurepredi,statepredi,varstatepredi] = kalman(SOL.STEADY_STATE(MODEL.varobs_idx_DR),MODEL.varobs_selection_matrix,MODEL.Sigma_e,SOL.gu,MODEL.Sigma_u,SOL.gx,DATAMAT);
    fprintf('The value of the log-likelihood function computed by kalman.m from Herbst and Schorfheide is: %12.10f.\n',sum(liki));
end
fprintf('Check whether both are equal: %d\n',isequal(sum(liki),log_likelihood));
