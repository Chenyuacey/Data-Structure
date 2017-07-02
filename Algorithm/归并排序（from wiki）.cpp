#include<stdio.h>
#include<stdlib.h>
/*分治法 递归调用*/ 
void merge_sort_recursive(int arr[],int reg[],int start,int end);
void merge_sort(int arr[],const int len); 
int main(){
    int text[15]={3,44,38,5,47,15,36,26,27,2,46,4,19,50,48};
    merge_sort(text,15);
    for(int i=0;i<15;i++) printf("%d ",text[i]);
	return 0;
}

void merge_sort(int arr[],const int len){
	int reg[len];
	merge_sort_recursive(arr,reg,0,len-1);
} 

void merge_sort_recursive(int arr[],int reg[],int start,int end){
	if(start>=end) return ;
	int len=end-start;
	int mid=start+len/2;
	int start1=start,end1=mid;
	int start2=mid+1,end2=end;
	merge_sort_recursive(arr,reg,start1,end1);
	merge_sort_recursive(arr,reg,start2,end2);
	int k=start;
	while(start1<=end1&&start2<=end2) 
	    reg[k++]= arr[start1]<arr[start2]?arr[start1++]:arr[start2++];
	while(start1<=end1) 
	    reg[k++]= arr[start1++];
	while(start2<=end2)
	    reg[k++]= arr[start2++];
	for(int i=start;i<=end;i++)
	    arr[i]=reg[i]; 	    
}
