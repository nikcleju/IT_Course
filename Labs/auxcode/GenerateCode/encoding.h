
/* Definition  */
typedef struct 
{
  int len;                /* length of code, in bits */
  unsigned long code;     /* the first "len" bits are the codeword (assuming len < 32). The other, don't care. */
} CODE32BIT;
