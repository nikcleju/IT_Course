---
title: Discrete Memoryless Sources
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

1. Consider the following game: I think of a number between 1 and 8, and you have to guess it by asking
yes/no questions.
    * How much uncertainty does the problem have?
    * How is the best way to ask questions? Why?
    * What if the questions are not asked in the best way?
    * On average, what is the number of questions required to find the number?

2. Guess the number: what is the optimal decision tree for guessing a number chosen according to the following distribution:
$$\sIV{S}{\fIoII}{\fIoIV}{\fIoVIII}{\fIoVIII}$$

3. Guess the number: what is the optimal decision tree for guessing a number chosen according to the following distribution:
$$\sIV{S}{0.14}{0.29}{0.4}{0.17}$$

4. A DMS has the following distribution
$$\sV{S}{\frac{1}{2}}{0}{\frac{1}{8}}{\frac{1}{4}}{\frac{1}{8}}$$
    a. Compute the information of message $s_1$, $s_2$ and $s_3$
    b. Compute the average information of a message
    c. Compute the efficiency, absolute redundancy and relative redundancy of the source

5. Compute the KL distance between the following two probability distributions:

	$$P = [0 0 0 1]$$
	
	$$Q = [0.1 0.05 0.05 0.8]$$
