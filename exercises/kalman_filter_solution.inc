The Kalman filter was originally developed by Kalman (1960) and Kalman and Bucy (1961).
\begin{enumerate}
	\item Point of departure is our first-order perturbation solution which can be cast into a linear Gaussian state-space system:
	\begin{align*}
		y_t &= g_x y_{t-1} + g_u u_t &\text{  [Transition Equation]}
		\\
		d_t &= \bar{d} + H y_t + e_t       &\text{  [Measurement Equation]}
	\end{align*}
	where $y_t$ denote model variables in deviation from their steady-state and $\bar{d}=H\bar{y}$ denotes the steady-state of the observable variables. Note that $H$ is simply a selection matrix picking the model variables that correspond to our data variables. In control theory, statistics or engineering such a system is called a \textbf{linear Gaussian state-space system}. In this literature:
	\begin{itemize}
		\item $y_t$ is the state vector (describe the state of the model)
		\item $d_t$ is the control vector (describe the observable variables)
		\item $u_t$ is the innovations vector (describe stochastic disturbances to the states)
		\item $e_t$ is the noise vector (describe measurement errors)
	\end{itemize}
	From statistics we know that linear combinations of Gaussian random vectors (like $u_t$ and $e_t$) are also Gaussian, so we can infer that
	$$d_t = \bar{d} +  H(g_x y_{t-1} + g_u u_t) + e_t$$
	is also Gaussian. However, the mean and covariance matrix are dependent on the mean and covariance of unobserved variables $y_{t-1}$, for which we don't have data, so we cannot directly construct the likelihood $f(d_T,...,d_1)$.
	
	\item So the \textbf{problem} the Kalman filter solves is to provide estimates for the mean and covariance matrix of the \textbf{unobserved variables} $y_{t}$ so that we can use the implied Gaussianity of $d_t$ to compute the likelihood $f(d_T,...,d_1)$. The Kalman filter backs these estimates out from the observed data in a \textbf{recursive fashion}. In more detail: we know
	\begin{itemize}
		\item the values of the state-space matrices: $g_x$, $g_u$, $\Sigma_u$, $\Sigma_e$		
		\item the linear structure with Gaussian $u_t$ and $e_t$		
	\end{itemize}
	This implies that the Gaussian distribution of $d_t$ and $y_t$ is sufficiently described by the first two moments. However, we only have \textbf{observed variables} $d^T = \{d_T,...,d_1\}$ from which we want to infer the \textbf{unobserved variables} $y^T = \{y_T,...,y_1\}$. Our aim is therefore to find \textbf{recursive} formulas for the		
	\begin{itemize}
		\item first moment, i.e. state forecast $\hat{y}_{t|t-1}$ and state forecast error $(y_t - \hat{y}_{t|t-1})$
		\item second moment, i.e. mean squared error\slash covariance matrix of state forecast error: $\Sigma_{t|t-1}$		
	\end{itemize}		
	Recursiveness allows for online tracking, i.e. at time $t$, when a new observation becomes available, we can combine the old forecast and the new observation to build the new forecast.
	
	\item How do we initialize the filter at $t=0$ where no observations are available? Let's \textbf{assume} that the initial value $y_0$ is also normally distributed as
	$$y_0 \sim N(\hat{y}_{0|-1},\Sigma_{0|-1})$$
	where the subscript ''-1'' denotes the information we have at the beginning of times (often this is just denoted by $y_0$ and $\Sigma_0$). Note that $\hat{y}_{0|-1}$ and $\Sigma_{0|-1}$ can be, in principle, any \textbf{known} matrix. However, for stationary systems, it has become common practice to initialize at the unconditional (long-run) mean and covariance matrix of $y_t$ which we can compute from our state transition equation. That is, provided that all eigenvalues of $g_x$ are inside the unit circle (which is true by construction of our solution algorithm), the unconditional mean $\mu_y$ is equal to 0 (as $y_t$ is defined as model variables $\tilde{y}_t$ in deviation from their steady-state $\bar{y}$):
	$$\hat{y}_{0|-1} = \mu_y = E[y_t] = E[\tilde{y}_t - \bar{y}] = E[\tilde{y}_t] - \bar{y} = \bar{y} - \bar{y} = 0$$
	and the unconditional covariance matrix is given by the solution $\Sigma_y$ to the Lyapunov equation:
	$$\Sigma_{0|-1} = \Sigma_y = E[(y_t-\mu_y)(y_t-\mu_y)'] = E[y_t y_t'] = g_x \Sigma_y g_x' + g_u \Sigma_u g_u'$$
	Again this is an arbitrary choice, but becomes important if one deals e.g. with non-stationarities in some variables in the state-space system. We won't cover the so-called \emph{diffuse filter} in these cases, but focus on stationary systems for which it has been shown that initialization by the unconditional first two moments is very efficient. Either way, the important insight is that we have some \textbf{known} values for $\hat{y}_{0|-1}$ and $\Sigma_{0|-1}$ by simply initializing these.

	Now, what does this imply for the distribution of $d_0 = \bar{d} + H y_0 + e_0$?
	\begin{itemize}
		\item Conditional expectation given information up to $t=-1$:
		$$\hat{d}_{0|-1} \equiv E(d_0|d^{-1}) = E[\bar{d} + Hy_0+e_0|d^{-1}] = \bar{d} + H \hat{y}_{0|-1}$$
		\item Conditional variance (which is the mean squared error of $d_0$) given information up to $t=-1$:
		\begin{align*}
			E\left[(d_0 - \hat{d}_{0|-1}) (d_0 - \hat{d}_{0|-1})'| d^{-1}\right] &= E\left[(Hy_0+e_0-H\hat{y}_{0|-1}) (Hy_0+e_0-H\hat{y}_{0|-1})' | d^{-1}\right]
			\\
			&= E\left[H(y_0-\hat{y}_{0|-1}) (y_0-\hat{y}_{0|-1})'H' + e_0e_0' | d^{-1}\right]
			\\
			&= H \Sigma_{0|-1}H' + \Sigma_e
		\end{align*}
		Note that cross terms in $e_0$ have been dropped due to them being uncorrelated with everything else.
	\end{itemize}
	Hence, we know the Normal distribution of $d_0$ in closed-form as we are able to compute the mean and the covariance matrix:
	$$d_0 \sim N(\bar{d} + H \hat{y}_{0|-1} , H \Sigma_{0|-1}H' + \Sigma_e) $$
	Conditional on this, let's now try to find the conditional Normal distribution of $d_1$, which is dependent on the conditional distribution of $y_1$ which will be described by the state forecast $\hat{y}_{1|0}$ and the covariance\slash mean-squared-error matrix $\Sigma_{1|0}$.

	\item Let's set up such a regression for some period $t$ (today) given $t-1$ (yesterday) information:
	$$(y_t-\hat{y}_{t|t-1}) = L_t (d_t - \hat{d}_{t|t-1}) + \eta_t$$	
	Note that $L_t$ is the regression coefficient and $\eta_t$ is orthogonal to the variables contained in the information set at time $t$ by being a regression residual. Our forecast $\hat{d}_{t|t-1}$ of $d_t$ is given from the state-space equations by: $\hat{d}_{t|t-1} = \bar{d} + H \hat{y}_{t|t-1}$
	
	Let's define the forecast error as: $a_t \equiv d_t - \hat{d}_{t|t-1} = d_t - \bar{d} - H\hat{y}_{t|t-1}$.
	
	The implied regression equation is then given by:
	$$(y_t-\hat{y}_{t|t-1}) = L_t (d_t - \bar{d} - H \hat{y}_{t|t-1}) + \eta_t$$
	Of course we don't know the left-hand side to actually run the regression and compute $L_t$. BUT if we somehow know $L_t$, we could form a forecast of our forecast error for the state. So let's use the general formula for the coefficient of a population regression:
	$$\beta = E[YX']E[(X'X)]^{-1} $$	
	In our case:
	\begin{align*}
	L_t &= E\left[ (y_t-\hat{y}_{t|t-1}) (d_t - \bar{d} - H \hat{y}_{t|t-1})' \right] \times \left(E\left[ (d_t - \bar{d} - H \hat{y}_{t|t-1})' (d_t - H \hat{y}_{t|t-1})\right]\right)^{-1}
	\\
	&=E\left[ (y_t-\hat{y}_{t|t-1}) (H y_t - H \hat{y}_{t|t-1})' \right] \times \left( H\Sigma_{t|t-1}H'+\Sigma_e\right)^{-1}
	\\
	&=E\left[ (y_t-\hat{y}_{t|t-1}) (y_t - \hat{y}_{t|t-1})'\right]H' \times \left( H\Sigma_{t|t-1}H'+\Sigma_e\right)^{-1}
	\\
	&= \Sigma_{t|t-1} H'(H\Sigma_{t|t-1}H' + \Sigma_e)^{-1}
	\end{align*}
	where again we use the fact that $e_t$ is orthogonal to all other terms and the expectation of these terms is zero and therefore those cross terms can be dropped. Note that $L_t$ is a function of values that we have already computed, the right-hand side is known from the previous period's covariance matrix. So for period 1:
	$$L_1 = \Sigma_{1|0} H'(H\Sigma_{1|0}H' + \Sigma_e)^{-1}$$
	Now, let's do the state forecast, i.e. given our best forecast for the state today at time 0, our best forecast for tomorrow's state $y_1$ is given by:
	$$\hat{y}_{1|0} = E[y_1|d^0] = E[g_x y_0 + g_u u_1|d^0] = g_x E[ y_0|d^0] + g_u \underbrace{E[u_1|d^0]}_{=0} = g_x \hat{y}_{0|0}$$
	At the same time, rewrite state transition equation $y_t = g_x y_{t-1} + g_u u_t$ for $y_1$ as:
	$$y_1 = g_x y_{0} + g_u u_1 = g_x \hat{y}_{0|-1} + g_x(y_0-\hat{y}_{0|-1}) + g_u u_1 = g_x \hat{y}_{0|-1} + g_x\left(L_0\left(d_0-\bar{d}-H\hat{y}_{0|-1}\right)+e_0\right) + g_u u_1$$
	Now try to forecast tomorrow's state given information until time 0:
	$$\hat{y}_{1|0} = E[y_1|d^0] = g_x \hat{y}_{0|-1} + \underbrace{g_x L_0}_{K_0}\left(d_0-\bar{d}-H\hat{y}_{0|-1}\right)$$
	This allows to forecast tomorrow's state just based on yesterday's forecast and today's observation. The matrix:
		$$K_0 = g_x L_0 = g_x \Sigma_{0|-1} H'(H\Sigma_{0|-1}H' + \Sigma_e)^{-1}$$
	is called the \textbf{Kalman gain}. It determines by how much your state estimate is updated based on your previous forecast error.

	\item The full distribution of $y_1$ is conditional normal:
		$$y_1|d^0 \sim N(\hat{y}_{1|0},\Sigma_{1|0})$$
		Note that we just computed the mean $\hat{y}_{1|0}$ and now only require to find the covariance\slash mean squared error matrix $\Sigma_{1|0}$. We first note that the state forecast error is:
		\begin{align*}
			(y_1 - \hat{y}_{1|0}) &= g_x y_0 + g_u u_1 - \hat{y}_{1|0} = g_x y_0 + g_u u_1 - \left( g_x \hat{y}_{0|-1} + K_0\left(d_0-\bar{d}-H\hat{y}_{0|-1}\right) \right)
			\\
			&=g_x \left(y_0 - \hat{y}_{0|-1} \right) + g_u u_1 - K_0 (d_0 - \bar{d} - H\hat{y}_{0|-1})
		\end{align*}		 
		Then the covariance matrix is:
		\begin{align*}
			\Sigma_{1|0} &= E\left[(y_1 - \hat{y}_{1|0})(y_1 - \hat{y}_{1|0})'|d^0\right]
			\\
			&=E\left[(g_x (y_0 - \hat{y}_{0|-1} ) + g_u u_1 - K_0 (d_0 - \bar{d} - H\hat{y}_{0|-1})) (g_x (y_0 - \hat{y}_{0|-1}) + g_u u_1 - K_0 (d_0 - \bar{d} - H\hat{y}_{0|-1}))' |d^0 \right]
			\\
			&=E\left[ g_x(y_0-\hat{y}_{0|-1})(y_0-\hat{y}_{0|-1})'g_x' + g_x(y_0-\hat{y}_{0|-1})u_1' g_u'- g_x(y_0-\hat{y}_{0|-1})(d_0 - \bar{d} - H\hat{y}_{0|-1})'K_0' |d^0 \right]
			\\
			&+ E\left[g_u u_1(y_0-\hat{y}_{0|-1})'g_x' + g_u u_1 u_1' g_u' - g_u u_1 (d_0 - \bar{d} - H\hat{y}_{0|-1})'K_0'|d^0 \right]
			\\
			&- E\left[K_0 (d_0 - \bar{d} - H\hat{y}_{0|-1})(y_0-\hat{y}_{0|-1})'g_x' - K_0 (d_0 - \bar{d} - H\hat{y}_{0|-1})u_1' g_u' \right.
			\\ &\left. \qquad\qquad\qquad\qquad\qquad\qquad\qquad\qquad+ K_0 (d_0 - \bar{d} - H\hat{y}_{0|-1})(d_0 - \bar{d} - H\hat{y}_{0|-1})' K_0'  |d^0 \right]			
		\end{align*}
		Let's insert $d_0=\bar{d} + H y_0 + e_0$ and note that both $u_1$ and $e_0$ are orthogonal to all cross terms on the right hand side of the above equation. Therefore:
		\begin{align*}
			\Sigma_{1|0} & =\underbrace{E\left[g_x(y_0-\hat{y}_{0|-1})(y_0-\hat{y}_{0|-1})'g_x'|d^0 \right]}_{g_x \Sigma_{0|-1}g_x'}
			\\
			&- \underbrace{E\left[g_x(y_0-\hat{y}_{0|-1})(H y_0 - H\hat{y}_{0|-1})'K_0'|d^0 \right]}_{g_x \Sigma_{0|-1}H'K_0'}
			\\
			&+ \underbrace{E\left[g_u u_1 u_1' g_u'|d^0 \right]}_{g_u \Sigma_u g_u'}
			\\
			&- \underbrace{E\left[K_0 (H y_0  - H\hat{y}_{0|-1})(y_0-\hat{y}_{0|-1})'g_x'|d^0 \right]}_{K_0 H \Sigma_{0|-1}g_x'}
			\\
	        &+ \underbrace{E\left[K_0 (H y_0  - H\hat{y}_{0|-1})(H y_0 - H\hat{y}_{0|-1})' K_0'|d^0 \right]}_{K_0(H\Sigma_{0|-1}H' + \Sigma_e)K_0'}
			\\
			\Sigma_{1|0}&=g_x \Sigma_{0|-1}g_x' + g_x \Sigma_{0|-1}H'K_0' + g_u \Sigma_u g_u' - K_0 H \Sigma_{0|-1}g_x' + K_0(H\Sigma_{0|-1}H' + \Sigma_e)K_0'
		\end{align*}	
		Simplifying:
		$$\Sigma_{1|0} = (g_x - K_0 H) \Sigma_{0|-1} (g_x - K_0 H)' + g_u \Sigma_u g_u' + K_0 \Sigma_e K_0'$$
		Note that to update the covariance matrix $\Sigma_{1|0}$ we only require knowledge of the previous period's covariance matrix $\Sigma_{0|-1}$ and the given matrices of the state-space system.
		
		We have thus computed everything we need for the distribution of 
		$$y_1|d^0 \sim N(\hat{y}_{1|0},\Sigma_{1|0})$$

		\item From the previous step we now know the conditional distribution of $y_1$ given information and our forecasts from $t=0$. We can start over again, delivering the recursion we were looking for, i.e. derive the conditional distribution of $y_2$ given information and our forecasts from $t=1$! This holds for any \emph{tomorrow} period $t+1$ conditional on the corresponding \emph{today} period $t$ such that the conditional distribution of $y_{t+1}$ given information from $t$ is given by:
		$$y_{t+1}|d^t \sim N(\hat{y}_{t+1|t},\Sigma_{t+1|t})$$
		where
		\begin{align*}
			\hat{y}_{t+1|t} &= g_x \hat{y}_{t|t-1} + K_t \underbrace{\left(d_t-\bar{d} - H\hat{y}_{t|t-1}\right)}_{a_t}
			\\
			\Sigma_{t+1|t} &= (g_x - K_t H) \Sigma_{t|t-1} (g_x - K_t H)' + g_u \Sigma_u g_u' + K_t \Sigma_e K_t'				
		\end{align*}
		
		\item Initialize $\hat{y}_{0|-1}$ and $\Sigma_{0|-1}$, then for $t=1,...,T$:
		\begin{enumerate}
			\item Compute the Kalman Gain using: $$K_t = g_x \Sigma_{t|t-1} H' \Omega_t^{-1}$$ where $\Omega=H \Sigma_{t|t-1} H' + \Sigma_e$		
			\item Compute the forecast error in the observations using: $$a_t=d_t - \bar{d} - H \hat{y}_{t|t-1}$$		
			\item Compute the state forecast for next period given today's information: $$\hat{y}_{t+1|t} = g_x \hat{y}_{t|t-1} + K_t a_t$$
			\item Update the covariance matrix: $$\Sigma_{t+1|t} = (g_x - K_t H) \Sigma_{t|t-1} (g_x - K_t H)' + g_u \Sigma_u g_u' + K_t \Sigma_e K_t'$$		
		\end{enumerate}

	\item Typically we are not interested in filtering per se, but rather in estimating the parameters of our DSGE model given our observables $d^t$ up to time $t$. The Likelihood function $f(d_T,...,d_0)$ can be factored as:
		$$f(d_T,...,d_0) = f(d_T|d^{T-1}) \times f(d_{T-1}|d^{T-2}) \times ... \times f(d_1|d^{0}) \times f(d_0)$$
		where $d_0 = d_{0|-1}$ denotes information at beginning of times.

		Now we can infer from $d_t = \bar{d} + H y_t + e_t$ that
		$$d_t|d^{t-1} \sim N(\bar{d}+H\hat{y}_{t|t-1},\underbrace{H\Sigma_{t|t-1}H' + \Sigma_e}_{\Omega_t})$$
		Note that the mean is a function of $\bar{d}$ and $d^{t-1}$ only, while $\Omega_t$ only depends on the population moments and not on the data. Thus, these moments are sufficient statistics to compute the likelihood as they describe the first two moments of the conditional normal distribution, which the observables follow.

		Hence the probability density of observing $d_t$ given $d^{t-1}$ is given by:
		$$f(d_t|d^{t-1})=\frac{1}{\sqrt{(2\pi)^{n_d}\det(\Omega_t)}} e^{-\frac{1}{2}(d_t - \bar{d} - H\hat{y}_{t|t-1})'\Omega_t^{-1}(d_t - \bar{d} - H\hat{y}_{t|t-1})}$$
		Taking logs and noting that $a_t = d_t - \bar{d} - H\hat{y}_{t|t-1}$ leads to the log-likelihood function for each observation:
		$$\log(f(d_t|d^{t-1})) = \frac{-n_d}{2}\log(2\pi) -\frac{1}{2}\log(\det(\Omega_t)) - \frac{1}{2} a_t' \Omega_t^{-1} a_t$$

		\textbf{In a nutshell: the Kalman filter delivers everything needed to compute the likelihood simply as a \emph{byproduct}!}
		\paragraph{Sidenote} Note that the Kalman filter recursions provide us with \textbf{filtered variables}, i.e. the best prediction for tomorrow's state given information up to today. We can also compute updated variables $\hat{y}_{t|t}$, i.e. our best estimate of the state today given information up to today (note that we don't have data on all $y_t$!). One can show that:
		\begin{align*}
		\hat{y}_{t|t} &= \hat{y}_{t|t-1} + L_ta_t
		\\
		\Sigma_{t|t} &= \Sigma_{t|t-1} - \Sigma_{t|t-1}H'(H\Sigma_{t|t-1}H'+\Sigma_e)H\Sigma_{t|t-1}	
		\end{align*}
		More importantly, we are regularly interested in our best estimates of shocks and states given the full observed data up to time $T$. The so-called \textbf{Kalman Smoother} provides (backward) recursions for obtaining these estimates. As we don't require this for estimation we won't cover it, but the idea is pretty much the same, except that we start with the full sample and work backwards in time to update the smoothed variables.
	
	\item Note that we need to compute an inverse of $\Omega_t = H\Sigma_{t|t-1}H' + \Sigma_e$, i.e. we require that the forecast error matrix of the observables must have full rank. Typical requirements:
		\begin{itemize}
			\item at least as many shocks+measurement errors as observables	
			\item having more shocks\slash measurement errors is not a problem	
			\item no collinearity between observables (e.g. when all components of budget constraint $y_t=c_t+i_t$ are observed, $\Omega_t$ will be singular)	
		\end{itemize}
		Typical way out: add measurement errors and don't use collinear observables.
	\item In our derivation we have motivated the Kalman filter as a least squares estimator. From econometrics we know that the OLS estimator is BLUE (best linear unbiased estimator), and this is also true for the Kalman filter. Of course, only if the assumptions are fullfilled. That is, \textbf{IF} we have a linear state-space system and \textbf{IF} the initial conditions, innovations and noise are normally distributed, then the Kalman filter provides the best predictors (unbiased and efficient) for the states! If conditions are not full-filled, the Kalman filter is still hard to beat in many applications and remains the benchmark.
	\item MATLAB code for \textbf{\texttt{dsge\_kalman\_filter.m}}\lstinputlisting[style=Matlab-editor,basicstyle=\mlttfamily]{progs/matlab/dsge_kalman_filter.m}
	\item MATLAB code for \textbf{\texttt{dsge\_loglikelihood.m}}\lstinputlisting[style=Matlab-editor,basicstyle=\mlttfamily]{progs/matlab/dsge_loglikelihood.m}
	\item MATLAB code for \textbf{full illustration for Basic New Keynesian model}
	\lstinputlisting[style=Matlab-editor,basicstyle=\mlttfamily]{progs/matlab/XRunKalmanFilter_BasicNewKeynesian.m}
\end{enumerate}