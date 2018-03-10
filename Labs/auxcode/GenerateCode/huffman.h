#ifndef _HUFFMAN_H_
#define _HUFFMAN_H_

/* This file contains the necessary headers for the functions and struct.
   Include this file in any .c file where you need to use the functions.
   Also include it in huffman.c, where the functions are defined
*/
  
/* Struct definition for representing a node */
typedef struct
{
	unsigned char c; /* The character stored in the node, or 0 if none */
	int left; /* Index of the left child node, or -1 if none*/
	int right; /* Index of the right child node, or -1 if none*/
	int parent; /* Index of the parent node, or -1 if none */
	double prob; /* Probability value. 
					For internal nodes, this is the sum of the probabilities of the children. 
					For leaf nodes, this is the actual probability of character c */
} Node;


/* Struct definition for representing a node */
typedef struct
{
	int len; /* The length of the codeword */
	int* code ; /* A vector of size 'len' containing the codeword 
				For example, if len is 5, then code[] might be {1,0,1,1,0}*/
} Codeword;

/* Function headers*/

/* Initializes the tree vector
   - make all nodes have 'parent', 'left' and 'right' equal to -1 (none)
   - make all nodes have probability 0
   - nodes from 0 to 255 have the 'c' the corresponding character value,
   - nodes beyond 256 have 'c' equal to 0 (won't be used)
   - set the correct value for numNodes
*/
void init_huffman_tree();



/* Sets the probability value for character c*/
void set_prob(unsigned char c, double p);



/* Makes node 'parent' the parent of the nodes 'leftchild' and 'rightchild'
   - sets the nodes 'leftchild' and 'rightchild' as children of 'parent'
   - sets 'parent' as the parent of the nodes 'leftchild' and 'rightchild'
 */
void make_parent(int parent, int leftchild, int rightchild);


/* A function to locate the two nodes with the smallest probabilities
   Outputs:
       - locmin:  at this address store the location of the minimum node
	   - locmin2: at this address store the location of the second minimum node
 */
void find_two_minima(int* locmin, int* locmin2);


/* A function to count the total number of root nodes in the vector.
   A root node is a node which has no parent (parent index is -1)
*/
int count_roots();


/* A node to make all the connections for the whole Huffman tree */
void make_huffman_tree();



/* A function to create the codewords from the final Huffman tree 
   The codewords and their lengths are written in the 'codebook' vector
*/
void make_codewords();


/* A function to save the codebook to a file */
void save_codebook(const char* filename);

/* A function to load the codebook from a file 
   Returns 1 if success, 0 if something failed (file could not be opened)
*/
int load_codebook(const char* filename);


#endif