#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define SIZE 10000

int main()
{
    char str[SIZE] = { 0 };
	fgets(str, SIZE, stdin);
    int len = strlen(str) - 1;
	str[len] = '\0';
	char str2[SIZE] = { 0 };
	str2[len] = '\0';
	int k = 0;
	for (int i = 0; i < len; ++i)
	{
	    if((i+1)%2==1){str2[k]=str[i]; k+=1;}
	}
	for (int i = 0; i < len; ++i)
	{
	    if((i+1)%2==0){str2[k]=str[i]; k+=1;}
	}
	printf("%s\n", str2);
}
