\section[Bayesian Estimation of Multivariate Linear Regression Model]{Bayesian Estimation of Multivariate Linear Regression Model\label{ex:BayesianEstimationMultivariateLinearRegressionModel}}
Consider a linear regression model with multiple regressors:
\begin{align*}
Y = X\beta + u
\end{align*}
with $u \sim \mathcal{N}(0, \sigma^2 I)$.
\begin{enumerate}
\item Name the idea and general procedure for estimating this model with Bayesian methods.
\item Provide an expression for the likelihood function $p(Y|\beta,\sigma^2)$.
\item Assume that $\sigma^2$ is known and the prior distribution for $\beta$ is Gaussian with mean $\beta_0$ and covariance matrix $\Sigma_{\beta,0}$.
Derive an expression for the \textbf{conditional posterior distribution} $p(\beta|\sigma^2,Y)$.
\item Assume that $\beta$ is known and the prior distribution for the precision $1/\sigma^2$ is Gamma with shape parameter $s_0$ and scale $v_0$.
Derive an expression for the \textbf{conditional posterior distribution} $p(1/\sigma^2|\beta,Y)$.
\item Now assume that both $\beta$ and $\sigma^2$ are unknown.
Since we are able to draw easily from the \textbf{conditional posterior distributions},
  we can use the Gibbs sampling algorithm to get draws from the \textbf{joint posterior distribution} $p(\beta,\sigma^2|Y)$.
Provide an overview of the basic steps and algorithm of the Gibbs sampling algorithm.
\end{enumerate}

\paragraph{Readings}
\begin{itemize}
	\item \textcite[Ch. 7.1]{Greenberg_2008_IntroductionBayesianEconometrics}
	\item \textcite[Ch. 3]{Koop_2003_BayesianEconometrics} 
\end{itemize}

\begin{solution}\textbf{Solution to \nameref{ex:BayesianEstimationMultivariateLinearRegressionModel}}
\ifDisplaySolutions
\input{exercises/bayesian_estimation_multivariate_regression_solution.inc}
\fi
\newpage
\end{solution}