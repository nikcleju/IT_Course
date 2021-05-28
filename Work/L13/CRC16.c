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
//        CRC16.exe     input.txt    output.dat
//         argv[0]       argv[1]     argv[2] 
 
int main(int argc, char* argv[])
{
	int pos;

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

	// Open the output file and write the original data there, before we destroy it in the process
	// STEP 3: Write the data into the output file argv[2]
	//   a. write the original input data
	f = fopen(argv[2], "wb");
	fwrite( input , sizeof(unsigned char) , nbytes , f); 

	// STEP 2
	input[nbytes]   = 0;   // make sure the two bytes which will hold the CRC start from the value of 0
	input[nbytes+1] = 0;
	for (pos=0; pos < nbytes*8 ; pos++)  // iterate through every bit in the input sequence
	{
		if( VECREAD_BIT(input, pos) == 1)   // only do something if the current bit is 1, otherwise just advance
		{
			VECWRITE_BIT(input, pos,    (VECREAD_BIT(input, pos)    + 1)%2 ); // toggle the bit at position pos
			VECWRITE_BIT(input, pos+2,  (VECREAD_BIT(input, pos+2)  + 1)%2 ); // toggle the bit at position pos
			VECWRITE_BIT(input, pos+15, (VECREAD_BIT(input, pos+15) + 1)%2 ); // toggle the bit at position pos
			VECWRITE_BIT(input, pos+16, (VECREAD_BIT(input, pos+16) + 1)%2 ); // toggle the bit at position pos
			// the positions = where the 1's are located in the g sequence
		}
	}

	//   b. append the two bytes of the CRC value (16 bits)
	fwrite( input + nbytes , 1, 2, f);   // write two more bytes in the output file
	                                     //  taken from the input vector, but the after the orignal data
	fclose(f);	
	
	printf("Written file %s. Bye!", argv[2]);
}
