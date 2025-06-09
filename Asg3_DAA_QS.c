#include <stdio.h>
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int i = 0, j = 0, p[100], n = 0;
int partition(int low, int high)
{
    int k = low, l = low - 1, pk = p[high];
    for (k = low; k < high; k++)
    {
        if (p[k] < pk)
        {
            l++;
            swap(&p[l], &p[k]);
        }
    }
    swap(&p[l + 1], &p[high]);
    return l + 1;
}
void quicksort(int low, int high)
{
    if (low < high)
    {
        int pivot = partition(low, high);
        quicksort(low, pivot - 1);
        quicksort(pivot + 1, high);
    }
}
int main()
{
    printf("\nEnter The Size: ");
    scanf("%d", &n);
    printf("\nEnter The Values: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &p[i]);
    }
    printf("\nWatch Unsorted Array: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", p[i]);
    }
    quicksort(0, n - 1);
    printf("\nWatch Sorted Array: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", p[i]);
    }
    return 0;
}