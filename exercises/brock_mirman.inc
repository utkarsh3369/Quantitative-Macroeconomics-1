\section[Brock and Mirman (1972) Model]{Brock and Mirman (1972) Model\label{ex:BrockMirman}}
Consider the simple RBC model with log-utility and full depreciation. The objective is to maximize
\begin{align*}
\underset{\{C_{t}\}}{\max}~E_t \sum_{j=0}^{\infty} \beta^{j} \log(C_{t+j})
\end{align*}
subject to the law of motion for capital $K_t$ at the end of period $t$
\begin{align*}
K_{t} = A_tK_{t-1}^\alpha - C_t
\end{align*}
with $\beta <1$ denoting the discount factor and $E_t$ is expectation given information at time $t$. Productivity $A_t$ is the driving force of the economy and evolves according to
\begin{align}
\log{A_{t}} &= \rho_A \log{A_{t-1}}  + \varepsilon_t^A \label{eq:BrockMirmanTFP}
\end{align}
where $\rho_A$ denotes the persistence parameter and $\varepsilon_t^A$ is assumed to be normally distributed with mean zero and variance $\sigma_A^2$.

Finally, we assume that the transversality condition is full-filled and the following non-negativity constraints are fullfilled: $K_t \geq0$ and $C_t \geq 0$.

\begin{enumerate}
	\item Show that the first-order condition is given by
	\begin{align*}
	C_t^{-1} &= \alpha \beta E_t C_{t+1}^{-1} A_{t+1} K_{t}^{\alpha-1}
	\end{align*}
	\item Compute the steady-state of the model, in the sense that there is a set of values for the endogenous variables that in equilibrium remain constant over time.
 	\item The solution to a DSGE model is characterized by decision rules $g$ and $h$, so-called policy functions, for the control variable $C_t$ and the state variables $K_{t}$ and $A_t$:
 	\begin{align*}
		\begin{pmatrix} C_{t}\\K_{t}\\A_{t} \end{pmatrix}
 		 &= g(A_{t-1},K_{t-1},\varepsilon_t^A)
 	\end{align*}
	Note that for $A_t$ the function $g$ is given from \eqref{eq:BrockMirmanTFP}. Now, guess that for $C_t$ and $K_t$ the function $g$ is linear in $A_t K_{t-1}^\alpha$:
 	\begin{align*}
 	C_{t} &= g^C A_t K_{t-1}^\alpha\\
 	K_{t} & = g^K A_t K_{t-1}^\alpha
 	\end{align*}
 	Derive the scalar values $g^C$ and $g^K$ in terms of model parameters $\alpha$ and $\beta$.
 	\item Write a MATLAB file for this RBC model with a feasible calibration for an OECD country. Compute the steady-state and approximate the policy and transition functions with a first-order perturbation method.
 	\item Compare simulated data for the endogenous variables as well as impulse response functions of a one-standard-deviation technology shock based on the true solution with the first-order approximated one.
% 	\begin{solution}
% 	Set \texttt{comparison = 1} and then run the above mod file with Dynare. You see that the first-order approximation of the true solution is quite accurate only when we are in the vicinity of the steady-state. For technology the first-order approximation is exactly the true decision function, because the first-order approximation is equal to a log-linearization. In the IRFs we understate the effect of the technology shock.
% 	\end{solution}
\end{enumerate} 