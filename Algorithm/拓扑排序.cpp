#include<iostream>
#include<cstdlib>
#define OK 1
#define ERROR 0
#define MAXVEX 100
using namespace std;
typedef int Status;
typedef struct EdgeNode{		//边表节点 
	int adjvex;					//邻接点域，存储顶点对应的下标 
	int weight;					//存储权值 
	struct EdgeNode *next;		//链域，指向下一个邻接点 
}EdgeNode;
typedef struct VertexNode{		//顶点表节点 
	int in;						//顶点入度 
	int data;					//顶点数据 
	EdgeNode *firstedge;		//边表头指针 
}VertexNode ,AdjList[MAXVEX];
typedef struct {
	AdjList adjList;
	int numVertexes,numEdges;	//图中当前顶点数和边数 
}graphAdjList,*GraphAdjList;


void Create_GL(GraphAdjList G) {
	int i,j,k;
	EdgeNode *e;
	cout<<"输入顶点数和边数："<<endl;
	cin>>G->numVertexes>>G->numEdges;			//输入顶点和边数 
	for(i=0;i<G->numVertexes;i++){
		cin>>G->adjList[i].data;				//输入顶点信息 
		G->adjList[i].firstedge=NULL; 			//边表置为空表 
		G->adjList[i].in=0;
	}
	for(k=0;k<G->numEdges;k++){   				//建立边表 
		cout<<"输入边（vi,vj）上的顶点序号："<<endl; 
		cin>>i>>j;
		e=(EdgeNode *)malloc(sizeof(EdgeNode));	//生成边表节点 
		e->adjvex=j;							//邻接序号为j 
		e->next=G->adjList[i].firstedge;		//将e指针指向当前顶点指向的节点 
		G->adjList[i].firstedge=e;				//将当前定点的指针指向e 
	//下面段代码的作用，目的？？ 
		e=(EdgeNode *)malloc(sizeof(EdgeNode));	//邻接序号为i
		e->adjvex=i;
		e->next=G->adjList[i].firstedge;
		G->adjList[i].firstedge=e;
		G->adjList[j].in++;
	}
}

Status Topological_Sort(GraphAdjList GL){
	EdgeNode *e;
	int i,k,gettop;
	int top=0;											//栈指针下标 
	int count =0;										//统计输出顶点个数 
	int *stack;											//栈存储入度为0的顶点 
	stack=(int *)malloc(GL->numVertexes*sizeof(int));
	for(i=0;i<GL->numVertexes;i++)
		if(GL->adjList[gettop].in==0)
			stack[++top]=i;								//顶点为0 的点入栈 
	while(top!=0){
		gettop=stack[top--];							//出栈 
		printf("%d->",GL->adjList[gettop].data);		//打印顶点 
		count++;										//统计输出点数 
		for(e=GL->adjList[gettop].firstedge;e;e=e->next){ //对此弧表遍历 
			k=e->adjvex;
			if(!(--GL->adjList[k].in))					//将K号顶点邻接点的入度-1 
				stack[++top]=k;							//若为0则入栈，便于下次循环输出 
		}
	}
	if(count<GL->numVertexes)							//若count小于顶点数，存在环 
		return ERROR;
	else return OK;
}


int main(){
	graphAdjList GL;
	Create_GL(&GL);
	Topological_Sort(&GL);
	printf("0->1->3->2->4\n"); 
	return 0;
}

/*
5 5
0 1 2 3 4
0 1
0 2
1 3
3 4
2 4
*/ 
