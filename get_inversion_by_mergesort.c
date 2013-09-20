#include <stdio.h>

int count = 0;	//用于逆序对的计数

void merge(int A[], int p, int m, int q)
{
    int L[100];
    int R[100];
    int l, r;
    int i = 0, j = 0;

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
			count += (l-i);		//计算R中每个元素的逆序数
            A[p+i+j] = R[j++];
        }
    }
    while (i < l)
        A[p+i+j] = L[i++];
    while (j < r)
        A[p+i+j] = R[j++];
}


void get_inversion_by_mergesort(int A[], int l, int r)
{
    int mid = 0;

	if (l < r)
    {
        mid = (l + r) / 2;
        get_inversion_by_mergesort(A, l, mid);
        get_inversion_by_mergesort(A, mid+1, r);
        merge(A, l, mid, r);
    }
}

int main(void)
{
    int A[10] = {5, 2, 6, 7, 1, 4, 9, 8, 0, 3};

    get_inversion_by_mergesort(A, 0, 9);
    printf("%d\n", count);
	for (int i = 0; i < 10; ++i)
		printf("%d ", A[i]);

    return 0;
}
