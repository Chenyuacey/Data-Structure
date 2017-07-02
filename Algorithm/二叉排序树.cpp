#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
typedef struct BiTNode
{
	int data;
	struct BiTNode *lch,*rch;
}BiTNode,*BiTree;
int last=0,flag=1;
int SerchBST(BiTree T,int key,BiTree f,BiTree *p){
	if(!T){
		*p=f;
		return 0;
	} 
	else if(key==T->data){
		*p=T;
		return 1;
	}
	else if(key<T->data) return SerchBST(T->lch,key,T,p);
	else return SerchBST(T->rch,key,T,p);
}

int InsertBST(BiTree *T,int key){
	BiTree p,s; 
	if(!SerchBST(*T,key,NULL,&p)){
		s=(BiTree )malloc(sizeof(BiTNode));
		s->data=key;
		s->lch=s->rch=NULL;
		if(!p) *T=s;
		else if(key<p->data) p->lch=s;
		else if(key>=p->data) p->rch=s;
		return 1;
	}
	else return 0;
} 

void PreTraverse(BiTree T){
	if(T==NULL) return;
	printf("%d ",T->data);
	PreTraverse(T->lch);
	PreTraverse(T->rch); 
} 
void InOrderTraverse(BiTree T){
	if(T==NULL) return;
	InOrderTraverse(T->lch);
	printf("%d ",T->data);
	InOrderTraverse(T->rch); 
}

void Delete(BiTree *p){
	BiTree q,s;
	if((*p)->rch == NULL) {  //右子树空，链接左子树 
		q=*p;
		*p=(*p)->lch;
		free(q);
	}
	else if((*p)->lch==NULL) {//左子树空，链接右子树 
		q=*p;
		*p=(*p)->rch;
		free(q);
	}
	else {                    //左右子树都不空 
		q=*p;
		s=(*p)->lch;
		while(s->rch){
			q=s;
			s=s->rch;
		}
		(*p)->data=s->data;
		if(q!=*p) q->rch=s->lch; 
		else q->lch=s->lch;
		free(s);
	}
}

void DeleteBST(BiTree *T,int key){
	if(!*T) return;
	else {
	if(key==(*T)->data) return Delete(T);
	else if(key<(*T)->data) return DeleteBST(&(*T)->lch,key);
	else return DeleteBST(&(*T)->rch,key); //参数传递 
	} 
} 

int IsBST(BiTree &T){
	if(T->lch&&flag) IsBST(T->lch);
	if(last>T->data) flag=0;
	last=T->data;
	if(T->rch&&flag) IsBST(T->rch);
	return flag;
} 

int main(){
	int i;
	int ar[10]={1,2,6,5,4,8,67,9,98,10};
	BiTree T=NULL;
	for(i=0;i<10;i++){
		InsertBST(&T,ar[i]);
	}
	printf("前序遍历树：");
	PreTraverse(T);
	printf("\n中序遍历树：");
	InOrderTraverse(T);
	if(IsBST(T)) cout<<endl<<"是二叉排序树"<<endl;
	else cout<<"不是二叉排序树"<<endl;
	return 0;
}
