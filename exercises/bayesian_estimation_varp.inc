\section[Bayesian Estimation Of VAR(p)]{Bayesian Estimation Of VAR(p)\label{ex:BayesianEstimationVARp}}
Consider the following K-variable VAR(p) model:
\begin{align*}
y_t = c + A_1 y_{t-1} + ... + A_p y_{t-p} + u_t= AZ_{t-1} + u_t
\end{align*}
where $E(u_t)=0$, $E(u_t u_t')=\Sigma_{u}$ and $E(u_t u_s')=0$ for $t\neq s$.
Define $\alpha = vec(A)$ and assume that $u_t|y_{t-1},...,y_1\sim N(0,\Sigma)$.
\begin{enumerate}
\item Explain why Bayesian methods are especially attractive when estimating a VAR(p) model.
\item Assume that the prior for $\alpha$ is normal with mean $\alpha_0$ and covariance matrix $V_0$. Provide an expression for the posterior conditional on $\Sigma$.
\item Assume that the prior for the VAR covariance matrix $\Sigma$ is inverse Wishart with degrees of freedom $v_0$ and scale matrix $S_0$. Provide an expression for the posterior conditional on $\alpha$. 
\item Briefly outline the basic steps of the Gibbs sampling algorithm given the conditional posteriors.
\item Provide intuition behind the \enquote{Minnesota prior}
and have a look at a possible implementation of it given the file \texttt{BVARMinnesotaPrior.m} in the appendix.

%\item Provide intuition behind the \enquote{independent normal-inverse Wishart prior}.
\end{enumerate}

\paragraph{Readings}
\begin{itemize}
	\item \textcite[Ch.~5]{Kilian.Lutkepohl_2017_StructuralVectorAutoregressive}
	\item \textcite[Ch.~1-2]{Koop.Korobilis_2010_BayesianMultivariateTime}
\end{itemize}

\begin{solution}\textbf{Solution to \nameref{ex:BayesianEstimationVARp}}
\ifDisplaySolutions
\input{exercises/bayesian_estimation_varp_solution.inc}
\fi
\newpage
\end{solution}