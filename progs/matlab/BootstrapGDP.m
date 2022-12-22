function yb = BootstrapGDP(VAR,opt)
% =======================================================================
% Computes a standard residual-based bootstrap GDP for VAR models with
% iid sampling with replacement for errors and random sampling of block
% initial values
% This function uses the companion VAR(1) form to do the simulations; That 
% is, any VAR(p) model with constant
%   y_t = c + A_1*y_{t-1} + ... + A_p*y_{t-p} + u_t
% can be represented as
%   Y_t = C + A*Y_{t-1} + U_t
% where 
%   Y_t = [y_t;y_{t-1};...;y_{t-p-1}]
%   C   = [c;0;...;0]
%   A   = [A_1 A_2 ... A_{p-1} A_p;
%          I_K 0_K ... 0_K     0_K;
%          0_K I_K ... 0_K     0_K:
%          ... ... ... ...     ...;
%          O_K 0_K ... I_K     0_K]
%   U_t = [u_t; 0; ...;0]
% =======================================================================
% yb = BootstrapGDP(VAR,opt)
% -----------------------------------------------------------------------
% INPUTS
%	- VAR     : Structure of reduced-form estimation function VARReducedForm.m. [structure]
%   - opt     : structure of options [structure]
% -----------------------------------------------------------------------
% OUTPUTS
%   - yb   : Data matrix. [number of periods x number of variables]
% =======================================================================
% Willi Mutschler, December 21, 2022
% willi@mutschler.eu
% =======================================================================

y     = transpose(VAR.ENDO);
p     = VAR.nlag;
const = opt.const;
[K,T] = size(y);
Acomp = VAR.Acomp;
U=[VAR.residuals; zeros(K*(p-1),T-p)]; % residuals for companion form
% create coefficient vectors for deterministic constant term in companion form
C = zeros(K*p,1);
if const == 1
    C(1:K,1) = VAR.A(:,1);
end

% create Y of companion form
%   note that Y_t = [y_t;y_{t-1};...;y_{t-p+1}] is [Kp x 1]
%   such that Y = [Y_p Y_{p+1} ... Y_T] is [Kp x (T-p+1)]
Y=y(:,p:T);
for i=1:p-1
 	Y=[Y; y(:,p-i:T-i)];
end

% initalize bootstrap GDP in companion form
Yb = zeros(K*p,T-p+1);
Ub = zeros(K*p,T-p);

% iid resampling for blockwise initial values of VAR(p) model is equivalent to randomly choosing a column of the companion VAR(1) model
%indexY = fix(rand(1,1)*(T-p+1))+1; % this generates a randomly chosen integer between 1 and T-p+1
indexY = randi(T-p+1); % this generates a randomly chosen integer between 1 and T-p+1
Yb(:,1)=Y(:,indexY);

% iid resampling for error terms
%indexU=fix(rand(1,T-p)*(T-p))+1; % this generates T-p randomly chosen integers between 1 and T-p
indexU = randi(T-p,1,T-p); % this generates T-p randomly chosen integers between 1 and T-p
Ub(:,2:T-p+1)=U(:,indexU);	

for t=2:T-p+1
    Yb(:,t)= C + Acomp*Yb(:,t-1) + Ub(:,t); 
end

yb = Yb(1:K,:);
for i=2:p
    yb=[Yb((i-1)*K+1:i*K,1) yb];
end
yb=yb';

end