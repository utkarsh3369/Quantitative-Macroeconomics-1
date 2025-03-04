\section[Bayesian Estimation of a VAR model for the US economy including the Zero-Lower-Bound]{Bayesian Estimation of a VAR model for the US economy including the Zero-Lower-Bound\label{ex:BayesianEstimationVARZLB}}
Consider a VAR(p) model for the US economy which includes (in this ordering)
  the federal funds rate, government bond yield, unemployment and inflation.
The sample period consists of 2007m1 to 2010m12.
Data is given in the file \texttt{USZLB.csv}.
\begin{enumerate}
\item Estimate the parameters of a VAR(2) model with a constant by using Bayesian methods,
  i.e. a Gibbs sampling method where you assume a Minnesota prior for the VAR coefficients and an inverse Wishart prior for the covariance matrix.
\\
To this end:
\begin{itemize}
\item Define a Minnesota prior for the VAR coefficients.
The prior mean $a_0$ should reflect the view that the VAR follows a random walk.
Set the hyperparameters for the prior covariance matrix $V_0$ such that
  the tightness parameter on lags of own variables is equal to 0.5,
  the one on lags of other variables is also equal to 0.5
  and the tightness parameter on the constant term is equal to 1.
  \\
  \emph{Hint: You may want to use the \texttt{BVARMinnesotaPrior.m} function in the appendix.}
\item Define an Inverse Wishart prior for the covariance matrix with degrees of freedoms $v_0$ equal to the number of variables and the identity matrix as prior scale matrix $S_0$. 
\item Initialize the first draw of the covariance matrix with OLS values.
\item Draw 40000 times from the conditional posteriors $$p(vec(A)|\Sigma,Y) \sim N(a_1,V_1)$$ and $$p(\Sigma|vec(A),Y) \sim IW(v_1, S_1)$$ where
\begin{align*}
V_1 &= (V_0^{-1}+ZZ' \otimes \Sigma^{-1})^{-1}\\
a_1 &= V_1 (V_0^{-1}a_0 + (Z \otimes \Sigma^{-1})vec(Y))\\
v_1 &= T + v_0\\
S_1 &= S_0 + (Y - A*Z)(Y - A*Z)'
\end{align*}
and keep the last 10000 draws for inference. 
Optionally: check the stability of the draws of the coefficient matrix $A$,
  i.e. compute the eigenvalues of the companion matrix and discard the draw
  if the modulus of all eigenvalues of the companion form is larger than one.
\end{itemize}
\item As the sample period includes the financial crisis,
  redo the exercise but now use a small prior variance to reflect the view that monetary policy is at the zero-lower-bound
  and hence unlikely to respond to changes in the other variables.
\end{enumerate}

\paragraph{Readings}
\begin{itemize}
	\item \textcite[Ch.~5]{Kilian.Lutkepohl_2017_StructuralVectorAutoregressive}
	\item \textcite[Ch.~1-2]{Koop.Korobilis_2010_BayesianMultivariateTime}
\end{itemize}

\begin{solution}\textbf{Solution to \nameref{ex:BayesianEstimationVARZLB}}
\ifDisplaySolutions
\input{exercises/bayesian_estimation_var_zlb_solution.inc}
\fi
\newpage
\end{solution}