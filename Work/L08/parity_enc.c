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
//     parity_enc.exe   input.txt   output.dat
//         argv[0]       argv[1]     argv[2] 
 
int main(int argc, char* argv[])
{

	// STEP 1
	unsigned char input[100000];  // allocate a vector with enough space for 100KB of data
	int nbytes;                   // will store the number of bytes actually read from the file by fread()
	
	// TODO: write here
	FILE* f = fopen(argv[1], "rb");
	if (f == NULL)
	{
		printf("File %s could not be opened", argv[1]);
		exit(1);
	}
	nbytes  = fread( input , sizeof(unsigned char) , 100000 , f);
	fclose(f);

	// STEP 2
	unsigned char output[200000];  // allocate a vector with enough space for 200KB of data
	
	// TODO: write here
	int n;
	for(n = 0; n < nbytes; n++)
	{
	    // Copy the next 8 bits from input to output
	    int k;
	    for (k = 0; k < 8; k++)
	    {
	        VECWRITE_BIT(output, n*9 + k , VECREAD_BIT(input, n*8 + k) );
	        
	        // Explanations:
	        // We are at iteration n
	        // We have already read n*8 bits from the input, and written n*9 bits in the output
	        // We need to read the next 8 bits, i.e. from n*8+0 to n*8+7, and copy them into n*9+0 to n*9+7
	    }
	    
	    // Compute the parity bit and append at the output
	    int sum = 0;
	    int i;
	    for (i = 0; i < 8; i++)
	    {
	        sum = sum + VECREAD_BIT(input, n*8 + i);
	    }
	    int p = sum % 2;
	    VECWRITE_BIT(output, 9*n + 8, p);   // last but was copied into position n*9+7, so we put parity at n*9+8
	}

	// STEP 3
	// TODO: write here
	f = fopen(argv[2], "wb");
	fwrite( output , sizeof(unsigned char) , ceil(nbytes*9.0/8) , f);
	fclose(f);	
	
	printf("Written file %s. Bye!", argv[2]);
}
