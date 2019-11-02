#include<iostream>
#include<conio.h>
using namespace std;


#define N 6
#define MAX 99999

int Graph[N][N];
int dst[N];
int V[N];


void init_()
{
	for (int i = 0; i < N; i++)
	{

		dst[i] = MAX; //Initialize all cost to MAX
		V[i] = 0;
		for (int j = 0; j < N; j++)
		{
			Graph[i][j] = MAX; //Intialize all cell in matrix to MAX
		}
	}
    //Represent the directed graph with our adjacency matrix
	Graph[0][1] = 10;
	Graph[0][2] = 10;
	Graph[0][4] = 30;
	Graph[0][5] = 100;
	Graph[1][2] = 5;
	Graph[2][3] = 50;
	Graph[3][5] = 10;
	Graph[4][5] = 60;
	Graph[4][3] = 20;
}
void Dijkstra(int G[][N], int source, int dst[], int V[])
{
	int shrt, next, i, j;
	int found[N];

	for (int j = 1; j<N; j++)
	{
		dst[j] = G[source][j];
		if (dst[j] < MAX)
			V[j] = source;
	}
	for (int j = 0; j<N; j++)
	{
		found[j] = 0;
	}
	found[source] = 1;
	for (int j = 0; j<N-1; j++)
	{
		next = N;
		for (i = 0; i<N; i++)
		{
			if (found[i] == 0)
			{
				shrt = dst[i];
				next = i;
				break;
			}
		}
		for (i = 0; i<N; i++)
		{
			if (found[i] == 0 && dst[i] < shrt)
			{
				shrt = dst[i];
				next = i;
			}
		}
		if (next != N)
		{
			found[next] = 1;
			for (i = 0; i<N; i++)
			{
				if (found[i] == 0 && dst[i] > dst[next] + Graph[next][i])
				{
					dst[i] = dst[next] + Graph[next][i];
					V[i] = next;
				}
			}
		}
	}
}

void dijkstra_path(int V[], int source, int dst)
{
	if (V[dst] == source)
	{
		cout << source << "->";
	}
	else
	{
		dijkstra_path(V, source, V[dst]);
		cout << V[dst] << "->";
	}
}

//Driver function
int main()
{

	int source = 0;
	init_();
	Dijkstra(Graph, source, dst, V);

    //Print path and the cost of single source shortest path
	for (int i = 0; i < N; i++)
	{
		if (i != 0)
		{
			cout << "Path " << source << " to  " << i << " : ";
			dijkstra_path(V, source, i);
			cout << i << " Cost: ";
			cout << dst[i] << endl;
		}
	}

}
