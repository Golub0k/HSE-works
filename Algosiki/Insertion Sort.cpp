#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define x 1000
int main()
{
	int n;
	int m;
	int k = 1;
	scanf("%int", &n);
	printf("Initial array:\n");
	int a[x] = { 0 };
	for (int i = 0; i < n; ++i)
	{
		scanf("%i", &a[i]);
		printf("%i ", a[i]);

	}
	printf("\n");
	for (int i = 0; i < n; ++i)
	{
		if (a[i + 1] < a[i] && i!=n-1)
		{
			printf("Insertion - Element #%d\n", i+1);
			k += 1;
			m = a[i];
			a[i] = a[i + 1];
			a[i + 1] = m;
			for (int j = i; j > 0; --j)
			{
				if (a[j] < a[j - 1])
				{
					m = a[j];
					a[j] = a[j - 1];
					a[j - 1] = m;
				}
			}
			for (int z = 0; z < n; ++z)
			{
				printf("%i ", a[z]);

			}
			printf("\n");
		}
		else
		{
			if (i != n - 1)
			{
				printf("Insertion - Element #%d\n", i + 1);
				for (int z = 0; z < n; ++z)
				{
					printf("%i ", a[z]);

				}
				printf("\n");
			}

		}
	}
}
