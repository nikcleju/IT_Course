---
title: IT Sample Exam

fontsize: 11pt
geometry: margin=2.5cm

# TODO: make a dedicated template!
---

\vspace{-2cm}

# Exercises (15p)

1. A discrete, complete and memoryless source has the following distribution: 
$$S: \begin{pmatrix}
	s_1 & s_2 & s_3 & s_4 & s_5 & s_6\\
	\frac{1}{4} & \frac{1}{4} & \frac{1}{8} & \frac{1}{8} & \frac{1}{16} & \frac{3}{16}
	\end{pmatrix}$$

    a. (1p) Compute the entropy of the source;
    b. (3p) Encode it with Huffman coding and write the resulting codewords.

1. (2p) Suppose we encode the source from Exercise 1 with the code below. Compute the efficiency and redundancy of this code.
  
    Message                       Code
------------------------- -------------------
        $s_1$                     00     
        $s_2$                     011    
        $s_3$                     010     
        $s_4$                     101     
        $s_5$                     100
        $s_6$                     11
        
	

3. At the input of a binary symmetric channel with the following channel matrix
	$$P(y_j | x_i) = 
	\begin{bmatrix}
	\frac{2}{3} & \frac{1}{3} \\
	\frac{1}{3} & \frac{2}{3} \\
	\end{bmatrix}$$
	we apply two inputs $x_1$ and $x_2$ with probabilities $p(x_1) = \frac{3}{4}$ and $p(x_2) = \frac{1}{4}$.
    a. (1p) Draw the graph of the channel;
    b. (1p) Compute the joint probability matrix $P(X,Y)$;
    c. (2p) Compute the mutual information $I(X,Y)$ on this channel.

2. (2p) Design a block code consisting of 4 codewords which is able to detect 2 errors in a codeword. 
Justify that it is able to detect 2 errors.

1. (3p) Consider a systematic code with parity-check matrix 
	$$[H] = 
	\begin{bmatrix}
	1 & 1 & 1 & 0 & 1 & 0 & 0 \\
	1 & 1 & 0 & 1 & 0 & 1 & 0 \\
	0 & 1 & 1 & 1 & 0 & 0 & 1 \\
	\end{bmatrix}$$

    We receive the sequence $\mathbf{r} = [0 1 0 0 0 1 0]$. 
    Find if there are errors in the received data, and, if yes, perform correction and find the 
	transmitted information bits.

  
### Theory questions (15p)

1. (4p) Prove that the entropy of any second-order extension, $H(S^2)$, is $2$ times larger than $H(S)$:
	$$H(S^2) = 2 \cdot H(S)$$

2. (2p) Consider two different joint probability matrices $P_A(X,Y)$ and $P_B(X,Y)$.
Which one do you think is better for a communication process? Justify (in words).

$$P_A(X,Y) = \begin{bmatrix}
    0.8 & 0 \\
    0 & 0.2 \\
\end{bmatrix}
\;\;\;\;
P_B(X,Y) = \begin{bmatrix}
    0.6 & 0.2 \\
    0.1 & 0.1 \\
\end{bmatrix}$$
  
3. (1p) Give an example of a channel matrix $P(Y|X)$ for a channel with zero mean error $H(Y|X) = 0$.
  
4. (4p) State and prove the Kraft inequality theorem
  
5. (2p) The family of Hamming codes contains many possible Hamming codes. What are the next two Hamming codes in the following sequence? Justify the answers.

        Hamming(7,4), Hamming(15,11), Hamming(?,?), Hamming(?,?), ...

6. (2p) Consider the following block code:
    a. Is it a linear code?
    b. Is it a systematic code? Justify your answers.

  Information word $i$       Codeword $c$  
------------------------- -------------------
        00                     00110     
        01                     11111     
        10                     00011     
        11                     11001  

## Notes

- You start with 3p ("punctul din oficiu"). 
- Grade = total points / 3 (e.g. 30p = grade 10, 15p = grade 5 etc).
- Time available: 2h
