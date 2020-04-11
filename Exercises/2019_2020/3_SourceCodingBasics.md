---
title: Source Coding Basics
subtitle: Information Theory
documentclass: scrartcl
fontsize: 12pt
---

\newcommand{\sIV}[5] {#1: \left( \begin{matrix} s_1 & s_2 & s_3 & s_4 \\ #2 & #3 & #4  & #5 \end{matrix} \right)}


1. Consider the binary codes below:

     Message     Code A		   Code B		  Code C	  Code D	  Code E	  Code F
    ---------   --------     -----------	----------	----------	----------	----------
      $s_1$        $00$			$0$			  $0$		  $0$		  $0$		  $0$
      $s_2$        $01$			$10$		  $01$		  $100$		  $110$		  $10$
      $s_3$        $10$			$110$		  $011$		  $11$		  $10$		  $11$
      $s_4$        $11$			$1110$		  $0111$	  $110$		  $111$		  $110$
    
    For each code:
    
    a. Verify the Kraft inequality
    b. Determine if the code is instantaneous / uniquely decodable
    c. Draw the graph


2. Consider a memoryless source with the following distribution:
$$\sIV{S}{\frac{1}{2}}{\frac{1}{4}}{\frac{1}{8}}{\frac{1}{8}}$$
	For this source we use two separate codes:

	  Message      Code A	   Code B
	-----------  ----------  ----------
	  $s_1$        $00$			$0$
	  $s_2$        $01$			$10$
	  $s_3$        $10$			$110$
	  $s_4$        $11$			$111$
	
	Requirements:
	a. Compute the average lengths of the two codes
	b. Compute the efficienty and redundancy of the two codes
	c. Encode the sequence $s_2s_4s_3s_3s_1$ with each code
	d. Decode the sequence `0110101010101111000010101` with each code

1. Fill in the missing bits (marked with ?) such that the resulting code is instantaneous.

	  Message       Codeword
	----------- -------------------
		$s_1$       ??
		$s_2$       1??
		$s_3$       11?
		$s_4$       0?
		$s_5$       ??

	(just replace the '?'; do not add additional bits)
    
