---
title: Exercises Week 8
subtitle: Information Theory
documentclass: scrartcl
fontsize: 12pt
---

\newcommand{\sII}[3] {#1: \left( \begin{matrix} s_1 & s_2 \\ #2 & #3 \end{matrix} \right)}
\newcommand{\sV}[6] {#1: \left( \begin{matrix} s_1 & s_2 & s_3 & s_4 & s_5 \\ #2 & #3 & #4 & #5 & #6 \end{matrix} \right)}


1. Find a Shannon code for the following information source

    $$\sV{S}{\frac{1}{2}}{\frac{1}{10}}{\frac{3}{10}}{\frac{1}{10}}{\frac{1}{10}}$$

    a. Draw the graph of the code
    a. Compute the efficiency and the redundancy of the code

1. Find a Shannon code for the following information source

    $$\sII{S}{0.95}{0.05}$$

    a. Find the average codeword length, the efficiency and the redundancy of the code
    a. Can you optimize the code? How?
    b. What is the efficiency and redundancy of your optimized code? Is it a big improvement?
	
2. Find a distribution such that the following code is optimal:

	  Message      Code A	
	-----------  ---------- 
	  $s_1$        $0$		
	  $s_2$        $101$		
	  $s_3$        $100$		
	  $s_4$        $11$		

3. We perform Shannon coding on an information source with $H(S) = 20$b.
    a. What are the possible values for the efficiency of the code?
    b. What are the possible values for the redundancy of the code?
    c. What is the minimum number of messages the source may possibly have?


    
