#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define x 100

int main() {
    int n;
    scanf("%d", &n);
    int a[x];
    int k = n - 1;
    for (int i = k; i > 0; i--)
        if (i % 2 == 1) {
            k = i;
            break;
        }
    a[(n - 1) / 2] = n;
    for (int i = 0; i < n; i++)
    {
        if (i < (n - 1) / 2)
        {
           a[i] = 2 * (i + 1);
        }
        if (i > (n - 1) / 2)
        {
            a[i] = k;
            k -= 2;
        }
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
}
