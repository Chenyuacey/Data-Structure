#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define N 15
void bubblesort_1(int ar[]);//ð������ 
void bubblesort_2(int ar[]);//ð������Ľ�1����־����pos,��ʱ��3����û������
void bubblesort_3(int ar[]); //ð������Ľ�2��˫��ð�ݣ���ʱ��2���� 
int main(){
	int text[N]={3,44,38,5,47,15,36,26,27,2,46,4,19,50,48};
	int i,n=N;
	printf("����text��֪�������\n");
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
        for(j=low;j<high;++j) //����ð��,�ҵ������
            if(ar[j]>ar[j+1]) {
                temp=ar[j];ar[j]=ar[j+1];ar[j+1]=temp;
            }
        --high;                 //�޸�highֵ, ǰ��һλ
        for(j=high;j>low;--j) //����ð��,�ҵ���С��
            if(ar[j]<ar[j-1]) {
                temp=ar[j];ar[j]=ar[j-1];ar[j-1]=temp;
            }
        ++low;                  //�޸�lowֵ,����һλ
    }
}
