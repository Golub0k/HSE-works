#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define x 200

void SetM(int arr[][x], int n, int m)
{
	for (unsigned i = 0; i < n + 2; ++i)
	{
		for (unsigned j = 0; j < m + 2; ++j)
		{
			if (j == 0 || j == m + 1 || i == 0 || i == n + 1) { arr[i][j] = -1; }
			else
			{
				scanf("%i", &arr[i][j]);
			}
		}
	}
}
void CopB(int arr[][x], int b[][x], int n, int m)
{
	for (unsigned i = 0; i < n + 2; ++i)
	{
		for (unsigned j = 0; j < m + 2; ++j)
		{
			b[i][j] = arr[i][j];
		}
	}
}
void PrintM(const int arr[][x], int n, int m)
{
	for (unsigned i = 1; i < n + 1; ++i)
	{
		for (unsigned j = 1; j < m + 1; ++j)
		{
			if (arr[i][j] == 1) {printf("x");}
			else { printf(" "); }
		}
		printf("\n");
	}
}
int Zizn(const int a[][x],int i, int j, int n, int m)
{
	int v, d, l, r;
	int k = 0;
			if (i - 1 == 0) { l = n; }
			else { l = i - 1; }
			if (i + 1 == n + 1) { r = 1; }
			else { r = i + 1; }
			if (j + 1 == m + 1) { v = 1; }
			else { v = j + 1; }
			if (j - 1 == 0) { d = m; }
			else { d = j - 1; }
			if (a[r][j] == 1) { k += 1; }
			if (a[l][j] == 1) { k += 1; }
			if (a[i][v] == 1) { k += 1; }
			if (a[i][d] == 1) { k += 1; }
			if (a[r][v] == 1) { k += 1; }
			if (a[r][d] == 1) { k += 1; }
			if (a[l][v] == 1) { k += 1; }
			if (a[l][d] == 1) { k += 1; }
	return(k);
}
int End(int arr[][x], int n, int m)
{
	int e = 0;
	for (int i = 1; i < n + 1; ++i)
	{
		for (int j = 1; j < m + 1; ++j)
		{
			if (arr[i][j] == 1) {e += 1;}
		}
	}
	return(e);
}
int main()
{
	int n, m;
	int k = 0;
	int h = 0;
	int e = 1;
	scanf("%i%i", &n, &m);
	int a[x][x];
	int b[x][x];
	SetM(a, n, m);
	int t = 0;
	int q = 0;
	while (e>0)
	{
		t += 1;
		e = 0;
		CopB(a, b, n, m);
		for (unsigned i = 1; i < n + 1; ++i)
		{
			for (unsigned j = 1; j < m + 1; ++j)
			{
				if (b[i][j] == 0 && (Zizn(b, i, j, n, m) == 3)) { a[i][j] = 1; q += 1; };
				if (b[i][j] == 1 && ((Zizn(b, i, j, n, m) > 3) || (Zizn(b, i, j, n, m) < 2))) { a[i][j] = 0; q += 1; }
				if (a[i][j] == 1) { h += 1; }
			}
		}
		e = End(a, n, m);
		if (e == 0) { printf("End life step %i", t); break; }
		if (t == 1 || t == 10 || t==100|| t==1000) {
			printf("Step %i: alives %i\n", t, h);
			PrintM(a, n, m);
		}
		h = 0;
		if ( q == 0 || t==1000) { printf("End life step %i", t); break; }
		q = 0;
	}
}
