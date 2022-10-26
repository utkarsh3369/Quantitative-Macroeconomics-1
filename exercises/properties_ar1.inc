\section[Properties of AR(1)]{Properties Of AR(1)\label{ex:PropertiesAR1}}

Let $\{\varepsilon_t\}$ be a white noise process with variance $\sigma_\varepsilon^2$.
\begin{enumerate}
	\item Consider the univariate first-order autoregressive process AR(1): 
	$$y_t = \phi y_{t-1} + \varepsilon_{t}$$
	Derive the conditional and unconditional first and second moments.	
	\item  Simulate different AR(1) processes and plot the corresponding autocorrelation function (ACF). To this end write a function \texttt{ACFPlots($y$,$p^{max}$,$\alpha$)} to plot the ACF of the data vector $y$ with maximum number of lags $p^{max}$. Also include an approximate (1-$\alpha$)\% confidence interval around zero in your plot. Hints: 
		 \begin{itemize}
		 	\item The empirical autocorrelation function at lag $k$ is defined as $r_k = c_k/c_0$ where
			$$c_k = \frac{1}{T} \sum_{t=k+1}^T (y_t - \bar{y})(y_{t-k}-\bar{y})$$ and $$c_0 = \frac{1}{T} \sum_{t=1}^T (y_t - \bar{y})(y_{t}-\bar{y})$$
			\item You can either use a for-loop to compute the sum or use vectors: $(y - \bar{y})'(y - \bar{y})$.
		 	\item The sample autocorrelation function is an estimate of the actual autocorrelation only if the process is stationary. If the process is purely random, that is, all members are mutually independent and identically distributed so that $y_t$ and $y_{t-k}$ are stochastically independent for $k\neq 0$, then the normalized estimated autocorrelations are asymptotically standard normally distributed, i.e. $\sqrt{T} r_k \rightarrow U \sim N(0,1)$ and thus $r_k \rightarrow \tilde{U} \sim N(0,1/T)$. 
		 \end{itemize}	
\end{enumerate}
\textbf{Hints:}
\begin{itemize}
	\item If $|\phi|<1$, then $\sum_{j=0}^{\infty} \phi^j = \frac{1}{(1-\phi)}$
\end{itemize}

\paragraph{Readings}

\begin{itemize}
	\item \textcite[Ch.2]{Bjornland.Thorsrud_2015_AppliedTimeSeries}
	\item \textcite{Lutkepohl_2004_UnivariateTimeSeries}
\end{itemize}

\begin{solution}\textbf{Solution to \nameref{ex:PropertiesAR1}}
\ifDisplaySolutions
\input{exercises/properties_ar1_solution.inc}
\fi
\newpage
\end{solution}