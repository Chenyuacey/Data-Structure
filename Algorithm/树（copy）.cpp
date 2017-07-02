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
 int head,rear;//headָ��ͷԪ�أ�rearָ��βԪ�ص���һ��λ��
}Queue;
void initqueue(Queue &Q)
{// ��ʼ������
 Q.head=0;
 Q.rear=0;
}
status qempty(Queue Q)
{//�п�
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
{//����в���Ԫ��
 if(qfull(Q))
 {
  printf("������\n");
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
{//���׳����У�����e���ض���ֵ
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
{//�������������������Ľڵ�ֵ�����ɶ�����
 char ch;
 scanf("%c",&ch);
 if(ch==' ') T=NULL;
 else
 {
  if(!(T=(Btree)malloc(sizeof(Btree)))) return ERROR;
  T->date=ch;//���ڵ�
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
{//�������������
 if(!T)  return OK;
 printf("%c",T->date);
 preorderprint(T->Lchild);
 preorderprint(T->Rchild);
 return OK;
}
status inorderprint(Btree T)
{//�������������
 if(!T)  return OK;
 preorderprint(T->Lchild);
 printf("%c",T->date);
 preorderprint(T->Rchild);
 return OK;
}
status postorderprint(Btree T)
{//�������������
 if(!T)  return OK;
 preorderprint(T->Lchild);
 preorderprint(T->Rchild);
 printf("%c",T->date);
 return OK;
}
elemtype findBtreeroot(Btree T)
{//���ض�����T�ĸ����
 if(T)
  return T->date;
 else
  return '*';
  
}
status findLchild(Btree T,elemtype elem)
{//����Ԫ��elem���ڽ�������
 if(!T)  return ERROR;
 if(T->date==elem)
  if(T->Lchild!=NULL)
   printf("Ԫ��%c������Ϊ%c\n",elem,T->Lchild->date);
  else return ERROR;
 findLchild(T->Lchild,elem);
 findLchild(T->Rchild,elem);
 return OK;
}
status findroot(Btree T,elemtype elem)
{//����elem���ڽ���˫��
 if(!T||elem==findBtreeroot(T)) return ERROR;
 if(T->Lchild->date==elem||T->Rchild->date==elem)
 {
  printf("Ԫ��%c��˫��Ϊ%c\n",elem,T->date);return OK;
 }
 else
 {
 if(findroot(T->Lchild,elem)) return OK;
 if(findroot(T->Rchild,elem)) return OK;
 }
 return OK;
}
int depth(Btree T)
{//���ض����������
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
{//�����Ľ����
 int num;
 if(T==NULL)
  return 0;
 num=nodenum(T->Lchild)+nodenum(T->Rchild)+1;
 return num;
}
int leafnodenum(Btree T)
{//��Ҷ�ӽ�������
 int num;
 if(T==NULL)
  return 0;
 if(T->Lchild==NULL&&T->Rchild==NULL)
  return 1;
 num=leafnodenum(T->Lchild)+leafnodenum(T->Rchild);
 return num;
}
status findnode_k(Btree T,int k)
{//�����������������е�K���ڵ�
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
{//������������
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
 printf("����������������������������һ���������ÿո��ʾ��\n");
 creatBtree(T);
 while(1)
 {
  printf("��ѡ��Ҫ���еĲ�����\n1 ���п�\n2 �����������������\n3 �����������������\n4 ������ĺ���������\n5 ��������\n6 ����ָ��Ԫ�ص�����\n7 ����ָ��Ԫ�صĸ�\n8 ���ض����������\n9 ���ض������Ľڵ�����\n10 ���ض�������Ҷ�ӽڵ���\n11 ��������������е�K���ڵ�\n12 �����������������������\n");
  scanf("%d",&option); 
  switch(option)
  {
   case 1:
    if(Btreeempty(T))
     printf("����!\n");
    else
     printf("���ǿ�!\n");
    printf("\n\n\n");
    break;
   case 2:
    printf("����������Ϊ��");
    preorderprint(T);printf("\n");
    printf("\n\n\n");
    break;
   case 3:
    printf("����������Ϊ��");
    inorderprint(T);printf("\n");
    printf("\n\n\n");
    break;
   case 4:
    printf("����������Ϊ��");
    postorderprint(T);printf("\n");
    printf("\n\n\n");
    break;
   case 5:
    root=findBtreeroot(T);
    printf(" ����Ϊ�� %c.\n",root);
    printf("\n\n\n");
    break;
   case 6:
    printf("������ָ����Ԫ�أ�");
    scanf("%s",&ch);
    findLchild(T,ch);
    printf("\n\n\n");
    break;
   case 7:
    printf("������ָ����Ԫ�أ�");
    scanf("%s",&ch);
    findroot(T,ch);
    printf("\n\n\n");
    break;
   case 8:
    printf(" ������T�����Ϊ��%d\n",depth(T));
    printf("\n\n\n");
    break;
   case 9:
    printf("������T�Ľ������Ϊ��%d\n",nodenum(T));printf("\n\n\n");
    break;
   case 10:
    printf("������T��Ҷ�ӽ������Ϊ��%d\n",leafnodenum(T));
    printf("\n\n\n");
    break;
   case 11:
    printf("������Ҫ�����������������k:");
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
