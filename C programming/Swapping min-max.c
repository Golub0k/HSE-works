#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#define x 100

int main()
{
	int n;
	int m;
	int max = 0;
	int min = 100000;
	int i1, i2, j1, j2;
	int z;
	scanf("%i%i", &n, &m);
	int a[x][x] = {0};
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			scanf("%i", &a[i][j]);
		}
	}
	for (int i = 0; i < n; ++i)
	{
			for (int j = 0; j < m; ++j)
			{
				if (abs(a[i][j]) >= max)
				{
					max = abs(a[i][j]); i1 = i; j1 = j;
				}
				if (abs(a[i][j]) <= min)
				{
					min = abs(a[i][j]); i2 = i; j2 = j;
				}
			}

	}
	z = a[i1][j1];
	a[i1][j1] = a[i2][j2];
	a[i2][j2] = z;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			printf("%i ", a[i][j]);
		}
		printf("\n");
	}
}
