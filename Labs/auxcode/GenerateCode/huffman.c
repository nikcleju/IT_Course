#include <stdlib.h>

#include "huffman.h"


/* GLOBAL DECLARATIONS
=======================
*/

/* Declare a vector 'tree' of 512 Nodes */
#define TREESIZE 512
Node tree[TREESIZE];

/* A counter indicating how many nodes from the vector are currently used */
int numNodes = 0;

/* A vector of the codewords which will be found for each character */
Codeword codebook[256];


/* FUNCTION DEFINITIONS
=======================
*/

/* Initializes the tree vector
   - make all nodes have 'parent', 'left' and 'right' equal to -1 (none)
   - make all nodes have probability 0
   - nodes from 0 to 255 have the 'c' the corresponding character value,
   - nodes beyond 256 have 'c' equal to 0 (won't be used)
   - set the correct value for numNodes
*/
void init_huffman_tree()
{
	for (int i=0; i < TREESIZE; i++)
	{
		// Initialize every node
		if (i < 256)
			tree[i].c = i;		// first 256 nodes correspond to the ASCII characters, their character = their index
		else
			tree[i].c = 0;		// after 256, nodes are only internal nodes, they don't have an attached character, set to 0 and don't use
		tree[i].parent = -1;	// no parent
		tree[i].left = -1;		// no left child
		tree[i].right = -1;		// no right child
		tree[i].prob = 0.0;		// zero probability
	}
	numNodes = 256; // Initialle 
}



/* Sets the probability value for character c*/
void set_prob(unsigned char c, double p)
{
	tree[c].prob = p;
}

/* Makes node 'parent' the parent of the nodes 'leftchild' and 'rightchild'
   - sets the nodes 'leftchild' and 'rightchild' as children of 'parent'
   - sets 'parent' as the parent of the nodes 'leftchild' and 'rightchild'
 */
void make_parent(int parent, int leftchild, int rightchild)
{
	tree[parent].left = leftchild;
	tree[parent].right = rightchild;
	tree[parent].prob = tree[leftchild].prob + tree[rightchild].prob;
	
	tree[leftchild].parent = parent;
	tree[rightchild].parent = parent;
}



/* A function to locate the two nodes with the smallest probabilities
   Outputs:
       - locmin:  at this address store the location of the minimum node
	   - locmin2: at this address store the location of the second minimum node
 */
void find_two_minima(int* locmin, int* locmin2)
{
	int i;
		
	// Init: search for the first root in the vector
	for (i = 0; i < numNodes; i++)
		if (tree[i].parent == -1)
			break; // stop here, tree[i] is the element we look for
	
	// i is the first element we must consider
	double min = tree[i].prob;
	*locmin = i; // location of the first min
	
	// Find minimum
	for (int i = 0; i < numNodes; i++)
		if (tree[i].parent == -1  &&  tree[i].prob < min) // we consider only root nodes (with no parents)
		{
			// save the value and the position of the minimum
			min = tree[i].prob;
			*locmin =i;
		}
		
	// The same for the second minimum.
	// Everything is the same, but we skip the minimum found before (*locmin)
	
	// Init: search for the first root in the vector
	for (i = 0; i < numNodes; i++)
		if (tree[i].parent == -1 && i != *locmin)
			break; // stop here, tree[i] is the element we look for
	
	// i is the first element we must consider
	min = tree[i].prob;
	*locmin2 = i; // location of the SECOND min
	
	// Find minimum
	for (int i = 0; i < numNodes; i++)
		if (tree[i].parent == -1  && i != *locmin  &&  tree[i].prob < min) // we consider only root nodes (with no parents)
		{
			// save the value and the position of the SECOND minimum
			min = tree[i].prob;
			*locmin2 =i;
		}	
		
	// locmin and locmin2 hold the locations of the first and second minima
}



/* A function to count the total number of root nodes in the vector.
   A root node is a node which has no parent (parent index is -1)
*/
int count_roots()
{	
	int count = 0;
	for (int i = 0;  i < numNodes; i++)
		if (tree[i].parent == -1)
			count++;
	
	return count;
}



/* A node to make all the connections for the whole Huffman tree */
void make_huffman_tree()
{
	int m1, m2;
	
	while (count_roots() > 1)
	{
		find_two_minima(&m1, &m2);
		make_parent(numNodes, m1, m2);  // numNodes indicates the first location available. Use it.
		//printf("made parent: %d, %d, %d\n", numNodes, m1, m2);
		numNodes++;						// We have added a new node, increment total number
	}
	
	// while() stoppes when there is only one root, so all is done!
}



/* A function to create the codewords from the final Huffman tree 
   The codewords and their lengths are written in the 'codebook' vector
*/
void make_codewords()
{	
	// For each character
	for (int c = 0; c < 256; c++)
	{
		// First, compute the codeword length
		int len = 0;
		int node = c;
		while (tree[node].parent != -1) // we must stop at the root node
		{
			// Go to the parent node, increment length
			//printf("%d\t%d\tup\n", node, tree[node].parent);
			node = tree[node].parent;
			len++;
			//printf("%d\n", node);
		}
		//printf("Length of codeword for %d = %d\n", c, len);
		
		// Save the computed length
		codebook[c].len = len;
		
		// Second, allocate memory for the codeword
		codebook[c].code = (int*) malloc(len * sizeof(int));
		
		// Third, compute the codeword itself
		node = c;
		while (tree[node].parent != -1) // we must stop at the root node
		{
			if (node == tree[tree[node].parent].left)  // if node == the left child of its parent ---> 0
				codebook[c].code[len-1] = 0;           // 	  set the last bit in the codeword to 0
			else									   // else ---> 1
				codebook[c].code[len-1] = 1;           // 	  set the last bit in the codeword to 1
			len--;									   // decrement len, so next time we will write the previous bit
			node = tree[node].parent;				   // move to parent node, then repeat
		}
	}
}

/* A function to save the codebook to a file */
void save_codebook(const char* filename)
{
	
}

/* A function to load the codebook from a file 
   Returns 1 if success, 0 if something failed (file could not be opened)
*/
int load_codebook(const char* filename)
{
	
}

