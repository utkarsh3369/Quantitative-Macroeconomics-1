\begin{enumerate}
\item Given the large number of parameters in VARs, estimates of objects of interest (e.g. impulse responses or forecasts) can become imprecise in large models.
By incorporating prior information the estimates generally become more precise.
Moreover, Bayesian simulation methods (such as Gibbs sampling) provide an easy way to characterize estimation uncertainty.

\item Conditional on $\Sigma$ and assuming a normal prior for $\alpha$, the conditional posterior is given by
\begin{align*}
p(\alpha|\Sigma,Y) \sim N(\alpha_1,V_1)
\end{align*}
where
\begin{align*}
V_1 &= (V_0^{-1}+ZZ' \otimes \Sigma^{-1})^{-1}\\
\alpha_1 &= V_1 (V_0^{-1} \alpha_0 + (Z \otimes \Sigma^{-1})vec(Y))
\end{align*}

\item Conditional on $\alpha$ and assuming an inverse Wishart prior distribution for $\Sigma$, the conditional posterior is given by:
\begin{align*}
    p(\Sigma|\alpha,Y) \sim IW(v_1, S_1)
\end{align*}
where
\begin{align*}
v_1 &= T + v_0
\\
S_1 &= S_0 + (Y - A*Z)(Y - A*Z)'
\end{align*}

\item Gibbs sampling consists of the following steps:
\begin{enumerate}
    \item Set priors for the VAR coefficients and the covariance matrix. Set a starting value for $\Sigma$, e.g. to OLS values.
    \item Compute the moments of the conditional posterior distribution for the VAR coefficients, $\alpha_1$ and $V_1$, and take a draw $\alpha(j)$ from $N(\alpha_1,V_1)$.
    \item Draw $\Sigma(j)$ from its conditional posterior distribution $IW(v_1,S_1)$.
    \item Repeat steps (2) and (3) a large number $M$ of times to generate sequences $\{\alpha(1),...,\alpha(M)\}$ and $\{\Sigma(1),...,\Sigma(M)\}$ and use the last $L$ draws for inference.
\end{enumerate}

\item A variety of priors can be used with VAR models, but 3 issues arise:
\begin{enumerate}
    \item VAR models are not parsimonious: they have many coefficients to estimate.
    Ideally our prior should provide information to improve the precisions of estimates by focusing on the most important coefficients
    or using prior information to \textbf{shrink} the parameter space.
    \item Some priors (conjugate) are more useful in terms of analytical expressions and closed-form results.
    This can hugely reduce the computational burden on sampling algorithms.
    \item Prior distributions should be flexible, meaning that specific information or uncertainty can be easily added to e.g. certain equations or on the deterministic terms.
\end{enumerate}
With this in mind, there is a literature trying to come up with \textbf{structured prior distributions} that are able to
(1) shrink the parameter space,
(2) imply closed-form expressions for conditional posteriors, and
(3) are flexible to include a wide variety of prior information.

To this end, researchers from the University of Minnesota and the Federal Reserve bank of Minneapolis have proposed a prior which is now known as the Minnesota prior and is used by default in many applications.
Basically, everything is as before, i.e. we have an Inverse Wishart prior on $\Sigma$ and a Normal conditional prior for $\alpha|\Sigma$;
  however, they introduce an automatic way to put structure on the prior based on just a few hyperparameters.

Consider the following example:
\begin{align*}
    \begin{pmatrix} y_t^1\\y_t^2 \end{pmatrix} = 
    \begin{pmatrix} c_1\\c_2 \end{pmatrix} 
    + \begin{pmatrix} A_{11}^1 & A_{12}^1\\A_{21}^1 & A_{22}^1 \end{pmatrix} 
    \begin{pmatrix} y_{t-1}^1\\y_{t-1}^2 \end{pmatrix} 
    + \begin{pmatrix} A_{11}^2 & A_{12}^2\\A_{21}^2 & A_{22}^2 \end{pmatrix} 
    \begin{pmatrix} y_{t-2}^1\\y_{t-2}^2 \end{pmatrix} 
    + \begin{pmatrix} u_t^1\\u_t^2 \end{pmatrix}
\end{align*}
Now the Minnesota prior imposes three things:
\begin{enumerate}
    \item The individual variables $y_t^1$ and $y_t^2$ follow a Random Walk.
    We implement this by setting the prior mean $\alpha_0$ to zero except for $A_{11}^1$ and $A_{22}^1$.
    This is the way we implement shrinkage.
    \\
    \emph{Sidenote:} Typically you will need to manually adjust this.
    For instance, growth rates typically show little persistence, so we could also set $A_{11}^1$ and $A_{22}^1$ to zero.
    Alternatively, for level variables with high persistence, we could set $A_{11}^1$ and $A_{22}^1$ to high values slightly below 1.
    Nevertheless, the Random Walk way is usually chosen by default in most implementations of the Minnesota prior.    
    \item The prior covariance matrix $V_0$ is set to reflect UNCERTAINTY about our prior mean. That is, we want to express how \textbf{certain} we are that
    (1) all coefficients on lags higher than 1 are zero and 
    (2) coefficients other than on own lags are zero.
    \\
    We operationalize this by a set of hyperparameters that control the tightness of this prior.
    Formally, this is implemented by specifying the covariance matrix $V_0$ as a diagonal matrix.
    Moreover, let $V^i_{0}$ denote the block of $V_0$ associated with coefficients in equation $i$,
      then the diagonal elements of $V^i_{0}$ are set in the following way:
    \begin{align*}
        V^i_{0,jj} = \begin{pmatrix}
                        \frac{\lambda_{1}}{l^2} & \text{for coefficients on own lag $l=1,...,p$}
                        \\
                        \frac{\lambda_{2}}{l^2} \frac{\sigma_{ii}}{jj} & \text{for coefficients on lag $l=1,...,p$ of variables $j\neq i$}
                        \\
                        \lambda_3 \sigma_{ii} & \text{for coefficients on exogenous variables}
                    \end{pmatrix}
    \end{align*}
    This specification implies that as the lag $l=1,...,p$ increases the coefficients are shrunk towards zero.
    Moreover, by specifying $\lambda_1<\lambda_2$ we make own lags more likely to be important than lags of other variables.
    Whereas setting $\lambda_1$ close to zero puts greater weight towards the Random Walk assumption.
    Note that the term $\frac{\sigma_{ii}}{jj}$ adjusts for differences in the units the variables are measured in. 
    Typically, we set $\sigma_{ii}$ to the OLS estimate of the standard error of the reduced-form innovations from univariate AR regressions in equation $i$.
    
    The common practice is then to use the typical natural conjugate priors,
      i.e. the prior for $\Sigma$ follows an Inverse Wishart prior and the prior for the coefficients $vec(A)$ conditional on $\Sigma$ is normal.
    Thus, we can make use of the Gibbs sampler by making use of the analytical expressions for the conditional posteriors.
 
% \item Restrictions inherent in the natural conjugate prior may be restrictive in practical applications.
% The independent Normal-inverse Wishart prior sets the priors for the VAR coefficients and error variance independently:
% \begin{align*}
%     p(\alpha) \sim N(\alpha_0,V_0) \text{ and } p(\Sigma)\sim IW(v_0, S0)
% \end{align*}
% Note that these priors are NOT natural conjugate priors!
% Analytical expressions for the marginal posterior distributions are not available, but Gibbs sampling is still possible.
\end{enumerate}
	
	
\end{enumerate}