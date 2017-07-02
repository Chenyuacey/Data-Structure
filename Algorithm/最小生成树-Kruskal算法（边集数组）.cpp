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
	cout<<"���붥�����ͱ�����"<<endl;
	cin>>G->numVertexes>>G->numEdges;
	cout<<"�����������:"<<endl;
	for(i=0;i<G->numVertexes;i++) cin>>G->vexs[i];
	for(i=0;i<G->numVertexes;i++)
		for(j=0;j<G->numVertexes;j++)
			G->arc[i][j]=INFINITE;
	for(k=0;k<G->numEdges;k++){
		cout<<"����ߵĶ����Ȩ��"<<endl;
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
	Sort_Edge(G);			//���ڽӾ����ɱ߼����鲢��weight��С�������� 
//for(int i=0;i<G.numEdges;i++) printf("%d %d %d\n",edges[i].begin,edges[i].end,edges[i].weight); 
	int i,m,n;
	int parent[MAXVEX];		//��������parent�ж��Ƿ��γɻ�· 
	for(i=0;i<G.numVertexes;i++) 
		parent[i]=0;		//��ʼ������Ϊ0
	for(i=0;i<G.numEdges;i++){
		n=Find(parent,edges[i].begin);   
		m=Find(parent,edges[i].end);
		if(m!=n){  			//���m��=n,˵��û���������������γɻ�· 
			parent[n]=m;	//���˱߽�β��������±�Ϊ����parent�У���ʾ�˶������������������� 
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
