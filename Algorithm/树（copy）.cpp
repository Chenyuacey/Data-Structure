#include <stdio.h>
#include <malloc.h>
#define OK 1
#define ERROR 0
#define status int
#define elemtype char
#define maxsize 100
typedef struct Bnode
{
 elemtype date;
 struct Bnode *Lchild,*Rchild;
}*Btree;
typedef struct queue
{
 elemtype qu[maxsize];
 int head,rear;//head指向头元素，rear指向尾元素的下一个位置
}Queue;
void initqueue(Queue &Q)
{// 初始化队列
 Q.head=0;
 Q.rear=0;
}
status qempty(Queue Q)
{//判空
 if(Q.head ==Q.rear)
  return OK;
 else
  return ERROR;
}
status qfull(Queue Q)
{
 if((Q.rear+1)%maxsize==Q.head)
  return OK;
 else
  return ERROR;
}
status insertq(Queue &Q,elemtype e)
{//向对中插入元素
 if(qfull(Q))
 {
  printf("队已满\n");
  return ERROR;
 }
 else
 {
  Q.qu[Q.rear]=e;
  Q.rear=(Q.rear+1)%maxsize;
  return OK;
 }
}
elemtype dequeue(Queue &Q,elemtype &e)
{//队首出队列，并用e返回队首值
 if(qempty(Q))
  return ERROR;
 else
 {
  e=Q.qu[Q.head];
  Q.head=(Q.head+1)%maxsize;
  return OK;
 }
}
status creatBtree(Btree &T)
{//按先序次序输入二叉树的节点值，生成二叉树
 char ch;
 scanf("%c",&ch);
 if(ch==' ') T=NULL;
 else
 {
  if(!(T=(Btree)malloc(sizeof(Btree)))) return ERROR;
  T->date=ch;//根节点
  creatBtree(T->Lchild);
  creatBtree(T->Rchild);
 }
 return OK;
}
status Btreeempty(Btree T)
{
 if(!T)
  return OK;
 else
  return ERROR;
}
status preorderprint(Btree T)
{//先序输出二叉树
 if(!T)  return OK;
 printf("%c",T->date);
 preorderprint(T->Lchild);
 preorderprint(T->Rchild);
 return OK;
}
status inorderprint(Btree T)
{//中序输出二叉树
 if(!T)  return OK;
 preorderprint(T->Lchild);
 printf("%c",T->date);
 preorderprint(T->Rchild);
 return OK;
}
status postorderprint(Btree T)
{//后序输出二叉树
 if(!T)  return OK;
 preorderprint(T->Lchild);
 preorderprint(T->Rchild);
 printf("%c",T->date);
 return OK;
}
elemtype findBtreeroot(Btree T)
{//返回二叉树T的根结点
 if(T)
  return T->date;
 else
  return '*';
  
}
status findLchild(Btree T,elemtype elem)
{//返回元素elem所在结点的左孩子
 if(!T)  return ERROR;
 if(T->date==elem)
  if(T->Lchild!=NULL)
   printf("元素%c的左孩子为%c\n",elem,T->Lchild->date);
  else return ERROR;
 findLchild(T->Lchild,elem);
 findLchild(T->Rchild,elem);
 return OK;
}
status findroot(Btree T,elemtype elem)
{//返回elem所在结点的双亲
 if(!T||elem==findBtreeroot(T)) return ERROR;
 if(T->Lchild->date==elem||T->Rchild->date==elem)
 {
  printf("元素%c的双亲为%c\n",elem,T->date);return OK;
 }
 else
 {
 if(findroot(T->Lchild,elem)) return OK;
 if(findroot(T->Rchild,elem)) return OK;
 }
 return OK;
}
int depth(Btree T)
{//返回二叉树的深度
 int dep;
 if(T==NULL)
  return 0;
 else
 {
  dep=depth(T->Lchild);
  dep=dep>depth(T->Rchild)?dep:depth(T->Rchild);
  return(dep+1);
 }
}
int nodenum(Btree T)
{//求树的结点数
 int num;
 if(T==NULL)
  return 0;
 num=nodenum(T->Lchild)+nodenum(T->Rchild)+1;
 return num;
}
int leafnodenum(Btree T)
{//求叶子结点的总数
 int num;
 if(T==NULL)
  return 0;
 if(T->Lchild==NULL&&T->Rchild==NULL)
  return 1;
 num=leafnodenum(T->Lchild)+leafnodenum(T->Rchild);
 return num;
}
status findnode_k(Btree T,int k)
{//输出二叉树先序遍历中第K个节点
 int i=1;
 if(T==NULL)
  return ERROR;
 if(i==k)
 {
  printf("%c\n",T->date);
  return OK;
 }
 if(findnode_k(T->Lchild,k-1)) return OK;
 if(findnode_k(T->Rchild,k-1)) return OK;
}
Btree exchange(Btree T)
{//互换左右子树
 Btree p;
 if(T!=NULL)
 {
  p=T->Lchild;
  T->Lchild=T->Rchild;
  T->Rchild=p;
 }
 else
  return NULL;
 exchange(T->Lchild);
 exchange(T->Rchild);
 return T;
}

int main()
{
 int option,k;
 elemtype root,elem,ch;
 Btree T;
 printf("请先输入树的先序遍历结果以生成一个树，空用空格表示：\n");
 creatBtree(T);
 while(1)
 {
  printf("请选择要进行的操作：\n1 树判空\n2 输出树的先序遍历结果\n3 输出树的中序遍历结果\n4 输出树的后序遍历结果\n5 返回树根\n6 返回指定元素的左孩子\n7 返回指定元素的根\n8 返回二叉树的深度\n9 返回二叉树的节点总数\n10 返回二叉树的叶子节点数\n11 输出先序遍历结果中第K个节点\n12 互换左右子树，并先序输出\n");
  scanf("%d",&option); 
  switch(option)
  {
   case 1:
    if(Btreeempty(T))
     printf("树空!\n");
    else
     printf("树非空!\n");
    printf("\n\n\n");
    break;
   case 2:
    printf("先序遍历结果为：");
    preorderprint(T);printf("\n");
    printf("\n\n\n");
    break;
   case 3:
    printf("中序遍历结果为：");
    inorderprint(T);printf("\n");
    printf("\n\n\n");
    break;
   case 4:
    printf("后序遍历结果为：");
    postorderprint(T);printf("\n");
    printf("\n\n\n");
    break;
   case 5:
    root=findBtreeroot(T);
    printf(" 树根为： %c.\n",root);
    printf("\n\n\n");
    break;
   case 6:
    printf("请输入指定的元素：");
    scanf("%s",&ch);
    findLchild(T,ch);
    printf("\n\n\n");
    break;
   case 7:
    printf("请输入指定的元素：");
    scanf("%s",&ch);
    findroot(T,ch);
    printf("\n\n\n");
    break;
   case 8:
    printf(" 二叉树T的深度为：%d\n",depth(T));
    printf("\n\n\n");
    break;
   case 9:
    printf("二叉树T的结点总数为：%d\n",nodenum(T));printf("\n\n\n");
    break;
   case 10:
    printf("二叉树T的叶子结点总数为：%d\n",leafnodenum(T));
    printf("\n\n\n");
    break;
   case 11:
    printf("请输入要输出的先序遍历的序号k:");
    scanf("%d",&k);
    findnode_k(T,4);
    printf("\n\n\n");
    break;
   case 12:
    exchange(T);
    preorderprint(T);printf("\n");
    printf("\n\n\n");
    break;
   default:
    break;
// levelprint(T);
  }
 }
}
