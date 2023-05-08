---
title: Exercises Week 13
subtitle: Information Theory
documentclass: scrartcl
fontsize: 12pt
---

\newcommand{\sII}[3] {#1: \left( \begin{matrix} s_1 & s_2 \\ #2 & #3 \end{matrix} \right)}
\newcommand{\sIII}[4] {#1: \left( \begin{matrix} s_1 & s_2 & s_3 \\ #2 & #3 & #4 \end{matrix} \right)}
\newcommand{\sV}[6] {#1: \left( \begin{matrix} s_1 & s_2 & s_3 & s_4 & s_5 \\ #2 & #3 & #4 & #5 & #6 \end{matrix} \right)}
\newcommand{\sVI}[7] {#1: \left( \begin{matrix} s_1 & s_2 & s_3 & s_4 & s_5 & s_6 \\ #2 & #3 & #4 & #5 & #6 & #7 \end{matrix} \right)}
\newcommand{\sVIII}[9] {#1: \left( \begin{matrix} s_1 & s_2 & s_3 & s_4 & s_5 & s_6 & s_7 & s_8 \\ #2 & #3 & #4 & #5 & #6 & #7 & #8 & #9  \end{matrix} \right)}


	
1. Consider a communication process defined by the following **joint probability matrix**:
$$P(x_i \cap y_j) = 
\begin{bmatrix}
\frac{1}{2} & 0 & 0 \\
0 & \frac{1}{4} & \frac{1}{4} \\
\end{bmatrix}$$

	a. compute the marginal probabilities and the marginal entropies $H(X)$ and $H(Y)$;
	b. Find the channel matrix $P(Y|X)$ and draw the graph of the channel;
	c. compute the mutual information $I(X,Y)$, and draw the geometrical representation.
	
3. At the input of a binary symmetric channel with the following channel matrix
$$P(y_j | x_i) = 
\begin{bmatrix}
\frac{2}{3} & \frac{1}{3} \\
\frac{1}{3} & \frac{2}{3} \\
\end{bmatrix}$$
we apply two inputs $x_1$ and $x_2$ with probabilities $p(x_1) = \frac{3}{4}$ and $p(x_2) = \frac{1}{4}$.
    a. Draw the graph of the channel
    b. Find $H(X)$, $H(Y)$ and $I(X,Y)$
    c. Compute the uncertainty remaining over the input $X$ when output symbol $y_2$ is received
    c. Compute the channel capacity, the redundancy and the efficiency of the channel.
	
2. Consider a communication process with 2 inputs and 3 outputs. The inputs and output events have equal probabilities, and are independent. 

    a. Write the joint probability matrix
    b. draw the graph of the channel (together with the probabilities)
    c. Compute the marginal entropies and the joint entropy, and verify that
$$H(X,Y) = H(X) + H(Y)$$
and that
$$I(X,Y) = 0$$

3. Give an example of a channel having 3 inputs and 3 outputs, with $H(Y|X) = 0$ (write the channel matrix).

3. Give an example of a channel with two inputs, such that $H(Y|x_1) \neq 0$ and $H(Y|x_2) = 0$ (write the channel matrix).


