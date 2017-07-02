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
}
/*Prim�㷨*/
void MiniSpanTree(MGraph G){
	int min,i,j,k;
	int adjvex[MAXVEX];   			//�涥���±� 
	int lowcost[MAXVEX];  			//����ض���Ȩֵ 
	lowcost[0]=0;         			//V0�Ѿ����������� 
	adjvex[0]=0;          			//��ʼ����һ���±�Ϊ0 
	for(i=1;i<G.numVertexes;i++){ 	//ѭ����0���ȫ������ 
		lowcost[i]=G.arc[0][i]; 	//Ȩֵ������ 
		adjvex[i]=0;				//�±궼��ʼ��ΪV0�� 
	}
	for(i=1;i<G.numVertexes;i++){
		min=INFINITE;
		j=1;k=0;
		while(j<G.numVertexes){  					//ѭ����һ��ȫ������ 
			if(lowcost[j]!=0&&lowcost[j]<min){   	//��Ȩֵ��Ϊ0��0��ʾ�Ѿ��ҹ�������С��min��ֵ 
				min=lowcost[j];						//�õ�ǰȨֵΪ��Сֵ 
				k=j;								//��Сֵ�±����K 
			}
			j++;
		}
		printf("(%d,%d)\n",adjvex[k],k);					//��ӡȨֵ��С�� 
		lowcost[k]=0; 									//��ǰ����Ȩֵ��Ϊ0����ʾ�Ѿ��ҹ� 
		for(j=1;j<G.numVertexes;j++){  					//�ٴ�ѭ����K�е�ȫ��Ԫ�� 
			if(lowcost[j]!=0&&G.arc[k][j]<lowcost[j]){  //δ�ҹ� �� Ȩֵ��ԭlowcost����Сʱ 
				lowcost[j]=G.arc[k][j];					//�ѽ�Сֵ��������lowcost 
				adjvex[j]=k;       						//���±�K����adjvex���� 
			}
		}
	}
}

int main(){
	MGraph G;
	Create_MGraph(&G);
	MiniSpanTree(G);
	return 0;
} 


/*     
��������       
9 15
0 1 2 3 4 5 6 7 8  
0 1 10
0 5 11
1 6 16
5 6 17
1 2 18
1 8 12
2 8 8
3 8 21
2 3 22
6 3 24
6 7 19 
3 7 16
3 4 20
4 5 26 
4 7 7 
*/ 
