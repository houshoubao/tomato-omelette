#include <stdio.h>
#define PRINT(i, n, a) while(i < n){ printf("%-4d", a[i++]);}

void insertion_sort(int*, int n);

int main()
{
    int a[] = {2, 5, 4, 1, 7, 7, 7, 1};
    int i = 0, n = 8;
    PRINT(i, n, a);
    printf("\n");
    insertion_sort(a, 8);
    i = 0;
    PRINT(i, n, a);
    return 0;
}

void insertion_sort(int *a, int n)
{
    int i = 0, j = 1, temp;
    for(;j < n; j++)
//    while(j++ < n)
    {
        for(i = j, temp = *(a + j); i >= 0 && *(a + i) > temp; i--)
        {
            *(a + i + 1) = *(a + i);
        }
        *(a + i + 1) = temp;
    }
}
