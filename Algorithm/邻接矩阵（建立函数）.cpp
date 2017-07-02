#include<iostream>
#include<algorithm>
using namespace std;

typedef char VertexType;
typedef int EdgeType;
#define MAXVEX 100
#define INFINITE 65535
typedef struct {
	VertexType vexs[MAXVEX];
	EdgeType arc[MAXVEX][MAXVEX];
	int numVertexes,numEdges;
}MGraph;

void Create_MGraph(MGraph *G){
	int i,j,k,w;
	cout<<"输入顶点数和边数："<<endl;
	cin>>G->numVertexes>>G->numEdges;
	for(i=0;i<G->numVertexes;i++) cin>>G->vexs[i];
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

int main(){
	
	return 0;
} 
 
