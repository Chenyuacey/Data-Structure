#include<stdio.h>
#define N 15
/*���η� �ݹ�   �ڿ�����   �򵥰汾 */ 
void quick_sort(int ar[],int l,int r);
int main(){
	int text[N]={3,44,38,5,47,15,36,26,27,2,46,4,19,50,48};
    quick_sort(text,0,N-1);
    for(int i=0;i<N;i++) printf("%d ",text[i]);
	return 0;
}

void quick_sort(int ar[],int l,int r){
        if(l<r){
        	int i=l,j=r,x=ar[i];   //x�ӵ�һ��Ԫ�ؿ�ʼ 
			while(i<j){
				while(i<j&&ar[j]>=x) j--;
				if(i<j) ar[i++]=ar[j];
				
				while(i<j&&ar[i]<x) i++;
				if(i<j) ar[j--]=ar[i];
			}
        	ar[i]=x;
        	quick_sort(ar,l,i-1);
        	quick_sort(ar,i+1,r);
		}
}
