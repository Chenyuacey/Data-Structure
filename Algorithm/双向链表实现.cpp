#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>
#define Elemtype int
typedef struct D_linklist{
	Elemtype data;
	struct D_linklist *front,*next;
}DL;
DL *create_DL(int n);//����˫������ 
void print_DL(DL *p);
DL *insert_DL(DL *p,int place,Elemtype e);//�������� 
DL *delete_DL(DL *p,int place); 
int main(){
	DL *head;
	int e,place,n;
	printf("������˫������Ԫ�ظ�����"); 
	scanf("%d",&n);
	head=create_DL(n);
	printf("�½�������Ϊ��\n");
	print_DL(head);
	printf("���������λ�ú�Ԫ��ֵ��"); 
	scanf("%d %d",&place,&e);
	head=insert_DL(head,place,e);
	printf("����������Ϊ��\n"); 
	print_DL(head);
	printf("������ɾ��Ԫ�ص�λ�ã�"); 
	scanf("%d",&place);
	head=delete_DL(head,place);
	printf("ɾ���������Ϊ��\n"); 
	print_DL(head); 
	return 0;
}  

DL *create_DL(int n){
	DL *p,*q;
	srand(time(0));
	p=(DL*)malloc(sizeof(DL));
	p->next=p->front=NULL;
	q=p;
	for(int i=1;i<=n;i++){
		q->next=(DL*)malloc(sizeof(DL));
		q->next->front=q;
		q=q->next;
		q->data=rand()/1000;
	}
	q->next=NULL;
	return p;
}
void print_DL(DL *p){
	DL *q;
	q=p->next;
	if(!q) printf("Empty DL");
	else while(q){
		printf("%d ",q->data);
		q=q->next;
	}	
	printf("\n");
}
DL *insert_DL(DL *p,int place,Elemtype e){
	int i=1;
	DL *q,*s;
	q=p;
	while(i<place){
		i++;
		q=q->next;
	} 
	s=(DL *)malloc(sizeof(DL)); 
	s->front=q;
	s->next=q->next;
	q->next->front=s;
	q->next=s;
	s->data=e;
	return p;
}

DL *delete_DL(DL *p,int place){
	int i=1;
	DL *q;
	q=p;
	while(i<place){
		i++;
		q=q->next;
	}
	printf("ɾ����Ԫ��ֵΪ��%d\n",q->next->data);
	q->next->next->front=q;
	q->next=q->next->next;
	return p;
} 
