---
title: Sources With Memory
subtitle: Information Theory Exercises
documentclass: scrartcl
fontsize: 12pt
---

\newcommand{\snII}[5]{#1: \left( \begin{matrix} {#2} & {#4} \\ #3 & #5 \end{matrix} \right)}
\newcommand{\snIV}[9]{#1: \left( \begin{matrix} {#2} & {#4} & {#6} & {#8} \\ #3 & #5 & #7 & #9 \end{matrix} \right)}
\newcommand{\sII}[3] {#1: \left( \begin{matrix} s_1 & s_2 \\ #2 & #3 \end{matrix} \right)}
\newcommand{\sIII}[4] {#1: \left( \begin{matrix} s_1 & s_2 & s_3 \\ #2 & #3 & #4 \end{matrix} \right)}
\newcommand{\sIV}[5] {#1: \left( \begin{matrix} s_1 & s_2 & s_3 & s_4 \\ #2 & #3 & #4  & #5 \end{matrix} \right)}
\newcommand{\sV}[6] {#1: \left( \begin{matrix} s_1 & s_2 & s_3 & s_4 & s_5 \\ #2 & #3 & #4  & #5 & #6 \end{matrix} \right)}
\newcommand{\sVI}[7] {#1: \left( \begin{matrix} s_1 & s_2 & s_3 & s_4 & s_5 & s_6 \\ #2 & #3 & #4 & #5 & #6 & #7\end{matrix} \right)}
\newcommand{\sVIII}[9] {#1: \left( \begin{matrix} s_1 & s_2 & s_3 & s_4 & s_5 & s_6 & s_7 & s_8\\ #2 & #3 & #4 & #5 & #6 & #7 & #8 & #9 \end{matrix} \right)}
\newcommand{\fIoII}{\frac{1}{2}}
\newcommand{\fIoIII}{\frac{1}{3}}
\newcommand{\fIoIV}{\frac{1}{4}}
\newcommand{\fIoV}{\frac{1}{5}}
\newcommand{\fIoVI}{\frac{1}{6}}
\newcommand{\fIoVII}{\frac{1}{7}}
\newcommand{\fIoVIII}{\frac{1}{8}}

1. Consider a discrete source with memory, with the graphical representation given below.
The states are defined as follows: $S_1: s_1s_1$, $S_2: s_1s_2$, $S_3: s_2s_1$, $S_4: s_2s_2$.

	![Graphical representation of the source](img/MemorySource3.png){.id width=35%}

    a. What are the values of $x$ and $y$?
    b. Write the transition matrix $[T]$;
	c. What is the probability of generating $s_1 $ if the current state is $S_3$?
	c. If the initial state is $S_4$, what is the probability of generating the sequence $s_1 s_2 s_2 s_1$?
    c. Compute the entropy in state $S_4$;
    d. Compute the global entropy of the source;
    e. What are the memory order, $m$, and the number of messages of the source, $n$?
    f. If the source is initially in state $S_2$, in what states and with what probabilities 
    will the source be after 2 messages?
    