#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#define x 100

int main()
{
	int n;
	int m;
	int sum = 0;
	int leftX, leftY, rightX, rightY;
	scanf("%i %i", &n, &m);
	scanf("%i %i", &leftX, &leftY);
	scanf("%i %i", &rightX, &rightY);
	int a[x][x] = {0};
	for (int i = 1; i < n+1; ++i)
	{
		for (int j = 1; j < m+1; ++j)
		{
			scanf("%i", &a[i][j]);
			if (i >= leftX && i <= rightX && j >= leftY && j <= rightY)
			{
				sum = sum + a[i][j];
			}
		}
	}


		printf("%i", sum);
}
