#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
typedef struct Linklist{
	int data;
	struct Linklist *next;
}LL;

LL *create_list(int n);//β�巨 �������� 

LL *headcreate_list(int n);//ͷ�巨 �������� 

void print_list(LL *p);//��ӡ���� 

LL *insert_list(LL *p,int place,int e);//��e����placeλ��

LL *delete_list(LL *p,int place);//��placeλ��ɾ�� 

int LOCATE(LL *p,int e);//Ѱ��λ�� 

int LENGTH(LL *p); //�󳤶�    

LL *nizhi(LL *p); //����������� 

int main(){
	LL *head;
	int e,n,place1,place2;
	printf("�����뽨������Ԫ�ظ�����\n");
	scanf("%d",&n);
	//head=create_list(n);
	head=headcreate_list(n);
	printf("����������Ϊ��\n");
	print_list(head);
	printf("�����λ�ú�Ԫ�أ�\n"); 
	scanf("%d %d",&place1,&e);
	printf("����������\n"); 
	head=insert_list(head,place1,e);
	print_list(head);
	printf("ɾ����λ��:\n");
	scanf("%d",&place2);
	head=delete_list(head,place2);
	printf("ɾ���������\n"); 
	print_list(head);
	printf("������Ҫ���ҵ�����") ;
	int ha;
	scanf("%d",&ha);
	int pl=LOCATE(head,ha);
	printf("��Ԫ���ڵ�%d��λ�ô�\n",pl); 
	int shu=LENGTH(head);
	printf("��ʱ������%d��Ԫ��\n",shu); 
	head=nizhi(head);
	printf("\n\n");
	printf("�����������\n"); 
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
	return p;//p��ͷ�ڵ� 
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
	printf("��ɾ����Ԫ��Ϊ��%d\n",e);
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
LL *nizhi(LL *head){ //��������� 
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
