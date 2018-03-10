#include <stdio.h>
#include <stdlib.h>

#include "encoding.h"
#include "bitmacros.h"

#include "huffman.h"

// Old-style codebooh, from huffman.c
extern Codeword codebook[256];

int main(int argc, char** argv) {
	
	printf("Generating codes...\n");

	// New-style codebook
	CODE32BIT newcodebook[256];
	
	//==================================
	// Generate ASCII-replacement code
	//==================================
	
	for (int i=0; i < 256; i++)
	{
		newcodebook[i].len = 8;
		
		// Code = the ASCII code of the next character
		int nextchar = i + 1;
		// 256 wraps back to 0
		if (nextchar == 256)
			nextchar = 0;
		
		for (int j = 0; j < 8; j++)
		{
			int bit = READ_BIT(nextchar,j);
			if (bit)
				SET_BIT(newcodebook[i].code, j);
			else
				CLEAR_BIT(newcodebook[i].code, j);
		}
		// Clear remaining bits
		for (int j = 8; j < 8*sizeof(newcodebook[i].code); j++)
			CLEAR_BIT(newcodebook[i].code, j);
	}
	
	// Save codebook to file
	FILE* f = fopen("testcode.dat", "wb");
	if (!f)
	{
		printf("Error at opening file %s\n", "testcode.dat");
		exit(1);
	}
	fwrite(newcodebook, sizeof(CODE32BIT), 256, f);
	fclose(f);
	//==================================



	//==================================
	// Generate Huffman code
	//==================================
	FILE* f1, *f2;
	int counters[256];
	float prob[256];
	unsigned char c;
	int cntall = 0;
	
	// Compute character probabilities
	f1 = fopen(argv[1],"rb");
	if (!f1)
		exit(1);
	
	for (int i=0; i < 256; i++)
		counters[i] = 0;
	
	while(fread(&c, 1, 1, f))
	{
		counters[c]++;
		cntall++;
	}
	
	for (int i=0; i < 256; i++)
		prob[i] = counters[i]/(float)cntall;

	// Do Huffman coding
	init_huffman_tree();			// init the vector
	//printf("Here 1\n");
	for (int i=0; i < 256; i++)		// set the probabilities of the characters
		set_prob(i, prob[i]);
	//printf("Here 2\n");
	make_huffman_tree();			// make the tree
	//printf("Here 3\n");
	make_codewords();				// find the codewords
	//printf("Here 4\n");
		
	// Show the codewords
	for (int i=0; i < 256; i++)
	{
		printf("%c\t count=%6d\t prob=%.6e\t code=", i, counters[i], prob[i]);	// Show the characer and its probability
		for (int j = 0; j < codebook[i].len; j++)	// then on the same line show all the codeword vector
			printf("%d", codebook[i].code[j]);
		printf("\n");								// Move to next line
	}
	
	// Convert old-style codewords to new-style codewords
	for (int i = 0; i < 256; i++)
	{
		newcodebook[i].len = codebook[i].len;
		
		for (int j = 0; j < codebook[i].len; j++)
		{
			if (codebook[i].code[j])
				SET_BIT(newcodebook[i].code, j);
			else
				CLEAR_BIT(newcodebook[i].code, j);
		}
	}
	
	// Show the new codewords, for checking
	for (int i=0; i < 256; i++)
	{
		printf("%c\t count=%6d\t prob=%.6e\t code=", i, counters[i], prob[i]);	// Show the characer and its probability
		for (int j = 0; j < codebook[i].len; j++)	// then on the same line show all the codeword vector
			printf("%d", READ_BIT(newcodebook[i].code, j) != 0);
		printf("\n");								// Move to next line
	}	
	
	// Save codebook to file
	f2 = fopen(argv[2], "wb");
	if (!f2)
	{
		printf("Error at opening file %s\n", "testcode.dat");
		exit(1);
	}
	fwrite(newcodebook, sizeof(CODE32BIT), 256, f2);
	fclose(f2);
	
	fclose(f1);


	
	printf("Bye!");
	return 0;
}
