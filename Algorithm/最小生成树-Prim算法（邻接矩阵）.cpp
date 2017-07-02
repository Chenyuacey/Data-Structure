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
}
/*Prim算法*/
void MiniSpanTree(MGraph G){
	int min,i,j,k;
	int adjvex[MAXVEX];   			//存顶点下标 
	int lowcost[MAXVEX];  			//存相关顶点权值 
	lowcost[0]=0;         			//V0已经加入生成树 
	adjvex[0]=0;          			//初始化第一个下标为0 
	for(i=1;i<G.numVertexes;i++){ 	//循环除0外的全部顶点 
		lowcost[i]=G.arc[0][i]; 	//权值存数组 
		adjvex[i]=0;				//下标都初始化为V0的 
	}
	for(i=1;i<G.numVertexes;i++){
		min=INFINITE;
		j=1;k=0;
		while(j<G.numVertexes){  					//循环这一行全部顶点 
			if(lowcost[j]!=0&&lowcost[j]<min){   	//找权值不为0（0表示已经找过），和小于min的值 
				min=lowcost[j];						//让当前权值为最小值 
				k=j;								//最小值下标存入K 
			}
			j++;
		}
		printf("(%d,%d)\n",adjvex[k],k);					//打印权值最小边 
		lowcost[k]=0; 									//当前顶点权值改为0，表示已经找过 
		for(j=1;j<G.numVertexes;j++){  					//再次循环第K行的全部元素 
			if(lowcost[j]!=0&&G.arc[k][j]<lowcost[j]){  //未找过 且 权值比原lowcost数组小时 
				lowcost[j]=G.arc[k][j];					//把较小值存入数组lowcost 
				adjvex[j]=k;       						//将下标K存入adjvex数组 
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
测试数据       
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
