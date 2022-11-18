\begin{enumerate}
\item For the specification of multi-equation models we require a clear distinction between exogenous and endogenous variables.
In economic theory this is often not clear or arbitrarily made in practice.
Vectorautoregressive models do not need this distinction,
  they can rather be understood as a dynamic version of a simultaneous multi-equation model.
This corresponds to reality, because economic variables are generated by dynamic processes which are often dependent.
For example, we are able to consider correlations between $ u_ {1, t} $ and $u_ {2,t}$,
  which we would not be able if we considered each equation separately.
VAR models therefore provide a powerful instrument.

Additionally, they can also deal with issues like non-stationarity (co-integration and long-term equilibria)
  as well as the analysis of dynamics of random shocks / impulses.
 Lastly, VAR models tend to have better predictive power than multi-equation models and are often used as a benchmark.

\item \emph{Interpretation of $E[y_t]$:}
Each component of $y_t$ has its own expectation.
Therefore, $E[y_t]$ is the unconditional expectation of $y_t$ at period $t$.
The expected value as a linear operator can be dragged into a vector or matrix:
\begin{align*}
E[y_t] = E\left[\begin{pmatrix}y_{1,t} \cr \vdots \cr y_{K,t} \end{pmatrix} \right] = \begin{pmatrix}E[y_{1,t}] \cr \vdots \cr E[y_{K,t}] \end{pmatrix}
\end{align*}

\emph{Interpretation of $\Gamma_y(h)$:}
In the univariate case we defined the autocovariance as the covariance of a random variable with its own lagged values.
In the multivariate case we also consider covariances between different variables and different points in time.
The autocovariance matrix ${\Gamma_y(h)} := Cov[{y_{t},{y_{t-h}}}]$ summarizes this information up in a neat fashion
and is therefore a powerful tool in multivariate time series analysis:
\begin{align*}
&Cov[{y_{t},{y_{t-h}}}] = E\left[({y_{t}}-E[{{y_{t}}}]) ({y_{t-h}}-E[{{y_{t-h}}}])' \right]\\
&= E\left[\begin{pmatrix}y_{1,t} - E[y_{1,t}] \cr \vdots \cr y_{K,t} - E[y_{K,t}] \end{pmatrix} \begin{pmatrix} y_{1,{t-h}} - E[y_{1,{t-h}}] & \dots & y_{K,{t-h}} - E[y_{K,{t-h}}]  \end{pmatrix} \right]\\
&= E\left[\begin{pmatrix}
(y_{1,t}- E[y_{1,t}])(y_{1,{t-h}} - E[y_{1,{t-h}}]) & \dots & (y_{1,t} - E[y_{1,t}])(y_{K,{t-h}} - E[y_{K,{t-h}}])\\
\vdots & \ddots & \vdots\\
(y_{K,t}- E[y_{K,t}])(y_{1,{t-h}} - E[y_{1,{t-h}}]) & \dots & (y_{K,t} - E[y_{K,t}])(y_{K,{t-h}} - E[y_{K,{t-h}}])
\end{pmatrix} \right]\\
&= \begin{pmatrix}
E[(y_{1,t}- E[y_{1,t}])(y_{1,{t-h}} - E[y_{1,{t-h}}])] & \dots & E[(y_{1,t} - E[y_{1,t}])(y_{K,{t-h}} - E[y_{K,{t-h}}])]\\
\vdots & \ddots & \vdots\\
E[(y_{K,t}- E[y_{K,t}])(y_{1,{t-h}} - E[y_{1,{t-h}}])] & \dots & E[(y_{K,t} - E[y_{K,t}])(y_{K,{t-h}} - E[y_{K,{t-h}}])]
\end{pmatrix}\\
&=\begin{pmatrix}
Cov[y_{1,t},y_{1,{t-h}}] & \dots & Cov[y_{1,t},y_{K,{t-h}}]\\
\vdots & \ddots & \vdots\\
Cov[y_{K,t},y_{1,{t-h}}] & \dots & Cov[y_{K,t},y_{K,{t-h}}]
\end{pmatrix}
\end{align*}
On the diagonals we have the autocovariance of each variable,
  on the off-diagonals we have the covariances between the different variables.
	
\item Basically it is the same:
A stochastic process is called weakly stationary (or covariance stationary),
  if for each period in time it has the same expectation independent of time
  and the autocovariance between any two points in time is only dependent on the distance of these two points.
The difference is that in the multivariate case we also consider the autocovariances between different variables
  and require these to be only dependent on the distance in time, but not on time itself.
\\
\texttt{Definition}: The K-dimensional stochastic process $y_t$ is called covariance stationary, if for all $h,t,\tau \in \mathbb{Z}$:
\begin{align}
E[{y_t}] &= E[{y_\tau}]\\
Cov(y_{t},y_{t-h}) &= Cov(y_{t+\tau}, y_{t-h+\tau}) \label{gammas}
\end{align}

\item We will use the \textbf{method of matching coefficients} to transform the VAR(1) model into a VMA($\infty$) representation.
\begin{align*}
	y_t &= A y_{t-1} + u_t\\
	\underbrace{(I_3 - A L)}_{A(L)} y_t &= u_t\\
	A(L) y_t &= u_t \\
	A(L)^{-1}A(L) y_t &= A(L)^{-1} u_t\\
	y_t &= A(L)^{-1} u_t = \nu + \Phi(L) u_t\\
	\Rightarrow & \nu= 0, \Phi(L) = A(L)^{-1}
\end{align*}
In the method of matching coefficient we compare the coefficient matrices multiplied to each power of $L$.
That is, the expression on the left hand side has to match the expression on the right hand side.
In our case:
\begin{align*}
	\Phi(L) &= A(L)^{-1}\\
	A(L) \Phi(L) &= I_3\\
	(I_3 - A L) \left(\sum_{i=0}^\infty \Phi_i L^i\right) &= I_3
\end{align*}
\begin{align*}
	\Phi_0 L^0 &+ \Phi_1 L^1 + \Phi_2 L^2 + \dots \\
	& - A \phi_0 L^1 - A \phi_1 L^2 - \dots = I_3 L^0
\end{align*}
\begin{align}
	L^0&: \Phi_0 &= I_3 \Rightarrow& \Phi_0 = I_3 = \begin{pmatrix}1&0&0\\0&1&0\\0&0&1 \end{pmatrix}\nonumber\\
	L^1&: \Phi_1 - A \Phi_0 &= 0 \Rightarrow& \Phi_1 = A \Phi_0 = A = \begin{pmatrix}0.5&0&0\\0.1&0.1&0.3\\0&0.2&0.3 \end{pmatrix}\nonumber\\
	L^2&: \Phi_2 - A \Phi_1 &= 0 \Rightarrow& \Phi_2 = A \Phi_1 = A^2 = \begin{pmatrix}0.25&0&0\\0.06&0.07&0.12\\0.02&0.08&0.15 \end{pmatrix}\nonumber\\
	\vdots\nonumber\\
	&\text{In general}: \Phi_s = A^s \label{allg}
	\end{align}
\end{enumerate}