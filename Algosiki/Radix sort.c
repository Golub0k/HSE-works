#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define X 100
void swap(char arr[X][X],int k,int max,int size[])
{
	char s[X];
	for(int i=0;i<max;i++){
		s[i]=arr[k][i];
		arr[k][i]=arr[k+1][i];
		arr[k+1][i]=s[i];
	}

	int tmp=size[k];
	size[k]=size[k+1];
	size[k+1]=tmp;
}
void null2(char arr[X][X],int N,int max)
{
	for(int i=0;i<N;i++)
	{
		while(arr[i][0]=='0')
		{
			for(int j=0;j<strlen(arr[i])-1;j++)
				arr[i][j]=arr[i][j+1];
			arr[i][strlen(arr[i])-1]='\0';
		}
	}
}

void null(char arr[X][X],int N, int max)
{
	for(int i=0;i<N;i++)
	{
		if(strlen(arr[i])<max){ int size=strlen(arr[i]);
			while(strlen(arr[i])<max)
			{
				for(int j=strlen(arr[i]);j>0;j--)
					arr[i][j]=arr[i][j-1];
				arr[i][0]='0';
			}
		}
	}
}
void radix(char a[X][X], int n, int size[])
{
	int max=strlen(a[n-1]);
	for(int i=0;i<n;i++)
		if(strlen(a[i])>max)
			max=strlen(a[i]);
	for(int i=max-1;i>=0;i--)
	{
		printf("Sorting by %d digit:\n",i);
		null(a,n,max);
		for(int j=0;j<n-1;j++)
			for(int k=0;k<n-j-1;k++)
				if((a[k][i]>a[k+1][i])||((a[k][i]==a[k+1][i])&&(size[k]>=(max-i)))&&(size[k+1]<(max-i))){
					swap(a,k,max,size);
				}
		null2(a,n,max);
		for(int j=0;j<n;j++)
    		printf("%s\n", a[j]);
		printf("\n");
	}
}

int main()
{
	int n;
	scanf("%d",&n);
	char str[X][X];
	for(int i=0;i<n;i++) {scanf("%s",str[i]);}
	int arr[X];
	for(int i=0;i<n;i++) {arr[i]=strlen(str[i]);}
	radix(str, n, arr);
	
}
