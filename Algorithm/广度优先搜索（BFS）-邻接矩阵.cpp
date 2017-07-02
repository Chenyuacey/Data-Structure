#include<iostream>
#include<algorithm>
#include<cstdio>
#include<queue>
#define MAXVEX 100
#define MAX 100 
#define INFINITE 65535
#define TRUE 1
#define FALSE 0
using namespace std;

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


typedef struct {
	VertexType vexs[MAXVEX];
	EdgeType arc[MAXVEX][MAXVEX];
	int numVertexes,numEdges;
}MGraph;


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

//图
void Create_MGraph(MGraph *G){
	int i,j,k,w;
	cout<<"输入顶点数和边数："<<endl;
	cin>>G->numVertexes>>G->numEdges;
	cout<<"请输入各顶点:"<<endl;
	for(i=0;i<G->numVertexes;i++) 
		cin>>G->vexs[i];//读入顶点信息建立顶点表
	for(i=0;i<G->numVertexes;i++)
		for(j=0;j<G->numVertexes;j++)
			G->arc[i][j]=INFINITE;
	for(k=0;k<G->numEdges;k++){
		cout<<"输入边的顶点和权："<<endl;
		cin>>i>>j>>w;
		G->arc[i][j]=w;
		G->arc[j][i]=G->arc[i][j];
	}
}

void BFSTraverse(MGraph G){
	int i,j;
	LinkQueue Q;
	InitQ(Q);
	for(i=0;i<G.numVertexes;i++)
		visited[i]=FALSE;
	for(i=0;i<G.numVertexes;i++){
		if(!visited[i]){
			visited[i]=TRUE;
			cout<<G.vexs[i]<<" ";
			Push_Q(&Q,i);
			while(!Empty(Q)){
				Pop_Q(&Q,&i);
				for(j=0;j<G.numVertexes;j++){
					if(G.arc[i][j]==1&&!visited[j]){
						visited[j]=TRUE;
						cout<<G.vexs[j];
						Push_Q(&Q,j);
					}
				}
			}
		}
	}
}

int main(){
	MGraph G;
	Create_MGraph(&G);
	cout<<"遍历结果为："<<endl; 
	BFSTraverse(G);
	return 0;
}

/*
 5 6
 0 1 2 3 4 
 0 1 9
 1 2 3 
 0 2 2
 2 3 5
 3 4 1
 4 0 6 
 */ 
