\begin{enumerate}
\item In Quantitative Macroeconomics and Econometrics we are concerned with using data to learn about a phenomenon,
  e.g. the relationship between two macroeconomic variables.
That is: we want to learn about something \emph{unknown} (the parameter $\mu$) given something \emph{known} (the data $y$).
In this example we want to use the sample mean as our estimating function: $\hat{\mu}=1/T \sum_{t=1}^T y_t$.
Due to the law of large numbers and the central limit theorem we can derive that $\hat{\mu}\sim N(\mu,\frac{\sigma^2}{T})$
and conduct inference using e.g. confidence intervals $[\hat{\mu}\pm 1.96 \frac{\sigma}{\sqrt{T}}]$.
\\
\textbf{Classical/Frequentist approach:} $\mu$ is a fixed unknown quantity, that is we think there exists a \emph{true value}.
The estimating function, $\hat{\mu}$, is a random variable and is evaluated via repeated sampling.
In a thought experiment, we would be able to regenerate a large number of datasets (given the true $\mu$)
  and our confidence interval will contain the true value in 95\% of cases.
The estimator $\hat{\mu}$ is \emph{best} in the sense of having the highest probability of being close to the true $\mu$.
\\
\textbf{Bayesian approach:} $\mu$ is treated as a \emph{random variable}; that is, there is NO true unknown value!
Instead our knowledge about the model parameter $\mu$ is summarized by a \emph{probability distribution}.
This distribution summarizes two sources of information:
\begin{enumerate}
	\item prior information: subjective beliefs about how likely different parameter values are (information BEFORE seeing the data)
	\item sample information: AFTER seeing the data, we update/revise our prior beliefs
\end{enumerate}
In a sense we explicitly make use of (subjective) probabilities to quantify uncertainty about the parameter.

\item The first key ingredient is based on the rules of probability, which imply for two events $A$ and $B$:
$p(A,B)=p(A|B)p(B)$, where $p(A,B)$ is the joint probability of both events happing simultaneously.
$p(A|B)$ is the probability of $A$ occurring conditional on $B$ having occurred;
and $p(B)$ is the marginal probability of $B$.
Alternatively, we can reverse $A$ and $B$ to get: $p(A,B)=p(B|A)p(A)$.
Equating the two expressions gives you the \textbf{first key ingredient}, which is \textbf{Bayes' rule}:
\begin{align*}
p(B|A) = \frac{p(A|B)p(B)}{p(A)}
\end{align*}
This rule also holds for continuous variables such as parameters $\theta$ and data $y$:
\begin{align*}
p(\theta|y) = \frac{p(y|\theta)p(\theta)}{p(y)}
\end{align*}
That is, the key object of interest is the \textbf{posterior} $p(\theta|y)$ distribution,
which is the product of the \textbf{likelihood function} $p(y|\theta)$ and the \textbf{prior density} $p(\theta)$,
divided by the \textbf{marginal data density} $p(y)$.
In other words, the prior contains our prior (non-data) information,
  whereas the likelihood function is the density of the data conditional on the parameters.
Note that the marginal data density $p(y)$ can be ignored as it does not depend on the parameters (it is just a normalization constant).
Therefore, we can use the proportional $\propto$ sign, that is the posterior is proportional to the likelihood times the prior:
\begin{align*}
p(\theta|y) \propto p(y|\theta) p(\theta)
\end{align*}
The posterior summarizes all we know about $\theta$ after seeing the data.
It combines both data and non-data information.
The equation can be viewed as an updating rule, where the data allow us to update our prior views about $\theta$.
	
Note that Bayesians are upfront and rigorous about including non-data information!
The idea is that more information (even if subjective) tends to be better than less.

\item In principle any distribution can be combined with the likelihood to form the posterior.
Some priors are, however, more convenient than others.
\\
\textbf{Conjugate priors:} If a prior is conjugate, then the posterior has the same density as the prior. This eases analytical derivations.
\\
\textbf{Natural conjugate priors:} A conjugate prior is called a natural conjugate prior,
if the posterior and the prior have the same functional form as the likelihood function.
That is, the prior can be interpreted as arising from a fictitious dataset from the same data-generating process.
	
\end{enumerate}