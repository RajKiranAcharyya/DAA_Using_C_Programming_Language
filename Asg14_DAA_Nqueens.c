#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 10

int x[MAX];            // Holds the column position for queens
int solutionCount = 0; // Count of solutions found

// Check if placing queen at (row, col) is safe
int isSafe(int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        if (x[i] == col || abs(x[i] - col) == abs(i - row))
        {
            return 0; // Conflict
        }
    }
    return 1; // Safe
}

// Recursive function to place queens
void solveNQueens(int row, int n)
{
    for (int col = 0; col < n; col++)
    {
        if (isSafe(row, col))
        {
            x[row] = col;

            if (row == n - 1)
            {
                solutionCount++;
                printf("\n\nSolution %d (Column positions):\n", solutionCount);
                for (int i = 0; i < n; i++)
                {
                    printf("%d\t", x[i] + 1); // +1 for user-friendly output
                }

                printf("\n\nBoard Representation:\n");
                for (int i = 0; i < n; i++)
                {
                    for (int j = 0; j < n; j++)
                    {
                        if (x[i] == j)
                            printf("Q%d\t", i + 1);
                        else
                            printf("...\t");
                    }
                    printf("\n");
                }
            }
            else
            {
                solveNQueens(row + 1, n);
            }
        }
    }
}

int main()
{
    int n;
    printf("Enter the number of queens (max %d): ", MAX);
    scanf("%d", &n);

    if (n <= 0 || n > MAX)
    {
        printf("Please enter a number between 1 and %d.\n", MAX);
        return 1;
    }

    solveNQueens(0, n);

    if (solutionCount == 0)
    {
        printf("\nNo solutions found for %d queens.\n", n);
    }
    else
    {
        printf("\nTotal Solutions: %d\n", solutionCount);
    }

    return 0;
}

/*
Enter the number of queens (max 10): 4


Solution 1 (Column positions):
2       4       1       3

Board Representation:
...     Q1      ...     ...
...     ...     ...     Q2
Q3      ...     ...     ...
...     ...     Q4      ...


Solution 2 (Column positions):
3       1       4       2

Board Representation:
...     ...     Q1      ...
Q2      ...     ...     ...
...     ...     ...     Q3
...     Q4      ...     ...

Total Solutions: 2
*/