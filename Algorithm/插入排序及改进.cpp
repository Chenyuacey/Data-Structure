#include<stdio.h>
#include<stdlib.h>
#define N 15
void Insertsort_1(int ar[]);//��������
void Insertsort_2(int ar[]);//���ֲ������� ����ѧ�� /*��ȥ�о�����*/ 
void Insertsort_3(int ar[]);
int main(){
	int text[N]={3,44,38,5,47,15,36,26,27,2,46,4,19,50,48};
    Insertsort_3(text);
    for(int i=0;i<N;i++) printf("%d ",text[i]);
	return 0;
}

void Insertsort_1(int ar[]){
	int key,i,j;
	for(i=1;i<N;i++){
		key=ar[i];
	j=i-1;                         //�Ӵ�Ԫ�ص�ǰһ��λ��������ǰ�Ƚ� 
	while(j>=0&&key<ar[j]){        //ע��������� 
		ar[j+1]=ar[j];             //����Ԫ�غ��� 
		j--;                       //ע��j--λ�� 
	}	
	ar[j+1]=key;                   //���� 
    }
} 

void Insertsort_2(int ar[]){
	int i,j,middle,left,right,key;
	for(i=1;i<N;i++){
		key=ar[i],left=0,right=i-1;
		while(left<=right){                           
		     middle=(left+right)/2;  
		     if(key<ar[middle]) right=middle-1;       //-1��       
		     else left=middle+1;                      //+1�� 
		}
		for(j=i-1;j>=left;j--){                      //���ں� ��  
			ar[j+1]=ar[j];              
		}
		ar[left]=key;                                //left�� 
	}
}

void Insertsort_3(int ar[]){
	int key,i,j;
	for(i=1;i<N;i++){
		key=ar[i];
	j=i-1;                         //�Ӵ�Ԫ�ص�ǰһ��λ��������ǰ�Ƚ� 
	while(j>=0&&key>ar[j]){        //ע��������� 
		ar[j+1]=ar[j];             //����Ԫ�غ��� 
		j--;                       //ע��j--λ�� 
	}	
	ar[j+1]=key;                   //���� 
    }
} 

