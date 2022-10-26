function r_k = ACFPlots(y,pmax,alph)
% =======================================================================
% r_k = ACFPlots(y,pmax,alph)
% =======================================================================
% Computes and plots the empirical autocorrelation function
% c_k = 1/T*\sum_{t=k+1}^T (y_t-\bar{y})(y_{t-k}-\bar{y})
% r_k = c_k/c0
% -----------------------------------------------------------------------
% INPUTS
%   - y    : Vector of data. [periods x 1]
%   - pmax : Maximum number of lags to plot. [scalar]
%   - alph : Significance level for asymptotic bands. [scalar, e.g. 0.05]
% -----------------------------------------------------------------------
% OUTPUTS
%   - rk   : Sample autocorrelation coefficient. [1 x maxlags]
% =======================================================================
% TEST CASE
% ARPlots
% r_k1 = ACFPlots(Y(:,1),8,0.05)
% r_k2 = ACFPlots(Y(:,2),8,0.05)
% r_k3 = ACFPlots(Y(:,3),8,0.05)
% r_k4 = ACFPlots(Y(:,4),8,0.05)
% you can compare to Matlab's econometrics toolbox:
% figure; autocorr(Y(:,1),'NumLags',8);
% =======================================================================
% Willi Mutschler, October 29, 2022
% willi@mutschler.eu
% =======================================================================

T=size(y,1);             % get number of periodes
y_demeaned = y-mean(y);  % put y in deviations from mean
r_k = nan(1,pmax);       % initialize output vector

% Compute variance
c0 = 1/T*(y_demeaned' * y_demeaned);
% Compute autocorrelations
for k=1:pmax
    c_k = 1/T * (y_demeaned(1+k:T,:)' * y_demeaned(1:T-k,:));
    r_k(1,k) = c_k/c0;
end

% Asymptotic bands
critval = norminv(1-alph/2);
ul = repmat(critval/sqrt(T),pmax,1);
ll = -1*ul;

% Barplots
figure('name','Autocorrelation');
bar(r_k);
hold on;
plot(1:pmax,ul,'color','black','linestyle','--');
plot(1:pmax,ll,'color','black','linestyle','--');
hold off;

% The following is just for pretty plots
acfbarplot = gca; % Get current axes handle
acfbarplot.Title.String = 'Sample autocorrelation coefficients';
acfbarplot.XAxis.Label.String = 'lags';
acfbarplot.XAxis.TickValues = 1:pmax;
acfbarplot.YAxis.Label.String = 'acf value';
acfbarplot.YAxis.Limits = [-1 1];
acfbarplot.XAxis.Limits = [0 pmax];

end % function end