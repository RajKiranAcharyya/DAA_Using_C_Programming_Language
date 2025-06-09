#include <stdio.h>
int n, m = 0;
float totalprofit = 0.0;
void knapsack(float *p, float *w, float *r, float *x)
{
    int i = 0, u = m;
    for (i = 0; i < n; i++)
    {
        if (w[i] > u)
            break;
        x[i] = 1.0;
        u = u - w[i];
    }
    if (i < n)
    {
        x[i] = (u / w[i]);
    }
}
void swap(float *a, float *b)
{
    float temp = 0.0;
    temp = *a;
    *a = *b;
    *b = temp;
}
int main()
{
    float profit = 0.0,
          temp = 0.0;
    float p[10],
        w[10], r[10], x[10] = {0.00};
    int i = 0, j = 0;
    printf("\nEnter The No. Of Items & Enter The Capacity: ");
    scanf("%d %d", &n, &m);
    printf("\nEnter Profit & Weight: ");
    for (i = 0; i < n; i++)
    {
        scanf("%f %f", &p[i], &w[i]);
        r[i] = p[i] / w[i];
    }
    printf("\nWatch Profit & Weight: ");
    for (i = 0; i < n; i++)
    {
        printf("\n%f %f %f", p[i], w[i], r[i]);
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n - 1; j++)
        {
            if (r[j] < r[j + 1])
            {
                swap(&r[j], &r[j + 1]);
                swap(&p[j], &p[j + 1]);
                swap(&w[j], &w[j + 1]);
            }
        }
    }
    printf("\nWatch Sorted Profit & Weight: ");
    for (i = 0; i < n; i++)
    {
        printf("\n%f %f %f", p[i], w[i], r[i]);
    }
    knapsack(p, w, r, x);
    for (i = 0; i < n; i++)
    {
        totalprofit += x[i] * p[i];
    }
    printf("\nTotalprofit = %f", totalprofit);
    return 0;
}

/*
Enter The No. Of Items & Enter The Capacity: 3 20

Enter Profit & Weight:
25 18
24 15
15 10

Watch Profit & Weight:
25.000000 18.000000 1.388889
24.000000 15.000000 1.600000
15.000000 10.000000 1.500000
Watch Sorted Profit & Weight:
24.000000 15.000000 1.600000
15.000000 10.000000 1.500000
25.000000 18.000000 1.388889
Totalprofit = 31.500000
*/