---
title: Exercises Week 5
subtitle: Information Theory
documentclass: scrartcl
fontsize: 12pt
---

1. For the following channels, compute the channel capacity and the input probabilities required to reach it:

    a. Noiseless binary channel
    b. Noisy binary non-overlapping channel
    c. "Noisy typewriter"
    d. Binary symmetric channel
    e. Binary erasure channel
    f. Symmetric channel of order $n$

2. Consider a discrete transmission channel with the following channel matrix:
$$P(Y | X) = 
\begin{bmatrix}
\frac{1}{2} & 0 & \frac{1}{2} & 0 & 0 & 0 \\
0 & 0 & 0 & \frac{1}{3} & 0 & \frac{2}{3} \\
0 & \frac{1}{6} & 0 & 0 & \frac{5}{6} & 0 \\
\end{bmatrix}$$
    
    a. Draw the graph of the channel, and compute the equivocation $H(X|Y)$;
    b. If $p(x_1) = \frac{1}{2}$, $p(x_2) = \frac{1}{4}$ and $p(x_3) = \frac{1}{4}$,
    compute the average information transmitted on the channel $I(X,Y)$;
    c. Compute the redundancy and the efficiency of the channel.
    
3. Two binary channels are connected in series, as in the picture below:

	[see on whiteboard]
	
	a. Find $q$ such that the equivalent channel is a binary symmetric channel;
	b. *Not done: Find the channel capacity of the equivalent channel from a).*


4. *Not done: A logical AND gate with two inputs can be considered a transmission channel, 
with four input symbols $x_1 = 00$, $x_2 = 01$, $x_3 = 10$, $x_4 = 11$, 
and two output symbols $y_1 = 0$, $y_2 = 1$.*
    
    a. *If $p(x_1) = p(x_2) = p(x_3) = p(x_4) = \frac{1}{4}$, find the average
    information transmitted on this channel;*
    b. *Find the channel capacity and the probabilities of the inputs 
    required to reach it.*


    
