#include<stdio.h>
#include<time.h>
#include<stdlib.h> 
typedef struct Linklist{
	int data;
	struct Linklist *next;
}LL;
LL *create1_list(int n);//尾插法创建单向循环链表
void print_list(LL *p);//打印 注意终止判断条件 
LL *insert_list(LL *p,int place,int e); 
LL *delete_list(LL *p,int place);
int main(){
	LL *head;
	head=create1_list(10);
	print_list(head);
	head=insert_list(head,11,100);
	print_list(head);
	head=delete_list(head,10);
	print_list(head);	
	return 0;
}

LL *create1_list(int n){
	LL *p,*q,*r;
	p=(LL *)malloc(sizeof(LL));
	q=p;
	srand(time(0));
	for(int i=1;i<=n;i++){
		r=(LL *)malloc(sizeof(LL));
		r->data=rand()/1000;
		r->next=p;
		q->next=r;
		q=r;
	}
	return p;
} 
void print_list(LL *p){
	LL *q;
	q=p->next;
	if(!q) printf("Empty list.");
	else while(q!=p){
		printf("%d ",q->data);
		q=q->next;
	}
	printf("\n");
}
LL *insert_list(LL *p,int place,int e){
	int i=1;
	LL *q,*s;
	q=p;
	while(i<place){
		i++;
		q=q->next;
	} 
	s=(LL *)malloc(sizeof(LL));
	s->data=e;
	s->next=q->next;
	q->next=s;
	return p;
}
LL *delete_list(LL *p,int place){
	int i=1,e;
	LL *q,*r;
	q=p;
	while(i<place){
		i++;
		q=q->next;
	}
	printf("被删除的元素：%d\n",q->next->data);
	r=q->next;
	q->next=q->next->next;
	free(r);
	return p; 
}
