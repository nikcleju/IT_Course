// file entropy.c

#include <stdio.h>
#include <math.h>

int main(int argc, char* argv[])
{
	
  FILE* pFile;
  unsigned char c;          // holds one byte with values from 0 to 255
  int counters[256] = {0};  // 256 counters, counters[k] holds the number of k's encountered 
  int gc=0;                 // holds the count of all bytes in the file
  int i;
  double entropy=0;
  
  double prob[256];         // holds the probabilities of every value
  
  //for (int i=0; i<256; i++)
  //  counters[i]=0;
  
  printf("Analyzing the file %s...", argv[1]);
  
  pFile = fopen(argv[1],"rb");	
  // TODO: Check if the file was actually opened
  
  // Read one byte repeatedly, until the end of the file
  while( fread(&c, 1, 1, pFile) )
  {
	// Increment the indivudal counter
	counters[c]++;
	// Increment the global counter
	gc++;
  }
  
  for (i=0; i<256; i++)
  {
  	prob[i] = counters[i] / (float)gc;
  	printf("prob[%d] = %g\n", i, prob[i]);
  
  	// Add the term to the total sum
	if (prob[i] > 0)
  		entropy = entropy - prob[i] * log2(prob[i]);
  }
  printf("Entropy = %g bits per message (i.e. per byte)", entropy);
  
  
  fclose(pFile);
}
