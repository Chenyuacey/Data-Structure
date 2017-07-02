#include<stdio.h>
#include<stdlib.h> 
typedef int QElemtype;  
  
typedef struct QNode{  
    QElemtype data;  
    struct QNode *next;  
}QNode,*QueuePtr;  
  
typedef struct{  
    QueuePtr front,rear;  
}LinkQueue;

void InitQueue(LinkQueue *q) 
{  
    q->front = q->rear = (QueuePtr)malloc(sizeof(QNode)); 
    q->front->next = NULL;  
}  

int EnQueue(LinkQueue *Q,QElemtype e){  
    QueuePtr s=(QueuePtr)malloc(sizeof(QNode));  
    if(!s) exit(0);  
    s->data=e;  
    s->next=NULL;  
    Q->rear->next=s;  
    Q->rear=s;  
    return 1;  
}  

void CreateQueue(LinkQueue *q) 
{  
    //InitQueue(q);  
    printf("请输入要进队的元素\n");  
    int k;  
    while((scanf("%d",&k)) != EOF)  
        EnQueue(q,k);  
}  


  
int DeQueue(LinkQueue *Q,QElemtype *e){  
    QueuePtr p;  
    if(Q->front==Q->rear) return 0; 
    p=Q->front->next;  
    *e=p->data;  
    Q->front->next=p->next;  
      
    if(Q->rear==p) Q->rear=Q->front;  
    free(p);  
    return 1;  
}    
void Print(LinkQueue *q) 
{  
    if(q->front == q->rear)  
        return;  
    QueuePtr temp = q->front->next;  
    while(temp != q->rear)  
    {  
        printf("%d ",temp->data);  
        temp = temp->next;  
    }  
    printf("%d",temp->data);  
    printf("\n");  
}  
int main(){
	LinkQueue q;
	//QElemtype e;
	//scanf("%d",&e); 
	CreateQueue(&q);
	Print(&q);
	return 0;
}
