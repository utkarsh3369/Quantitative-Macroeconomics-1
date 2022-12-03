[![Build LaTeX exercises as PDF](https://github.com/wmutschl/Quantitative-Macroeconomics/actions/workflows/latex-exercises.yml/badge.svg)](https://github.com/wmutschl/Quantitative-Macroeconomics/actions/workflows/latex-exercises.yml)

# Quantitative Macroeconomics

These are my course materials for the graduate course on Quantitative Macroeconomics taught at the University of Tübingen.
The compiled materials (such as PDFs) are available under [Releases](https://github.com/wmutschl/Quantitative-Macroeconomics/releases).

## Content

We cover modern theoretical macroeconomics (the study of aggregated variables such as economic growth, unemployment and inflation by means of structural macroeconomic models) and combine it with econometric methods (the application of formal statistical methods in empirical economics). We focus on the quantitative aspects and methods for solving and estimating the most prominent model classes in macroeconomics: Structural Vector Autoregressive (SVAR) and Dynamic Stochastic General Equilibrium (DSGE) models. Using these two model strands, the theoretical and methodological foundations of quantitative macroeconomics is taught. The students are thus enabled to understand the analyses and forecasts of public (universities, central banks, economic research institutes) as well as private (business banks, political consultations) research departments, but also to derive and empirically evaluate their own structural macroeconomic models.

As Quantitative Macroeconomics is highly computational, the course is interactive and *hands-on*, so there is no formal separation between the lecture and the exercise class. Each topic begins with a theoretical input and presentation of methods. These concepts are practiced directly thereafter by means of exercises and implemented on the computer in MATLAB and Dynare.

## Learning target

Students acquire knowledge of advanced methods of quantitative research in the field of modern macroeconomics. This knowledge is relevant for the realization of a wide variety of macroeconomic research projects and is applied in central banks, ministries, research institutes (e.g. DIW, ifo, IfW, IWH, RWI) and research departments of international organizations (e.g. IMF, World Bank). Upon successful completion of this module, students are prepared to work in these areas. At the same time, the module prepares students for the requirements of a quantitatively oriented macroeconomic dissertation.

The gained methodological skills enable a precise understanding and largely independent empirical analysis of the most important model classes in quantitative macroeconomics. Students are familiar with a variety of examples and situations in which quantitative thinking is useful in explaining abstract macroeconomic phenomena. They recognize and appreciate the connections between theory and evidence and use their training to find possible avenues of research. While constructing abstract models, they identify appropriate economic and statistical tools and evaluate their strengths and weaknesses in the context of problem solving. They utilize computers and software effectively as tools for solving and estimating macroeconomic models. In addition, because students work on the problem sets as a team, students' coordination, organization, and communication skills are enhanced.

## Requirements

Basic undergraduate knowledge of macroeconomics as well as econometrics are required, programming skills in a scripting language are advantageous, but not necessary.

## Software used

* [MATLAB](https://mathworks.com) or [Octave](https://octave.org)
* [Dynare](https://www.dynare.org)

## Week 1: Introductions

### Goals

* understand what Quantitative Macroeconomics is about
* decide whether you want to take the course
* prepare your computer for the course with MATLAB and GitKraken
* do your first steps in MATLAB and GitKraken

### To Do

* [ ] read the general course information
* [ ] prepare the [exercises for week 1](https://github.com/wmutschl/Quantitative-Macroeconomics/releases/latest/download/week_1.pdf); we will do them together in class
* [ ] prepare your computer
  * [ ] install MATLAB R2022b following [this guide](https://uni-tuebingen.de/einrichtungen/zentrum-fuer-datenverarbeitung/dienstleistungen/clientdienste/software/matlab-einzelplatzlizenz/) if you are a student of the University of Tübingen
  * [ ] create an account on [GitHub.com](https://github.com/signup)
  * [ ] install the [GitKraken Client](https://gitkraken.com/download)
  * [ ] sign up for the [GitHub Students Developer Pack](https://education.github.com/pack) to get a free Pro license for GitKraken (among other things)
* [ ] write down all your questions
* [ ] [schedule an online meeting](https://schedule.mutschler.eu) with me
  * [ ] put *"I am interested in this course"* under *"What is the meeting about?"*
  * [ ] check your emails and cancel the meeting again using the link in the email
  * [ ] now you know how easy it is to schedule a meeting with me :-)
* [ ] participate in the Q&A sessions

## Week 2: Time series data and fundamental concepts

### Goals

* learn how to obtain macroeconomic data from different sources
* learn how to visualize macroeconomic time series data and do some basic descriptive statistics with MATLAB
* learn about different frequencies and what they can be useful for
* understand the concept of a white noise process
* get intuition about stationarity, autocovariance function, lag-operator, conditional and unconditional moments
* simulate white noise processes and moving-averages in MATLAB

### To Do

* [ ] review the solutions of [last week's exercises](https://github.com/wmutschl/Quantitative-Macroeconomics/releases/latest/download/week_1.pdf) and write down all your questions
* [ ] Read Bjørnland and Thorsrud (2015, Ch.1 and Ch.2) and Lütkepohl (2004). Make note of all the aspects and concepts that you are not familiar with or that you find difficult to understand.
* [ ] TRY (!!!) to do exercise sheet 2
* [ ] participate in the Q&A sessions with all your questions and concerns
* [ ] for immediate help: [schedule a meeting](https://schedule.mutschler.eu)
* [ ] (optionally) checkout the short [Beginner Git Video Tutorials from GitKraken](https://www.gitkraken.com/learn/git/tutorials#beginner)

## Week 3: Dependent time series data and the autoregressive process

### Goals

* understand the concept of an AR(1) and AR(p) process
* get intuition about the law of large numbers and the central limit theorem
* visualize the law of large numbers and the central limit theorem for dependent data using Monte Carlo simulations

### To Do

* [ ] review the solutions of [last week's exercises](https://github.com/wmutschl/Quantitative-Macroeconomics/releases/latest/download/week_2.pdf) and write down all your questions
* [ ] Read Lütkepohl (2004), Lütkepohl (2005, Appendix C) and Bjørnland and Thorsrud (2015, Ch.1 and Ch.2). Make note of all the aspects and concepts that you are not familiar with or that you find difficult to understand.
* [ ] TRY (!!!) to do exercise sheet 3
* [ ] participate in the Q&A sessions with all your questions and concerns
* [ ] for immediate help: [schedule a meeting](https://schedule.mutschler.eu)
* [ ] (optionally) checkout the short [Intermediate Git Video Tutorials from GitKraken](https://www.gitkraken.com/learn/git/tutorials#intermediate)

## Week 4: Ordinary Least Squares (OLS) and Maximum Likelihood (ML) estimation of the autoregressive process

### Goals

* review OLS and ML for the AR(p) process
* implement OLS and ML estimation of the AR(p) process

### To Do

* [ ] review the solutions of [last week's exercises](https://github.com/wmutschl/Quantitative-Macroeconomics/releases/latest/download/week_3.pdf) and write down all your questions
* [ ] Read Lütkepohl (2004). Make note of all the aspects and concepts that you are not familiar with or that you find difficult to understand.
* [ ] TRY (!!!) to do exercise sheet 4
* [ ] participate in the Q&A sessions with all your questions and concerns
* [ ] for immediate help: [schedule a meeting](https://schedule.mutschler.eu)
* [ ] (optionally) checkout the short [Advanced Git Video Tutorials from GitKraken](https://www.gitkraken.com/learn/git/tutorials#advanced)

## Week 5: Information Criteria, Specification Tests, and Bootstrap

### Goals

* understand the intuition of information criteria, specification tests and bootstrap
* implement simple examples for information criteria, specification tests and bootstrap for the univariate AR(p) process

### To Do

* [ ] review the solutions of [last week's exercises](https://github.com/wmutschl/Quantitative-Macroeconomics/releases/latest/download/week_4.pdf) and write down all your questions
* [ ] Read Lütkepohl (2004) and Kilian and Lütkepohl (2007, Ch. 12). Make note of all the aspects and concepts that you are not familiar with or that you find difficult to understand.
* [ ] TRY (!!!) to do exercise sheet 5
* [ ] participate in the Q&A sessions with all your questions and concerns
* [ ] for immediate help: [schedule a meeting](https://schedule.mutschler.eu)
* [ ] (optionally) fork the course repository on GitHub

## Week 6: Multivariate Time Series Concepts

### Goals

Familiarize yourself with

* important matrix concepts such as Eigenvalues, Kronecker product, orthogonality, rotation matrices, Cholesky decomposition and Lyapunov equations
* multivariate notation and dimensions of vectors and matrices for VAR(p) models
* autocovariances, stability and covariance-stationarity in multivariate VAR(p) models
* the companion form

### To Do

* [ ] Review the solutions of [last week's exercises](https://github.com/wmutschl/Quantitative-Macroeconomics/releases/latest/download/week_5.pdf) (except the bootstrap one) and write down all your questions
* [ ] Read Kilian and Lütkepohl (2007, Ch. 2.2) and Lütkepohl (2005, Chapter 2 and Appendix A). Make note of all the aspects and concepts that you are not familiar with or that you find difficult to understand.
* [ ] Do exercise sheet 6 (the solutions are already available)
* [ ] If you have questions, get in touch with me via email or (better) [schedule a meeting](https://schedule.mutschler.eu)

## Week 7: Estimating VAR models with OLS and ML

### Goals

* estimate VAR models with Ordinary Least Squares (OLS) and Maximum Likelihood (ML)
* understand multivariate lag-order selection criteria

### To Do

* [ ] Review the solutions of [last week's exercises](https://github.com/wmutschl/Quantitative-Macroeconomics/releases/latest/download/week_6.pdf) and write down all your questions
* [ ] Read Kilian and Lütkepohl (2007, Ch. 2.3 and Ch. 2.6). Make note of all the aspects and concepts that you are not familiar with or that you find difficult to understand.
* [ ] Do exercise sheet 7
* [ ] If you have questions, get in touch with me via email or (better) [schedule a meeting](https://schedule.mutschler.eu)


## Week 8: Identification Problem in Structural Vector Autoregressive (SVAR) Models and Recursive Solution

### Goals

* understand the identification problem in SVAR models 
* understand recursive identification
* implement recursive identification both via Cholesky or numerical optimization

### To Do

* [ ] Review the solutions of [last week's exercises](https://github.com/wmutschl/Quantitative-Macroeconomics/releases/latest/download/week_7.pdf) and write down all your questions
* [ ] Read Kilian and Lütkepohl (2007, Ch. 4.1, Ch. 7.6, Ch.8, Ch.9). Make note of all the aspects and concepts that you are not familiar with or that you find difficult to understand.
* [ ] Do exercise sheet 8
* [ ] If you have questions, get in touch with me via email or (better) [schedule a meeting](https://schedule.mutschler.eu)