#include<stdio.h>
#include<stdlib.h>
struct student{
	int num;
	int score;
	struct student *next;
};
int n;
struct student *create(void){
	struct student *head;
	struct student *p1,*p2;
	p1=p2=(struct student *)malloc(sizeof(struct student));
	head=NULL;
	n=0;
	scanf("%d %d",&p1->num,&p1->score);
	while(p1->num!=0){
		n++;
		if(n==1) head=p1;
		else p2->next=p1;
		p2=p1;
		p1=(struct student *)malloc(sizeof(struct student));
		scanf("%d %d",&p1->num,&p1->score);
	}
	p2->next=NULL;
	return head;
}

void print(struct student *L){
	for(int i=0;i<n;i++){
		printf("%d ",L->score);
		L=L->next;
	}
}

void Insert(struct student *L,int q,int x,int y){
	int j=1;
	struct student *s;
	while(j<q&&L){
		++j;
		L=L->next;
	}
	s=(struct student *)malloc(sizeof(struct student));
	s->num=x,s->score=y;
    s->next=L->next;
    L->next=s;
	n++;
}
void Delete(struct student *L,int i){
	int j;
	struct student *p,*q;
	p=L;
	j=1;
	while(p->next&&j<i)
	{
		p->next;
		++j;
	}
	q=p->next;
	p->next=q->next;
	n--;
} 
int main(){
	struct student *A,*B;
	int q,x,y,z;
	A=create();
	print(A);
	printf("\n请输入插入位置，数据：\n");
	scanf("%d %d %d",&q,&x,&y);
	Insert(A,q-1,1278,100);//Insert 有问题 
	print(A);
	printf("\n请输入删除的位置:\n");
	scanf("%d",&z);
	Delete(A,z-1);
	print(A);
	return 0;
}
