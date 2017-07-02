#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define M 6
#define N 7
#define MAXSIZE 100
typedef int Elemtype;

typedef struct{
	int r;
	int c;
	Elemtype d;
}Tupnode;
typedef struct{
	int row;
	int col;
	int num;
	Tupnode data[MAXSIZE];
}TSMatrix; 

void CreateMat(TSMatrix &t,Elemtype A[M][N]);
void DispMat(TSMatrix t);
void Trantat(TSMatrix t,TSMatrix &tb);

int main(){
	TSMatrix t,tb;
	int A[6][7]=
    {
        {0,0,1,0,0,0,0},
        {0,2,0,0,0,0,0},
        {3,0,0,0,0,0,0},
        {0,0,0,5,0,0,0},
        {0,0,0,0,6,0,0},
        {0,0,0,0,0,7,4}
    };
    CreateMat(t,A);
    DispMat(t);printf("\n");
    Trantat(t,tb);
    DispMat(tb);printf("\n");
	return 0;
}

void CreateMat(TSMatrix &t,Elemtype A[M][N]){
	t.row=M;
	t.col=N;
	t.num=0;
	for(int i=0;i<M;i++){
		for(int j=0;j<N;j++){
			if(A[i][j]){
				t.data[t.num].c=j;
				t.data[t.num].r=i;
				t.data[t.num].d=A[i][j];
				t.num++;
			}
		}
	}
}

void DispMat(TSMatrix t){
	int i;
	if(t.num<=0) return ;
	printf("%d %d %d",t.row,t.col,t.num);
	printf("\n------\n");
	for(i=0;i<t.num;i++){
		printf("%d %d %d",t.data[i].r,t.data[i].c,t.data[i].d);
		printf("\n");
	}
}
void Trantat(TSMatrix t,TSMatrix &tb)       //¾ØÕó×ªÖÃ
{
    int i,j,k=0;
    tb.row=t.col;
    tb.col=t.row;
    tb.num=t.num;
    if(t.num!=0){
    	for(i=0;i<t.col;i++){
    		for(j=0;j<t.num;j++){
    			if(t.data[j].c==i){
    				tb.data[k].c=t.data[j].r;
    				tb.data[k].r=t.data[j].c;
    				tb.data[k].d=t.data[j].d;
    				k++;
				}
			}
		}
	}
}
