\section[The Kalman filter for DSGE models]{The Kalman filter for DSGE models\label{ex:KalmanFilterDSGE}}
Consider a DSGE model approximated with first-order perturbation techniques such that the endogenous variables $\tilde{y}_t$ are determined linearly by previous endogenous variables $\tilde{y}_{t-1}$ and current shocks $u_t$:
$$(\tilde{y}_t - \bar{y}) = \bar{y} + g_x (\tilde{y}_{t-1} - \bar{y}) + g_u u_t$$
where $\bar{y}$ denotes the steady-state and the shocks are Gaussian: $u_t \sim N(0,\Sigma_u)$. Assume that a subset of variables $d_t$ from $y_t$ can be observed with a measurement error $e_t$ which is orthogonal to $u_t$ and also normally distributed with mean zero and covariance matrix $\Sigma_e$:
$$d_t = H \tilde{y}_t + e_t$$
In the following exercises, we'll make use of the following notation: (1) a time subscript, e.g. $d_t$, denotes a particular observation, (2) a time superscript, e.g. $d^t=\{d_t,...,d_1\}$, denotes the complete history of observations up to a certain point in time $t$, (3) $\hat{y}_{t|t-1} \equiv E(y_t|d^{t-1})$ is the conditional expectation on information provided by $d^{t-1}$ and $\Sigma_{t|t-1} \equiv E\left[ (y_t-\hat{y}_{t|t-1}) (y_t-\hat{y}_{t|t-1})'|d^{t-1}\right]$ is the corresponding mean-squared-error/covariance matrix conditional on $d^{t-1}$.

\begin{enumerate}
	\item Denote $y_t = \tilde{y}_t - \bar{y}$ as model variables in deviation from steady-state. Show how to put the model solution into a so-called linear Gaussian state-space system. What are the controls, states, innovations and noise variables? What is the probability distribution of $d_t$? Why isn't it possible to directly construct it? What do we need?
	\item What is the basic problem the Kalman filter solves? What is the goal?
	\item Derive the recursive algorithm in the following steps:
	\begin{enumerate}
		\item Assume that the initial value $y_0$ is normally distributed: $y_0 \sim N(\hat{y}_{0|-1},\Sigma_{0|-1})$ with \textbf{known} values for $\hat{y}_{0|-1}$ and $\Sigma_{0|-1}$. What does this imply for the distribution of $d_0$? Moreover, comment on the values one typically uses for $\hat{y}_{0|-1}$ and $\Sigma_{0|-1}$ when the underlying state-space model is stationary.
		\item Based on $d_0$ and $y_0$, compute the state forecast $\hat{y}_{1|0}$ using the idea of a population regression coefficient. That is, use a regression of the unknown difference between the true state $y_1$ and our forecast of it made yesterday $\hat{y}_{1|0}$ on the new information contained in the observation $d_1$ compared to what we had predicted it to be, i.e. $(d_1 - \hat{d}_{1|0})$. In other words, derive the following formula:
		$$\hat{y}_{1|0} \equiv E[y_1|d^0] = g_x \hat{y}_{0|-1} + K_0\left(d_0-H\hat{y}_{0|-1}\right)$$
	    where the matrix $K_0 = g_x \Sigma_{0|-1} H'(H\Sigma_{0|-1}H' + \Sigma_e)^{-1}$ is the so-called Kalman gain. Interpret this equation.
		\item Derive the full distribution of $y_1|d^0$.
		\item Generalize the previous steps and outline the recursive nature of the Kalman filter. That is, show that the conditional distribution of $y_{t+1}$ given information from $t$ is given by:
		$$y_{t+1}|d^t \sim N(\hat{y}_{t+1|t},\Sigma_{t+1|t})$$
		Provide the closed-form expressions for the state forecast $\hat{y}_{t+1|t}$ and corresponding mean-squared-error/covariance matrix $\Sigma_{t+1|t}$.
		\item Summarize the recursive algorithm and key objects to compute when doing the Kalman filter recursions.
	\end{enumerate}
	\item Derive the log-likelihood function $p(d_T,...,d_1)$ by factorizing it. Show that the Kalman filter delivers everything needed to compute the log-likelihood as a \emph{by-product}.
	\item What does the concept of \emph{stochastic singularity} mean in the context of computing the Gaussian likelihood function using the Kalman filter?
	\item In which sense is the Kalman filter \emph{optimal} for linear Gaussian state-space systems?
	\item Write a function called \texttt{dsge\_kalman\_filter.m} that computes the log-likelihood for any DSGE model given a data matrix $d^T$,values for the steady-state of observables $\bar{d}$, values for the state-space matrices $H$, $g_x$, $g_u$, and values for the covariance matrices $\Sigma_u$ and $\Sigma_e$. The output is the $T$-dimensional vector of the conditional contributions $\log p(d_t|d^{t-1})$ to the Gaussian log-likelihood function, where the first entry is based on the prediction of $y_t$ at its unconditional mean and unconditional covariance matrix.
	\item Write a function called \texttt{dsge\_loglikelihood.m} that computes the log-likelihood for any DSGE model by first solving the model with first-order perturbation techniques and then summing up the conditional log-likelihood contributions $\log p(d_t|d^{t-1})$ computed by above function \texttt{dsge\_kalman\_filter.m}. Note that the inputs are data matrix $d^T$ and numerical values for the parameters (both model and covariance matrix parameters).
	\item Compute the log-likelihood function of the Basic New Keynesian model given a feasible calibration for the model and covariance parameters. Use the simulated data provided in \texttt{BasicNewKeynesianSimdat.mat}.
\end{enumerate}

\begin{solution}\textbf{Solution to \nameref{ex:KalmanFilterDSGE}}
\ifDisplaySolutions
\input{exercises/kalman_filter_solution.inc}
\fi
\newpage
\end{solution}