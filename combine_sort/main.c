#include <stdio.h>
#include <math.h>

#define MAX (int)(pow(2, (sizeof(int) * 8)) - 1)
#define PRINT(i, n, a) while(i < n){ printf("%-4d", a[i++]);}

void combine(int*, int, int, int);
void combine_sort(int*, int, int);

int main()
{
    int i = 0, n = 8, a[] = {2, 5, 4, 1, 7, 7, 7, 1};
    printf("befort sort array is: ");
    PRINT(i, n, a);
    printf("\n");
    combine_sort(a, 0, 7);
    i = 0;
    printf("after sort array is: ");
    PRINT(i, n, a);
    printf("\n");
    return 0;
}

void combine(int *a, int p, int q, int r)
{
    int i = 0, j = 0, lengthL = q - p + 1, lengthR = r - q, arrayL[lengthL + 1], arrayR[lengthR + 1];
    for(; i < lengthL; i++)
        *(arrayL + i) = *(a + p + i);
    for(; j < lengthR; j++)
        *(arrayR + j) = *(a + q + j + 1);
    *(arrayL + i) = MAX;
    *(arrayR + j) = MAX;
    i = 0;
    j = 0;
    while(p <= r)
    {
        if(*(arrayL + i) <= *(arrayR + j))
        {
            *(a + p) = *(arrayL + i);
            i++;
        }
        else
        {
            *(a + p) = *(arrayR + j);
            j++;
        }
        p++;
    }
}

void combine_sort(int* a, int p, int r)
{
    if(p < r)
    {
        int q = (p + r) / 2;
        combine_sort(a, p, q);
        combine_sort(a, q + 1, r);
        combine(a, p, q, r);
    }
}
