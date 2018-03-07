---
title: Exercises Week 4
subtitle: Information Theory
documentclass: scrartcl
fontsize: 12pt
---

\newcommand{\snII}[5]{#1: \left( \begin{matrix} {#2} & {#4} \\ #3 & #5 \end{matrix} \right)}
\newcommand{\snIV}[9]{#1: \left( \begin{matrix} {#2} & {#4} & {#6} & {#8} \\ #3 & #5 & #7 & #9 \end{matrix} \right)}
\newcommand{\sII}[3] {#1: \left( \begin{matrix} s_1 & s_2 \\ #2 & #3 \end{matrix} \right)}
\newcommand{\sIII}[4] {#1: \left( \begin{matrix} s_1 & s_2 & s_3 \\ #2 & #3 & #4 \end{matrix} \right)}
\newcommand{\sIV}[5] {#1: \left( \begin{matrix} s_1 & s_2 & s_3 & s_4 \\ #2 & #3 & #4  & #5 \end{matrix} \right)}
\newcommand{\sV}[6] {#1: \left( \begin{matrix} s_1 & s_2 & s_3 & s_4 & s_5 \\ #2 & #3 & #4  & #5 & #6 \end{matrix} \right)}
\newcommand{\sVI}[7] {#1: \left( \begin{matrix} s_1 & s_2 & s_3 & s_4 & s_5 & s_6 \\ #2 & #3 & #4 & #5 & #6 & #7\end{matrix} \right)}
\newcommand{\sVIII}[9] {#1: \left( \begin{matrix} s_1 & s_2 & s_3 & s_4 & s_5 & s_6 & s_7 & s_8\\ #2 & #3 & #4 & #5 & #6 & #7 & #8 & #9 \end{matrix} \right)}
\newcommand{\fIoII}{\frac{1}{2}}
\newcommand{\fIoIII}{\frac{1}{3}}
\newcommand{\fIoIV}{\frac{1}{4}}
\newcommand{\fIoV}{\frac{1}{5}}
\newcommand{\fIoVI}{\frac{1}{6}}
\newcommand{\fIoVII}{\frac{1}{7}}
\newcommand{\fIoVIII}{\frac{1}{8}}

1. For the first two exercises of last week, also compute the equivocation $H(X|Y)$, 
the mutual information $I(X,Y)$, and draw the geometrical representation.

2. A communication process has the following joint probability matrix:
$$P(x_i \cap y_j) = 
\begin{bmatrix}
\frac{1}{2} & \frac{1}{4} \\
\frac{1}{8} & \frac{1}{8} \\
\end{bmatrix}$$

    a. Find the noise matrix $P(Y|X)$ and the channel matrix P(X|Y)
    b. Compute the average information obtained on the input $X$ when output symbol $y_2$ is received
    c. Compute the uncertainty remaining over the input $X$ when output symbol $y_2$ is received
  
3. At the input of a binary symmetric channel with the following channel matrix
$$P(y_j | x_i) = 
\begin{bmatrix}
\frac{2}{3} & \frac{1}{3} \\
\frac{1}{3} & \frac{2}{3} \\
\end{bmatrix}$$
we apply two inputs $x_1$ and $x_2$ with probabilities $p(x_1) = \frac{3}{4}$ and $p(x_2) = \frac{1}{4}$.
    a. Draw the graph of the channel
    b. Find $H(X)$, $H(Y)$ and $I(X,Y)$

4. Find the mutual information for a channel defined by
$$P(y_j | x_i) = 
\begin{bmatrix}
\frac{1}{2} & 0 & \frac{1}{2} & 0 & 0 & 0 \\
0 & 0 & 0 & \frac{1}{3} & 0 & \frac{2}{3} \\
0 & \frac{1}{6} & 0 & 0 & \frac{5}{6} & 0 \\
\end{bmatrix}$$
    if the input probabilities are $p(x_1) = \frac{1}{2}$, $p(x_2) = \frac{1}{4}$ and $p(x_3) = \frac{1}{4}$.
