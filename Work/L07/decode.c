#include <stdio.h>
#include <stdlib.h>


#define READ_BIT(x,i)       (int)(((x) & (1U << (i))) != 0)                                 /* read bit i from x */
#define SET_BIT(x,i)        ((x) = (x) | (1U << (i)))                                       /* set bit i from x to 1 */
#define CLEAR_BIT(x,i)      ((x) = (x) & ~(1U << (i)))                                      /* clear bit i from x to 0 */
#define WRITE_BIT(x,i,val)  ((val) ? SET_BIT((x),(i)) : CLEAR_BIT((x),(i)))                 /* write 'val' in bit i from x */
#define TOGGLE_BIT(x,i)     ((x) = (x) ^ (1U << (i)))                                       /* toggle bit i from x */
#define VECREAD_BIT(v,i)       (READ_BIT((v[(i)/8]),(i)%8))                                 /* read bit i from byte vector v */
#define VECWRITE_BIT(v,i,val)  (WRITE_BIT((v[(i)/8]),((i)%8),val))                          /* write 'val' in bit i from byte vector v */

// Define the structure type
typedef struct 
{
    int len;                /* length of code, in bits */
    unsigned int code;     /* the first "len" bits are the codeword */
} CODE32BIT;


// We'll run the program like this:
//     decode.exe code.dat input.enc decoded.txt
//      argv[0]    argv[1]  argv[2]    argv[3]
 
int main(int argc, char* argv[])
{

	int i,j;

	// A. Read the full codewords' vector from the codebook file;
	
	// Define a vector of 256 codewords, one for each ASCII character
	CODE32BIT cb[256];
	
	// Open the file
	FILE* f = fopen(argv[1], "rb");
	
	// Check if file is actually opened
	if (f == NULL)
	{
		printf("Bye bye! Adios! Code file nould not be opened!");
		exit(1); 
	}
	
	// Read the vector from the file
	fread(&cb[0], sizeof(CODE32BIT), 256, f);   // Read from f, 256 elements, each of size "sizeof(CODE32BIT)" bytes, and place them in cb
	// &cb[0] is the same as cb
	
	fclose(f);
	//sizeof(unsigned int)


	// Go through all characters and print all the codewords
	for (i=0; i < 256; i++) // bug at 128 
	{
	    // Print the codeword for character with code i
	    //
	    // cb[i].len  = the length of the codeword
	    // cb[i].code = contains the bits
	    //
	    // TODO: write below
	    printf("%c (%d): ", i, i); 
	    for (j=0; j < cb[i].len; j++)
	    {
	        printf("%d" ,READ_BIT(cb[i].code, j));
	    }
	printf("\n");
	}
	

	// B. Read the full input encoded file, in the same order as we wrote the data last week:

	unsigned char vec[1000000];                                // define a vector to hold the data we read
	int len;                                                   // will hold the total number of bits used from the vector
	
	f = fopen(argv[2], "rb");                                  // open file
	
	// Check if file is actually opened
	if (f == NULL)
	{
		printf("Bye bye! Adios! IUnput file nould not be opened!");
		exit(1); 
	}
		
	fread(&len, sizeof(int), 1, f);                            // read one integer, place it in len
	fread(vec, sizeof(unsigned char), 1000000, f);             // read the encoded bitstring, up to 1000000 bytes. fread() will stop when it reaches the file end.
	fclose(f);       	
	

	// C. Decode the characters from the vec array, as follows
	
	char decoded[1000000];                            // place the decoded characters in here
	j=0;                                              // the current position in the decoded vector
	
	int ch;
	int pos;
	
	// TODO: decode the sequence in 'vec', print the decoded characters 
	//       and also save them in vector `decoded`

	int vp = 0; // the current position in the sequence
	
	// Decode until we have processed all the encoded bits (the number is `len`)
	while( vp < len )
	{
	    // Decode the next character
	    for ( ch = 0; ch<256; ch++ )
	    {
	        // Check codeword of character ch
	        int match = 1;     // assume it matches
	        for (pos = 0; pos < cb[ch].len; pos++)                        // go through the codeword
	        {
	            if (READ_BIT(cb[ch].code, pos) !=  VECREAD_BIT(vec, vp+pos))  // compare each bit from codeword with the bit from the encoded sequence, following vp
	            { 
	                match = 0;                                                // we found a bit which doesn't match
	                break;
	            }
	        }
	        // `match` will tell us if the codeword fully matches the sequence or not
	
	        if (match == 1)        // we found it! The character is ch
	        {
	            printf("%c", ch);   // print the decoded character
	            decoded[j] = ch;     // and also save it in a vector `decoded`
	            j++;
	            
	            vp = vp + cb[ch].len;   // advance vp with the length of the codeword we just decoded
	            break;                  // we can stop the search (the for loop), we found our first character
	        }
	        // if there was no match, the for loop will try the next character
	    }
	}
	
	// D. Save the decoded character vector in the output file
	f = fopen( argv[3], "wb" );
	fwrite( decoded , sizeof(char) , j , f);
	fclose(f);
	
}
