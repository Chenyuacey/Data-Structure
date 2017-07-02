#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define N 15
void bubblesort_1(int ar[]);//冒泡排序 
void bubblesort_2(int ar[]);//冒泡排序改进1，标志变量pos,耗时短3倍（没看懂）
void bubblesort_3(int ar[]); //冒泡排序改进2，双向冒泡，耗时与2类似 
int main(){
	int text[N]={3,44,38,5,47,15,36,26,27,2,46,4,19,50,48};
	int i,n=N;
	printf("数列text已知，排序后：\n");
	bubblesort_3(text);
	for(i=0;i<n;i++) printf("%d ",text[i]);
	return 0;
} 

void bubblesort_1(int ar[]){
	int i,j,temp,n=N;
	for(i=0;i<n-1;i++){
		for(j=0;j<n-1-i;j++){
			if(ar[j]>ar[j+1]){
				temp=ar[j];
				ar[j]=ar[j+1];
				ar[j+1]=temp;
			}
		}
	}
}

void bubblesort_2(int ar[]){
	int n=N;
	int i=n-1,j,temp;
	while(i>0){
	int pos=0;
	for(j=0;j<i;j++){
		if(ar[j]>ar[j+1]){
				temp=ar[j];ar[j]=ar[j+1];ar[j+1]=temp;
				pos=j;
		}
	}
	i=pos;
    }
}

void bubblesort_3(int ar[]){
	int n=N,j,temp;
	int high=n-1,low=0;
	while(low<high) {
        for(j=low;j<high;++j) //正向冒泡,找到最大者
            if(ar[j]>ar[j+1]) {
                temp=ar[j];ar[j]=ar[j+1];ar[j+1]=temp;
            }
        --high;                 //修改high值, 前移一位
        for(j=high;j>low;--j) //反向冒泡,找到最小者
            if(ar[j]<ar[j-1]) {
                temp=ar[j];ar[j]=ar[j-1];ar[j-1]=temp;
            }
        ++low;                  //修改low值,后移一位
    }
}
