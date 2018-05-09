---
title: Exercises Week 12
subtitle: Information Theory
documentclass: scrartcl
fontsize: 12pt
---

1. Consider a systematic code with generator matrix
$$[G] = 
\begin{bmatrix}
1 & 0 & 0 & 0 & 1 & 1 & 0 \\
0 & 1 & 0 & 0 & 1 & 1 & 1 \\
0 & 0 & 1 & 0 & 1 & 0 & 1 \\
0 & 0 & 0 & 1 & 0 & 1 & 1 \\
\end{bmatrix}$$

    a. Compute the parity-check matrix $[H]$;
    b. Find out how many errors this code can detect, and how many it can correct.
    
2. Compute the codewords for transmitting the information words
 $\mathbf{i_1} = [1 0 0 1]$ with the Hamming (7,4) code, and $\mathbf{i_2} = [1 1 1 0]$
  with the Hamming (8,4) SECDED code.

3. We receive a sequence $\mathbf{r} = 1010111$, which was encoded with
the Hamming (7,4) code. Find if there are errors in the
received data, and, if yes, perform correction and retrieve the 
transmitted information bits.

3. We receive a sequence $\mathbf{r} = 10101010$, which was encoded with
the Hamming (8,4) SECDED code. Find if there are errors in the
received data, and, if yes, perform correction and retrieve the 
transmitted information bits.

4. Give an example of errors which the Hamming (15, 11) is not able to detect.
Give another example of errors which the Hamming (15, 11) is able to detect, but is not able to correct.
