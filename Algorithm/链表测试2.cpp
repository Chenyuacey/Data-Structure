#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#define maxn 5
typedef int ElementType;
typedef struct LNode *List;
struct LNode{
	ElementType data;
	List next;
};
struct LNode L;
List Ptrl;
void create(List *l,int n){
	List p,r;
	int i;
	srand(time(0));
	*l=(List)malloc(sizeof(struct LNode));
	(*l)->data=rand()%100+1;
	r=*l;
	for(i=0;i<n;i++){
		p=(List)malloc(sizeof(struct LNode));
		p->data=rand()%100+1;
		r->next=p;
		r=p;
	}
	r->next=NULL;
}

void print(List l,int n){
	int i; 
	for(i=0;i<n;i++){
		printf("%d\n",(l)->data);
		l=(l)->next;
	}
}
List FindKth(int k,List l){
	List p=l;
	int i=1;
	while(p!=NULL&&i<k){
		p=p->next;
		i++;
	}
	if(i==k) return p;
	else return NULL;
}
List Insert(List l,int place,int m){
	List p,s;
	if(place==1){
		p=(List)malloc(sizeof(struct LNode));
		p->data=m;
		p->next=l;
		return p;
	}
	s=FindKth(place-1,l);
	if(s==NULL) {
	printf("error\n");
	return NULL;
	}
	else{
		p=(List)malloc(sizeof(struct LNode));
		p->data=m;
		p->next=s->next;
	    s->next=p;
        return l; 
	}
}

List Delete(List l,int place){
	List p,s;
	if(place==1) {
		s=l;
		if(l!=NULL) l=l->next;
		else return NULL;
		free(s);
		return l;
	} 
	p=FindKth(place-1,l);
	if(p==NULL) {
		printf("%d not ex",place-1);
	}else if(p->next==NULL) {
		printf("%d not ex",place);
	}
	else {
		s=p->next;
		p->next=s->next;
		free(s);
		return l;
	}
} 
int main(){
	List temp; 
	create(&Ptrl,5);
	print(Ptrl,5);
	printf("\n");
	Ptrl=Insert(Ptrl,3,80);//潜在危险。。若找不到place，返回NULL，打印出错，程序崩溃。 位置数为6,7的时候不对。 
	print(Ptrl,6);
	printf("\n");
	Ptrl=Delete(Ptrl,4);
	print(Ptrl,5);
	return 0;
}
