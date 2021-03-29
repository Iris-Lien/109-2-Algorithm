#include <stdio.h>
#include <stdlib.h>

void sort_by_digit(int *A, int n, int r, int p)
{
    int base = 100;
    while (p > 0)
    {
        --p;
        base /= r;
    }
    int count[r], B[n];

    for (int j = 0; j < r; ++j)
        count[j] = 0;

    for (int i = 0; i < n; ++i)
        count[(A[i] / base) % r]++;

    for (int j = 0, psum = 0, sum = 0; j < r; ++j)
    {
        psum = sum;
        sum += count[j];
        count[j] = psum;
    }

    for (int i = 0; i < n; ++i)
        B[count[(A[i] / base) % r]++] = A[i];

    for (int i = 0; i < n; ++i)
        A[i] = B[i];
}

void radix_sort(int *A, int n, int r, int d)
{
    for (int i = 0; i < d; ++i)
        sort_by_digit(A, n, r, i);
}

int main()
{
    int data[10] = {170, 45, 75, 90, 802, 2, 24, 66, 101, 73, 22, 94, 46, 55, 17, 28, 60, 39};
    printf("Unsorted: ");
    int i;
    for(i = 0; i < 10; i++)
        printf("%d ", data[i]);
    printf("\n");
    radix_sort(data, 10, 10, 3);
    printf("Sorted: ");
    for(i = 0; i < 10; i++)
        printf("%d ", data[i]);
    return 0;
}
