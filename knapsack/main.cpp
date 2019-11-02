//Implement divide and conquer and dynamic programming to solve knapsack problem
//Uboho Victor
#include "iostream"


// V is two dimentional array
// v is value
// w is weight
// i item no
// j capacity


using namespace std;

int Knapsack_Iter(int V[][7], int v[], int w[], int i, int j)
{
	int result;
	if (V[i][j]<0)
	{
		for (int i = 0; i<6; i++)
		{
			V[i][0] = 0;							// intialize for zero for V[0][0] to V[6][0]
		}
		for (int j = 0; j<7; j++)
		{
			V[0][j] = 0;							//// intialize for zero for V[0][0] to V[0][7]
		}

		for (int i = 1; i <= 5; i++)
		{
			for (int j = 1; j <= 6; j++)
			{
				if (w[i]>j)
					V[i][j] = V[i - 1][j];
				else
				{
					V[i][j] = V[i - 1][j] > v[i] + V[i - 1][j - w[i]] ? V[i - 1][j] : v[i] + V[i - 1][j - w[i]];
					result = V[i][j];
				}
			}
		}

	}
	return result;
}
int Knapsack_Recur(int V[][7], int v[], int w[], int i, int j)
{
	if (V[i][j] < 0)
	{
		if (i == 0 || j == 0)
			V[i][j] = 0;
		else
		{
			if (w[i]>j)
				return Knapsack_Recur(V, v, w, i - 1, j);
			int v1 = Knapsack_Recur(V, v, w, i - 1, j);
			int v2 = Knapsack_Recur(V, v, w, i - 1, j - w[i]) + v[i];
			V[i][j] = v1>v2 ? v1 : v2;
		}
	}
	return V[i][j];
}
int Knapsack_Div_Conq(int v[], int w[], int i, int j)
{
	if (i == 0 || j == 0)
		return 0;
	else
	{
		if (w[i]>j)
			return Knapsack_Div_Conq(v, w, i - 1, j);
		int v1 = Knapsack_Div_Conq(v, w, i - 1, j);
		int v2 = Knapsack_Div_Conq(v, w, i - 1, j - w[i]) + v[i];
		return v1>v2 ? v1 : v2;
	}
}



int main(int argc, char* argv[])
{
	int option = 3;
	int V[6][7];
	int v[6];
	int w[6];

	//initialize values and weight

	w[0] = 0;
	w[1] = 3;
	w[2] = 2;
	w[3] = 1;
	w[4] = 4;
	w[5] = 5;

	v[0] = 0;
	v[1] = 25;
	v[2] = 20;
	v[3] = 15;
	v[4] = 40;
	v[5] = 50;

	for (int i = 0; i<6; i++)
	{
		for (int j = 0; j<7; j++)
		{
			V[i][j] = -1;
		}
	}

			cout << "The Result for Iteration is: " << Knapsack_Iter(V, v, w, 5, 6) << endl;


			cout << "The Result for Recursion is: " << Knapsack_Recur(V, v, w, 5, 6) << endl;


			cout << "The Result for Divide & conquer is: " << Knapsack_Div_Conq(v, w, 5, 6) << endl;


	system("pause");
	return 0;

}
