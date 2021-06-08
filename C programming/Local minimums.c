#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#define x 100

int main()
{
	int n;
	int m, v, d, l, r;
	int k = 0;
	int min = 32768;
	scanf("%i %i", &n, &m);

	int a[x][x] = { 0 };
	for (int i = 1; i < n + 1; ++i)
	{
		for (int j = 1; j < m + 1; ++j)
		{
			scanf("%i", &a[i][j]);

		}
	}
	for (int i = 1; i < n + 1; ++i)
	{
		for (int j = 1; j < m + 1; ++j)
		{
			if (i - 1 == 0) { l = n; }
			else { l = i - 1; }
			if (i + 1 == n + 1) { r = 1; }
			else { r = i + 1; }
			if (j + 1 == m + 1) { v = 1;}
			else { v = j + 1; }
			if (j - 1 == 0) { d = m; }
			else { d = j - 1; }
			if ((a[r][j] > a[i][j]) && (a[l][j] > a[i][j])
				&& (a[i][v] > a[i][j]) && (a[i][d] > a[i][j]) && (a[r][v]>a[i][j])&& (a[r][d] > a[i][j])&& (a[l][v] > a[i][j])&& (a[l][d] > a[i][j]))
			{
				
				printf("%i %i \n", i, j);
				k += 1;
			}
		}
	}
	if (k==0) { printf("0"); }
	else {
		printf("%i", k);
	}
}
