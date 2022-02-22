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
//     Hamming_enc.exe   input.txt   output.dat
//         argv[0]       argv[1]     argv[2] 
 
int main(int argc, char* argv[])
{

	int i3, i5, i6, i7, c0, c1, c2, c4;


	// STEP 1: Read the input file argv[1] into the vector `input`
	unsigned char input[100000];  // allocate a vector with enough space for 100KB of data
	int nbytes;                   // will store the number of bytes actually read from the file by fread()
	
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
	
	inpos  = 0;
	outpos = 0;
	while ( ... )
	{
		i3 = VECREAD_BIT(input, inpos+0);
		i5 = VECREAD_BIT(input, inpos+1);
		i6 = VECREAD_BIT(input, inpos+2);
		i7 = VECREAD_BIT(input, inpos+3);
		
		c0 = (i3 + i5 + i6) % 2;
		c1 = (i3 + i5 + i7) % 2;
		c2 = (i3 + i6 + i7) % 2;
		c4 = (i5 + i6 + i7) % 2;
		
		VECWRITE_BIT(output, outpos+0, c0);
		VECWRITE_BIT(output, outpos+1, c1);
		VECWRITE_BIT(output, outpos+2, c2);
		VECWRITE_BIT(output, outpos+3, i3);
		VECWRITE_BIT(output, outpos+4, c4);
		VECWRITE_BIT(output, outpos+5, i5);
		VECWRITE_BIT(output, outpos+6, i6);
		VECWRITE_BIT(output, outpos+7, i7);
		
		inpos  = inpos  + 4;
		outpos = outpos + 8;
	}
	

	// STEP 3: Write the `output` vector into the output file argv[2]
	f = fopen(argv[2], "wb");
	fwrite( output , sizeof(unsigned char) , ceil(nbytes*9.0/8) , f);
	fclose(f);	
	
	printf("Written file %s. Bye!", argv[2]);
}
