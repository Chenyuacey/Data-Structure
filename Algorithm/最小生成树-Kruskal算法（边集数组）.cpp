#include<iostream>
#include<algorithm>
using namespace  std;
typedef char VertexType;
typedef int EdgeType;
#define MAXVEX 100
#define MAXEDGE 100
#define INFINITE 65535
typedef struct {
	int begin;
	int end;
	int weight;
}Edge;

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
/*	for(i=0;i<G->numVertexes;i++){
		for(j=0;j<G->numVertexes;j++){
			printf("%7d",G->arc[i][j]);
		}
		cout<<endl;
	}
*/
}

Edge edges[MAXEDGE];

void Sort_Edge(MGraph G){
	int k=0,i,j;
	for(i=0;i<G.numVertexes;i++){
		for(j=0;j<G.numVertexes;j++){
			if(i==j) break;
			if(G.arc[i][j]!=INFINITE){
				edges[k].begin=i;
				edges[k].end=j;
				edges[k].weight=G.arc[i][j];
				k++;
			}
		}
	}
//printf("%d\n",k);
/*for(i=0;i<G.numEdges;i++) printf("%d ",edges[i].weight);
cout<<endl;*/
	Edge temp;		
	for( i=0;i<G.numEdges-1;i++)
		for( j=1;j<G.numEdges;j++)
			if(edges[i].weight>edges[j].weight){
				temp=edges[i];edges[i]=edges[j];edges[j]=temp;
			}	
}

int Find(int *parent,int f){
	while(parent[f]>0)
		f=parent[f];
	return f;
}

void MiniSpanTree_Kruskal(MGraph G){
	Sort_Edge(G);			//将邻接矩阵变成边集数组并按weight从小到大排序 
//for(int i=0;i<G.numEdges;i++) printf("%d %d %d\n",edges[i].begin,edges[i].end,edges[i].weight); 
	int i,m,n;
	int parent[MAXVEX];		//定义数组parent判断是否形成环路 
	for(i=0;i<G.numVertexes;i++) 
		parent[i]=0;		//初始化数组为0
	for(i=0;i<G.numEdges;i++){
		n=Find(parent,edges[i].begin);   
		m=Find(parent,edges[i].end);
		if(m!=n){  			//如果m！=n,说明没有与现有生成树形成环路 
			parent[n]=m;	//将此边结尾顶点放入下标为起点的parent中，表示此顶点已在生成树集合中 
			printf("(%d,%d) %d\n",edges[i].begin,edges[i].end,edges[i].weight);
		}
	} 
}

int main(){
	MGraph G;
	Create_MGraph(&G);
	MiniSpanTree_Kruskal(G);
	return 0;
}
