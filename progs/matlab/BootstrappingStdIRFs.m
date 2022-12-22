% =======================================================================
% Compute standard deviation of structural IRFs for the example by 
% Rubio-Ramirez, Waggoner, Zha (2010)'s model which uses both
% short-run and long-run restrictions to identify the structural shocks
% =======================================================================
% Willi Mutschler, December 22, 2022
% willi@mutschler.eu
% =======================================================================

% Point estimate for structural IRFs in exactly identified model
RWZSRLR;
disp(IRFpoint);

B = 1000;
var_nbr = size(VAR.ENDO,2);
nsteps = size(IRFpoint,3)-1;

THETAstar = zeros(var_nbr,var_nbr,nsteps+1,B);
opt.dispestim = false;   % don't display results in VARReducedForm
optim_options.Display = 'off'; % don't display results of fsolve
tic
parfor b=1:B % use parfor if you have parallel toolbox installed, otherwise use for
    ystar = BootstrapGDP(VAR,opt);
    VARstar = VARReducedForm(ystar,nlag,opt);
    % redo identification steps as in RWZSRLR
    A1starinv_big = inv(eye(size(VARstar.Acomp,1))-VARstar.Acomp); % from the companion
    LRMatstar = A1starinv_big(1:var_nbr,1:var_nbr);    % total impact matrix inv(eye(nvars)-A1hat-A2hat-...-Aphat)
    % Call optimization routine fsolve, note that we use point estimate B0inv as initial value
    [B0invstar,fval,exitflag,output]=fsolve(f,B0inv,optim_options,VARstar.SigmaOLS,LRMatstar);
    % Store results
    THETAstar(:,:,:,b)=IRFs(VARstar.Acomp,B0invstar,nsteps,IRFcumsum,varnames,epsnames,1); % note that the 1 at the end sets noplot=1
end
toc
% Compute standard deviation across r
IRFse=std(THETAstar,0,4);
IRF95LO=IRFpoint-1.96*IRFse;
IRF95UP=IRFpoint+1.96*IRFse;
IRF68LO=IRFpoint-1*IRFse;
IRF68UP=IRFpoint+1*IRFse;

figure('Name','Inference');
countplots = 1;
x_axis = zeros(1,nsteps+1);
for ivar = 1:var_nbr
    for ishock = 1:var_nbr
        subplot(var_nbr,var_nbr,countplots);        
        irfpoint   = squeeze(IRFpoint(ivar,ishock,:));
        irf95up    = squeeze(IRF95UP(ivar,ishock,:));
        irf95lo    = squeeze(IRF95LO(ivar,ishock,:));
        irf68up    = squeeze(IRF68UP(ivar,ishock,:));
        irf68lo    = squeeze(IRF68LO(ivar,ishock,:));
        plot(0:1:nsteps,irfpoint,'b','LineWidth',2);        
        hold on;        
        plot(0:1:nsteps, [irf68lo irf68up] ,'--b');
        plot(0:1:nsteps, [irf95lo irf95up] ,'--r');
        plot(0:1:nsteps,x_axis,'k','LineWidth',2);
        grid;
        xlim([0 nsteps]);
        ylabel(varnames{ivar})
        title(epsnames{ishock})
        countplots = countplots + 1;
    end
end