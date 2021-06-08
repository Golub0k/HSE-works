#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(){
	int N,b;
	scanf("%d",&N);
	double arr[N],buck[2*N][N],arr2[N], t;
	int ind[2*N];
	for(int i=0;i<N; i++)
		scanf("%lf",&arr[i]);
	printf("Initial array:\n");
	for(int i=0;i<N;i++)
		printf("%.2lf ", arr[i]);
	printf("\n\n");
	double min=arr[0],max=arr[0];
	for(int i=0;i<N; i++){
		if(arr[i]>max)
			max=arr[i];
		if(arr[i]<min)
			min=arr[i];
	}
	for(int i=0;i<2*N;i++)
		ind[i]=0;
	int n_b;
	for(int i=0;i<N;i++)
	{
		n_b=(int)(((arr[i]-min)*2*N)/(max-min));
		if(arr[i]==max)
		{
			buck[2*N-1][ind[2*N-1]]=arr[i];
			ind[2*N-1]+=1;
		}
		else
		{
			buck[n_b][ind[n_b]]=arr[i];
			ind[n_b]+=1;
		}
	}
	for(int i=0;i<2*N;i++){
		for(int j=0;j<ind[i];j++)
			arr2[j]=buck[i][j];
		if(ind[i]!=0){
			printf("Bucket:\n");
			for(int j=0;j<ind[i];j++)
				printf("%.2lf ",arr2[j]);
		    printf("\n");
        }
	for (int u = 1; u < ind[i]; u++){
		t = arr2[u];
		for (int j = u - 1; j >= 0; j--)
		{
			if (arr2[j] < t)
				break;
		arr2[j + 1] = arr2[j];
        arr2[j] = t;
		}
	}

		if(ind[i]!=0){
			printf("Sorted bucket:\n");
			for(int j=0;j<ind[i];j++)
				printf("%.2lf ",arr2[j]);
		    printf("\n\n");
        }
		for(int j=0;j<ind[i];j++)
			buck[i][j]=arr2[j];
	}
	int k=0;
	for(int i=0;i<2*N;i++)
		for(int j=0;j<ind[i];j++)
			arr[k++]=buck[i][j];
	printf("Final array:\n");
	for(int i=0;i<N;i++)
		printf("%.2f ", arr[i]);
}
