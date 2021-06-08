#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define x 100

int main()
{
	int n;
	int m;
	scanf("%i%i", &n, &m);
	int a[x][x] = {0};
	int b[x][x] = { 0 };
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			scanf("%i", &a[i][j]);
		}
	}
	for (int i = 0; i < m; ++i)
	{
	
	
			for (int j = 0; j < n; ++j)
			{
				if (i != j)
				{
					b[i][j] = a[j][i];
				}
				else { b[i][j] = a[i][j]; }
				printf("%i ", b[i][j]);
			}
		
		printf("\n");
	}
}
