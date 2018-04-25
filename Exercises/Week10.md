---
title: Exercises Week 10
subtitle: Information Theory
documentclass: scrartcl
fontsize: 12pt
---

1. For the following code, do the following:
    a. compute the minimum Hamming distance and indicate
    how many errors it can detect and how many errors it can correct, with 
    the nearest neighbor decoding algorithm;
    a. considering two received codewords, $\mathbf{r_1} = 11100$ and 
    $\mathbf{r_2} = 00011$, perform decoding and say if there are errors,
    and if so then correct the errors (find the correct codeword and 
    indicate where the errors are located);
    a. Give an example of errors the code cannot detect, and another
    example of errors it can detect but it cannot correct, using
    the nearest neighbor decoding algorithm.


 Message      Codeword
---------   -------------------
$s_1$           $c_1$ = 00000
$s_2$           $c_2$ = 10011
$s_3$           $c_3$ = 11100
$s_4$           $c_4$ = 00111

2. Design a block code consisting of 4 codewords, with minimum codeword length,
which is able to detect 3 errors in a codeword.

2. Design a block code consisting of 4 codewords, with minimum codeword length,
which is able to correct 2 errors in a codeword.

2. If we send one codeword of the previous code from exercise 2 over a Binary
Symmetric Channel with error probability $p = 0.1\%$, what is the probability
that nearest neighbor error detection algorithms fails?
    
    *Hint*: compute the probability that we get a number of errors more than
    the code can handle (4, 5 or 6 errors).
