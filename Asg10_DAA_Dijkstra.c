/*
0 10 0 0 5
0 0  1 0 2
0 0 0 4 0
7 0 6 0 0
0 3 9 2 0
*/

#include <stdio.h> 
#define INF 999 // Define a large value as infinity (used for unreachable paths)

// Global arrays
int cost[100][100];	  // Adjacency matrix to store graph edge costs
int dist[100];		  // Stores the shortest distance from the source
int predecessor[100]; // Stores the predecessor of each node in the shortest path

// Function to implement Dijkstra's algorithm
void dijkstra(int n, int v)
{
	int status[100]; // To track if a node is finalized (1) or not (0)
	int i, count, j, min, w, u;

	// Initialization of distances and status
	for (i = 1; i <= n; i++)
	{
		status[i] = 0;				  // Mark all nodes as unvisited
		dist[i] = cost[v][i];		  // Distance from source to node i
		if (dist[i] != INF && i != v) // If edge exists and not self-loop
			predecessor[i] = v;		  // Set source as predecessor
		else
			predecessor[i] = -1; // No predecessor (unreachable or self)
	}

	dist[v] = 0;   // Distance from source to itself is 0
	status[v] = 1; // Mark source as visited

	// Main loop runs for (n - 1) nodes
	for (count = 2; count <= n; count++)
	{
		min = INF;

		// Find the unvisited node with the smallest distance
		for (w = 1; w <= n; w++)
		{
			if ((dist[w] < min) && (status[w] == 0))
			{
				min = dist[w];
				u = w; // u is the next node to process
			}
		}

		status[u] = 1; // Mark the selected node as visited

		// Update distances of the neighbors of u
		for (w = 1; w <= n; w++)
		{
			if ((dist[u] + cost[u][w] < dist[w]) && (status[w] == 0))
			{
				dist[w] = dist[u] + cost[u][w]; // Update distance
				predecessor[w] = u;				// Update predecessor
			}
		}
	}

	// Print predecessor list for each node
	printf("\nPredecessors:\n");
	for (i = 1; i <= n; i++)
	{
		if (i != v)
			printf("Node %d <- %d\n", i, predecessor[i]);
	}
}

// Main function
int main()
{
	int i, j, vertices, svertex;

	// Input number of vertices
	printf("Enter the number of vertices: ");
	scanf("%d", &vertices);

	// Input cost adjacency matrix
	printf("Enter the cost matrix:\n");
	for (i = 1; i <= vertices; i++)
	{
		for (j = 1; j <= vertices; j++)
		{
			scanf("%d", &cost[i][j]);
			// If cost is 0 (no direct edge) and not same vertex, set as INF
			if (cost[i][j] == 0 && i != j)
				cost[i][j] = INF;
		}
	}

	// Input source vertex
	printf("Enter the source vertex: ");
	scanf("%d", &svertex);

	// Run Dijkstra algorithm
	dijkstra(vertices, svertex);

	// Print shortest distances from source to all other nodes
	printf("\nShortest distances from source %d:\n", svertex);
	for (i = 1; i <= vertices; i++)
	{
		if (i != svertex)
			printf("%d -> %d = %d\n", svertex, i, dist[i]);
	}

	return 0;
}

/*
Enter the number of vertices: 5
Enter the cost matrix:
0 10 0 0 5
0 0  1 0 2
0 0 0 4 0
7 0 6 0 0
0 3 9 2 0
Enter the source vertex: 1

Predecessors:
Node 2 <- 5
Node 3 <- 2
Node 4 <- 5
Node 5 <- 1

Shortest distances from source 1:
1 -> 2 = 8
1 -> 3 = 9
1 -> 4 = 7
1 -> 5 = 5
*/