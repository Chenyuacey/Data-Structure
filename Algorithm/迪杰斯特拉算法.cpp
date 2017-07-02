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
            G.edges[i][j]=MAX;//�������ʼ��ΪMAX  
    for(k=0;k<e;k++)  
    {  cout<<"����ߣ�vi,vj���ϵĶ�����ż�Ȩֵ��"<<endl; 
        cin>>i>>j>>weight;  
        G.edges[i][j]=weight;  
    }  
}  
void ShortestPath_DJ(MGraph &G,int v)  
{  
    int i,j,k,min;  
    int final[MAX_VERTEX_NUM];//������������ʶ�����Ƿ���ȷ�������·��  
    int dist[MAX_VERTEX_NUM];  
    string path[2*MAX_VERTEX_NUM];  
    for(i=0;i<G.vexnum;i++)  
    {//��ʼ������  
        dist[i]=G.edges[v][i];//dist���������洢��ǰ�ҵ���v����������������·��  
        if(dist[i]<MAX)  
            path[i]=G.vexs[v]+G.vexs[i];//���v��i�бߵĻ����Ѷ����ַ��浽path�ַ������У���ʾ·��  
        else  
            path[i]="";  
        final[i]=0;//��ʼ����ʶ����Ϊ0  
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
            }//�ҵ�dist��������Сֵ��λ��k  
        cout<<path[k]<<" Ȩֵ��Ϊ��"<<dist[k]<<endl;//������·��  
        final[k]=1;//���ñ�־λ  
        for(i=0;i<G.vexnum;i++)  
        {//����ÿ������i�͵�ǰ������������·���Ķ���k���Ƚϣ�����Դ�㾭������k������i��·������dist[i]С��  
            //����¶���dist[i]  
            if(dist[i]>dist[k]+G.edges[k][i] && final[i]==0)  
            {  
                dist[i]=dist[k]+G.edges[k][i];  
                path[i]=path[k]+G.vexs[i];  
            }  
        }//�������������������k���ڽӵ�ĵ�ǰ���·��  
    }  
}  
int main()  
{  
    MGraph G;  
    int a,b;
    cout<<"���붥�����ͱ�����"<<endl;
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
