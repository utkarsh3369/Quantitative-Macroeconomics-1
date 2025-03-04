\begin{enumerate}

\item Due to the transversality condition,
  we will not have corner solutions and can neglect the non-negativity constraints.
Moreover, due to the concave optimization problem, we only need to focus on the first-order conditions.

The Lagrangian for the household problem is
\begin{align*}
\pounds^H = E_t\sum_{j=0}^{\infty}\beta^j&\left\{\gamma \log(c_{t+j}) + \psi \log(1-l_{t+j}) \right\}
\\
+\beta^j \lambda_{t+j} &\left\{ \left(w_{t+j} l_{t+j} + r_{k,t+j} k_{t-1+j} - c_{t+j} - i_{t+j}\right) \right\}
\\
+\beta^j \mu_{t+j} &\left\{ \left((1-\delta)k_{t-1+j} + i_{t+j} - k_{t+j}\right)\right\}
\end{align*}
Note that the problem is not to choose $\{c_t,i_t,l_t,k_{t}\}_{t=0}^\infty$ all at once in an open-loop policy,
  but to choose these variables sequentially given the information at time $t$ in a closed-loop policy,
  i.e. at period $t$ decision rules for $\{c_t,i_t,l_t,k_{t}\}$ given the information set at period $t$;
  at period $t+1$ decision rules for $\{c_{t+1},i_{t+1},l_{t+1},k_{t+1}\}$ given the information set at period $t+1$,
  and so on.
		
The first-order condition w.r.t. $c_t$ is given by
\begin{align*}
\frac{\partial \pounds^H}{\partial c_{t}} &= E_t \left(\gamma c_t^{-1}-\lambda_{t}\right) = 0
\\
\Leftrightarrow \lambda_{t} &= \gamma c_{t}^{-1} & (I)
\end{align*}
The first-order condition w.r.t. $l_t$ is given by
\begin{align*}
\frac{\partial \pounds^H}{\partial l_{t}} &= E_t \left(\frac{-\psi}{1-l_{t}} + \lambda_{t} w_{t}\right) = 0
\\
\Leftrightarrow \lambda_{t} w_{t} &= \frac{\psi}{1-l_{t}} &(II)
\end{align*}
The first-order condition w.r.t. $i_{t}$ is given by
\begin{align*}
\frac{\partial \pounds^H}{\partial i_{t}} &= E_t \left(-\lambda_{t} + \mu_{t}\right) = 0
\\
\Leftrightarrow \lambda_{t} &= \mu_{t} & (III)
\end{align*}
The first-order condition w.r.t. $k_{t}$ is given by
\begin{align*}
\frac{\partial \pounds^H}{\partial k_{t}} &= E_t (-\mu_{t}) + 
	E_t \beta \left(\lambda_{t+1} r_{k,t+1} + \mu_{t+1}(1-\delta)\right) = 0
\\
\Leftrightarrow \mu_{t} &= E_t \beta(\mu_{t+1}(1-\delta) + \lambda_{t+1} r_{k,t+1}) & (IV)
\end{align*}

(I) and (III) in (IV) yields
\begin{align*}
\underbrace{\gamma c_t^{-1}}_{U_{c,t}} &= \beta E_t \underbrace{\gamma c_{t+1}^{-1}}_{U_{c,t+1}}\left(1 - \delta + r_{k,t+1}\right)
\end{align*}
This is the Euler equation of \textbf{intertemporal optimality}. It reflects the trade-off between consumption and savings.
If the household saves a (marginal) unit of consumption, i.e. invest this into the capital stock,
  she can consume $(1-\delta+r_{k,t+1})$ units in the following period.
The marginal utility of consuming a unit today is equal to $U_{c,t}$,
  whereas consuming tomorrow has expected utility equal to $E_t(U_{c,t+1})$.
Discounting expected marginal utility with $\beta$, an optimum is characterized by a situation
  in which the household must be indifferent between both choices.

(I) in (II) yields:
\begin{align*}
w_t = -\frac{\frac{-\psi}{1-l_t}}{\gamma c_t^{-1}} \equiv - \frac{U_{l,t}}{U_{c,t}}
\end{align*}
This equation reflects \textbf{intratemporal optimality}; in other words, the labor supply function.
According to the equation, the real wage must be equal to the marginal rate of substitution between consumption and leisure.

\item First, note that even though firms maximize expected profits it is actually a static problem as there are no forward-looking terms.
That is, the objective is to maximize profits
\begin{align*}
{div}_t = a_t k_{d,t-1}^\alpha l_{d,t}^{1-\alpha} - w_t l_{d,t} - r_{k,t} k_{d,t-1}
\end{align*}
The first-order condition w.r.t. $l_{d,t}$ is given by
\begin{align*}
\frac{\partial {div}_t}{\partial l_{d,t}} &= (1-\alpha) a_t k_{d,t-1}^\alpha l_{d,t}^{-\alpha} - w_t = 0
\\
\Leftrightarrow w_t &= (1-\alpha) a_t k_{d,t-1}^\alpha l_{d,t}^{-\alpha} = f_l = (1-\alpha) \frac{y_t}{l_{d,t}}
\end{align*}
The real wage must be equal to the marginal product of labor.
Due to the Cobb-Douglas production function it is a constant proportion $(1-\alpha)$ of the ratio of total output to labor.
Simply put, this is the labor demand function.
				
The first-order condition w.r.t. $k_{d,t-1}$ is given by
\begin{align*}
\frac{\partial {div}_t}{\partial k_{d,t-1}} &= \alpha a_t k_{d,t-1}^{\alpha-1} l_{d,t}^{1-\alpha} - r_{k,t} = 0
\\
\Leftrightarrow r_{k,t} &= \alpha a_t k_{d,t-1}^{\alpha-1} l_{d,t}^{1-\alpha} = f_k = \alpha \frac{y_t}{k_{d,t-1}}
\end{align*}
The real rental rate for capital must be equal to the marginal product of capital.
Due to the Cobb-Douglas production function it is a constant proportion $\alpha$ of the ratio of total output to capital.
Simply put, this is the capital demand function.

\item Making use of clearing of labor and capital markets implies that the firms profits in the optimum are given by:
\begin{align*}
{div}_t &= y_t - w_t l_{t} - r_{k,t} k_{t-1} = y_t - (1-\alpha)y_t - \alpha y_t = 0
\\
\Leftrightarrow y_t &= w_t l_{t} + r_{k,t} k_{t-1}
\end{align*}
Insert into the budget restriction of the households yields:
\begin{align*}
c_t + i_t = w_t l_{t} + r_{k,t} k_{t-1} + {div}_t = y_t
\end{align*}
This is a manifestation of Walras law: if 2 out of 3 markets are cleared, the last market must clear as well.

\item First, consider the steady-state value of technology:
\begin{align*}
\log{a}&=\rho_a \log{a} + 0 \Leftrightarrow \log{a} = 0
\\
\Leftrightarrow a &= 1 
\end{align*}
The Euler equation in steady-state becomes:
\begin{align*}
U_c &= \beta U_c (1-\delta+r_k)
\\
\Leftrightarrow r_k &= \frac{1}{\beta} + \delta - 1
\end{align*}
Next we will provide recursively closed-form expressions for all variables in terms of steady-state labor.
That is the right-hand sides of the following equations are given in terms of parameters or previously computed expressions.
\begin{itemize}
	\item The firms demand for capital in steady-state becomes
	\begin{align*}
	r_k &= \alpha a k^{\alpha-1} l^{1-\alpha}
	\\
	\Leftrightarrow \frac{k}{l} &= \left(\frac{\alpha a}{r_k}\right)^{\frac{1}{1-\alpha}}
	\end{align*}
	\item The firms demand for labor in steady-state becomes:
	\begin{align*}
	w = (1-\alpha) A k^\alpha l^{-\alpha} = (1-\alpha)a \left(\frac{k}{l}\right)^\alpha
	\end{align*}
	\item The law of motion for capital in steady-state implies
	\begin{align*}
	\frac{i}{l} &= \delta\frac{k}{l}
	\end{align*}
	\item The production function in steady-state becomes
	\begin{align*}
	\frac{y}{l} = a \left(\frac{k}{l}\right)^\alpha
	\end{align*}
	\item The clearing of the goods market in steady-state implies 
	\begin{align*}
	\frac{c}{l} = \frac{y}{l} - \frac{i}{l}
	\end{align*}
\end{itemize}
Now, we have expressions for all variables as a ratio to steady-state labor.
Hence, once we compute $l$, we can revisit the above expressions to compute all values in closed-form.
Due to the log-utility function, we can actually derive a closed-form expression for $l$.
To this end, set labor demand equal to labor supply and express the right hand side in terms of previously computed expressions.
\begin{align*}
\psi \frac{1}{1-l} &= \gamma c^{-1} w
\\
\Leftrightarrow \psi \frac{l}{1-l} &= \gamma \left(\frac{c}{l}\right)^{-1} w
\\
\Leftrightarrow l &= (1-l)\frac{\gamma}{\psi} \left(\frac{c}{l}\right)^{-1} w
\\
\Leftrightarrow l &= \frac{\frac{\gamma}{\psi} \left(\frac{c}{l}\right)^{-1} w}{1+\frac{\gamma}{\psi} \left(\frac{c}{l}\right)^{-1} w}
\end{align*}
Lastly, it is straightforward to compute the remaining steady-state values, i.e.
\begin{align*}
c = \frac{c}{l} l,\qquad
i = \frac{i}{l}l ,\qquad
k = \frac{k}{l} l,\qquad	
y = \frac{y}{l} l
\end{align*}

\item The transversality condition for an infinite horizon dynamic optimization problem is the boundary condition
  determining a solution to the problem's first-order conditions together with the initial condition.
The transversality condition requires the present value of the state variables (here $k_t$ and $a_t$) to converge to zero as the planning horizon recedes towards infinity.
The first-order and transversality conditions are sufficient to identify an optimum in a concave optimization problem.
Given an optimal path, the necessity of the transversality condition reflects the impossibility of finding an alternative feasible path
  for which each state variable deviates from the optimum at each time and increases discounted utility.
These conditions are implicit only, we don't enter them in a computer program.
But implicitly we do consider them when we focus on unique and stable solutions or when we pick certain steady-state values.
	
\item General hints: construct and parameterize the model such, that it corresponds to certain properties of the true economy.
One often uses steady-state characteristics for choosing the parameters in accordance with observed data.
For instance, long-run averages (wages, hours worked, interest rates, inflation, consumption-shares, government-spending-ratios, etc.) are used 
  to target certain steady-state values of the endogenous variables, which implies certain values for some parameters.
You can also use micro-studies, however, one has to be careful about the aggregation.
			
We will focus on OECD countries and discuss one \enquote{possible} way to calibrate the model parameters (there are many other ways):
\begin{itemize}
\item[$\boldsymbol{\alpha}$] productivity parameter of capital.
Due to the Cobb Douglas production function thus should be equal to the proportion of capital income to total income of economy.
So, one looks inside the national accounts for OECD countries and sets $\alpha$ to 1 minus the share of labor income over total income.
For most OECD countries this implies a range of 0.25 to 0.40.
\item[$\boldsymbol{\beta}$] subjective intertemporal preference rate of households:
  it is the value of future utility in relation to present utility.
Usually this parameter takes a value slightly less than unity, indicating that agents discount the future.
For quarterly data, we typically set it around 0.99 and for yearly data 0.96.
These values imply a certain steady-state real rental rate.
To see this, re-consider the Euler equation in steady-state: $\beta = \frac{1}{\bar{r_k}+1-\delta}$ where $r_k= \alpha \frac{y}{k}$.
Looking at OECD data one usually finds that the average capital productivity $k/y$ is in the range of $9$ to $11$.
\item[$\boldsymbol{\delta}$] depreciation rate of capital stock.
For quarterly data the literature uses values in the range of 0.02 to 0.03, for yearly data you often find 0.10.
Again let's use a steady-state relationship to get a reasonable value.
That is, $\delta=\frac{\bar{I}}{\bar{K}}=\frac{\bar{I/Y}}{\bar{K/Y}}$.
For OECD data one usually finds an average ratio of investment to output, $\bar{I}/\bar{Y}$, around 0.25.
\item[$\boldsymbol{\gamma}$ and $\boldsymbol{\psi}$] households's preference regarding consumption and leisure.
Often a certain interpretation in terms of elasticities of substitutions is possible.
In the RBC mode, we can make use of the First-Order-Conditions in steady-state, i.e.
\begin{align*}
\frac{\psi}{\gamma} = \bar{W}\frac{(1-\bar{L})}{\bar{C}}= (1-\alpha)\left(\frac{\bar{K}}{\bar{L}}\right)^\alpha\frac{(1-\bar{L})}{\bar{C}} = (1-\alpha)\left(\frac{\bar{K}}{\bar{L}}\right)^\alpha\frac{\frac{1}{\bar{L}}(1-\bar{L})}{\frac{\bar{C}}{\bar{L}}}
\end{align*}
Note that $\bar{C}/\bar{L}$ as well as $\bar{K}/\bar{L}$ are given in terms of already calibrated parameters (see steady-state computations).
Therefore, one possible way is to normalize one of the parameters to unity (e.g. $\gamma=1$)
  and calibrate the other one in terms of steady-state ratios
  for which we would only require to set a value for steady-state hours worked $\bar{L}$.
In the specification of the utility function, we see that labor is normalized to be between 0 and 1.
So, targeting 8 hours a day implies $l=8/24=1/3$.
\item[$\boldsymbol{\rho_A}$ and $\boldsymbol{\sigma_A}$] parameters of process for total factor productivity.
These do not influence the steady-state values, but the dynamics of the model.
Often you can calibrate these by e.g. estimating the Cobb-Douglas production function with OLS and then compute the Solow residuals.
Then look at the persistence and standard error of the residuals.
Typically we find that $\rho_A$ is mostly set above 0.9 to reflect persistence of the technological process
  and $\sigma_A$ around $0.6$ in the simple RBC model.
\end{itemize}
\item The function might look like this:
\lstinputlisting[style=Matlab-editor,basicstyle=\mlttfamily]{progs/matlab/rbc_logutil_ss.m}
You can try it out with the following parametrization (same as in the Dynare mod file):
\lstinputlisting[style=Matlab-editor,basicstyle=\mlttfamily]{progs/matlab/rbc_logutil_ss_test.m}
\item The mod file might look like this:
\lstinputlisting[style=Matlab-editor,basicstyle=\mlttfamily]{progs/dynare/rbc_logutil.mod}
Obviously, the results are the same.
\item
\begin{enumerate}
	\item  For the first-order conditions of the household we know use
	\begin{align*}
	U_{c,t} &= \gamma c_t^{-\eta_c}
	\\
	U_{l,t} &= - \psi (1-l_t)^{-\eta_l}
	\end{align*}
	The steady-state for labor changes to
	\begin{align*}
	w \gamma \left(\frac{c}{l}\right)^{-\eta_c} &= \psi(1-l)^{-\eta_l}L^{\eta_c}
	\end{align*}
	This cannot be solved for $l$ in closed-form.
	Rather, we need to condition on the values of the parameters and use a numerical optimizer to solve for $l$.
	\item The function might look like this:
	\lstinputlisting[style=Matlab-editor,basicstyle=\mlttfamily]{progs/matlab/rbc_ss.m}
	You can try it out with the following parametrization (same as in the Dynare mod file):
	\lstinputlisting[style=Matlab-editor,basicstyle=\mlttfamily]{progs/matlab/rbc_ss_test.m}
	\item In Dynare we could use the following mod file:
	\lstinputlisting[style=Matlab-editor,basicstyle=\mlttfamily]{progs/dynare/rbc_ces.mod}
	and the following helper function:
	\lstinputlisting[style=Matlab-editor,basicstyle=\mlttfamily]{progs/dynare/rbc_ces_helper_function.m}
	Obviously, the results are the same.
\end{enumerate}		

\end{enumerate}