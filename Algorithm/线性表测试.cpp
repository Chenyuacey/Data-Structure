#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define MAXN 5
#define OK 1
int i; 
typedef int Cchange;
typedef int Status;
typedef struct{
	int length;
	int data[MAXN];
}SqList;
Status Get(SqList L,int i,Cchange *e)
{
	if(L.length==0||i<1||i>L.length) return 0;
	*e=L.data[i-1];
	return OK;
  }  
Status Insert(SqList *L,int i,Cchange e) 
{
	int k;
	if(L->length==MAXN) return 0;
	if(i<1||i>L->length+1) return 0;                       //���ʣ�Ϊ��Ϊ1/length+1' 
	if(i<=L->length)
	{
		for(k=L->length-1;k>=i-1;k--) L->data[k+1]=L->data[k];
	}
	L->data[i-1]=e;
	L->length++;
	return OK;
 } 
Status Delete(SqList *L,int i,Cchange *e){
 	int k;
 	if(L->length==0) return 0;
 	if(i<1||i>L->length+1) return 0;                       //���ʣ���Ϊ��Ϊ1/length?
	*e=L->data[i-1];
	if(i<L->length)
	{
		for(k=i;k<L->length;k++) L->data[k-1]=L->data[k];
	  }  
	  L->length--;
	  return OK;
 }
 int main(){
 	SqList a;
 	int i,n,h,k;
 	Cchange *p=&i;
 	Status de=0;
 	for(i=0;i<MAXN;i++) 
 	scanf("%d",&a.data[i]);
 	a.length=MAXN;
 	//printf("%d\n",a.length);
	for(i=0;i<MAXN;i++) 
    printf("%d ",a.data[i]);
    printf("\n��������Ҫɾ������λ�ã�\n");
    scanf("%d",&n); 
 	de=Delete(&a,n,p);
 	printf("����Ϊ:%d\n",*p);
 	printf("ɾ��һ����������Ա�Ϊ��\n"); 
	for(i=0;i<a.length;i++) printf("%d ",a.data[i]); 
	printf("\n������λ�ã�����\n");
	scanf("%d %d",&h,&k);
	Insert(&a,h,k);
	printf("���һ����������Ա�Ϊ��\n"); 
	for(i=0;i<a.length;i++) printf("%d ",a.data[i]); 
 	return 0;
 }
