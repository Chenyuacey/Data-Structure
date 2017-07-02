#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
typedef struct Linklist{
	int data;
	struct Linklist *next;
}LL;

LL *create_list(int n);//尾插法 创建链表 

LL *headcreate_list(int n);//头插法 创建链表 

void print_list(LL *p);//打印链表 

LL *insert_list(LL *p,int place,int e);//把e插入place位置

LL *delete_list(LL *p,int place);//把place位置删除 

int LOCATE(LL *p,int e);//寻找位置 

int LENGTH(LL *p); //求长度    

LL *nizhi(LL *p); //单链表的逆置 

int main(){
	LL *head;
	int e,n,place1,place2;
	printf("请输入建立链表元素个数：\n");
	scanf("%d",&n);
	//head=create_list(n);
	head=headcreate_list(n);
	printf("创建的链表为：\n");
	print_list(head);
	printf("插入的位置和元素：\n"); 
	scanf("%d %d",&place1,&e);
	printf("插入后的链表：\n"); 
	head=insert_list(head,place1,e);
	print_list(head);
	printf("删除的位置:\n");
	scanf("%d",&place2);
	head=delete_list(head,place2);
	printf("删除后的链表：\n"); 
	print_list(head);
	printf("请输入要查找的数：") ;
	int ha;
	scanf("%d",&ha);
	int pl=LOCATE(head,ha);
	printf("此元素在第%d个位置处\n",pl); 
	int shu=LENGTH(head);
	printf("此时链表有%d个元素\n",shu); 
	head=nizhi(head);
	printf("\n\n");
	printf("输出逆置链表：\n"); 
	print_list(head);
	return 0;
}

LL *create_list(int n){
	LL *p,*r,*q;
	p=(LL*)malloc(sizeof(LL));
	p->next=NULL;
	r=p;
	srand(time(0));
	for(int i=1;i<=n;i++){
		q=(LL*)malloc(sizeof(LL));
	    q->data=rand()/1000;
	    q->next=r->next;
	    r->next=q;
	    r=q;
	}
	return p;//p是头节点 
}

void print_list(LL *p){
	LL *q;
	q=p->next;
	if(!q) printf("Empty list.");
	else while(q){
		printf("%d ",q->data);
		q=q->next;
	}
	printf("\n");
}

LL *insert_list(LL *p,int place,int e){
	LL *q,*s;int j;
	q=p;j=1;
	while(j<place){
		q=q->next;
		j++;
	}
	s=(LL*)malloc(sizeof(LL));
	s->data=e;
	s->next=q->next;
	q->next=s;
	return p;
}
LL *delete_list(LL *p,int place){
	int e,j=1;
	LL *q,*r;
	q=p;
	while(j<place){
		q=q->next;
		j++;
	}
	e=q->next->data;
	printf("被删除的元素为：%d\n",e);
	r=q->next;
	q->next=q->next->next;
	free(r);
	return p;
}
LL *headcreate_list(int n){
	LL *p,*q;
	p=NULL;
	srand(time(0));
	for(int i=0;i<=n;i++){
		q=(LL *)malloc(sizeof(LL));
		q->data=rand()/1000;
		q->next=p;
		p=q;
	} 
	return p;
} 

int LOCATE (LL *p,int e){
	int i;
	LL *q;
	if(p){
		i=1;
		q=p->next;
		while(q){
			if(q->data==e) return i;
			i++;
			q=q->next;
		}
	}
	return 0;
}

int LENGTH(LL *p){
	LL *q;
	int n=0;
	if(p){
		q=p->next;
		while(q){
			n++;
			q=q->next;
		}
	}
	return n;
}
LL *nizhi(LL *head){ //链表的逆置 
	LL *p,*pnext;
	p=head->next;
	head->next=NULL;
	while(p){
		pnext=p->next;
		p->next=head->next;
		head->next=p;
		p=pnext;
	}
	return head;
} 
