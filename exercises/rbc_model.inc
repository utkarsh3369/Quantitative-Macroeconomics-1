\section[RBC model]{RBC model\label{ex:RBCModel}}
Consider the basic Real Business Cycle (RBC) model with leisure.
The representative household maximizes present as well as expected future utility
\begin{align*}
	\max E_t \sum_{j=0}^{\infty} \beta^{j} U_{t+j}
\end{align*}
with $\beta <1$ denoting the discount factor and $E_t$ is expectation given information at time $t$.
The contemporaneous utility function 
\begin{align*}
	U_t = \gamma \log(c_t) + \psi \log{(1-l_{t})}
\end{align*}
is additively separable and has two arguments: consumption $c_t$ and normalized labor supply $l_{t}$.
The marginal utility of consumption is positive, whereas more labor supply reduces utility.
Accordingly, $\gamma$ is the consumption weight in the utility function and $\psi$ the weight on leisure.
In each period the household takes the real wage $w_t$ as given and supplies perfectly elastic labor service to the representative firm.
In return, she receives real labor income in the amount of $w_t l_{t}$ and, additionally,
  real profits ${div}_t$ from the firm as well as revenue from lending capital $k_{t-1}$ at real rental rate $r_{k,t}$ to the firms,
  as it is assumed that the firm and capital stock are owned by the household.
Income and wealth are used to finance consumption $c_t$ and investment $i_t$.
In total, this defines the (real) budget constraint of the household:
\begin{align*}
c_t + i_t = w_t l_{t} + r_{k,t} k_{t-1} + {div}_t
\end{align*}
The law of motion for capital $k_t$ at the end of period $t$ is given by
\begin{align*}
k_{t} = (1-\delta) k_{t-1} + i_t
\end{align*}
where $\delta$ is the capital depreciation rate.\footnote{
    Note that we use the end-of-period timing convention for capital, i.e. $k_t$ instead of $k_{t+1}$,
      because the investment decision is done in period $t$ and hence capital is also determined in $t$.
    In older papers and books you will often find beginning-of-period timing convention for capital,
    so always think about when a variable is decided and determined.}
Assume that the transversality condition is full-filled.
	
Productivity $a_t$ is the driving force of the economy and evolves according to
\begin{align*}
\log{a_{t}} &= \rho_a \log{a_{t-1}}  + \varepsilon_{a,t}
\end{align*}
where $\rho_a$ denotes the persistence parameter and $\varepsilon_{a,t}$ is assumed to be normally distributed with mean zero and variance $\sigma_a^2$.
	
Real profits ${div}_t$ of the representative firm are revenues from selling output $y_t$ minus costs from labor $w_t l_{d,t}$ and renting capital $r_{k,t} k_{d,t-1}$:
\begin{align*}
{div}_t = y_{t} - w_{t} l_{d,t} - r_{k,t} k_{d,t-1}
\end{align*}
The representative firm maximizes expected profits
\begin{align*}
	\max E_t \sum_{j=0}^{\infty} {\Lambda}_{t,t+j} {div}_{t+j}
\end{align*}
subject to a Cobb-Douglas production function
\begin{align*}
f(k_{d,t-1}, l_{d,t}) = y_t = a_t k_{d,t-1}^\alpha l_{d,t}^{1-\alpha}
\end{align*}
The stochastic discount factor ${\Lambda}_{t,t+j}$ takes into account that firms are owned by the household,
  i.e. it is the present value of a unit of consumption in period $t+j$ or, respectively,
  the marginal utility of an additional unit of profit;
  therefore
\begin{align*}
\Lambda_{t,t+j}=\beta^j \frac{\partial U_{t+j}/\partial c_{t+j}}{\partial U_{t}/\partial c_{t}}
\end{align*}
	
Finally, we have non-negativity constraints	$k_t \geq 0$, $c_t \geq 0$ and $0 \leq l_t \leq 1$.

\begin{enumerate}
\item Show that the first-order conditions of the representative household are given by
\begin{align*}
U_{c,t} &= \beta E_t\left[U_{c,t+1} \left(1-\delta + r_{k,t+1}\right)\right]
\\
w_t &= -\frac{U_{l,t}}{U_{c,t}}
\end{align*}
where $U_{c,t} = \gamma c_t^{-1}$ and $U_{l,t} = \frac{-\psi}{1-l_t}$.
Interpret these equations in economic terms.

\item Show that the first-order conditions of the representative firm are given by
\begin{align*}
w_t &= f_l
\\
r_{k,t} &= f_k
\end{align*}
where $f_l = (1-\alpha) a_t \left(\frac{k_{d,t-1}}{l_{d,t}}\right)^\alpha$ and $f_k = \alpha a_t \left(\frac{k_{d,t-1}}{l_{d,t}}\right)^{1-\alpha}$.
Interpret these equations in economic terms.

\item Show that combining the optimal decisions with clearing of both the labor market, i.e. $l^s_t = l_t$, and the capital market, $k^d_t = k_t$ implies clearing of the goods market:
\begin{align*}
y_t = c_t + i_t
\end{align*}  

\item Derive the steady-state of the model, in the sense that there is a set of values for the endogenous variables that in equilibrium remain constant over time.

\item Discuss how to calibrate the following parameters $\alpha$, $\beta$, $\delta$, $\gamma$, $\psi$, $\rho_a$ and $\sigma_a$.

\item Briefly provide intuition behind the transversality condition.

\item Write a script for this RBC model with a feasible calibration for an OECD country that computes the steady-state of the model.

\item Write a DYNARE mod file for this RBC model with a feasible calibration for an OECD country
  and compute the steady-state of the model by using a \texttt{steady\_state\_model} block.
  Compare this to the steady-state computed above.

\item Now assume a contemporaneous utility function of the CRRA (constant Relative Risk Aversion) type:\footnote{
    Note that due to L'Hopital's rule $\eta_c=\eta_l=1$ implies the original specification, $U_t=\gamma \log c_t + \psi \log(1-l_t)$.}
\begin{align*}
    U_t = \gamma \frac{c_{t}^{1-\eta_c}-1}{1-\eta_c} + \psi \frac{(1-l_{t})^{1-\eta_l}-1}{1-\eta_l}
\end{align*}
\begin{enumerate}
    \item Derive the model equations and steady-state analytically.
    \item Write a script to compute the steady-state for this model.
    \item Write a DYNARE mod file and compute the steady-state for this model by using a helper function in the \texttt{steady\_state\_model} block.
\end{enumerate}

\end{enumerate}

\paragraph{Readings}
\begin{itemize}
	\item \textcite[Ch.~3, Ch.~6]{McCandless_2008_ABCsRBCsIntroduction}
	\item \textcite[Ch.~1, Ch.~2]{Torres_2013_IntroductionDynamicMacroeconomic}
\end{itemize}

\begin{solution}\textbf{Solution to \nameref{ex:RBCModel}}
\ifDisplaySolutions
\input{exercises/rbc_model_solution.inc}
\fi
\newpage
\end{solution}