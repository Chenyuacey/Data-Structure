#include<bits/stdc++.h>  

using namespace std;

typedef char Elemtype;
typedef struct Bnode{
	Elemtype  data;
	struct Bnode *lch,*rch;
}Bnode,*Btree;
int flag=1,last=0;
void Pre_Create_BTree(Btree &T);//前序创建树 
void PreOrder_Traverse(Btree T);//前序遍历 
void InOrder_Traverse(Btree T);//中序遍历 
void PostOrder_Traverse(Btree T);//后序遍历 
int IsBST(Btree &T);

int main(){
	printf("请输入扩展二叉树的前序序列：\n");
	Btree Root;
	Pre_Create_BTree(Root);
	printf("\n此树的前序序列为：\n");
	PreOrder_Traverse(Root);
	printf("\n此树的中序序列为：\n");
	InOrder_Traverse(Root);
	printf("\n此树的后序序列为：\n");
	PostOrder_Traverse(Root); 
	if(IsBST(Root)) cout<<endl<<"是二叉排序树"<<endl;
	else cout<<endl<<"不是二叉排序树"<<endl;
	return 0;
}

void Pre_Create_BTree(Btree &T){
	Elemtype ch;
	cin>>ch;  
	if(ch=='#') T=NULL;
	else {
		T=(Btree)malloc(sizeof(Bnode));
		if(!T) exit(0);
		T->data=ch;
		Pre_Create_BTree(T->lch);
		Pre_Create_BTree(T->rch);
	}
}
void PreOrder_Traverse(Btree T){
	if(T==NULL) return ;
	printf("%c",T->data);
	PreOrder_Traverse(T->lch);
	PreOrder_Traverse(T->rch);
}
void InOrder_Traverse(Btree T){
	if(T==NULL) return ;
	InOrder_Traverse(T->lch);
	printf("%c",T->data);
	InOrder_Traverse(T->rch);
}
void PostOrder_Traverse(Btree T){
	if(T==NULL) return ;
	PostOrder_Traverse(T->lch);
	PostOrder_Traverse(T->rch);
	printf("%c",T->data);
}

int IsBST(Btree &T){
	if(T->lch&&flag) IsBST(T->lch);
	if(last>T->data) flag=0;
	last=T->data;
	if(T->rch&&flag) IsBST(T->rch);
	return flag;
} 
