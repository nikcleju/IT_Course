---
title: Exercises Week 11
subtitle: Information Theory
documentclass: scrartcl
fontsize: 12pt
---

1. Consider a code with generator matrix
$$[G] = 
\begin{bmatrix}
1 & 1 & 0 & 0 & 0 & 1 & 0 \\
0 & 1 & 0 & 0 & 1 & 1 & 1 \\
1 & 1 & 1 & 0 & 1 & 0 & 1 \\
0 & 0 & 1 & 1 & 0 & 1 & 1 \\
\end{bmatrix}$$

    a. Compute the codewords $\mathbf{c_1}$ and $\mathbf{c_2}$ 
    for transmitting the information words
    $\mathbf{i_1} = [1 0 0 1]$ and $\mathbf{i_2} = [1 1 1 0]$
    b. Compute $\mathbf{c_3} = \mathbf{c_1} \oplus \mathbf{c_2}$. 
    Is this a codeword? If yes, what is its corresponding information word $\mathbf{i_3}$?

2. Alice builds codewords $\mathbf{c'}$ in the following way: it computes the
codeword $\mathbf{c}$ with $[G]$ from Exercise 1, and then it
writes all the bits $\mathbf{c}$ in the opposite order.

    a. Is this also a linear block code?
    b. If yes, what is its generator matrix? If no, why?
    c. Similar question: Bob doesn't reverse $\mathbf{c}$, but instead it 
    always removes the third bit from $\mathbf{c}$. Repeat the two questions.
    
1. Consider a systematic code with generator matrix
$$[G] = 
\begin{bmatrix}
1 & 0 & 0 & 0 & 1 & 1 & 0 \\
0 & 1 & 0 & 0 & 1 & 1 & 1 \\
0 & 0 & 1 & 0 & 1 & 0 & 1 \\
0 & 0 & 0 & 1 & 0 & 1 & 1 \\
\end{bmatrix}$$

    a. Compute the codewords $\mathbf{c_1}$ and $\mathbf{c_2}$ 
    for transmitting the information words
    $\mathbf{i_1} = [0 1 0 0]$ and $\mathbf{i_2} = [1 0 1 1]$
    b. Compute the parity-check matrix $[H]$ and check that 
    $\mathbf{0} = [H] \cdot \mathbf{c_1}^T$ and $\mathbf{0} = [H] \cdot \mathbf{c_2}^T$.
    
1. Consider a systematic code with parity-check matrix 
$$[H] = 
\begin{bmatrix}
1 & 1 & 1 & 0 & 1 & 0 & 0 \\
1 & 1 & 0 & 1 & 0 & 1 & 0 \\
0 & 1 & 1 & 1 & 0 & 0 & 1 \\
\end{bmatrix}$$

    We receive two sequences $\mathbf{r_1} = [0 1 0 1 1 0 0]$ and
    $\mathbf{r_2} = [1 1 0 1 1 0 0]$. Find if there are errors in the
    received data, and, if yes, perform correction and retrieve the 
	transmitted information bits.
    
