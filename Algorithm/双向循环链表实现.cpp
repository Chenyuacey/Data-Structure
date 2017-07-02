#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define Elemtype int
typedef struct D_linklist{
	Elemtype data;
	struct D_linklist *front,*next;
}DL;
DL *create_DL(int n);
void print_DL(DL *p); 
DL *insert_DL(DL *p,int place,Elemtype e);
DL *delete_DL(DL *p,int place);

int main(){
	DL *head;
	head=create_DL(10);
	print_DL(head); 
	head=insert_DL(head,11,100);
	print_DL(head);
	head=delete_DL(head,11);
	print_DL(head);
	return 0;
} 

DL *create_DL(int n){
	DL *p,*q;
	srand(time(0));
	p=(DL *)malloc(sizeof(DL));
	p->front=p->next=p;
	q=p;
	srand(time(0));
	for(int i=1;i<=n;i++){
		q->next=(DL *)malloc(sizeof(DL));
		q->next->data=rand()/1000; 
		q->next->front=q;
		q->next->next=p;
		p->front=q;
		q=q->next;
	}
	return p;
} 

void print_DL(DL *p){
	DL *q;
	q=p->next;
	if(q==p) printf("Empte list");
	else while(q!=p){
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
	printf("删除的元素值为：%d\n",q->next->data);
	q->next->next->front=q;
	q->next=q->next->next;
	return p;
} 
