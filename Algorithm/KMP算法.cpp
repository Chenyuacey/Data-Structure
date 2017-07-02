#include<stdio.h>
#include<string.h>
void get_next(char br[],int *next);
int index_KMP(char ar[],char br[],int pos);
int main(){
	char ar[255],br[255];
	int ans;
	scanf("%s %s",ar,br);
	ans=index_KMP(ar,br,0);
	printf("%d\n",ans+1);
	
 	return 0;
} 
void get_next(char br[],int *next){
	int i,j;
	i=1;j=0;
	next[1]=0;
	while(i<strlen(br)){
		if(j==0||br[i]==br[j])
		{
			++i;
			++j;
			next[i]=j;
		}
		else j=next[j];
	}
}

int index_KMP(char ar[],char br[],int pos){
	int next[255];
	int i=pos,j=1;
	get_next(br,next);
	while(i<=strlen(ar)&&j<=strlen(br)){
		if(ar[i]==br[j]){
			i++;j++;
		}
		else j=next[j];
	}
	if(j>strlen(br)) return i-strlen(br);
	else return 0;
}
