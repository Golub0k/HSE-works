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
	scanf("%i%i", &n, &m);
	int a[x][x] = {0};
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			scanf("%i", &a[i][j]);
		}
	}
sum = -1000000;
stolb = 0;
int sum2 = 1000000;
int stolb2 = 0;
	for (int j = 0; j<m;++j)
	{
		int s = 0;
		for (int i = 0; i < n; ++i)
		{
			s += a[i][j];
		}
		printf("%i ",s);
		if (s > sum) {
		sum = s;
		stolb = j;
		}
		if (s<sum2){
			sum2 = s;
			stolb2 = j;
		}
	}

	for (int i = 0; i < n; ++i)
	{
		z = a[i][stolb];
		a[i][stolb] = a[i][stolb2];
		a[i][stolb2] = z;
	}
	printf("\n");
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{

			printf("%i ", a[i][j]);
		}
		printf("\n");
	}
}
