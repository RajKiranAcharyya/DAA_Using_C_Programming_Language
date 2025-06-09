#include <stdio.h>

#define max 20

// Global arrays
int id[max], p[max], d[max], slot[max];

// Sort jobs in decreasing order of profit
void sort(int n)
{
    int i, j, temp;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (p[j] < p[j + 1]) // Compare profits
            {
                // Swap profit
                temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;

                // Swap deadlines
                temp = d[j];
                d[j] = d[j + 1];
                d[j + 1] = temp;

                // Swap job IDs
                temp = id[j];
                id[j] = id[j + 1];
                id[j + 1] = temp;
            }
        }
    }
}

// Job sequencing function (returns total profit)
int js(int n)
{
    int i, k, dmax = d[0], profit = 0, count = 0;

    // Find the maximum deadline
    for (i = 1; i < n; i++)
    {
        if (d[i] > dmax)
            dmax = d[i];
    }

    // Initialize all time slots as empty (-1)
    for (i = 0; i < dmax; i++)
        slot[i] = -1;

    // Try to place each job in a slot before its deadline
    for (i = 0; i < n; i++)
    {
        // Find the latest free slot before deadline
        k = d[i] - 1;
        while (k >= 0)
        {
            if (slot[k] == -1)
            {
                slot[k] = id[i];  // Schedule the job
                profit += p[i];   // Add profit
                count++;
                break;
            }
            k--;
        }

        // Optimization: if slots filled up, stop
        if (count == dmax)
            break;
    }
    return profit;
}

// Display sorted jobs
void display(int n)
{
    int i;
    printf("\nSorted Profit: ");
    for (i = 0; i < n; i++)
        printf("%d ", p[i]);

    printf("\nSorted Deadline: ");
    for (i = 0; i < n; i++)
        printf("%d ", d[i]);
}

int main()
{
    int n, i, k;

    printf("How many jobs: ");
    scanf("%d", &n);

    printf("Enter job details (profit and deadline):\n");
    for (i = 0; i < n; i++)
    {
        k = i + 1;
        printf("Job %d >> p%d & d%d: ", k, k, k);
        scanf("%d %d", &p[i], &d[i]);
        id[i] = k; // Assign job ID
    }

    // Sort jobs by profit
    sort(n);
    display(n);

    // Run Job Sequencing
    int totalProfit = js(n);

    // Display scheduled jobs
    printf("\nSelected Jobs: ");
    for (i = 0; i < max; i++)
    {
        if (slot[i] != -1)
            printf("J%d ", slot[i]);
    }

    printf("\nTotal Profit = %d\n", totalProfit);
    return 0;
}
