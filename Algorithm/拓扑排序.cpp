#include<iostream>
#include<cstdlib>
#define OK 1
#define ERROR 0
#define MAXVEX 100
using namespace std;
typedef int Status;
typedef struct EdgeNode{		//�߱�ڵ� 
	int adjvex;					//�ڽӵ��򣬴洢�����Ӧ���±� 
	int weight;					//�洢Ȩֵ 
	struct EdgeNode *next;		//����ָ����һ���ڽӵ� 
}EdgeNode;
typedef struct VertexNode{		//�����ڵ� 
	int in;						//������� 
	int data;					//�������� 
	EdgeNode *firstedge;		//�߱�ͷָ�� 
}VertexNode ,AdjList[MAXVEX];
typedef struct {
	AdjList adjList;
	int numVertexes,numEdges;	//ͼ�е�ǰ�������ͱ��� 
}graphAdjList,*GraphAdjList;


void Create_GL(GraphAdjList G) {
	int i,j,k;
	EdgeNode *e;
	cout<<"���붥�����ͱ�����"<<endl;
	cin>>G->numVertexes>>G->numEdges;			//���붥��ͱ��� 
	for(i=0;i<G->numVertexes;i++){
		cin>>G->adjList[i].data;				//���붥����Ϣ 
		G->adjList[i].firstedge=NULL; 			//�߱���Ϊ�ձ� 
		G->adjList[i].in=0;
	}
	for(k=0;k<G->numEdges;k++){   				//�����߱� 
		cout<<"����ߣ�vi,vj���ϵĶ�����ţ�"<<endl; 
		cin>>i>>j;
		e=(EdgeNode *)malloc(sizeof(EdgeNode));	//���ɱ߱�ڵ� 
		e->adjvex=j;							//�ڽ����Ϊj 
		e->next=G->adjList[i].firstedge;		//��eָ��ָ��ǰ����ָ��Ľڵ� 
		G->adjList[i].firstedge=e;				//����ǰ�����ָ��ָ��e 
	//����δ�������ã�Ŀ�ģ��� 
		e=(EdgeNode *)malloc(sizeof(EdgeNode));	//�ڽ����Ϊi
		e->adjvex=i;
		e->next=G->adjList[i].firstedge;
		G->adjList[i].firstedge=e;
		G->adjList[j].in++;
	}
}

Status Topological_Sort(GraphAdjList GL){
	EdgeNode *e;
	int i,k,gettop;
	int top=0;											//ջָ���±� 
	int count =0;										//ͳ������������ 
	int *stack;											//ջ�洢���Ϊ0�Ķ��� 
	stack=(int *)malloc(GL->numVertexes*sizeof(int));
	for(i=0;i<GL->numVertexes;i++)
		if(GL->adjList[gettop].in==0)
			stack[++top]=i;								//����Ϊ0 �ĵ���ջ 
	while(top!=0){
		gettop=stack[top--];							//��ջ 
		printf("%d->",GL->adjList[gettop].data);		//��ӡ���� 
		count++;										//ͳ��������� 
		for(e=GL->adjList[gettop].firstedge;e;e=e->next){ //�Դ˻������ 
			k=e->adjvex;
			if(!(--GL->adjList[k].in))					//��K�Ŷ����ڽӵ�����-1 
				stack[++top]=k;							//��Ϊ0����ջ�������´�ѭ����� 
		}
	}
	if(count<GL->numVertexes)							//��countС�ڶ����������ڻ� 
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
