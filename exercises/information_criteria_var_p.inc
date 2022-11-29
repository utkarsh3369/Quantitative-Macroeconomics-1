\section[Information Criteria for VAR(p)]{Information Criteria for VAR(p)\label{ex:InformationCriteriaVARp}}
Information criteria used for VAR lag order selection have the general form:
\begin{align*}
C(m) = log(det(\tilde{\Sigma_u})) + c_T \varphi(m)
\end{align*}
where $\tilde{\Sigma}_u=T^{-1}\sum_{t=1}^T \hat{u}_t\hat{u}_t'$ is the residual covariance matrix estimator
  for a reduced-form VAR model of order $m$ based on OLS residuals $\hat{u}_t$,
  $\varphi(m)$ is a function of the order $m$ that penalizes large VAR orders
  and $c_T$ is a sequence of weights that may depend on the sample size.
The function $\varphi(m)$ corresponds to the total number of regressors in the system of VAR equations.
Since there are one intercept and $m K$ lagged regressors in each equation and $K$ equations in the VAR model, $\varphi(m)= mK^2 + K$.
Information criteria are based on the premise that there is a trade-off between the improved fit of the VAR model,
  as $m$ increases, and the parsimony of the model.
Given $T$, the fit of the model by construction improves with larger $m$,
  indicated by a reduction in $\log(det(\tilde{\Sigma}_u(m)))$.
At the same time the penalty term, $c_T \varphi(m)$, unambiguously increases with $m$.
We are searching for the value of $m$ that balances the objectives of model fit and parsimony.
The choice of the penalty term determines the trade-off between these conflicting objectives. 

The three most commonly used information criteria for VAR models are known as
  the Akaike Information Criterion (AIC), Schwarz Information Criterion (SIC) and Hannan-Quinn Criterion (HQC):
\begin{align*}
AIC(p)  &= \log(det(\tilde{\Sigma}_u(m))) + \frac{2}{T}\varphi(m)\\
SIC(p)  &= \log(det(\tilde{\Sigma}_u(m))) + \frac{\log T}{T}\varphi(m)\\
HQC(p)  &= \log(det(\tilde{\Sigma}_u(m))) + \frac{2\log (\log T)}{T}\varphi(m)
\end{align*}

The VAR order is chosen such that the respective criterion is minimized over the possible orders $m = p^{min},...,p^{max}$.
A key issue in implementing information criteria is the choice of the upper and lower bounds.
In the context of a model of unknown finite lag order, the default is to set $p^{min}=0$ or sometimes $p^{min} = 1$.
The value of $p^{max}$ must be chosen long enough to allow for delays in the response of the model variables to the shocks.
In practice, common choices would be 12 or 24 lags for monthly data and 4 or 8 lags for quarterly data.

\begin{enumerate}
\item Why is it essential that for a given lag order we compute $\tilde{\Sigma}_u(m)$ on exactly the same evaluation period, $t=p^{max}+1,...T$, for all $m$?
	\item Why is it essential that the criterion function be evaluated at the ML estimator $\tilde{\Sigma}_u=T^{-1}\sum_{t=1}^T \hat{u}_t\hat{u}_t'$ rather than the OLS estimator $\hat{\Sigma}_u=(T-Km-1)^{-1}\sum_{t=1}^T \hat{u}_t\hat{u}_t'$?
 	\item Comment on the asymptotically and finite-sample properties of the criteria.
 	\item Consider data given in \texttt{ThreeVariableVAR.csv} for $y_t = (\Delta gnp_t,i_t,\Delta p_t)'$,
      where $gnp_t$ denotes the log of U.S. real GNP, $p_t$ the corresponding GNP deflator in logs,
      and $i_t$ the federal funds rate, averaged by quarter.
      The estimation period is restricted to 1954q4-2007q4.
      Let $m=\{0,1,...,4\}$.
      Select the lag-order according to the information criteria for the three-variable VAR model given by $y_t$.
\end{enumerate}

\paragraph{Readings}
\begin{itemize}
\item \textcite[Ch.~2.6]{Kilian.Lutkepohl_2017_StructuralVectorAutoregressive}
\end{itemize}

\begin{solution}\textbf{Solution to \nameref{ex:InformationCriteriaVARp}}
\ifDisplaySolutions
\input{exercises/information_criteria_var_p_solution.inc}
\fi
\newpage
\end{solution}