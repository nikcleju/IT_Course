---
title: Exercises Week 13
subtitle: Information Theory
documentclass: scrartcl
fontsize: 12pt
---

1. Find the systematic cyclic codeword for the sequence $\mathbf{i} = [1 0 1 0 0 0 1 1 0 0]$, 
considering a cyclic code with generator polynomial $g(x) = 1\oplus x \oplus x^3$.
    a. Do it "the mathematical way" (with polynomials)
    b. Do it "the programming way" (XOR-ing bit sequences)
    
\ 

2. We receive a sequence $\mathbf{r} = 101011100101$, which was encoded with
a cyclic code with generator polynomial $g(x) = 1\oplus x^2 \oplus x^3$.
Find if there are errors in the received data, and, if yes, perform correction and retrieve the 
transmitted information bits.
    a. Do it "the mathematical way" (with polynomials)
    b. Do it "the programming way" (XOR-ing bit sequences)

\ 

3. We do cyclic coding on information words of length $k = 8$ bits.
We want the coding rate $R$ to be at most $0.6$. What degree must the generator polynomial $g(x)$ have?

