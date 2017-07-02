#include<iostream>
#include<algorithm>
#define MAXVEX 100
#define INFINITE 65535
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
		cout<<"����ߣ�vi,vj���ϵĶ�����ţ�\n"<<endl; 
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

int main(){
	
	
	return 0;
}
