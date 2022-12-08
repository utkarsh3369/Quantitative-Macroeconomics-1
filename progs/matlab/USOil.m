% =========================================================================
% USOil.m
% =========================================================================
% Estimates a SVAR(4) model to identify an oil price shock for the US economy
% =========================================================================
% Willi Mutschler, December 8, 2022
% willi@mutschler.eu
% =========================================================================
clearvars; clc;close all;

%% data handling
y = importdata('../../data/USOil.csv');
y = y.data; % already has correct order dlog(poil), dlog(p), dlog(gdp)

%% estimate reduced-form
nlag = 4;
opt.const = 1;
VAR = VARReducedForm(y,nlag,opt);

%% structural identification with Cholesky decomposition
y = y(:,[1 2 3]); % order dlog(oilprice) first, then dlog(price deflator) and dlog(GDP)
B0inv_chol = chol(VAR.SigmaOLS,'lower');
% note that the Cholesky decomposition always yields positive diagonal elements, so no normalization needed
table(B0inv_chol)

%% structural identification with numerical optimization, identification restrictions are put into auxiliar function USOil_fSR
f = 'USOil_fSR';
StartValueMethod = 1; %0: Use identity matrix, 1: use square root, 2: use cholesky as starting value
% Options for fsolve
TolX = 1e-4;         % termination tolerance on the current point
TolFun = 1e-9;       % termination tolerance on the function value
MaxFunEvals = 50000; % maximum number of function evaluations allowed
MaxIter = 1000;      % maximum numberof iterations allowed
OptimAlgorithm = 'trust-region-dogleg'; % algorithm used in fsolve
options = optimset('TolX',TolX,'TolFun',TolFun,'MaxFunEvals',MaxFunEvals,'MaxIter',MaxIter,'Algorithm',OptimAlgorithm);
if StartValueMethod == 0
    B0inv = eye(size(y,2)); % use identity matrix as starting value
elseif StartValueMethod == 1
    B0inv = VAR.SigmaOLS^.5; % use square root of vcov of reduced form as starting value
elseif StartValueMethod == 2
    B0inv = chol(VAR.SigmaOLS,'lower'); % use Cholesky decomposition of vcov of reduced form
end
[B0inv_opt,fval,exitflag,output] = fsolve(f,B0inv,options,VAR.SigmaOLS);

% Normalize sign of B0inv such that diagonal elements are positive
if any(diag(B0inv_opt)<0)
    idx_negative = diag(B0inv_opt)<0;
    B0inv_opt(:,(idx_negative==1)) = -1*B0inv_opt(:,(idx_negative==1)); % flip sign
end
table(B0inv_opt)
    
%% compute and plot structural impulse response function
nsteps = 30;
IRFcumsum = [1 0 1]; % the variables in the SVAR are in differences, we want to plot IRFs of the first and last variable by using cumsum
varnames = ["Real Price of Oil","GDP Deflator Inflation","Real GDP"]; 
epsnames = ["Oil Price Shock", "eps2 Shock", "eps3 Shock"]; 
IRFpoint_chol = IRFs(VAR.Acomp,B0inv_chol,nsteps,IRFcumsum,varnames,epsnames);
IRFpoint_opt = IRFs(VAR.Acomp,B0inv_opt,nsteps,IRFcumsum,varnames,epsnames);

%% both approaches are (numerically) equivalent
norm(abs(B0inv_chol-B0inv_opt),'Inf') % max abs error
norm(abs(IRFpoint_chol(:) - IRFpoint_opt(:)),'Inf') % max abs error