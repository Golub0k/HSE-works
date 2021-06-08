#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h> 
#include<stdio.h> 
#define x 500
void merge(int a[], int l, int mid, int r)
{
    int i = 0;
    int j = 0;
    int k = l;
    int l1 = mid - l + 1;
    int r1 = r - mid;
    int L[x], R[x];
    for (i = 0; i < l1; i++) { L[i] = a[l + i]; }
    for (j = 0; j < r1; j++) { R[j] = a[mid + 1 + j]; }
    i = 0; j = 0;
    while (i < l1 && j < r1) 
    {
        if (L[i] <= R[j]) 
        {
            a[k] = L[i];
            i+=1;
        }
        else { a[k] = R[j]; j+=1;}
        k+=1;
    }
    while (i < l1) { a[k] = L[i];i+=1;k+=1;}
    while (j < r1)  { a[k] = R[j]; j+=1; k+=1;}
    printf("Left part: ");
    for (i = 0; i < l1; i++)
        printf("%d ", L[i]);
    printf("\n");
    printf("Right part: ");
    for (i = 0; i < r1; i++)
        printf("%d ", R[i]);
    printf("\n");
    printf("Merged parts: ");
    for (i = l; i < l + r1 + l1; i++)
        printf("%d ", a[i]);
    printf("\n\n");
}

void mergeSort(int a[], int l, int r) 
{
    if (l!=r) 
    {
        int m = (int)(((float)(r + l) / 2) + 0.5);
        if (m != l) {
            mergeSort(a, l, m - 1);
            mergeSort(a, m, r);
            merge(a, l, m - 1, r);
        }
        else {mergeSort(a, l, m); mergeSort(a, m + 1, r); merge(a, l, m, r);}
    }
    return;
}

int main()
{
    int n;
    scanf("%d", &n);
    int arr[x];
    printf("Initial array:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        printf("%d ", arr[i]);
    }

    printf("\n\n");
    mergeSort(arr, 0, n - 1);
}
