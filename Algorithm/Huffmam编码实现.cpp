#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define N 5
typedef struct {
	unsigned int w;
	unsigned pa,lch,rch; 
}HTnode;
char *HC[N+1];

void Create_Huffman(HTnode *HT,char *HC[],int W[],int n){
	if(n<1) return ;
	int m=2*n-1;
//初始化 
	HTnode *p;
	HT=(HTnode *)malloc((m+1)*sizeof(HTnode));
	for(i=1,p=HT+1;i<=n;i++,p++){
		p->w=W[i];p->pa=p->lch=p->rch=0;
	}
	for(;i<=m;i++,p++)
		p->w=p->lch=p->pa=p->rch=0;
	j=n-1; 
//建树		
	for(i=n+1;i<=m;i++){
		s1=select(HT,i-1);
		s2=select(HT,i-1);
		HT[i].w=HT[s1].w+HT[s2].w;
		HT[i].lch=s1;HT[i].rch=s2;
		HT[s1].pa=i;HT[s2].pa=i;
	}
//求编码
	char *cd;
	int start;
	HC=(char *)malloc((n+1)*sizeof(char));
	cd=(char *)malloc(n*sizeof(char));
	cd[n-1]='\0';
	for(i=1;i<=n;i++){
		start=n-2;
		for(c=i,f=HT[i].pa;!f;c=f,f=HT[f].pa)
			if(HT[f].lch==c) cd[start--]='0';
			else cd[start--]='1';
			strcpy(HC[i],cd[start+1]);
	} 
}

