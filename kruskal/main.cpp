// Simple C++ implementation for Kruskal's
// algorithm
#include <bits/stdc++.h>
using namespace std;

#define V 6
#define MAX 9999
int parent[V];

// Find set of vertex i
int find(int i)
{
	while (parent[i] != i)
		i = parent[i];
	return i;
}

// Does union of i and j. It returns
// false if i and j are already in same
// set.
void union1(int i, int j)
{
	int a = find(i);
	int b = find(j);
	parent[a] = b;
}

// Finds MST using Kruskal's algorithm
void kruskalMST(int cost[][V])
{
	int mincost = 0; // Cost of min MST.

	// Initialize sets of disjoint sets.
	for (int i = 0; i < V; i++)
		parent[i] = i;

	// Include minimum weight edges one by one
	int edge_count = 0;
	while (edge_count < V - 1) {
		int min = INT_MAX, a = -1, b = -1;
		for (int i = 0; i < V; i++) {
			for (int j = 0; j < V; j++) {
				if (find(i) != find(j) && cost[i][j] < min) {
					min = cost[i][j];
					a = i;
					b = j;
				}
			}
		}

		union1(a, b);
		printf("Edge %d:(%d, %d) cost:%d \n",
			edge_count++, a, b, min);
		mincost += min;
	}
	printf("\n Minimum cost= %d \n", mincost);
}

// driver program to test above function
int main()
{

	int cost[][V] = {
		{ MAX, 10, 10, MAX, 30, 100 },
		{ 10, MAX, 5, MAX, MAX, MAX },
		{ 10, 5, MAX, 50, MAX, MAX },
		{ MAX, MAX, 50, MAX, 10, 10 },
		{ 30, MAX, MAX, 20, MAX, 60 },
		{ 100, MAX, MAX, 10, 60, MAX },
	};

	// Print the solution
	kruskalMST(cost);

	return 0;
}
