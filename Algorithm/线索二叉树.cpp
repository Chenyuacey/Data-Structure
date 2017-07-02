// ERROR ERROR ERROR

#include<bits/stdc++.h>
using namespace std;
typedef enum {Link,Thread} Pointertag;
typedef char TElemtype; 
typedef struct BiThrtree{
	TElemtype data;
	struct BiThrtree *lch,*rch;
	Pointertag Ltag,Rtag;
}BiThrNode ,*BiThrTree;
BiThrTree pre;

void Create(BiThrTree &T){
	char ch;
	cin>>ch;
	if(ch=='#')
		T=NULL;
	else {
		T=(BiThrTree)malloc(sizeof(BiThrNode));
		if(!T) exit(0);
		T->data=ch;
		Create(T->lch);
		Create(T->rch);
	}
}
void Inorderprint(BiThrTree T){
	if(T==NULL) return ;
	Inorderprint(T->lch);
	cout<<T->data<<" ";
	Inorderprint(T->rch);
}

void InorderTravers_Thr(BiThrTree T) {
	BiThrTree p;
	p=T->lch;
	while(p!=T){
		while(p->Ltag==Link){
			p=p->lch;
		}
		cout<<p->data<<" ";
		while(p->Rtag==Thread &&p->rch!=T){
			p=p->rch;
			cout<<T->data<<" ";
		}                 //while(p->rch!=T) p=p->rch;
		p=p->rch;
	}
}

void InThreading (BiThrTree &T){
	if(T){
		InThreading (T->lch);
		if(!T->lch){
			T->lch=pre;
			T->Ltag=Thread;
		}
		if(!pre->rch){
			pre->Rtag=Thread;
			pre->rch=T;
		}
		pre=T;
		InThreading(T->rch);
	}
}

void InorderThrTree_Head(BiThrTree &h,BiThrTree T){
	h=(BiThrTree )malloc(sizeof(BiThrNode));
	if(!h) exit(0);
	h->rch=h;
	h->Rtag=Link;
	if(!T){
		h->lch=h;
		h->Ltag=Link;
	}
	else {
		pre=h;
		h->lch=T;
		h->Ltag=Link;
		InThreading(T);
		pre->rch=h;
		pre->Rtag=Thread;
		h->rch=pre;
		//h->Ltag=Thread;
	}
}


int main(){
	BiThrTree t,temp;
	printf("输入建立的树：\n");
	Create(t);
	//Inorderprint(t);
	//cout<<endl;
	//线索化 
	InorderThrTree_Head(temp,t);
	printf("打印线索化之后的线索二叉树中序序列：\n"); 
	InorderTravers_Thr(temp);
	return 0;
}
