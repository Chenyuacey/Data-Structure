#include<iostream>  
#include<string>  
using namespace std;  
/*邻接矩阵的类型定义*/  
#define MAX 10000000  
#define MAX_VERTEX_NUM 20  
typedef struct  
{  
    string vexs[MAX_VERTEX_NUM];//用一维数组存储顶点信息  
    int edges[MAX_VERTEX_NUM][MAX_VERTEX_NUM];//用二维数组充当矩阵，来存储顶点边的信息  
    int vexnum,edgenum;//顶点树和边数  
}MGraph;  
/*构造有向网的邻接矩阵*/  
void CreateDN_AM(MGraph &G,int n,int e)  
{  
    G.vexnum=n;  
    G.edgenum=e;  
      
    int i,j,k;  
    int weight;  
    for(i=0;i<n;i++)  
        cin>>G.vexs[i];//输入顶点信息  
    for(i=0;i<n;i++)  
        for(j=0;j<n;j++)  
            G.edges[i][j]=MAX;//将矩阵初始化为MAX  
    for(k=0;k<e;k++)  
    {  cout<<"输入边（vi,vj）上的顶点序号及权值："<<endl; 
        cin>>i>>j>>weight;  
        G.edges[i][j]=weight;  
    }  
}  
void ShortestPath_DJ(MGraph &G,int v)  
{  
    int i,j,k,min;  
    int final[MAX_VERTEX_NUM];//该数组用来标识顶点是否已确定了最短路径  
    int dist[MAX_VERTEX_NUM];  
    string path[2*MAX_VERTEX_NUM];  
    for(i=0;i<G.vexnum;i++)  
    {//初始化工作  
        dist[i]=G.edges[v][i];//dist数组用来存储当前找到的v到其他各顶点的最短路径  
        if(dist[i]<MAX)  
            path[i]=G.vexs[v]+G.vexs[i];//如果v到i有边的话，把顶点字符存到path字符数组中，表示路径  
        else  
            path[i]="";  
        final[i]=0;//初始化标识数组为0  
    }  
    dist[v]=0;  
    final[v]=1;  
    for(j=1;j<G.vexnum;j++)  
    {  
        min=MAX;  
        for(i=0;i<G.vexnum;i++)  
            if(dist[i]<min && final[i]==0)  
            {  
                min=dist[i];  
                k=i;  
            }//找到dist数组中最小值的位置k  
        cout<<path[k]<<" 权值和为："<<dist[k]<<endl;//输出最短路径  
        final[k]=1;//设置标志位  
        for(i=0;i<G.vexnum;i++)  
        {//遍历每个顶点i和当前的已求出的最短路径的顶点k作比较，若从源点经过顶点k到顶点i的路径，比dist[i]小，  
            //则更新顶点dist[i]  
            if(dist[i]>dist[k]+G.edges[k][i] && final[i]==0)  
            {  
                dist[i]=dist[k]+G.edges[k][i];  
                path[i]=path[k]+G.vexs[i];  
            }  
        }//从整体上来看就是算出k的邻接点的当前最短路径  
    }  
}  
int main()  
{  
    MGraph G;  
    int a,b;
    cout<<"输入顶点数和边数："<<endl;
    cin>>a>>b;
    CreateDN_AM(G,a,b);  
    ShortestPath_DJ(G,0); 
	return 0; 
}  

/*
10 13
0 1 2 3 4 5 6 7 8 9
0 1 3
0 2 4
1 3 5
1 4 6
2 3 8
2 5 7
3 4 3
4 6 9
4 7 4
5 7 6
6 9 2
7 8 5 
8 9 3 

*/ 
