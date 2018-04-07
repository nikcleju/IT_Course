---
title: Hamming Codes. Part I - Encoding
subtitle: Information Theory Lab 9
documentclass: scrartcl
fontsize: 12pt
---

# Objective

Perform encoding of a data file with the Hamming (8,4) SECDED 
(Single Error Correction - Double Error Detection) code.

# Theoretical notions

## Encoding 

Hamming (8,4) SECDED encoding procedure operates on a block of 4
information bits (denoted as $i_3, i_5, i_6, i_7$) and produces
a block of 8 output bits:
$$\mathbf{c} = c_0c_1c_2i_3c_4i_5i_6i_7$$

The bits denoted with $c$ are parity bits (or *control* bits), and are
computed as follows:
$$
\begin{cases}
c_0 = i_3 \oplus i_5 \oplus i_6 = c_1 \oplus c_2 \oplus i_3 \oplus c_4 \oplus i_5 \oplus i_6 \oplus i_7\\
c_1 = i_3 \oplus i_5 \oplus i_7\\
c_2 = i_3 \oplus i_6 \oplus i_7\\
c_4 = i_5 \oplus i_6 \oplus i_7\\
\end{cases}
$$

The coding is done for every group of 4 bits in the data.

In the C language, modulo-2 sum is done by the bitwise `XOR` operation (`^`).

### Decoding

Considering the received 8-bit block
$$\mathbf{r} = r_0r_1r_2r_3r_4r_5r_6r_7,$$
decoding is done by computing the **syndrome**:
$$
\begin{cases}
z_0 &= r_0 \oplus r_1 \oplus r_2 \oplus r_3 \oplus r_4 \oplus r_5 \oplus r_6 \oplus r_7\\
z_1 &= c_4 \oplus i_5 \oplus i_6 \oplus i_7\\
z_2 &= c_2 \oplus i_3 \oplus i_6 \oplus i_7\\
z_3 &= c_1 \oplus i_3 \oplus i_5 \oplus i_7\\
\end{cases}
$$

The following cases may take place:

* $z_0 = z_1 = z_2 = z_3 = 0$: no error
* $z_0 = 1$: 1 error on position given by ${z_1z_2z_3}_{(10)}$
* $z_0 = 0$, other $z_i \neq 0$: 2 errors on unknown positions

# Exercises

1. Write a C program that performs encoding of a data file with the
Hamming (8,4) SECDED code.

    The program shall be called as follows:

    `HammingEncode.exe original.dat encoded.dat`
    
    * The arguments are:
        * `original.dat`: the original input file
        * `encoded.dat`: the encoded output file 
            
    * The program should consist of the following steps:
        * declare two large vectors of `unsigned char`, for input
        and output bits
        * open the input file and read everything into the input vector
        * for every group of 4 bits from the input vector:
            * compute the control bits $c_0$, $c_1$, $c_2$, $c_4$
            * write all the 8 bits in the correct order in the output
            vector
            * advance by 4 and repeat
        * write the output vector to the output data file

2. Run the program to produce the output file, for some input
file. What is the size of the output file compared to the input file?

## Program design

1. The bit operation macro definitions are available in `bitmacros.h`.

	For quick access to a bit number $i$ in a large array, use the
	following macros:
	
```
#define VECREAD_BIT(v,i) (READ_BIT((v[(i)/8]),(i)%8))
#define VECWRITE_BIT(v,i,val) (WRITE_BIT((v[(i)/8]),(i)%8, val))
```

# Final questions

1. TBD


