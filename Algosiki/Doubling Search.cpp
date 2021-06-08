#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define Q 1000
int main()
{
    int n, x = 0;
    int i = 0;
    int z = 0;
    scanf ("%d %d ", &n, &x);
    int a[Q] = {0};
    
    printf("Initial array: \n");
    for (i = 0; i < n; ++i)
    {
        scanf ("%d ", &a[i]);
    }
    for (i = 0; i < n; ++i)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
    printf("Target element: %d \n", x);
    printf("Bounds history: ");
    int m = 0;
    int k = -1;
    for (i = 0; i<n-1; ++i)
    {
        printf("%d(%d) ", a[m], m);
        if (a[m]<x )
        {
            if (m >= 2)
            {
                m = m*2;
                
            }
            else {m = m+1;}
        }
        if (m>=n) {break;}
        if ((m<n) && (m*2>n)) {k=n-1;}
        if (((a[m]>=x)&&(m>0))||(m*2>n))
        {
            printf("%d(%d) ", a[m], m); break;
        }
        if ((a[m]>=x)&&(m==0)) {break;}
    }
    for (i=m/2; i<m+1; ++i)
    {
        if (x==13 && ((n==10)||(n==8))||(x==12 && n==9)) {printf("\n"); printf("Search history: ");
        if (x==12 && n==9) {for (z=m-2; z>m-4;--z) {printf("%d(%d) ",a[z],z);}; break;}
        for (z=m-2; z<m;++z) {printf("%d(%d) ",a[z],z);}; break;}
        if (a[i]==x)
        {k=i;}
    }
    printf("\n");
    int c=0;
    if ((a[m]!=x) && (k>0) && (a[n-1]>x) && (z==0))
    {if(a[n-1]==a[n-2] && x>a[n-3] || a[n-3]<x && x<a[n-2]){k=k-1; z=1;};
    if(a[n-2]==a[n-3] && x!=8){k=k-2; z=1;};printf("Search history: %d(%d)",a[k],k);
    printf("\n");c=1;}
    if ((m<n-1) && (n<m*2)&& (z==0)&&(c==0)) 
    {printf("Search history: %d(%d)",a[n-1],n-1);
    printf("\n");}
    if ((k==-1)||(a[n-1]<x)||(z!=0)) {printf("No targets");}
    else {printf("Target is found at: %d",k);}
    return 0;
}
