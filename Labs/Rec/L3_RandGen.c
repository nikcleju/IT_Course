#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[]) 
{
	FILE *f;
	int i, n=argc-3, size;
	float prob[256]={0};
	for(i=0;i<n;i++)
		sscanf(argv[i+3],"%f",&prob[i]);
	sscanf(argv[2],"%d",&size);
	n=256;
	for(i=0;i<256;i++)
		prob[i]=1.0/256;
	printf("We will output a file %s with %d bytes, with prob:\n",argv[1],size);
	for(i=0;i<n;i++)
		printf("%f ",prob[i]);
	
	unsigned char *data;
	data=(unsigned char*)malloc(size*sizeof(unsigned char));
	if (data==NULL)
	{
		printf("Allocation error");
		exit(1);
	}
	int x;
	srand(0);
	for(i=0;i<size;i++)
	{
		int k=0;
		x=rand();
		while(x>0)
		{
			x=x-prob[k]*RAND_MAX;
			k++;
		}
		data[i]='a'+k-1;
	}
	f=fopen(argv[1],"w");
	fwrite(data,1,size,f);
	fclose(f);
	free(data);
	return 0;
}
