#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#define x 100

int main()
{
	int n;
	int m;
	int sum = 0;
	int stolb = 0;
	int z;
	int c;
	scanf("%i", &n);
	int a[x][x] = {0};
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			scanf("%i", &a[i][j]);
		}
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (a[i][j] == 0)
			{
				for (int z = 0; z < n; ++z)
				{
					c = a[j][z];
					a[j][z] = a[i][z];
					a[i][z] = c;
				}
			}
		}
	}
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{

			printf("%i ", a[i][j]);
		}
		printf("\n");
	}
}
