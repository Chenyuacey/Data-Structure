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
        {  
            if(i==j)  
                G.edges[i][j]=0;//主对角线上的权值为0  
            else  
                G.edges[i][j]=MAX;//将矩阵初始化为MAX  
        }  
    for(k=0;k<e;k++)  
    {  
        cin>>i>>j>>weight;  
        G.edges[i][j]=weight;  
    }  
}  
void ShortestPath_Floyd(MGraph &G)  
{  
    int i,j,k;  
    int dist[MAX_VERTEX_NUM][MAX_VERTEX_NUM];  
    string path[2*MAX_VERTEX_NUM][2*MAX_VERTEX_NUM];  
    for(i=0;i<G.vexnum;i++)  
        for(j=0;j<G.vexnum;j++)  
        {//初始化工作  
            dist[i][j]=G.edges[i][j];  
            if(dist[i][j]<MAX)  
                path[i][j]=G.vexs[i]+G.vexs[j];  
            else  
                path[i][j]="";  
        }  
    //三个for循环求最短路径  
    for(k=0;k<G.vexnum;k++)  
        for(i=0;i<G.vexnum;i++)  
            for(j=0;j<G.vexnum;j++)  
                if(dist[i][k]+dist[k][j]<dist[i][j])  
                {  
                    dist[i][j]=dist[i][k]+dist[k][j];  
                    path[i][j]=path[i][k]+path[k][j];  
                }  
    for(i=0;i<G.vexnum;i++)  
    {  
        for(j=0;j<G.vexnum;j++)  
            cout<<path[i][j]<<" "<<dist[i][j]<<" ";  
        cout<<endl;  
    }  
}  
int main()  
{  
    MGraph G;  
    CreateDN_AM(G,4,6);  
    ShortestPath_Floyd(G);  
    return 0;
}  
