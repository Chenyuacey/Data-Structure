/*����50��0-20�ڵ���������ÿ�������ִ�����Ƶ��*/ 
#include<stdio.h>
#include<time.h>
#include<stdlib.h> 
#define N 50
void create(int ar[]); 
void print(int ar[]);
void count(int num[],int data[]);

int main(){
	int data[N+1],num[20]={0};
	printf("��50����Ϊ:\n");
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
		printf("%d ���ֵĴ���Ϊ %d\n",i,ar[i]);
	}
	printf("\n");
}
void count(int num[],int data[]){
	for(int i=1;i<N;i++){
		num[data[i]]++;
	}
}
