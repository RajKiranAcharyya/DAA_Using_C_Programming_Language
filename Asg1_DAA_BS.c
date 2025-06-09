#include <stdio.h>
#define maxsize 100

void binarysearch(int a[], int l, int r, int s)
{
    if (l > r)
    {
        printf("%d Is Not Found\n", s);
        return;
    }

    int m = (l + r) / 2;

    if (a[m] == s)
    {
        printf("%d Is Found At Index %d\n", s, m);
        return;
    }
    else if (s > a[m])
    {
        binarysearch(a, m + 1, r, s);
    }
    else
    {
        binarysearch(a, l, m - 1, s);
    }
}

int main()
{
    int a[maxsize], n = 0;
    int i = 0, s = 0;
    printf("\nEnter The Size Of The Array: ");
    scanf("%d", &n);
    printf("\nEnter The Elements\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    while (1)
    {
        printf("\nEnter The Element To Be Searched: ");
        scanf("%d", &s);
        binarysearch(a, 0, n - 1, s);
    }
    return 0;
}