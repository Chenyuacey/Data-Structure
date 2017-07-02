/*生成50个0-20内的数，计算每个数出现次数和频率*/ 
#include<stdio.h>
#include<time.h>
#include<stdlib.h> 
#define N 50
void create(int ar[]); 
void print(int ar[]);
void count(int num[],int data[]);

int main(){
	int data[N+1],num[20]={0};
	printf("这50个数为:\n");
	create(data);
	count(num,data);
	print(num);
	return 0;
} 

void create(int ar[]){
	srand(time(0));
	for(int i=1;i<=N;i++) {
	ar[i]=rand()%20;
	printf("%d ",ar[i]);
	}
    ar[0]=N;
    printf("\n");
}
void print(int ar[]){
	for(int i=0;i<20;i++){
		printf("%d 出现的次数为 %d\n",i,ar[i]);
	}
	printf("\n");
}
void count(int num[],int data[]){
	for(int i=1;i<N;i++){
		num[data[i]]++;
	}
}
