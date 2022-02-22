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
//     Hamming_enc.exe   input.enc   output.txt
//         argv[0]       argv[1]     argv[2] 
 
int main(int argc, char* argv[])
{

	int r0, r1, r2, r3, r4, r5, r6, r7, z0, z1, z2, z3;


	// STEP 1: Read the input file argv[1] into the vector `input`
	unsigned char input[200000];  // allocate a vector with enough space for 100KB of data
	int nbytes;                   // will store the number of bytes actually read from the file by fread()
	
	FILE* f = fopen(argv[1], "rb");
	if (f == NULL)
	{
		printf("File %s could not be opened", argv[1]);
		exit(1);
	}
	nbytes  = fread( input , sizeof(unsigned char) , 200000 , f);
	fclose(f);



	// STEP 2
	unsigned char output[100000];  // allocate a vector with enough space for 200KB of data
	
	int inpos  = 0;
	int outpos = 0;
	while ( inpos < nbytes*8 )     // nbytes*8 = total number of bits which must be processed
	{
		
		r0 = VECREAD_BIT(input, inpos+0);
		r1 = VECREAD_BIT(input, inpos+1);
		r2 = VECREAD_BIT(input, inpos+2);
		r3 = VECREAD_BIT(input, inpos+3);
		r4 = VECREAD_BIT(input, inpos+4);
		r5 = VECREAD_BIT(input, inpos+5);
		r6 = VECREAD_BIT(input, inpos+6);
		r7 = VECREAD_BIT(input, inpos+7);
	
		z0 = (r0 + r1 + r2 + r3 + r4 + r5 + r6 + r7) % 2;
		z1 = (r4 + r5 + r6 + r7) % 2;
		z2 = (r2 + r3 + r6 + r7) % 2;
		z3 = (r1 + r3 + r5 + r7) % 2;
		
		// Fix the errors
		if(z0 == 1)
		{
			// We have 1 error
			
			// Get the position of the error: z1 z2 z3 from base 2 into base 10
			int error_position = z1*4 + z2*2 + z3;
			
			// Fix the error: go to that position and change the bit to the opposite value
			int wrong_bit = VECREAD_BIT(input, inpos + error_position);    // read the wrong bit
			int fixed_bit = (wrong_bit + 1) % 2;                           // invert it                  (bit + 1) % 2 = the opposite bit
			VECWRITE_BIT(input, inpos + error_position, fixed_bit);    // overwrite the wrong bit with the correct one
			
			printf("Detected and fixed one error\n");
		}
		else  // z0 is 0
		{
			if(z1 == 1 || z2 == 1 || z3 == 1)
			{
				// There are 2 errors
				printf("Two errors detected, can't fix them.\n");
			}
		}
		
		// Write the 4 information bits from the received word into the output vector
		// Read them again, because one of them might have been fixed in the meantime
		VECWRITE_BIT(output, outpos+0, VECREAD_BIT(input, inpos+3));
		VECWRITE_BIT(output, outpos+1, VECREAD_BIT(input, inpos+5));
		VECWRITE_BIT(output, outpos+2, VECREAD_BIT(input, inpos+6));
		VECWRITE_BIT(output, outpos+3, VECREAD_BIT(input, inpos+7));
	
		inpos  = inpos  + 8;
		outpos = outpos + 4;
	}
	

	// STEP 3: Write the `output` vector into the output file argv[2]
	f = fopen(argv[2], "wb");
	fwrite( output , sizeof(unsigned char) , outpos/8 , f);   // the output data is half as big as the input (nbytes/2). 
	                                //Or we can use outpos to tell us how many bits we have in the output vector, and divide by 8
	fclose(f);	
	
	printf("Written file %s. Bye!", argv[2]);
}
