#include<stdio.h>
#include<stdlib.h>
#define N 15
void Insertsort_1(int ar[]);//插入排序
void Insertsort_2(int ar[]);//二分插入排序 （玄学） /*多去研究二分*/ 
void Insertsort_3(int ar[]);
void BubbleSort(int ar[]);
void SerchSort(int ar[]);
int main(){
	int text[N]={3,44,38,5,47,15,36,26,27,2,46,4,19,50,48};
    SerchSort(text);
    for(int i=0;i<N;i++) printf("%d ",text[i]);
	return 0;
}

void Insertsort_1(int ar[]){
	int key,i,j;
	for(i=1;i<N;i++){
		key=ar[i];
	j=i-1;                         //从此元素的前一个位置依次向前比较 
	while(j>=0&&key<ar[j]){        //注意入口条件 
		ar[j+1]=ar[j];             //数组元素后移 
		j--;                       //注意j--位置 
	}	
	ar[j+1]=key;                   //插入 
    }
} 

void Insertsort_2(int ar[]){
	int i,j,middle,left,right,key;
	for(i=1;i<N;i++){
		key=ar[i],left=0,right=i-1;
		while(left<=right){                           
		     middle=(left+right)/2;  
		     if(key<ar[middle]) right=middle-1;       //-1玄       
		     else left=middle+1;                      //+1玄 
		}
		for(j=i-1;j>=left;j--){                      //等于号 玄  
			ar[j+1]=ar[j];              
		}
		ar[left]=key;                                //left玄 
	}
}

void Insertsort_3(int ar[]){
	int key,i,j;
	for(i=1;i<N;i++){
		key=ar[i];
	j=i-1;                         //从此元素的前一个位置依次向前比较 
	while(j>=0&&key>ar[j]){        //注意入口条件 
		ar[j+1]=ar[j];             //数组元素后移 
		j--;                       //注意j--位置 
	}	
	ar[j+1]=key;                   //插入 
    }
} 

void BubbleSort(int ar[])
{
	int i=N-1,j,temp;
	while(i>0){
	int pos=0;
	for(j=0;j<i;j++){
		if(ar[j]<ar[j+1]){
				temp=ar[j];ar[j]=ar[j+1];ar[j+1]=temp;
				pos=j;
		}
	}
	i=pos;
    }
}
void SerchSort(int ar[])
{
	int i,j;
	for (j = 0; j < N-1; j++) 
  	{
    	int iMax = j;
    	for (i = j+1; i < N; i++) {
        	if (ar[i] >ar[iMax]) {
            iMax = i;
        }
    }
    if(iMax != j) {
    	int temp;
    	temp=ar[j];
    	ar[j]=ar[iMax];
    	ar[iMax]=temp;
	}
}
}

