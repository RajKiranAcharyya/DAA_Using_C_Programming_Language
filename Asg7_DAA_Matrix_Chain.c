#include <stdio.h>
#include <limits.h>
int n = 0, dim = 0, m[20][20], s[20][20], p[20];
void MCO()
{
    int i = 0, j = 0, k = 0, l = 0, cost = 0;
    for (i = 1; i <= n; i++)
    {
        m[i][i] = 0;
    }
    for (l = 2; l <= n; l++)
    {
        for (i = 1; i <= n - l + 1; i++)
        {
            j = i + l - 1;
            m[i][j] = INT_MAX;
            for (k = i; k <= j - 1; k++)
            {
                cost = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (m[i][j] > cost)
                {
                    m[i][j] = cost;
                    s[i][j] = k;
                }
            }
        }
    }
}
void POP(int i, int j)
{
    if (i == j)
    {
        printf("A%d ", i);
    }
    else
    {
        printf("( ");
        POP(i, s[i][j]);
        POP(s[i][j] + 1, j);
        printf(" )");
    }
}
int main()
{
    int w = 0, x = 0, u = 0;
    printf("Enter The No. Of Dimensions: ");
    scanf("%d", &dim);
    n = dim - 1;
    printf("Enter The Dimensions: ");
    for (u = 0; u < dim; u++)
    {
        scanf("%d", &p[u]);
    }
    MCO();
    printf("\nWatch M Matrix\n");
    for (w = 1; w <= n; w++)
    {
        for (x = 1; x <= n; x++)
        {
            if (w <= x)
                printf("%d ", m[w][x]);
            else
                printf("  ");
        }
        printf("\n");
    }
    printf("\nWatch S Matrix\n");
    for (w = 1; w <= n; w++)
    {
        for (x = 1; x <= n; x++)
        {
            if (w < x)
                printf("%d ", s[w][x]);
            else
                printf("  ");
        }
        printf("\n");
    }
    printf("\nMimimum Cost: %d", m[1][n]);
    printf("\nParenthesis Sequence: ");
    POP(1, n);
    return 0;
}

/*
Enter The No. Of Dimensions: 5
Enter The Dimensions: 5 6 7 8 9

Watch M Matrix
0 210 490 850
  0 336 768
    0 504
      0

Watch S Matrix
  1 2 3
    2 3
      3


Mimimum Cost: 850
Parenthesis Sequence: ( ( ( A1 A2  )A3  )A4  )
*/