/*
0 1 1 0 1
1 0 1 0 1
1 1 0 1 0
0 0 1 0 1
1 1 0 1 0
*/

#include <stdio.h>
#include <stdbool.h>

#define MAX 50

// Global variables
int n, m;              // n = number of vertices, m = number of colors
int graph[MAX][MAX];   // adjacency matrix representation of the graph
int x[MAX];            // array to store colors assigned to each vertex
int solutionCount = 0; // to count and label the solutions

// Function to check if it's safe to assign color 'c' to vertex 'k'
bool isSafe(int k, int c)
{
    for (int j = 0; j < n; j++)
    {
        // Check if vertex k and j are adjacent and have same color
        if (graph[k][j] && x[j] == c)
        {
            return false; // Not safe to color
        }
    }
    return true; // Safe to color
}

// Function to print a valid coloring solution
void write()
{
    printf("%d. ", ++solutionCount);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", x[i]); // Print color of each vertex
    }
    printf("\n");
}

// Recursive function to try all possible colorings
void mColoring(int k)
{
    // Try every color from 1 to m for vertex k
    for (int c = 1; c <= m; c++)
    {
        if (isSafe(k, c))
        {
            x[k] = c; // Assign color

            if (k == n - 1)
            {
                // If last vertex is colored, we found a valid solution
                write();
            }
            else
            {
                // Move to the next vertex
                mColoring(k + 1);
            }

            // Backtrack to try another color
            x[k] = 0;
        }
        else
        {
            // If not safe, skip this color
            continue;
        }
    }
}

int main()
{
    int i, j;

    // Read number of vertices and colors
    printf("Enter number of vertices (n): ");
    scanf("%d", &n);
    printf("Enter number of colors (m): ");
    scanf("%d", &m);

    // Edge case check
    if (n <= 0 || n > MAX)
    {
        printf("Error: Invalid number of vertices. Must be between 1 and %d.\n", MAX);
        return 1;
    }
    if (m <= 0)
    {
        printf("Error: Number of colors must be greater than 0.\n");
        return 1;
    }
    // Read adjacency matrix
    printf("Enter the %d x %d adjacency matrix:\n", n, n);
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    // Initialize color array
    for (i = 0; i < n; i++)
    {
        x[i] = 0;
    }

    // Start the coloring process
    printf("All possible colorings:\n");
    mColoring(0);

    return 0;
}

/*
Enter number of vertices (n): 5
Enter number of colors (m): 3
Enter the 5 x 5 adjacency matrix:
0 1 1 0 1
1 0 1 0 1
1 1 0 1 0
0 0 1 0 1
1 1 0 1 0
All possible colorings:
1. 1 2 3 1 3
2. 1 2 3 2 3
3. 1 3 2 1 2
4. 1 3 2 3 2
5. 2 1 3 1 3
6. 2 1 3 2 3
7. 2 3 1 2 1
8. 2 3 1 3 1
9. 3 1 2 1 2
10. 3 1 2 3 2
11. 3 2 1 2 1
12. 3 2 1 3 1







Enter number of vertices (n): 5
Enter number of colors (m): 4
Enter the 5 x 5 adjacency matrix:
0 1 1 0 1
1 0 1 0 1
1 1 0 1 0
0 0 1 0 1
1 1 0 1 0
All possible colorings:
1. 1 2 3 1 3
2. 1 2 3 1 4
3. 1 2 3 2 3
4. 1 2 3 2 4
5. 1 2 3 4 3
6. 1 2 4 1 3
7. 1 2 4 1 4
8. 1 2 4 2 3
9. 1 2 4 2 4
10. 1 2 4 3 4
11. 1 3 2 1 2
12. 1 3 2 1 4
13. 1 3 2 3 2
14. 1 3 2 3 4
15. 1 3 2 4 2
16. 1 3 4 1 2
17. 1 3 4 1 4
18. 1 3 4 2 4
19. 1 3 4 3 2
20. 1 3 4 3 4
21. 1 4 2 1 2
22. 1 4 2 1 3
23. 1 4 2 3 2
24. 1 4 2 4 2
25. 1 4 2 4 3
26. 1 4 3 1 2
27. 1 4 3 1 3
28. 1 4 3 2 3
29. 1 4 3 4 2
30. 1 4 3 4 3
31. 2 1 3 1 3
32. 2 1 3 1 4
33. 2 1 3 2 3
34. 2 1 3 2 4
35. 2 1 3 4 3
36. 2 1 4 1 3
37. 2 1 4 1 4
38. 2 1 4 2 3
39. 2 1 4 2 4
40. 2 1 4 3 4
41. 2 3 1 2 1
42. 2 3 1 2 4
43. 2 3 1 3 1
44. 2 3 1 3 4
45. 2 3 1 4 1
46. 2 3 4 1 4
47. 2 3 4 2 1
48. 2 3 4 2 4
49. 2 3 4 3 1
50. 2 3 4 3 4
51. 2 4 1 2 1
52. 2 4 1 2 3
53. 2 4 1 3 1
54. 2 4 1 4 1
55. 2 4 1 4 3
56. 2 4 3 1 3
57. 2 4 3 2 1
58. 2 4 3 2 3
59. 2 4 3 4 1
60. 2 4 3 4 3
61. 3 1 2 1 2
62. 3 1 2 1 4
63. 3 1 2 3 2
64. 3 1 2 3 4
65. 3 1 2 4 2
66. 3 1 4 1 2
67. 3 1 4 1 4
68. 3 1 4 2 4
69. 3 1 4 3 2
70. 3 1 4 3 4
71. 3 2 1 2 1
72. 3 2 1 2 4
73. 3 2 1 3 1
74. 3 2 1 3 4
75. 3 2 1 4 1
76. 3 2 4 1 4
77. 3 2 4 2 1
78. 3 2 4 2 4
79. 3 2 4 3 1
80. 3 2 4 3 4
81. 3 4 1 2 1
82. 3 4 1 3 1
83. 3 4 1 3 2
84. 3 4 1 4 1
85. 3 4 1 4 2
86. 3 4 2 1 2
87. 3 4 2 3 1
88. 3 4 2 3 2
89. 3 4 2 4 1
90. 3 4 2 4 2
91. 4 1 2 1 2
92. 4 1 2 1 3
93. 4 1 2 3 2
94. 4 1 2 4 2
95. 4 1 2 4 3
96. 4 1 3 1 2
97. 4 1 3 1 3
98. 4 1 3 2 3
99. 4 1 3 4 2
100. 4 1 3 4 3
101. 4 2 1 2 1
102. 4 2 1 2 3
103. 4 2 1 3 1
104. 4 2 1 4 1
105. 4 2 1 4 3
106. 4 2 3 1 3
107. 4 2 3 2 1
108. 4 2 3 2 3
109. 4 2 3 4 1
110. 4 2 3 4 3
111. 4 3 1 2 1
112. 4 3 1 3 1
113. 4 3 1 3 2
114. 4 3 1 4 1
115. 4 3 1 4 2
116. 4 3 2 1 2
117. 4 3 2 3 1
118. 4 3 2 3 2
119. 4 3 2 4 1
120. 4 3 2 4 2


*/
