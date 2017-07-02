#include<iostream>
#include<algorithm>
#include<cstdio>
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

typedef struct {
	VertexType vexs[MAXVEX];
	EdgeType arc[MAXVEX][MAXVEX];
	int numVertexes,numEdges;
}MGraph;

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

void DFS(MGraph G,int i){
	int j;
	visited[i]=TRUE;
	printf("%c ",G.vexs[i]);
	for(j=0;j<G.numVertexes;j++){
		if(G.arc[i][j]==1&&!visited[j])
			DFS(G,j);
	}
}

void DFSTraverse(MGraph G){
	int i;
	for(i=0;i<G.numVertexes;i++)
		visited[i]=FALSE;
	for(i=0;i<G.numVertexes;i++){
		if(!visited[i])
			DFS(G,i);
	}
}

int main(){
	MGraph G;
	Create_MGraph(&G);
	cout<<"遍历结果为："<<endl; 
	DFSTraverse(G);
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
