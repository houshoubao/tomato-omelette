#include <stdio.h>
#define PRINT(i, n, a) while(i < n){ printf("%-4d", a[i++]);}

void quicksort(int*, int, int);
int partition(int*, int, int);

int main()
{
    int i = 0, n = 8;
    int a[] = {2, 5, 4, 1, 7, 7, 7, 1};
    quicksort(a, 0, 7);
    PRINT(i, n, a);
    return 0;
}

void quicksort(int *a, int p, int r)
{
    if(p < r)
    {
        int q = partition(a, p, r);
        quicksort(a, p, q - 1);
        quicksort(a, q + 1, r);
    }
}

int partition(int *a, int p, int r)
{
    int mid = *(a + r), i = p - 1, j = p, temp;
    while(j < r - 1)
    {
        if(*(a + j) <= mid)
        {
            i++;
            temp = *(a + j);
            *(a + j) = *(a + i);
            *(a + i) = temp;
        }
        j++;
    }
    temp = *(a + i + 1);
    *(a + i + 1) = *(a + r);
    *(a + r) = temp;
    return ++i;
}
