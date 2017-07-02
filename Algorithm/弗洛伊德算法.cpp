#include<iostream>  
#include<string>  
using namespace std;  
/*�ڽӾ�������Ͷ���*/  
#define MAX 10000000  
#define MAX_VERTEX_NUM 20  
typedef struct  
{  
    string vexs[MAX_VERTEX_NUM];//��һά����洢������Ϣ  
    int edges[MAX_VERTEX_NUM][MAX_VERTEX_NUM];//�ö�ά����䵱�������洢����ߵ���Ϣ  
    int vexnum,edgenum;//�������ͱ���  
}MGraph;  
/*�������������ڽӾ���*/  
void CreateDN_AM(MGraph &G,int n,int e)  
{  
    G.vexnum=n;  
    G.edgenum=e;  
      
    int i,j,k;  
    int weight;  
    for(i=0;i<n;i++)  
        cin>>G.vexs[i];//���붥����Ϣ  
    for(i=0;i<n;i++)  
        for(j=0;j<n;j++)  
        {  
            if(i==j)  
                G.edges[i][j]=0;//���Խ����ϵ�ȨֵΪ0  
            else  
                G.edges[i][j]=MAX;//�������ʼ��ΪMAX  
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
        {//��ʼ������  
            dist[i][j]=G.edges[i][j];  
            if(dist[i][j]<MAX)  
                path[i][j]=G.vexs[i]+G.vexs[j];  
            else  
                path[i][j]="";  
        }  
    //����forѭ�������·��  
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
