#include <stdio.h>
#include <stdlib.h>

#define READ_BIT(x,i)       (int)(((x) & (1U << (i))) != 0)                                 /* read bit i from x */
#define SET_BIT(x,i)        ((x) = (x) | (1U << (i)))                                       /* set bit i from x to 1 */
#define CLEAR_BIT(x,i)      ((x) = (x) & ~(1U << (i)))                                      /* clear bit i from x to 0 */
#define WRITE_BIT(x,i,val)  ((val) ? SET_BIT((x),(i)) : CLEAR_BIT((x),(i)))                 /* write 'val' in bit i from x */
#define TOGGLE_BIT(x,i)     ((x) = (x) ^ (1U << (i)))                                       /* toggle bit i from x */
#define VECREAD_BIT(v,i)       (READ_BIT((v[(i)/8]),(i)%8))                                 /* read bit i from byte vector v */
#define VECWRITE_BIT(v,i,val)  (WRITE_BIT((v[(i)/8]),((i)%8),val))                          /* write 'val' in bit i from byte vector v */

// We'll run the program like this:
//     parity_dec.exe   input.dat   output.dat
//         argv[0]       argv[1]     argv[2] 
 
int main(int argc, char* argv[])
{

	// STEP 1: read the input file into an input vector
	unsigned char input[200000];  // allocate a vector with enough space for 200KB of data
	int nbytes;                   // will store the number of bytes actually read from the file by fread()
	
	// TODO: write here
	FILE* f = fopen(argv[1], "rb");
	if (f == NULL)
	{
		printf("File %s could not be opened", argv[1]);
		exit(1);
	}
	nbytes  = fread( input , sizeof(unsigned char) , 100000 , f);  // read everything from the file
	fclose(f);
	printf("Read %d bytes from file %s\n", nbytes, argv[1]);


	// STEP 2: do the thing!
	unsigned char output[100000];  // allocate a vector with enough space for 100KB of data
	
	int n;
	for(n = 0; n < nbytes*8/9; n++)   // nbytes*8/9 = total number of groups of 9 bits in the input data
	{
	    // Copy the next 8 bits from input to output
	    int k;
	    for (k = 0; k < 8; k++)
	    {
	        VECWRITE_BIT(output, n*8 + k , VECREAD_BIT(input, n*9 + k) );
	        
	        // Explanations:
	        //   We are at iteration n
	        //   We have already read n*9 bits from the input, and written n*8 bits in the output
	        //   We need to read the next 8 bits, i.e. from n*9+0 to n*9+7, and copy them into n*8+0 to n*8+7
	    }
	    
	    // Compute the parity bit
	    int sum = 0;
	    int i;
	    for (i = 0; i < 8; i++)
	    {
	        sum = sum + VECREAD_BIT(input, n*9 + i);
	    }
	    int p = sum % 2;
	    
	    // and check if it is the same as the value in the input data
	    if(p != VECREAD_BIT(input, n*9 + 8))
	    {
	    	printf("I'm sorry to tell you this, but there may be an error somewhere in byte number %d\n", n);
		}
	}


	// STEP 3: write the output vector into the output file
	f = fopen(argv[2], "wb");
	fwrite( output , sizeof(unsigned char) , floor(nbytes*8.0/9) , f); // nbytes*8/9
	fclose(f);	
	
	printf("Written file %s. Bye!", argv[2]);

}
