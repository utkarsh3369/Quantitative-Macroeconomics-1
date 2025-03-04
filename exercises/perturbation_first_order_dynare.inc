\section[Solving rational expectations models at first order: what Dynare does]{Solving rational expectations models at first order: what Dynare does\label{ex:PerturbationDynareFirstOrder}}
\begin{enumerate}
 	\item Outline the general DSGE model framework used by Dynare. Particularly, distinguish the different types of endogenous and exogenous variables and comment on the information set underlying the model framework.
 	\item Why is it difficult to find the policy function? What is the underlying intuition behind the perturbation approach?
 	\item Do a first-order Taylor expansion around the non-stochastic steady-state of the policy function. What are the knowns, what are the unknowns?
 	\item Do a first-order Taylor expansion around the non-stochastic steady-state of the dynamic model equations using the implicit function theorem. Take the conditional expectation and set it to zero. Which equations define (implictly) which coefficient matrices of the approximated policy function?
 	\item Recover the first-order partial derivative of the policy function with respect to the state variables. To this end:
	 \begin{itemize}
		 \item Comment on the underlying computational problem.
		 \item Derive the structural state-space representation (at first-order) and discuss why we cannot simply invert the system. 
		 \item Take the Schur decomposition of the matrix pencil of the structural state-space representation and re-order the decomposition such that generalized eigenvalues (with modulus less than 1) are in the upper left corner of the left-hand matrices of the Schur decomposition.
		 \item Focus on the lower part of the system that contains the explosive Eigenvalues. We want to exclude solutions that contain expolisive behavior. Show that using this idea one can derive the first-order coefficients of the policy function with respect to the states.
		 \item What are the Blanchard and Khan (1980) order and rank conditions?
	 \end{itemize} 
	\item Recover the first-order partial derivative of the policy function with respect to the exogenous variables. How does the computational problem differ from the derivatives with respect to the state variables?
	\item Recover the first-order partial derivative of the policy function with respect to the perturbation parameter. Show that this is always a vector of zeros. Why is this property called \emph{certainty equivalence}?
	\item Derive the unconditional first two moments of the model variables from the first-order approximated system.
 	\item Illustrate the numerical approach and algorithm for the Basic New Keynesian Model of the previous exercise.
\end{enumerate}

\begin{solution}\textbf{Solution to \nameref{ex:PerturbationDynareFirstOrder}}
\ifDisplaySolutions
\input{exercises/perturbation_first_order_dynare_solution.inc}
\fi
\newpage
\end{solution}