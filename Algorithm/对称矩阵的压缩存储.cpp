#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 4 
int Value(int b[], int i, int j)
{
    if (i>=j)
        return b[(i*(i+1))/2+j];
    else
        return b[(j*(j+1))/2+i];
}
int main(){
	int M=N*(N+1)/2,i,j,k=0;
	int ar[N][N],br[M];
	int cn[N][N];
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			scanf("%d",&ar[i][j]); 
		}
	}
	//Ñ¹Ëõ 
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			if(i+1==j) break; 
			br[k++]=ar[i][j];
		}
	}
	printf("\nbr=");
	for(i=0;i<M;i++) printf("%d ",br[i]);
	printf("\n\n");
	printf("»¹Ô­ºó£º\n");
	for (i=0; i<N; i++)
    {
        for (j=0; j<N; j++)
            printf("%d ",Value(br,i,j));
        printf("\n");
    }
	
	return 0;
}








/*1 5 6 7  
  5 2 8 9 
  6 8 3 0 
  7 9 0 4*/
