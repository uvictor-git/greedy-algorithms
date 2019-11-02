//Implementing a dynamic programming algorithm to solve the optimal binary search tree problem
//Uboho Victor

#include <limits.h>
#include <iostream>
#include <iomanip>

using namespace std;
// Declare global variables
#define MAX 9999;
int n = 10;
double*   freq = new double[n+1];	// freq[i] = frequency of key[i]
char** key  = new char*[n+1];

double**  cost = new double*[n+2];	// cost[i,j] is cost of optimal bst for
                                // keys K[i],K[i+1],...,K[j]. Thus, cost[1,n]
                                // is the minimum cost of a bst with n nodes.
int**  root = new int*[n+1];	// root[i,j] = r where K[r] is the root of
            			// the optimal bst for keys K[i],...,K[j].
				// Thus key[r], r=root[1,n], is the key of the
				// root of the optimal bst for n nodes, and
                                // key[root[1,r-1]] is the key of the root
                                // of the left-subtree & key[root[r+1,n]]
                                // is the key of the root of the right subtree.

void optBST(int n);
void printOBST(int i, int j);


// A function to print the optimal bst for keys K[i],K[i+1],...,K[j]
// The tree is printed using parenthesis notation similar to Scheme

void printOBST(int i, int j){

  if (j < i) return;

  if (root[i][j] - 1 != NULL) {
    cout << "{";
    printOBST(i,root[i][j]-1);
    cout << "}";
  }

  cout << " " << key[root[i][j]] << " ";
  if (root[i][j] + 1 != NULL)
  {
      cout << "[";
      printOBST(root[i][j]+1,j);
      cout << "]";
  }


//  	cout <<"Root of the binary search tree is: " << key[root[i][j]] << endl;
//	if (root[i][j] - 1 != NULL)
//	{
//		cout << "left of " << key[root[i][j]] << " is ";
//		printOBST(i, root[i][j] - 1);
//
//	}
//	if (root[i][j] + 1 != NULL)
//	{
//		cout << "right of " << key[root[i][j]] << " is ";
//		printOBST(root[i][j] + 1, j);
//	}



}

// Calculate the cost and root arrays of the optimal bst for keys
// K[1],K[2],...,K[n]

void optBST(int n){
int i,j,r;
double t;

for (i = 1; i <= n; i++)        // Initializations that simplify main loop
   for (j = i+1; j <= n+1; j++)
      cost[i][j] = MAX;	// Assuming that the cost of any bst is
				// less than INT_MAX.
for (i = 1; i <= n+1; i++)
   cost[i][i-1] = 0;             // Cost of optimal bst of zero nodes

for (i = 1; i <= n; i++){
   cost[i][i] = freq[i];         // Cost of optimal bst of one node
   root[i][i] = i;		 // Root of optimal bst of one node
}

for (j = 1; j <= n-1; j++)	// Find optimal bsts containing j+1 nodes
   for (i=1; i <= n-j; i++){    // Find optimal bsts for keys K[i],...,K[i+j]
      for (r = i; r <= i+j; r++){ // Try K[r] as the root of t bst for keys
         t = cost[i][r-1] + cost[r+1][i+j]; // K[i],...,K[j]
         if (t < cost[i][i+j]){   // It it has the minimum cost so far
            cost[i][i+j] = t;	  // update cost[i][i+j] and
            root[i][i+j] = r;     // root[i][i+j]
         }
      }
      for (int k = i; k <= i+j; cost[i][i+j] += freq[k++])
         ; // empty body
      // Actually, the sum = freq[i] + ... + freq[i+j] need be computed
      // only once for each value of i and j and the sum then added to
      // cost[i][i+j] at this point, i.e.,  cost[i][i+j] += sum;
   }
}
//Driver function
main(){
  int i,j;

   // Allocate space for the 2-dim'l cost array
   for (i = 0; i < n+2; i++)
      cost[i] = new double[n+2];

   // Allocate space for the 2-dim'l root array
   for (i = 0; i < n+1; i++)
      root[i] = new int[n+1];

   // Iniitialize key and freq arrays.  The keys must be entered in order
   // from smallest to largest.
   key[1] = "A"; freq[1] = 0.11;
   key[2] = "B"; freq[2] = 0.06;
   key[3] = "C"; freq[3] = 0.12;
   key[4] = "D"; freq[4] = 0.13;
   key[5] = "E"; freq[5] = 0.04;
   key[6] = "F"; freq[6] = 0.09;
   key[7] = "G"; freq[7] = 0.14;
   key[8] = "H"; freq[8] = 0.08;
   key[9] = "I"; freq[9] = 0.07;
   key[10] = "J"; freq[10] = 0.16;

   optBST(n);			// Compute optimal bst for keys K[1],...,K[n]

   cout << endl <<"Optimal binary search average comparism number: " << cost[1][n] << endl;
   printOBST(1,n);		// Print optimal bst using parenthesis notation
   cout << endl << endl;	// for the tree

   // Print the cost array
   cout << endl << "Cost array" << endl;
   for (i = 1; i <= n; i++){
      for (j = 1; j <= n; j++) {
        if (i>j)
          cost[i][j] = 0;
          cout << cost[i][j] << " ";
      }
      cout << endl << endl;

   }

   // Print the array of roots
//   cout << "Root array" << endl;
//   for (i = 1; i <= n; i++){
//      for (j = 1; j <= n; j++)
//         cout << setw(2) << root[i][j] << " ";
//      cout << endl;
//   }
}


