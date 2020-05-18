#include <stdio.h>
#include <stdlib.h>
#include <math.h>  

// Macro definitions for bit-handling
#define READ_BIT(x,i)   ((x)&(1U<<(i)))
#define CLEAR_BIT(x,i)  ((x)=(x)&~(1U<<(i)))
#define SET_BIT(x,i)    ((x)=(x)|(1U<<(i)))
#define TOGGLE_BIT(x,i) ((x)=(x)^(1U<<(i)))

// Structure to hold the codeword of a byte
typedef struct{
	
	int len;
	unsigned long code;
	
}CODE32BIT;

// Fire away!
int main(int argc, char *argv[]) {
	
	// Define variables here (C-style)
	int i,n=0;
	CODE32BIT v[256];
	unsigned char c, buff[1000000];
	
	// Open code file and read the complete codewords' vector
	FILE *f;
	f=fopen(argv[1],"rb");
	if(!f)
	{
		printf("eroare la deschidere f1");
		exit(1);
	}
	fread(v,sizeof(CODE32BIT),256,f);
	fclose(f);
	
	// Open the encoded file
	f=fopen(argv[2],"rb");
	if(!f)
	{
		printf("eroare la deschidere f2");
		exit(1);
	}
	
	// Read every byte from the file into variable c
	while(fread(&c,1,1,f))
	{
		// Go through every bit from the codeword of byte c
		for(i=0;i<v[c].len;i++)
		{
			// Is the bit 1 or 0?
			if(READ_BIT(v[c].code,i))
			{
				// The bit is 1, append a bit of 1 to the output vector, on position k
				SET_BIT(buff[n/8],n%8);
			}
			else
			{
				// The bit is 0, append a bit of 0 to the output vector, on position k
				CLEAR_BIT(buff[n/8],n%8);
				n++;
			}	
		}
	}
	fclose(f);
	
	// Open the output file ...
	f=fopen(argv[3],"wb");
	// ... and write the full output vector
	fwrite(buff,1,ceil(n/8.0),f);
	fclose(f);
	
	return 0;
}
