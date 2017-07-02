#include<iostream>
#include<algorithm>
#define MAXVEX 100
#define INFINITE 65535
#define MAX 100
#define FALSE 0
#define TRUE 1
using namespace std;

typedef char VertexType;//�������� 
typedef int EdgeType;//Ȩֵ���� 
//�߱�ڵ� 
typedef struct EdgeNode{
	int adjvex;//�ڽӵ��򣬴��涥���±� 
	EdgeType weight;//Ȩֵ 
	struct EdgeNode *next;//���� 
}EdgeNode;
//�����ڵ� 
typedef struct VertexNode{
	VertexType data;//������Ϣ 
	EdgeNode *firstedge;//�߱�ͷָ�� 
}VertexNode ,AdjList[MAXVEX]; 
typedef struct {
	AdjList adjList;
	int numVertexes,numEdges;//�������ͱ��� 
}GraphAdjList;

typedef char VertexType;
typedef int EdgeType;
typedef int Boolean;
Boolean visited[MAX]; 
typedef  char Elemtype;


typedef struct Qnode{
	int data;
	struct Qnode *next;
}Qnode,*Qnodeptr;
typedef struct queue{
	Qnodeptr front;
	Qnodeptr tail;
}LinkQueue;

//����
void InitQ(LinkQueue &Q){
	Q.front=Q.tail=(Qnodeptr)malloc(sizeof(Qnode));
	Q.front->next=NULL;
}
void Push_Q(LinkQueue *Q,Elemtype e){
	Qnodeptr s=(Qnodeptr)malloc(sizeof(Qnode));
	if(!s) exit(0);
	s->data=e;
	s->next=NULL;
	Q->tail->next=s;
	Q->tail=s;
}
void Pop_Q(LinkQueue *Q,int *e){
	Qnodeptr p;
	if(Q->front==Q->tail) exit(0);
	p=Q->front->next;
	*e=p->data;
	Q->front->next=p->next;
	if(Q->tail==p) Q->tail=Q->front;
	free(p);
}
bool Empty(LinkQueue Q){
	if(Q.front==Q.tail) return 1;
	else return 0;
}


void Create_ALGraph(GraphAdjList *G){
	int i,j,k;
	EdgeNode *e;
	cout<<"���붥�����ͱ�����"<<endl;
	cin>>G->numVertexes>>G->numEdges;//���붥��ͱ��� 
	for(i=0;i<G->numVertexes;i++){
		cin>>G->adjList[i].data;//���붥����Ϣ 
		G->adjList[i].firstedge=NULL; //�߱���Ϊ�ձ� 
	}
	for(k=0;k<G->numEdges;k++){   //�����߱� 
		cout<<"����ߣ�vi,vj���ϵĶ�����ţ�"<<endl; 
		cin>>i>>j;
		e=(EdgeNode *)malloc(sizeof(EdgeNode));//���ɱ߱�ڵ� 
		
		e->adjvex=j;//�ڽ����Ϊj 
		e->next=G->adjList[i].firstedge;//��eָ��ָ��ǰ����ָ��Ľڵ� 
		G->adjList[i].firstedge=e;//����ǰ�����ָ��ָ��e 
	//����δ�������ã�Ŀ�ģ��� 
		e=(EdgeNode *)malloc(sizeof(EdgeNode));//�ڽ����Ϊi
		e->adjvex=i;
		e->next=G->adjList[i].firstedge;
		G->adjList[i].firstedge=e; 
	}
} 

void BFSTraverse(GraphAdjList GL){
	int i;
	EdgeNode *p;
	LinkQueue Q;
	InitQ(Q);
	for(i=0;i<GL.numVertexes;i++)
		visited[i]=FALSE;
	for(i=0;i<GL.numVertexes;i++){
		if(!visited[i]){
			visited[i]=TRUE;
			cout<<GL.adjList[i].data<<" ";
			Push_Q(&Q,i);
			while(!Empty(Q)){
			Pop_Q(&Q,&i);
			p=GL.adjList[i].firstedge;
			while(p){
				if(!visited[p->adjvex]){
					visited[p->adjvex]=TRUE;
					cout<<GL.adjList[p->adjvex].data<<" ";
					Push_Q(&Q,p->adjvex);
				}
				p=p->next;
			}
			}
		}
	}
}

int main(){
	GraphAdjList G;
	Create_ALGraph(&G);
	BFSTraverse(G);
	return 0;
}

/*
5 6
0 1 2 3 4 
0 1 
1 2  
0 2 
2 3 
3 4 
4 0 
*/ 
