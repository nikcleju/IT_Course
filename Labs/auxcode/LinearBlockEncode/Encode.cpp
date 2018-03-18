#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "encoding.h"
#include "bitmacros.h"


int main(int argc, char** argv) {
	
	// New-style codebook
	CODE32BIT codebook[256];

	FILE* f;

	unsigned char bitvector[1000000];
	unsigned char c;
	int n = 0;

	// Read code from code file
	f = fopen(argv[1],"rb");
	if (!f) 
	{
	  printf("Code file cannot be opened...\n");
	  exit(1);
	}
	fread(codebook, sizeof(CODE32BIT), 256, f);
	fclose(f);

	// Process input file
	f = fopen(argv[2],"rb");
	if (!f) 
	{
	  printf("Input file cannot be opened...\n");
	  exit(1);
	}

	while(fread(&c, 1, 1, f))
	{
	  for (int i=0; i < codebook[c].len; i++)
          {
            if (READ_BIT(codebook[c].code, i))
              SET_BIT(bitvector[n/8], n%8);
	    else
              CLEAR_BIT(bitvector[n/8], n%8);
	    n++;
	  }
	}
	fclose(f);

	// Write bitvector to output file
	f = fopen(argv[3], "wb");
	if (!f)
	{
	  printf("Could not open output file...\n");
	  exit(1);
	}
	fwrite(bitvector, 1, ceil(n/8), f);
	fclose(f);

	printf("Bye!\n");
	return 0;
}
