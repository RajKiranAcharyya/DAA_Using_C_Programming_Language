/*
0 10 0 0 5
0 0 1 0 2
0 0 0 4 0
7 0 6 0 0
0 3 9 2 0
*/

#include <stdio.h>

#define INF 999  // Large value to represent infinity (no direct edge)

// Global variables
int k, v1, v2, n, i, j;
int visited[10];     // Tracks visited nodes
int min, mincost = 0; // min: for minimum edge cost, mincost: total MST cost
int g[10][10];       // Adjacency matrix

// Prim's Algorithm Function
int prim()
{
    // Initially mark all nodes as unvisited
    for (i = 1; i <= n; i++)
        visited[i] = 0;

    visited[1] = 1; // Start MST from node 1

    printf("\nEdges in the Minimum Spanning Tree:\n");

    // Repeat until we add (n-1) edges to MST
    for (k = 1; k < n; k++)
    {
        min = INF;

        // Search for the minimum cost edge from visited to unvisited
        for (i = 1; i <= n; i++)
        {
            for (j = 1; j <= n; j++)
            {
                // Check: edge exists, one node is visited, the other is not
                if (g[i][j] != INF && visited[i] == 1 && visited[j] == 0)
                {
                    if (g[i][j] < min)
                    {
                        min = g[i][j];
                        v1 = i;
                        v2 = j;
                    }
                }
            }
        }

        // Print the selected edge
        printf("Edge %d: (%d -> %d) with cost %d\n", k, v1, v2, min);

        // Mark both vertices as visited
        visited[v1] = visited[v2] = 1;

        // Add cost to MST total
        mincost += min;
    }

    return mincost; // Return total cost of MST
}

int main()
{
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix (0 if no edge):\n");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            scanf("%d", &g[i][j]);

            // Convert 0 to INF only for non-self-loop (i != j)
            if (g[i][j] == 0 && i != j)
                g[i][j] = INF;
        }
    }

    int cost = prim(); // Run Prim's Algorithm

    printf("\nMinimum Cost of the Spanning Tree: %d\n", cost);

    return 0;
}



/*
Enter The No. Of Nodes: 5

Enter The Adjacency Matrix
0 10 0 0 5
0 0 1 0 2
0 0 0 4 0
7 0 6 0 0
0 3 9 2 0


Edge 1(1->5)
Edge 2(5->4)
Edge 3(5->2)
Edge 4(2->3)
Minimum Cost: 11
*/