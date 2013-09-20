#include <stdio.h>

int merge(int A[], int p, int m, int q)
{
    int L[100];
    int R[100];
    int l, r;
    int i = 0, j = 0;
    int count = 0;

    l = m - p + 1;
    r = q - m;
    while(i < l)
        L[i++] = A[p+i];
    while(j < r)
        R[j++] = A[m+j+1];

    i = j = 0;
    while(i < l && j < r)
    {
        if (L[i] < R[j])
            A[p+i+j] = L[i++];
        else 
        {
            A[p+i+j] = R[j++];
            count++;
        }
    }
    while (i < l)
    {
        A[p+i+j] = L[i++];
        count++;
    }
    while (j < r)
        A[p+i+j] = R[j++];

    return count;
}


int get_inversion_by_mergesort(int A[], int l, int r)
{
    int count = 0;
    int mid = 0;

    if (l < r)
    {
        mid = (l + r) / 2;
        get_inversion_by_mergesort(A, l, mid);
        get_inversion_by_mergesort(A, mid+1, r);
        count += merge(A, l, mid, r);
    }

    return count;
}

int main(void)
{
    int A[10] = {5, 2, 6, 7, 1, 4, 9, 8, 0, 3};
    int count = 0;

    count = get_inversion_by_mergesort(A, 0, 9);
    printf("%d\n", count);

    return 0;
}
