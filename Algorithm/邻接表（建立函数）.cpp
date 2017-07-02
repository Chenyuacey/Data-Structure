#include<iostream>
#include<algorithm>
#define MAXVEX 100
#define INFINITE 65535
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
		cout<<"输入边（vi,vj）上的顶点序号：\n"<<endl; 
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

int main(){
	
	
	return 0;
}
