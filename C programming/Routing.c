#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define SIZE 100
typedef struct SETADRESS
{
	char adress[20];
	char maska[20];
	char shlus[20];
	char interface[20];
}SETADRESS;

int main()
{
	FILE* in;
	FILE* out;
	in = fopen("input.txt", "r");
	out = fopen("output.txt", "w");
	char str[1000] = { 0 };
	int n=0;
	SETADRESS table[100];
	int t = 0;
	fscanf(in, "%d", &n);
	fgets(str, 1000, in);
	fgets(str, 1000, in);
	for (int i = 0; i < n-1; ++i)
	{
		fgets(str, 1000, in);
		int j = 0, q=0;
		while (str[j] == ' ') { j += 1; }
		while (str[j] != ' ') { table[t].adress[q] = str[j]; q += 1; j += 1; }
		table[t].adress[q] = '\0';
		while (str[j] == ' ') { j += 1; }
		q = 0;
		while (str[j] != ' ') { table[t].maska[q] = str[j]; q += 1; j += 1; }
		table[t].maska[q] = '\0';
		while (str[j] == ' ') { j += 1; }
		q = 0;
		while (str[j] != ' ') { table[t].shlus[q] = str[j]; q += 1; j += 1; }
		table[t].shlus[q] = '\0';
		while (str[j] == ' ') { j += 1; }
		q = 0;
		while (str[j] != ' ') { table[t].interface[q] = str[j]; q += 1; j += 1; }
		table[t].interface[q] = '\0';
		t += 1;
	}
	int n2 = 0;
	fscanf(in, "%d", &n2);
	//fgets(str, 1000, in);
	fgets(str, 1000, in);
	for (int i = 0; i < n2; ++i)
	{
		fgets(str, 1000, in);
		int j = 0, q = 0;
		char ip[20];
		char mask[20];
		while (str[j] == ' ') { j += 1; }
		while (str[j] != ' ') { ip[q] = str[j]; q += 1; j += 1; }
		ip[q] = '\0';
		while (str[j] == ' ') { j += 1; }
		q = 0;
		while (str[j] != ' ' && str[j]!='\0') {mask[q] = str[j]; q += 1; j += 1; }
		mask[q] = '\0';
		int a = 0,a2=0, q1=0, q2=0;
		char set_adress[20]; int k = 0;
		for (int i = 0; i < 4; ++i)
		{
			while (ip[q1] != '.' && ip[q1] != '\0') { a = 10 * a + ((int)ip[q1] - 48); q1 += 1; }q1 += 1;
			while (mask[q2] != '.' && mask[q2] != '\0' && mask[q2] != '\n') { a2 = 10 * a2 + ((int)mask[q2] - 48); q2 += 1; }q2++;
			int a3 = a & a2;
			a = 0; a2 = 0;
			if (a3 < 10) { set_adress[k] = (a3 % 10) + 48; k++; }
			if (a3 >= 10 && a3 < 100) { set_adress[k+1] = (a3 % 10) + 48; a3 /= 10; set_adress[k] = (a3 % 10) + 48; k+=2; }
			if (a3 >= 100) { set_adress[k + 2] = (a3 % 10) + 48; a3 /= 10; set_adress[k + 1] = (a3 % 10) + 48; a3 /= 10;  set_adress[k] = (a3 % 10) + 48; k+=3; }
			if (i != 3) { set_adress[k] = '.'; k += 1; }
			else{ set_adress[k] = '\0'; }
		}
		fprintf(out, "%s ",set_adress);
		int c=0;
		for (int i = 0; i < n; ++i)
		{
			if (strcmp(table[i].adress, set_adress) == 0) { fprintf(out, "%s\n", table[i].interface); c += 1; }
		}
		if(c==0){ fprintf(out, "%s\n", table[0].interface); }
	}
}
