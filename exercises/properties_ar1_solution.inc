\begin{enumerate}

\item Let's first get a representation of the process that is useful to compute the moments.
We can do this in different ways:
    \begin{itemize}

    \item \textbf{Recursive substitution} (starting at some infinite time $j$):	
    \begin{align*}
    y_t &= \phi y_{t-1} + \varepsilon_t\\
        &= \phi \left( \phi y_{t-2} + \varepsilon_{t-1}\right) + \varepsilon_t\\ 
        &= \phi^2(\phi y_{t-3} + \varepsilon_{t-2} ) + \phi \varepsilon_{t-1} + \varepsilon_t\\
        &\vdots\\
        & = \phi^{j+1} y_{t-{j+1}}+\phi^j \varepsilon_{t-j}+...+\phi^2 \varepsilon_{t-2} + \phi \varepsilon_{t-1} + \varepsilon_t
    \end{align*}
    $y_t$ is a linear function of an initial value $\phi^{j+1} y_{t-{j+1}}$
      and historical values of the white noise process $\varepsilon_t$.
    If $|\phi|<1$ and $j$ becomes large,
      then $ \phi^{j+1} y_{t-{j+1}} \rightarrow 0$,
      thus we get a so-called $MA(\infty)$ process:
    $$y_t = \varepsilon_t + \phi \varepsilon_{t-1} + \phi^2 \varepsilon_{t-2}+... = \sum_{j=0}^\infty \phi^j \varepsilon_{t-j}$$

    \item \textbf{With Lag Operators}: works only if $|\phi| < 1$ and $\{y_t\}$ is bounded,
    that is, there exists a finite number $k$ such that $|y_t| < k$ for all t. Then
    \begin{align*}
    (1-\phi L) y_t = \varepsilon_t\\
    (1-\phi L)^{-1}(1-\phi L) y_t =	y_t = (1-\phi L)^{-1}\varepsilon_t\\
    \end{align*}
    We can use the geometric rule: $(1-\phi L)^{-1} = \lim\limits_{j\rightarrow \infty}(1+\phi L + \phi^2 L^2+...+(\phi L)^j)$
    Therefore:
    \begin{align*}
    y_t = (1+\phi L + \phi^2 L^2+...+(\phi L)^j)\varepsilon_t 
        = \varepsilon_t + \phi \varepsilon_{t-1} + \phi^2 \varepsilon_{t-2}+...
        = \sum_{j=0}^\infty \phi^j \varepsilon_{t-j}
    \end{align*}
    \end{itemize}
    If we can express an AR process as a MA process, we call this process invertible.
    Let's now compute the moments from the MA($\infty$) representation
      and using the fact that $\varepsilon_t$ is a white noise process:
    \begin{itemize}
        \item \textbf{Unconditional Moments:}
        \begin{align*}
            E[y_t] &= \mu = 0\\
            Var[y_t] &= \gamma_0 = \frac{\sigma^2}{1-\phi^2} \\
            Cov[y_t,y_{t-k}] &= \gamma_k = \phi^k \gamma_0 \text{ for } k>0
        \end{align*}
        \item \textbf{Conditional Moments:}
        \begin{itemize}
            \item conditional on $y_{t-1}$:
            \begin{align*}
            E[y_t|y_{t-1}] &= \phi y_{t-1}\\
            Var[y_t|y_{t-1}] &= \sigma^2\\
            Cov[y_t,y_{t-j}|y_{t-k-1}] &= 0 \text{ for } k>0
            \end{align*}
            \item conditional on $y_{t-2}$:
            \begin{align*}
            E[y_t|y_{t-2}] &= \phi^2 y_{t-2}\\
            Var[y_t|y_{t-2}] &= (1+\phi^2)\sigma^2\\
            Cov[y_t,y_{t-1}|y_{t-2}] &= \phi\sigma^2\\
            Cov[y_t,y_{t-k}|y_{t-2}] &= 0 \text{ for } k>1
            \end{align*}
        \end{itemize} 
    \end{itemize}
	 	
\item \lstinputlisting[style=Matlab-editor,basicstyle=\mlttfamily]{progs/matlab/ACFPlots.m}
\end{enumerate}