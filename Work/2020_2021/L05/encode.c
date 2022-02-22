// file encode.c

#include <stdio.h>
#include <math.h>

// Have the macro definitions here, outside the main function
#define READ_BIT(x,i)       (int)(((x) & (1U << (i))) != 0)                                 /* read bit i from x */
#define SET_BIT(x,i)        ((x) = (x) | (1U << (i)))                                       /* set bit i from x to 1 */
#define CLEAR_BIT(x,i)      ((x) = (x) & ~(1U << (i)))                                      /* clear bit i from x to 0 */
#define WRITE_BIT(x,i,val)  ((val) ? SET_BIT((x),(i)) : CLEAR_BIT((x),(i)))                 /* write 'val' in bit i from x */
#define TOGGLE_BIT(x,i)     ((x) = (x) ^ (1U << (i)))                                       /* toggle bit i from x */
#define VECREAD_BIT(v,i)       (READ_BIT((v[(i)/8]),(i)%8))                                 /* read bit i from byte vector v */
#define VECWRITE_BIT(v,i,val)  (WRITE_BIT((v[(i)/8]),((i)%8),val))                          /* write 'val' in bit i from byte vector v */


// Structure definitions are typically put outside of the main function
// Define the structure type
typedef struct 
{
    int len;                /* length of code, in bits */
    unsigned int code;     /* the first "len" bits are the codeword */
} CODE32BIT;


// The main program
int main(int argc, char* argv[])
{

	int j;
	
	// Let's print a welcome message
	printf("Going to encode file %s with the codewords from %s, and save result to %s\n", argv[2], argv[1], argv[3]);
	
	
	// ==========================================================================
	// Step 1. Open the file with the codewords, and read them all into a vector
	// The file is received as the first argument, so argv[1]
	// ==========================================================================
	
	// Define a vector of 256 codewords (codebook), one for each ASCII character
	CODE32BIT cb[256];
	
	// Open the file received as the first argument
	FILE* f = fopen(argv[1], "rb");
	
	// Read the vector from the file
	fread(&cb[0], sizeof(CODE32BIT), 256, f);   // Read from f, 256 elements, each of size "sizeof(CODE32BIT)" bytes, and place them in cb
	
	// Close the file once we read everything from it
	fclose(f);
	
	// ==========================================================================
	// Step 2. Open the file to be encoded, read every character, and write the codewords in a vector
	// The file to be encoded is received as the second argument, so argv[2]
	// ==========================================================================	
	
	//const char* filename = "textro.txt";    // the text file to encode
	// filename is now argv[1]
	
	unsigned char vec[1000000];             // one milion bytes, holds up to 1MB of data
	unsigned char c;
	
	// Open file, for reading ("rb")
	//FILE* f = fopen(argv[2], "rb");  
	// We don't need to declare f again as FILE*, we can just reuse the variable
	f = fopen(argv[2], "rb");  
	    
	// (TODO: check if it actually opened)
	
	// Don't forget to declare and initialize pos to 0.
	// On the web, it was in a previous code cell
	int pos = 0;
	
	// Read every character, stop when fread() returns 0 
	while( fread(&c, 1, 1, f) )
	{
	    // Next character is in c, write its codeword in vector vec
	    //
	    // TODO: write here
	
	    for (j = 0; j < cb[ c ].len; j++)
	    {
	        //printf("%d", READ_BIT(cb[ c ].code, j) );
	        VECWRITE_BIT(vec , pos , READ_BIT(cb[ c ].code, j) );
	        pos++;
	    }        
	}
	// We're done with the file
	fclose(f);
	
	// ==========================================================================
	// Step 3. Open the output file and write the stuff in it
	// The destination file is received as the third argument, so argv[3]
	// We write first the number `pos`, and then the data from the output vector `vec`
	// ==========================================================================		
	
	// We don't need to declare f again as FILE*, we can just reuse the variable
	f = fopen(argv[3], "wb");                                   // open file
	fwrite(&pos, sizeof(int), 1, f);                           // write pos 
	fwrite(vec, sizeof(unsigned char), ceil(pos/8.0), f);      // write the encoded bitstring, only the actual written bytes ceil(len/8)
	fclose(f);        	

	// We're done, let's print a message
	printf("Done!");
}
