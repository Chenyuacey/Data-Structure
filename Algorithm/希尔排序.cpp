#include<stdio.h>
#include<stdlib.h>
#define N 15
/*缩小增量排序   插入排序的一种变形*/ 
/*需要多看多研究！*/ 
void shellsort_1(int ar[]);
int main(){
	int text[N]={3,44,38,5,47,15,36,26,27,2,46,4,19,50,48};
	shellsort_1(text);
	for(int i=0;i<N;i++) printf("%d ",text[i]);
	return 0;
} 

void shellsort_1(int ar[]){
	int gap,i,j,temp;
	for(gap=N/2;gap>0;gap/=2){
		for(i=gap;i<N;i++){
			temp=ar[i];
			for(j=i-gap;j>=0&&temp<ar[j];j-=gap) ar[j+gap]=ar[j];
			ar[j+gap]=temp;        //????
		}
	}
	
	
}
