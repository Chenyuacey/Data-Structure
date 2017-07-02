#include<iostream>
#include<algorithm>
#define MAXVEX 100
#define INFINITE 65535
#define MAX 100
#define FALSE 0
#define TRUE 1
using namespace std;

typedef char VertexType;//顶点类型 
typedef int EdgeType;//权值类型 
//边表节点 
typedef struct EdgeNode{
	int adjvex;//邻接点域，储存顶点下标 
	EdgeType weight;//权值 
	struct EdgeNode *next;//链域 
}EdgeNode;
//顶点表节点 
typedef struct VertexNode{
	VertexType data;//顶点信息 
	EdgeNode *firstedge;//边表头指针 
}VertexNode ,AdjList[MAXVEX]; 
typedef struct {
	AdjList adjList;
	int numVertexes,numEdges;//顶点数和边数 
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

//队列
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
	cout<<"输入顶点数和边数："<<endl;
	cin>>G->numVertexes>>G->numEdges;//输入顶点和边数 
	for(i=0;i<G->numVertexes;i++){
		cin>>G->adjList[i].data;//输入顶点信息 
		G->adjList[i].firstedge=NULL; //边表置为空表 
	}
	for(k=0;k<G->numEdges;k++){   //建立边表 
		cout<<"输入边（vi,vj）上的顶点序号："<<endl; 
		cin>>i>>j;
		e=(EdgeNode *)malloc(sizeof(EdgeNode));//生成边表节点 
		
		e->adjvex=j;//邻接序号为j 
		e->next=G->adjList[i].firstedge;//将e指针指向当前顶点指向的节点 
		G->adjList[i].firstedge=e;//将当前定点的指针指向e 
	//下面段代码的作用，目的？？ 
		e=(EdgeNode *)malloc(sizeof(EdgeNode));//邻接序号为i
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
