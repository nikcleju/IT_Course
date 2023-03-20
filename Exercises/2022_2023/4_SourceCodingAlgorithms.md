---
title: Source Coding Algorithms
subtitle: Information Theory Exercises
documentclass: scrartcl
fontsize: 12pt
---

\newcommand{\sII}[3] {#1: \left( \begin{matrix} s_1 & s_2 \\ #2 & #3 \end{matrix} \right)}
\newcommand{\sIII}[4] {#1: \left( \begin{matrix} s_1 & s_2 & s_3 \\ #2 & #3 & #4 \end{matrix} \right)}
\newcommand{\sV}[6] {#1: \left( \begin{matrix} s_1 & s_2 & s_3 & s_4 & s_5 \\ #2 & #3 & #4 & #5 & #6 \end{matrix} \right)}
\newcommand{\sVI}[7] {#1: \left( \begin{matrix} s_1 & s_2 & s_3 & s_4 & s_5 & s_6 \\ #2 & #3 & #4 & #5 & #6 & #7 \end{matrix} \right)}
\newcommand{\sVIII}[9] {#1: \left( \begin{matrix} s_1 & s_2 & s_3 & s_4 & s_5 & s_6 & s_7 & s_8 \\ #2 & #3 & #4 & #5 & #6 & #7 & #8 & #9  \end{matrix} \right)}


1. We perform Shannon coding on an information source with $H(S) = 20$b.
    a. What are the possible values for the efficiency of the code?
    b. What are the possible values for the redundancy of the code?
    c. What is the minimum number of messages the source may possibly have?



1. A discrete memoryless source has the following distribution:

    $$\sV{S}{0.05}{0.4}{0.1}{0.25}{0.2}$$
    
    a. Encode the source with Shannon, Shannon-Fano coding and Huffman
    coding and compute the average length in every case.
    b. Find the efficiency and redundancy of the Huffman code
    c. Compute the probabilities of the symbols $0$ and $1$, for the Huffman code

1. For the following source, perform Huffman coding and obtain three 
different codes with same average length, but different individual codeword length.

    $$\sVI{S}{0.05}{0.05}{0.15}{0.25}{0.25}{0.25}$$
    
    a. Compute the average length in all three cases and show it is the same
    
1. A discrete memoryless source has the following distribution:

    $$\sIII{S}{0.1}{0.7}{0.2}$$
    
    a. Find the average code length obtained with Huffman coding on the
    original source and on its second order extension.
    
    b. Encode the sequence $s_7 s_7 s_3 s_7 s_7 s_7 s_1 s_3 s_7 s_7$
    with both codes.

1. A discrete memoryless source has the following distribution

	$$\sVIII{S}{0.4}{0.3}{0.2}{0.04}{0.03}{0.02}{0.009}{0.001}$$
	
	Find the Huffman code for a code with 4 symbols,
	$x_1$, $x_2$, $x_3$ and $x_4$, and encode the sequence
	
	$$s_1 s_7 s_8 s_3 s_3 s_1$$

