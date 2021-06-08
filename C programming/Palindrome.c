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
	int rez=0;
	int len2 = 0;
	for (int i = 0; i < len; ++i)
	{
	    if(str[i]!=' '){str2[k]=str[i]; k+=1;len2+=1;}
	}
	k=0;
	for (int i = 0; i < len2; ++i)
	{
	    if(str2[i]==str2[len2-1-k]){k+=1;}
	    else{rez+=1;}
	}
	if (rez==0){printf("yes");}
	else {printf("no");}

	    
	}
