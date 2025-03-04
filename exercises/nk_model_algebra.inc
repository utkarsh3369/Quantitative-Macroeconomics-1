\section[The Algebra of New Keynesian Models]{The Algebra of New Keynesian Models\label{ex:AlgebraNewKeynesianModels}}
Consider the basic New Keynesian (NK) model without capital, a linear production function and \textcite{Calvo_1983_StaggeredPricesUtilitymaximizing} price frictions.

\paragraph{Households} The economy is assumed to be inhabitated by a large number of identical households.
The representative household maximizes present as well as expected future utility
\begin{align*}
\max E_t \sum_{j=0}^{\infty} \beta^{j} U(c_{t+j}, l_{t+j}, z_{t+j})
\end{align*}
with $\beta <1$ denoting the discount factor and $E_t$ is the expectation operator conditional on information at time $t$.
The contemporaneous utility function 
\begin{align*}
U(c_t, l_t, z_t) = z_t \cdot \left( \frac{c_t^{1-\sigma}}{1-\sigma} - \frac{l_t^{1+\varphi}}{1+\varphi} \right)
\end{align*}
has three arguments: a consumption index $c_t$, a labor supply index $l_t$ which corresponds to either hours worked or employed household members,
  and an exogenous preference shifter $z_t$.
Note that the marginal utility of consumption is positive, whereas more labor reduces utility.
The inverse of $\sigma$ is the intertemporal elasticity of substitution,
  whereas the inverse of $\varphi$ is the Frisch elasticity of labor.
Note that the exogenous preference shifter $z_t$ influences only intertemporal decisions, but not intratemporal ones.
The consumption index is formed by aggregating a continuum of goods represented on the interval $h\in [0,1]$
  into a single consumption good using a \textcite{Dixit.Stiglitz_1977_MonopolisticCompetitionOptimum} aggregation technology:
\begin{align*}
	c_t = \left(\int_0^1 c_t(h)^{\frac{\epsilon-1}{\epsilon}} dh \right)^{\frac{\epsilon}{\epsilon-1}}
\end{align*}
That is, $c_t(h)$ denotes the quantity of good $h$ consumed by the household in period $t$.
$\epsilon>1$ is an elasticity parameter measuring the \emph{love-of-variety}.
The household decides how to allocate its consumption expenditures among the different goods by taking the price $P_t(h)$ of good $h$ as given
  and maximizing the consumption index $c_t$ for any given level of expenditures.
Similarly, in each period the household takes the nominal wage $W_t$ as given and supplies perfectly elastic labor service to the firm sector.
In return she receives nominal labor income $W_t l_t$ and, additionally,
  nominal profits and dividends $P_t \int_0^1 {div}_t(f)df$ from each firm $f\in[0,1]$ in the intermediate goods sector,
  because the firms are owned by the household.
Moreover, the household purchases a quantity of one-period nominally riskless bonds $B_t$ at price $Q_t$.
The bond matures the following period and pays one unit of money at maturity.
Income and wealth are used to finance consumption expenditures.
In total this defines the (nominal) budget constraint of the household
\begin{align*}
\int_0^1 P_t(h) c_t(h) dh + Q_t B_t \leq B_{t-1} + W_t l_t + P_t \int_0^1 div_t(f) df
\end{align*}
In addition, it is assumed that the household is subject to a solvency constraint that prevents it from engaging in Ponzi-type schemes:
\begin{align*}
\lim_{T \rightarrow \infty} E_t \left\{\Lambda_{t,T} \frac{B_T}{P_T}\right\} \geq 0
\end{align*}
for all periods $t$, where
\begin{align}
\Lambda_{t,T} = \beta^{T-t} \frac{\partial{U(c_{T},l_{T},z_T)}/\partial c_T}{\partial{U(c_{t},l_{t},z_T)}/\partial c_t} \label{eq:StochasticDiscountFactor}
\end{align}
denotes the stochastic discount factor.

Furthermore, let $\Pi_t=P_t/P_{t-1}$ denote the gross inflation rate,
  then the following relationships for the nominal interest rate $R_t$ and the real interest rate $r_t$ hold:
\begin{align}
Q_t &= \frac{1}{R_t} \label{eq:NominalInterestRate}
\\
R_t &= r_t E_t \Pi_{t+1} \label{eq:RealInterestRate}
\end{align}

\begin{enumerate}
\item Explain the economic intuition behind equation \eqref{eq:NominalInterestRate} that determines the nominal interest rate
  and equation \eqref{eq:RealInterestRate} that determines the real interest rate.

\item Is there debt in this model? In other words, what is the optimal path for $B_t$ in this model?

\item Explain the difference between the solvency constraint $\lim_{T \rightarrow \infty} E_t \left\{\Lambda_{t,T} \frac{B_T}{P_T}\right\} \geq 0$
  and the transversality condition $\lim_{T \rightarrow \infty} E_t \left\{\Lambda_{t,T} \frac{B_T}{P_T}\right\} = 0$ which holds in the optimum allocation.

\item Show that cost minimization of consumption expenditures implies
\begin{align*}
c_t(h) &= \left(\frac{P_t(h)}{P_t}\right)^{-\epsilon} c_t
\\
P_t &= \left(\int_0^1 P_t(h)^{1-\epsilon}dh\right)^{\frac{1}{1-\epsilon}}
\end{align*}
Interpret these equations. What does this imply for the budget constraint?

\item Derive the intratemporal and intertemporal optimality conditions:
\begin{align*}
w_t &:= \frac{W_t}{P_t} = - \frac{ \frac{\partial U(c_t,l_t,z_t)}{\partial l_t}}{ \frac{\partial U(c_t,l_t,z_t)}{\partial c_t}}
\\
\frac{\partial U(c_t,l_t,z_t)}{\partial c_t} &= \beta E_t \left[\frac{\partial U(c_{t+1},l_{t+1},z_{t+1})}{\partial c_{t+1}} r_t \right]
\end{align*}
where $w_t$ denotes the real wage and $\Pi_{t+1} = P_{t+1}/P_t$ the gross inflation rate. Interpret these equations.
\end{enumerate}

\paragraph{Firms: final good}
The economy is populated by a continuum of firms indexed by $f \in [0,1]$ that produce differentiated goods $y_t(f)$.
The technology for transforming these intermediate goods into the final output good $y_t$ has the \textcite{Dixit.Stiglitz_1977_MonopolisticCompetitionOptimum} form:
\begin{align}
y_t = \left[\int\limits_0^1 y_t(f)^{\frac{\epsilon-1}{\epsilon}}df\right]^{\frac{\epsilon}{\epsilon-1}} \label{eq:Firms_DS_Aggregator}
\end{align}
where $\epsilon>1$ is the substitution elasticity between inputs, the so-called \emph{love-of-variety}. 
\begin{enumerate}[resume]
\item Show that profit maximization in the final goods sector implies:
\begin{align*}
y_t(f) &= \left(\frac{P_t(f)}{P_t}\right)^{-\epsilon} y_t
\\
P_t &= \left[\int_{0}^{1} P_t(f)^{1-\epsilon}df\right]^{\frac{1}{1-\epsilon}}
\end{align*}
Interpret these equations. What does this imply for profits in the final goods sector?
\end{enumerate}

\paragraph{Firms: intermediate goods}
Intermediate firm $f$ uses the following linear production function to produce their differentiated good
\begin{align}
y_t(f) = a_t l_{d,t}(f) \label{eq:Firms_ProductionFunction}
\end{align}
where $a_t$ denotes the common technology level available to all firms.
Firms face perfectly competitive factor markets for hiring labor $l_{d,t}(f)$.
Real profits of firm $f$ are equal to revenues from selling its differentiated good at price $P_t(f)$ minus costs from hiring labor at wage $w_t$:
\begin{align}
{div}_t(f) = \frac{P_t(f)}{P_t} y_t(f) - w_t l_{d,t}(f) \label{eq:Firms.Profits}
\end{align}
The objective of the firm is to choose contingent plans for $P_t(f)$ and $l_{d,t}(f)$ so as to maximize the present discounted value of nominal dividend payments given by
\begin{align*}
E_t \sum_{j=0}^{\infty}\Lambda_{t,t+j} P_{t+j} div_{t+j}(f)
\end{align*}
where household's stochastic discount factor $\Lambda_{t,t+j}$ takes into account that firms are owned by the household.

Prices of intermediate goods are determined by nominal contracts as in \textcite{Calvo_1983_StaggeredPricesUtilitymaximizing} and \textcite{Yun_1996_NominalPriceRigidity}.
In each period firm $f$ faces a constant probability $1-\theta, 0\leq \theta \leq 1$, of being able to re-optimize the price $P_t(f)$ of its good $y_t(f)$.
The probability is independent of the time it last reset its price.
Formally:
\begin{align}
P_t(f) = \begin{cases}
\widetilde{P}_t(f) & \text{with probability } 1-\theta\\
P_{t-1}(f) & \text{with probability } \theta
\end{cases}
\label{eq:NewKeynesianCalvoMechanism}
\end{align}
where $\widetilde{P}_t(f)$ is the re-optimized price in period $t$.
Accordingly, when a firm cannot re-set its price for $j$ periods, its price in period $t+j$ is given by $\widetilde{P}_t(f)$
  and stays there until the firm can optimize it again.
Hence, the firm's objective in $t$ is to set $\widetilde{P}_t(f)$ to maximize expected profits
  until it can re-optimize the price again in some future period $t+j$.
The probability to be stuck at the same price for $j$ periods is given by $\theta^j$. 

\begin{enumerate}[resume]
\item Derive the following expression for the stochastic discount factor:
\begin{align*}
\Lambda_{t,t+1+j} = \beta \frac{\lambda_{t+1}}{\lambda_t} \Pi_{t+1}^{-1} \Lambda_{t+1,t+1+j}
\end{align*}

\item Show that the optimal labor demand schedule of intermediate good firm $f$ is given by:
\begin{align*}
w_t = mc_t(f) a_t = mc_t(f) \frac{y_t(f)}{l_{d,t}(f)}
\end{align*}
where $mc_t(f)$ are real marginal costs of firm $f$.
What does this imply for aggregate real marginal costs $mc_t=\int_0^1 mc_t(f)df$?

\item Denote $\widetilde{p}_t := \frac{\widetilde{P}_t(f)}{P_t}$ and show that optimal price setting of intermediate firms must satisfy:
\begin{align*}
\widetilde{p}_t \cdot s_{1,t} &= \frac{\epsilon}{\epsilon-1} \cdot s_{2,t} \\
s_{1,t}&=y_t \frac{\partial U(c_t,n^s_t,z_t)}{\partial c_t} + \beta \theta E_t \Pi_{t+1}^{\epsilon-1}s_{1,t+1} \\
s_{2,t}&= mc_t y_{t} \frac{\partial U(c_t,n^s_t,z_t)}{\partial c_t} + \beta \theta E_t \Pi_{t+1}^{\epsilon} s_{2,t+1}
\end{align*}
Explain why firms that reset prices set the same price, i.e. $\widetilde{P}_t(f) =\widetilde{P}_t$ or in other words we can drop the $f$.

\item Show that the law of motion for the optimal re-set price $\widetilde{p}_t = \frac{\widetilde{P}_t(f)}{P_t}$ is given by:
\begin{align*}
1&=\theta \Pi_{t}^{\epsilon-1}+\left(1-\theta\right) \widetilde{p}_t^{1-\epsilon}
\end{align*}

\end{enumerate}

\paragraph{Monetary Policy}
The central bank adjusts the nominal interest rate $R_t$ according to an interest rate rule in response to deviations of (i) gross inflation $\Pi_t$ from a target $\Pi^*$ and (ii) output $y_t$ from steady-state output $y$:
\begin{align}
    R_t = R \left(\frac{\pi_t}{\pi^*}\right)^{\phi_\pi} \left(\frac{y_t}{y}\right)^{\phi_y} e^{\nu_t} \label{eq:NewKeynesianMonetaryPolicyRule}
\end{align}
where $R$ denotes the nominal interest rate in steady state, $\phi_\pi$ the sensitivity parameter to inflation deviations, $\phi_y$ the feedback parameter of the output gap and $\nu_t$ an exogenous deviation to the rule.


\paragraph{Exogenous variables and stochastic shocks}
The exogenous preference shifter $z_t$, the level of technology $a_t$ and the exogenous deviations  $\nu_t$ from the monetary rule evolve according to
\begin{align}
    \log{z_t} &= \rho_z \log{z_{t-1}} + \varepsilon_{z,t} \label{eq:NewKeynesianLoMPreferenceShifter}\\
    \log{a_t} &= \rho_a \log{a_{t-1}} + \varepsilon_{a,t} \label{eq:NewKeynesianLoMTechnology}\\
    \nu_t &= \rho_\nu \nu_{t-1} + \varepsilon_{\nu,t} \label{eq:NewKeynesianLoMMonPol}
\end{align}
with persistence parameters $\rho_z$, $\rho_a$ and $\rho_\nu$. The preference shock $\varepsilon_{z,t}$, the productivity shock $\varepsilon_{a,t}$ and the monetary policy shock $\varepsilon_{\nu,t}$ are iid Gaussian:
\begin{align*}
    \begin{pmatrix}
        \varepsilon_{z,t}\\\varepsilon_{a,t}\\\varepsilon_{\nu,t}
    \end{pmatrix}
    \sim N\left(\begin{pmatrix} 0\\0\\0\end{pmatrix}, \begin{pmatrix} \sigma_z^2 & 0& 0\\0 & \sigma_{a}^2& 0\\0 & 0 & \sigma_{\nu}^2\end{pmatrix}\right)
\end{align*}

\paragraph{Market clearing}
\begin{enumerate}[resume]
	\item What does market clearing imply for private bonds $B_t$?
	\item Explain why labor market clearing implies:
	\begin{align*}
		l_t = \int_0^1 l_{d,t}(f) df
	\end{align*}
	\item Show that aggregate real profits of the intermediate firms are given by
	\begin{align*}
	div_t \equiv \int_{0}^{1} div_t(f) df = y_t - w_t l_t
	\end{align*}
	\item Show that aggregate demand is given by
	\begin{align}
	y_t = c_t
	\end{align}
	\item Denote $p_t^* = \int_{0}^1 \left(\frac{P_t(f)}{P_t}\right)^{-\epsilon} df$.
	Show that aggregate supply is given by
	\begin{align*}
	p_t^* y_t = a_t l_t
	\end{align*}
	Explain why $p_t^*$ is called the price efficiency distortion.
	\item Derive the law of motion for the price efficiency distortion $p_t^*$:
	\begin{align}
	p_{t}^*=\left(1-\theta\right) \widetilde{p}_t^{-\epsilon}+\theta \pi_{t}^{\epsilon} p_{t-1}^*
	\end{align}
\end{enumerate}

\paragraph{Readings}
\begin{itemize}
	\item \textcite[Ch.~3]{Gali_2015_MonetaryPolicyInflation}
	\item \textcite[Ch.~19]{Heijdra_2017_FoundationsModernMacroeconomics}
	\item \textcite[Ch.~7]{Romer_2019_AdvancedMacroeconomics}
	\item \textcite[Ch.~3]{Woodford_2003_InterestPricesFoundations}	
	\item \textcite[Ch.~8]{Walsh_2017_MonetaryTheoryPolicy}
\end{itemize}

\begin{solution}\textbf{Solution to \nameref{ex:AlgebraNewKeynesianModels}}
\ifDisplaySolutions
\input{exercises/nk_model_algebra_solution.inc}
\fi
\newpage
\end{solution}