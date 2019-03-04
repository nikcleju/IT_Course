---
title: Exercises Week 3
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

1. Consider a communication process defined by the following **joint probability matrix**:
$$P(x_i \cap y_j) = 
\begin{bmatrix}
\frac{1}{2} & 0 & 0 \\
0 & \frac{1}{4} & \frac{1}{4} \\
\end{bmatrix}$$

	a. compute the marginal probabilities and the marginal entropies $H(X)$ and $H(Y)$
	b. what is the uncertainty of the output when the input symbol is $x_2$?
	c. draw the graph of the channel (together with the probabilities)
	c. compute the joint entropy $H(X,Y)$ and the mean error $H(Y|X)$
	
2. Consider a communication process with 2 inputs and 3 outputs. The inputs and output events have equal probabilities, and are independent. 

    a. Write the joint probability matrix
    b. draw the graph of the channel (together with the probabilities)
    c. Compute the marginal entropies and the joint entropy, and verify that
$$H(X,Y) = H(X) + H(Y)$$

3. Give an example of a channel having 3 inputs and 3 outputs, with $H(Y|X) = 0$ (write the channel matrix).

3. Give an example of a channel with two inputs, such that $H(Y|x_1) \neq 0$ and $H(Y|x_2) = 0$ (write the channel matrix).
