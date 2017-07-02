#include<stdlib.h>  
#include<stdio.h>  
  
typedef char TElemType;  
  
typedef enum {Link,Thread} PointerTag;  
  
typedef  struct BiThrNode  
{  
    TElemType data;
    struct BiThrNode *lchild,*rchild;
    PointerTag LTag;
    PointerTag RTag;  
}BiThrNode, *BiThrTree;  
  
BiThrTree pre=NULL;
  
void InThreading(BiThrTree p)  
{  
    if(p)  
    {  
        InThreading(p->lchild);  
        printf("%c",p->data);  
        if(!p->lchild){  
            p->LTag=Thread;  
            p->lchild=pre;
        }  
        if(!p->rchild){  
            pre->RTag=Thread;  
            pre->rchild=p;  
        }  
        pre=p;  
        InThreading(p->rchild);  
    }  
}  
  
void InOrder_Thr(BiThrTree &head,BiThrTree T)  
{  
    head=(BiThrTree)malloc(sizeof(BiThrNode));  
    head->LTag=Link;  
    head->RTag=Thread;  
    head->rchild=head;   
  
    if(!T)  
        head->lchild=head;  
    else  
    {  
        head->lchild=T;
        pre=head;  
        InThreading(T);  
        pre->RTag=Thread;  
        pre->rchild=head;
        head->rchild=pre;  
    }  
}  
  
void CreateBiTree(BiThrTree &T)  
{  
    TElemType ch;  
    scanf("%c",&ch);  
    if(ch=='#') T=NULL;  
    else{  
        T=(BiThrTree)malloc(sizeof(BiThrNode));  
        T->data=ch;  
        CreateBiTree(T->lchild);  
        CreateBiTree(T->rchild);  
    }  
}  
  
int main()  
{  
    BiThrTree T,head=NULL;  
	printf("输入建立的树：\n");
    CreateBiTree(T);  
	printf("打印线索化之后的线索二叉树中序序列：\n"); 
    InOrder_Thr(head,T);  
}  
