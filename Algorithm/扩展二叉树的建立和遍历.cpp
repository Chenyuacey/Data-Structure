#include<bits/stdc++.h>  

using namespace std;

typedef char Elemtype;
typedef struct Bnode{
	Elemtype  data;
	struct Bnode *lch,*rch;
}Bnode,*Btree;
int flag=1,last=0;
void Pre_Create_BTree(Btree &T);//ǰ�򴴽��� 
void PreOrder_Traverse(Btree T);//ǰ����� 
void InOrder_Traverse(Btree T);//������� 
void PostOrder_Traverse(Btree T);//������� 
int IsBST(Btree &T);

int main(){
	printf("��������չ��������ǰ�����У�\n");
	Btree Root;
	Pre_Create_BTree(Root);
	printf("\n������ǰ������Ϊ��\n");
	PreOrder_Traverse(Root);
	printf("\n��������������Ϊ��\n");
	InOrder_Traverse(Root);
	printf("\n�����ĺ�������Ϊ��\n");
	PostOrder_Traverse(Root); 
	if(IsBST(Root)) cout<<endl<<"�Ƕ���������"<<endl;
	else cout<<endl<<"���Ƕ���������"<<endl;
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
