function [log_likelihood] = dsge_loglikelihood(DATAMAT,PARAM,MODEL)

% This function computes the log-likelihood of a DSGE model solved with
% perturbation at first order
% Inputs
% PARAM: Structure of Vector of Structural Parameters
% DATA: Structure with data

% Outputs
% log_likelihood: value of log-likelihood function


[SOL,error_indicator] = get_first_order_perturbation_solution(MODEL,PARAM);

if ~error_indicator
    [log_lik_t_tm1] = dsge_kalman_filter(DATAMAT,SOL.STEADY_STATE(MODEL.varobs_idx_DR),MODEL.varobs_selection_matrix,SOL.gx,SOL.gu,MODEL.Sigma_u,MODEL.Sigma_e);
    log_likelihood = sum(log_lik_t_tm1);
else
    log_likelihood = -10^8; % some very small number, can also use -Inf
end

end % main function end