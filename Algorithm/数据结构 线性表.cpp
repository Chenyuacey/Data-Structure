//数据结构  线性表的实现 
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define Elemtype int
int N =10;
void create_list(int ar[]);
void search1_list(int ar[],Elemtype x);//按数值查找 
int  search2_list(int ar[],int place);//按位置查找 
void insert1_list(int ar[],int place,int y);//按位置插入 第i个之前 
void insert2_list(int ar[],Elemtype x);//有序表按数值插入 
void delete1_list(int ar[],int place);//按位置删除
void delete2_list(int ar[],int y);//按数值删除 
void quick_sort(int ar[],int l,int r);
void printl_list(int ar[]); 


int main(){
	int num[11];
	create_list(num);
	printl_list(num);
	int x; 
	//scanf("%d",&x);
	search1_list(num,5);
	int place;
	//scanf("%d",&place); 
	printf("NO.%d is %d\n",5,search2_list(num,5));
	insert1_list(num,5,199) ;
	printl_list(num);
	delete1_list(num,5);
	printl_list(num);
    quick_sort(num,0,N-1);
	printl_list(num);
	insert2_list(num,10) ;
	printl_list(num);
	delete2_list(num,10);
	printl_list(num);
	return 0;
} 


void create_list(int ar[]){
	srand(time(0));
	for(int i=0;i<N;i++){
		ar[i]=rand()/1000;
	}
}

void printl_list(int ar[]){
	for(int i=0;i<N;i++) printf("%d ",ar[i]);
	printf("\n");
}

void search1_list(int ar[],Elemtype x){
	int flag=1;
	for(int i=0;i<N;i++){
		if(ar[i]==x){
			printf("%d is in list.\n",x);
			flag=0;
			break;
		}
	}
    if(flag) printf("%d is not in list.\n",x);
}

int search2_list(int ar[],int place){
	return ar[place-1];
}

void insert1_list(int ar[],int place,int y){
	int i;
	for( i=N-1;i>place-2;i--){
		ar[i+1]=ar[i];
	} 
	ar[i+1]=y;
	N++;
}
 
void delete1_list(int ar[],int place){
	for(int i=place;i<N;i++) ar[i-1]=ar[i];
	N--;
}

void insert2_list(int ar[],int y){
	int i;
	for(i=N-1;y<ar[i];i--) ar[i+1]=ar[i];
	ar[i+1]=y;
	N++;
}

void delete2_list(int ar[],int y){
	int i,k;
	for(i=0;i<N;i++) {
		if(ar[i]==y) k=i;
	} 
	for(i=k+1;i<N+1;i++) ar[i-1]=ar[i];
    N--;
}


void quick_sort(int ar[],int l,int r){
        if(l<r){
        	int i=l,j=r,x=ar[i];   
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
