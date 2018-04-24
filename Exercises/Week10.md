---
title: Exercises Week 9
subtitle: Information Theory
documentclass: scrartcl
fontsize: 12pt
---

1. For the following code, compute the minimum Hamming distance and indicate
how many errors it can detect and how many errors it can correct, with 
the nearest neighbor decoding algorithm.
    a. Give an example of errors the code cannot detect, and another
    example of errors it can detect but it cannot correct, using
    the nearest neighbor decoding algorithm.


 Message      Codeword
---------   -------------------
$s_1$           $c_1$ = 00000
$s_2$           $c_2$ = 10011
$s_3$           $c_3$ = 11100
$s_3$           $c_4$ = 00111

2. Design a block code consisting of 4 codewords, with minimum codeword length,
which is able to detect 3 errors in a codeword.

2. Design a block code consisting of 4 codewords, with minimum codeword length,
which is able to correct 2 errors in a codeword.

1. Prove the following property of Hamming distance:
    $$d_H(\mathbf{a}, \mathbf{b}) + d_H(\mathbf{b}, \mathbf{c}) \geq d_H(\mathbf{a}, \mathbf{c}),$$
    where $\mathbf{a}, \mathbf{b}, \mathbf{c}$ are sequences of $N$ bits.
