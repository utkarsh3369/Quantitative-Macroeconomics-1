\begin{enumerate}

	\item The parameters $\theta=[\beta,\sigma^2]'$ are random variables with a probability distribution.
A Bayesian estimation of this distribution combines prior beliefs and information from the data:
\begin{enumerate}
	\item Prior distribution $p(\theta)$
	\item Likelihood $p(Y|\theta)$
	\item Bayes' rule gives posterior distribution: $p(\theta|Y) \propto p(Y|\theta) p(\theta)$
\end{enumerate}

\item Because $u$ is normally distributed, $Y$ is also Gaussian; hence, we can derive the precise form of the likelihood function:
\begin{align*}
p(Y|\beta,\sigma^2) = \frac{1}{(2\pi \sigma^2)^{T/2}} \exp\left\{-\frac{1}{2\sigma^2} (Y-X\beta)'(Y-X\beta)\right\}
\end{align*}

\item Assuming that $\sigma^2$ is known and the prior for $\beta$ is Gaussian,
  we have $p(\beta) = p(\beta|\sigma^2) \sim N(\beta_0,\Sigma_0)$;
  that is, the prior density is given by:
\begin{align*} 
p(\beta|\sigma^2) &= (2\pi)^{-K/2} |\Sigma_0|^{-1/2} \exp\left\{ -\frac{1}{2} (\beta - \beta_0) \Sigma_0^{-1} (\beta - \beta_0) \right\}
\end{align*}
Conditional on $\sigma^2$ the likelihood is proportional to:
\begin{align*}
p(Y|\beta,\sigma^2) \propto \exp\left\{-\frac{1}{2\sigma^2} (Y-X\beta)'(Y-X\beta)\right\}
\end{align*}
Combining prior and likelihood yields:
\begin{align*}
p(\beta|\sigma^2,Y) \propto \exp\left\{ -\frac{1}{2} (\beta-\beta_0)' \Sigma_0^{-1} (\beta-\beta_0) - \frac{1}{2\sigma^2} (Y-X\beta)'(Y-X\beta) \right\}
\end{align*}
One can show, that this is a Gaussian distribution
\begin{align*}
p(\beta|\sigma^2,Y) \sim N(\beta_1,\Sigma_1)
\end{align*}
with
\begin{align*}
\beta_1 &= \left( \Sigma_0^{-1} + \sigma^{-2} (X'X) \right)^{-1} \left( \Sigma_0^{-1} \beta_0 + \sigma^{-2} (X'Y) \right)
\\
\Sigma_1 &= \left( \Sigma_0^{-1} + \sigma^{-2} (X'X) \right)^{-1}
\end{align*}

\item Assuming that $\beta$ is known and the prior for $1/\sigma^2$ is Gamma,
we have $p(1/\sigma^2) = p(1/\sigma^2|\beta) \sim \Gamma(s_0,v_0)$;
that is, the prior density is given by:
\begin{align*}
	p(1/\sigma^2|\beta) & \propto \left(\frac{1}{\sigma^2} \right)^{s_0-1} \exp\left\{ -\frac{1}{v_0\sigma^2}\right\}
\end{align*}
Conditional on $\beta$ the likelihood is proportional to:
\begin{align*}
p(Y|\sigma^2,\beta) \propto (\sigma^2)^{-T/2} \exp\left\{-\frac{1}{2\sigma^2} (Y-X\beta)'(Y-X\beta)\right\}
\end{align*}
Combining prior and likelihood yields (see the readings for the algebra):
\begin{align*}
p(1/\sigma^2 | \beta, Y) \sim \Gamma(s_1,v_1)
\end{align*}
where
\begin{align*}
s_1 &= s_0 + T
\\
v_1 &= v_0 + (Y-X\beta)'(Y-X\beta)
\end{align*}

\item In the previous exercises we have derived the conditional posteriors in closed-form.
When both $\beta$ and $\sigma$ are unknown,
  we can specify the \textbf{joint prior} distribution for these parameters assuming a Gamma distribution for the marginal prior for $1/\sigma^2$
  and a normal distribution for the conditional prior for $\beta|1/\sigma^2$,
i.e. the joint prior is then $p(\beta, 1/\sigma^2) \propto p(\beta|1/\sigma^2) p(1/\sigma^2)$.
It can then be shown that the joint posterior density is:
\begin{align*}
p(\beta,1/\sigma^2|Y) = p(\beta|1/\sigma^2,Y) p(1/\sigma^2|Y)
\end{align*}
To make inference on $\beta$, we need to know the marginal posterior
\begin{align*}
p(\beta|Y) = \int_0^\infty p(\beta,1/\sigma^2|Y) d(1/\sigma^2)
\end{align*}
This integration is very hard, but we can make use of another approach: \textbf{Gibbs sampling}.

The idea of Gibbs sampling is to repeatedly sample from the conditional posterior distributions
  to get an approximation of the marginal and joint posterior distributions of the parameters.

 Basic steps of the Gibbs sampling algorithm:
\begin{enumerate}
	\item Set priors and initial guess for $\sigma^2$
	\item Sample $\beta$ conditional on $1/\sigma^2$
	\item Sample $1/\sigma^2$ conditional on $\beta$
	\item Repeat (2) and (3) a large number of times $R$ and keep the last $L$ draws.
	\item Use the $L$ draws to make inference on $\beta$ and $\sigma$.
\end{enumerate}
\end{enumerate}