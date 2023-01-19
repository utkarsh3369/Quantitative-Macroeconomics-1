\section[Bayesian Estimation of Quarterly Inflation]{Bayesian Estimation of Quarterly Inflation\label{ex:BayesianEstimationQuarterlyInflation}}
Perform a Bayesian estimation of an AR(2) model of quarterly US inflation with the Gibbs sampler
  by assuming a Gamma distribution for the marginal prior for the precision $1/\sigma_u^2$
  and a normal distribution for the conditional prior for the coefficients $\phi$ given $1/\sigma_u^2$.
To this end, do the following:
\begin{enumerate}
\item Load the dataset \texttt{QuarterlyInflation.csv}. It contains a series for US quarterly inflation from 1947Q1 to 2012Q3.
Plot the data.
\item Create the matrix of regressors, $X$, and the corresponding vector of endogenous variables, $y$, for an AR(2) model with a constant.
\item Set the prior mean for the coefficients to a vector of zeros, $\phi_0 = 0$, and the prior covariance matrix to the identity matrix, $\Sigma_{\phi,0}=I$.
\item Set the shape parameter for the variance parameter to $s_0=1$ and the scale parameter to $v_0=0.1$.
\item Set the total number of Gibbs iterations to $R=50000$ with a burn-in phase of $B=40000$.
\item Initialize output matrices for the remaining $R-B$ draws of the coefficient estimates and the variance estimate.
\item Initialize the first draw of $1/\sigma_u^2$ to its OLS estimate.
\item For $j=1,...,R$ do the following
\begin{enumerate}	
	\item Sample $\phi(j)$ conditional on $1/\sigma_u^2(j)$ from $\mathcal{N}(\phi_1,\Sigma_{\phi,1})$ where
	\begin{align*}
	\Sigma_{\phi,1} &= (\Sigma_{\phi,0}^{-1} +\sigma_u^{-2}(j)(X'X))^{-1}
    \\
    \phi_1 &= \Sigma_{\phi,1} \cdot (\Sigma_{\phi,0}^{-1}\phi_0 + \sigma_u^{-2}(j) X'y)
	\end{align*}
	Optionally: check the stability of the draw to avoid an explosive AR processes.
	\item Sample $1/\sigma_u^2(j)$ conditional on $\phi(j)$ from the Gamma distribution $G(s_1,v_1)$ where $s_1 = s_0 + T$ and $v_1 = v_0 + (y-X\beta(j))'(y-X\beta(j))$.
	\item If you passed the burn-in phase, i.e. $j>B$, then save the draws of $\phi(j)$ and $\sigma^2(j)$ into the output matrices.
\end{enumerate}
\item Plot the histograms of the draws in your output matrices.
\end{enumerate}

\paragraph{Readings}
\begin{itemize}
	\item \textcite{Chib.Greenberg_1994_BayesInferenceRegression}
	\item \textcite[Ch.~11.1]{Greenberg_2014_IntroductionBayesianEconometrics}
\end{itemize}

\begin{solution}\textbf{Solution to \nameref{ex:BayesianEstimationMultivariateLinearRegressionModel}}
\ifDisplaySolutions
\input{exercises/bayesian_estimation_quarterly_inflation_solution.inc}
\fi
\newpage
\end{solution}