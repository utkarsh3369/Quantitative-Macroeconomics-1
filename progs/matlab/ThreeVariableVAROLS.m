% =======================================================================
% ThreeVariableVAROLS.m
% =========================================================================
% Visualize and estimate 3-equation VAR(4) model with OLS
% =========================================================================
% Willi Mutschler, November 29, 2022
% willi@mutschler.eu
% =========================================================================
clearvars; close all;
ThreeVariableVAR = importdata('../../data/ThreeVariableVAR.csv');
y = ThreeVariableVAR.data;
varnames = {'Real GNP Growth' 'Federal Funds Rate' 'GNP Deflator Inflation'};
subsample_start = datetime('1954Q4','InputFormat','yyyyQQQ');
subsample_end   = datetime('2007Q4','InputFormat','yyyyQQQ');
subsample       = transpose(subsample_start:calquarters(1):subsample_end);


%% Plot of data
for j=1:3
    subplot(3,1,j); 
    plot(subsample,y(:,j),'linewidth',2);    
    title(varnames{j});
end

%% OLS estimation of VAR(4)
nlag=4;
opt.const=1;
VAR4 = VARReducedForm(y,nlag,opt);
VAR4.maxEig

VAR4.eq1.bint
VAR4.eq2.bint
VAR4.eq3.bint