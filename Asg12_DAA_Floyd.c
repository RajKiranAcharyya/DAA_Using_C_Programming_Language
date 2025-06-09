/*
0 8 0 1
0 0 1 0
4 0 0 0
0 2 9 0
*/

#include <stdio.h>
#define INF 99999
#define N 100
int cost[10][10], n, A[10][10], P[10][10];
void allpaths()
{
	int i, j, k;
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			A[i][j] = cost[i][j];
			P[i][j] = -1;
		}
	}
	for (k = 1; k <= n; k++)
	{
		for (i = 1; i <= n; i++)
		{
			for (j = 1; j <= n; j++)
			{
				if (A[i][j] > A[i][k] + A[k][j])
				{
					A[i][j] = A[i][k] + A[k][j];
					P[i][j] = k;
				}
			}
		}
	}
}

int main()
{
	int i, j;
	printf("\nEnter The No. Of Vertices: ");
	scanf("%d", &n);
	printf("\nEnter The Adjacency Matrix\n");
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			scanf("%d", &cost[i][j]);
			if (i != j && cost[i][j] == 0)
				cost[i][j] = INF;
		}
	}
	allpaths();
	printf("\nWatch The Shortest Path Matrix\n");
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			printf("%d ", A[i][j]);
		}
		printf("\n");
	}
	printf("\nWatch The Path Matrix\n");
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			printf("%d ", P[i][j]);
		}
		printf("\n");
	}
	return 0;
}
/*
Enter The no. Of Vertices: 4

Enter The Adjacency Matrix
0 8 0 1
0 0 1 0
4 0 0 0
0 2 9 0

Watch Path Matrix
-1 4 4 -1 
3 -1 -1 3 
-1 4 -1 1 
3 -1 2 -1 

Watch Shortest Path Matrix
0 3 4 1
5 0 1 6
4 7 0 5
7 2 3 0
*/