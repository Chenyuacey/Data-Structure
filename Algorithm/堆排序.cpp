#include<stdio.h>
#include<stdlib.h>
int ar[10000];
int n;

void swap(int ar[],int i,int j){
	int temp;
	temp=ar[i];ar[i]=ar[j];ar[j]=temp;
}

void Heap_Adjust(int ar[],int s,int m){
	int temp,j;
	temp=ar[s];
	for(j=2*s;j<=m;j*=2){
	if(j<m&&ar[j]<ar[j+1])
		j++;
	if(temp>=ar[j])
		break;
	ar[s]=ar[j];
	s=j;
	}
	ar[s]=temp;
}

void Heap_Sort(int ar[]){
	int i;
	for(int i=n/2;i>0;i--) Heap_Adjust(ar,i,n);
	for(int i=n;i>1;i--){
		swap(ar,1,i);
		Heap_Adjust(ar,1,i-1);
	}
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&ar[i]);
	Heap_Sort(ar);
	for(int i=1;i<=n;i++) printf("%d ",ar[i]);
	return 0;
} 
