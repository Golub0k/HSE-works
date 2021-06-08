#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 100000
int StrLen(const char* s)
{
	int i = 1;
	int k = 0;
	while (s[i++])
	{
		if (s[i] == ' ' && s[i - 1] != ' ') { k += 1; }
	};
	if (s[strlen(s) - 1] != ' ') { k += 1; }
	return k;
}
int main()
{
	char str[SIZE] = { 0 };
	fgets(str, SIZE, stdin);
	str[strlen(str) - 1] = '\0';
	printf("%d\n", StrLen(str));
}
