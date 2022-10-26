\begin{enumerate}
\item \begin{align*}
        y_t &= c + d\cdot t + \phi y_{t-1} + u_t\\
        \Leftrightarrow y_t &= \frac{c + d\cdot t + u_t}{1-\phi L}\\
        \Leftrightarrow y_t &= \sum_{j=0}^{\infty}\phi^j(c+d(t-j)+u_{t-j}) = \frac{c}{1-\phi} + \frac{dt}{1-\phi} - d\sum_{j=0}^{\infty}\phi^j j + \sum_{j=0}^{\infty}\phi^j u_{t-j}
    \end{align*}
    as $|\phi| <1$ the geometric series holds.
    For $\sum_{j=0}^{k} \phi^j j$ we also have a closed-form formula,
      which can be derived similar to the geometric series:
    \begin{eqnarray*}
        \text{Denote } S_{k}  
        &=&	\sum_{j=0}^{k} \phi^j j = \sum_{j=1}^{k} \phi^j j
        =	\phi^1 \cdot 1 + \phi^2 \cdot 2+ \phi^3 \cdot 3 + \dots +  	
        \phi^k \cdot k, \\
        \text{then } \phi S_{k} 
        &=& \phi^2 \cdot 1 + \phi^3 \cdot 2+ \phi^4 \cdot 3 + \dots +  	
        \phi^{k+1} \cdot k \\
        \text{and we get } (1 - \phi) S_{k}
        &=& \phi^1 \cdot 1+ \phi^2 \cdot 1 + \phi^3 \cdot 1 + \dots + \phi^{k} \cdot 1 - \phi^{k+1} \cdot k \\
        S_{k}	&=& \frac{1}{1 - \phi} \sum_{j = 1}^{k} \phi^j - \frac{\phi^{k+1}}{1 - \phi} k.
    \end{eqnarray*} 
    Looking at the limit of $S_{k}$ for $k \to \infty$, we get
    $\lim\limits_{k \to \infty} S_{k} = \frac{\phi}{(1 - \phi)^2}$. \\
    Therefore, $y_{t}$ is given by
    \begin{displaymath}
    y_{t} = \frac{c}{1-\phi} + \frac{dt}{1-\phi} - d \frac{\phi}{(1 - \phi)^2}  + \sum_{j=0}^{\infty} \phi^j u_{t-j}.
    \end{displaymath} 
    Unconditional mean:
    \begin{eqnarray*}
        E[y_{t}] &=& \frac{c}{1-\phi} + \frac{dt}{1-\phi} - d \frac{\phi}{(1 - \phi)^2}  + \underbrace{\sum_{j=0}^{\infty} \phi^j E[u_{t-j}]}_{=0 \text{, as } \space  u_{t} \sim iid(0, \sigma^2)} \\
        &=& \frac{c}{1-\phi} + \frac{dt}{1-\phi} - d \frac{\phi}{(1 - \phi)^2}
    \end{eqnarray*}	
    Unconditional variance:
    \begin{eqnarray*}
    Var[y_{t}] 
    &=& E[(y_{t} - E[y_{t}])^2 ] \\
    &=& E[(\sum_{j=0}^{\infty} \phi^j E[u_{t-j}]) \cdot (\sum_{j=0}^{\infty} \phi^j E[u_{t-j}])] \\
    &=& E[(u_{t} + \phi^1 u_{t-1} + \phi^2 u_{t-2} + \dots)(u_{t} + \phi^1 u_{t-1} + \phi^2 u_{t-2} + \dots)] \\
    &=& E[	u_{t}^2 + 2\phi^1 u_{t}u_{t-1} + 2\phi^2 u_{t}u_{t-2} + \dots + 
    \phi^2 u_{t-1}^2 + 2\phi^3 u_{t-1}u_{t-2} + 2\phi^4 u_{t-1}u_{t-3} + \dots  \\
    &&+ \phi^4 u_{t-2}^2 + 2\phi^5 u_{t-2}u_{t-3} + 2\phi^5 u_{t-2}u_{t-4} + \dots ] \\
    &\overset{iid}{=}& E [ u_{t}^2+ \phi^2 u_{t-1}^2 + \phi^4 u_{t-2}^2 + \dots ] \\
    \end{eqnarray*}
    $\text{with } Var[u_{t}] = E[u_{t}^2] - E[u_{t}]^2 = E[u_{t}^2] = \sigma^2 \text{ we get}$
    \begin{displaymath}
    Var[y_{t}] = \sigma^2 ( \phi^0 + \phi^2 + \phi^4 + \dots )] = \frac{\sigma^2}{1-\phi^2}.
    \end{displaymath}

    Autocovariance:
    \begin{eqnarray*}
        \gamma(k)
        &=& E[(y_{t}-E[y_{t}])(y_{t-k}-E[y_{t-k}])] \\
        &=& E[(\sum_{j=0}^{\infty} \phi^j 
        u_{t-j})(\sum_{j=0}^{\infty} \phi^j u_{t-j-k})] \\
        &=& E[(u_{t} + \phi^1 u_{t-1} + \phi^2 u_{t-2} + \dots + 
        \phi^k u_{t-k}  + \phi^{k+1} u_{t-k-1} + \phi^{k+2} u_{t-k-2} + \dots) \\
        && 	(u_{t-k}  + \phi^{1} u_{t-k-1} + \phi^{2} u_{t-k-2} + \dots)] \\
        &=& E[u_{t}u_{t-k} + \phi^1 u_{t} u_{t-k-1} + \phi^2 u_{t} 
        u_{t-k-3} + \dots   \\
        &&	\phi^1 u_{t-1}u_{t-k} + \phi^2 u_{t-1}u_{t-k-1}	+ \phi^3 
        u_{t-1}u_{t-k-2} + \dots \\
        && 	\phi^2 u_{t-2}u_{t-k} + \phi^3 u_{t-2}u_{t-k-1}	+ 
        \phi^4 u_{t-2}u_{t-k-2} + \dots \\
        &&	\vdots \\
        &&  \phi^{k} u_{t-k}^2 + 2\phi^{k+1} u_{t-k}u_{t-k-1}	+ 	
        2\phi^{k+2} u_{t-k}u_{t-k-2} + \dots \\
        && 	\phi^{k+2} u_{t-k-1}^2 + 2\phi^{k+3} u_{t-k-1}u_{t-k-2} +
        2\phi^{k+4} u_{t-k-1}u_{t-k-3} + \dots \\ 
        && 	\phi^{k+4} u_{t-k-2}^2 + 2\phi^{k+5} u_{t-k-2}u_{t-k-3} +
        2\phi^{k+6} u_{t-k-2}u_{t-k-4} + \dots] \\
        &\overset{iid}{=}& 
        E[\phi^{k}u_{t-k}^2 + \phi^{k+2}u_{t-k-1}^2 + \phi^{k+4}u_{t-k-2}^2 + \dots] \\
        &=& \phi^{k}\sigma^2(\phi^0 + \phi^2 + \phi^4 + \dots ) \\
        &=& \frac{\phi^{k}\sigma^2}{1-\phi^2}
    \end{eqnarray*}

	Autocorrelation: $\rho(k)  = \frac{\gamma(k)}{\gamma(0)}$. Therefore:
    \begin{displaymath}
    \rho(k) = \frac{\gamma(k)}{\gamma(0)} = \frac{\frac{\phi^{k}\sigma^2}{1-\phi^2}}{\frac{\sigma^2}{1-\phi^2}} = \phi^{k}.
    \end{displaymath} 
\item The expectation is time-dependent, hence it is not stationary.
One could subtract the expectation, e.g. look at $y_{t}^{s} = y_{t} -E[y_t]$,
  where $y_t^s$ is now covariance stationary.
  The unknown coefficient $d$ must be estimated first though.
\end{enumerate}