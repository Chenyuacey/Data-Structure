#include<iostream>
#include<cstdio>
#include<algorithm>
#define LH +1        //��� 
#define EH 0         //�ȸ� 
#define RH -1        //�Ҹ� 
#define TRUE 1
#define FALSE 0
using namespace std;

typedef int Status;
typedef struct BiTNode{
	int data;
	int bf;
	struct BiTNode *lch,*rch;
}BiTNode,*BiTree;

void R_Rotate(BiTree *p){   //���� �Գ��������� 
	BiTree L;
	L=(*p)->lch;             
	(*p)->lch=L->rch;
	L->rch=(*p);
	*p=L;
}

void L_Rotate(BiTree *p){   //���� ����������Գ� 
	BiTree R;
	R=(*p)->rch;
	(*p)->rch=R->lch;
	R->lch=(*p);
	*p=R;
}

void LeftBalance(BiTree *T){ //��ƽ����ת����  
	BiTree L,Lr;              
	L=(*T)->lch;             //Lָ��T���������ĸ� 
	switch(L->bf){           //���T��������ƽ��ȣ���ƽ�⴦�� 
		case LH:             //�½�������T�����ӵ��������ϣ����������� 
			(*T)->bf=L->bf=EH;
			R_Rotate(T);
			break;
		case RH:             //�½�������T�����ӵ��������ϣ���˫������ 
			Lr=L->rch;       //Lrָ��T�����ӵ��������� 
			switch(Lr->bf)   //�޸�T�������ӵ�ƽ������ 
			{
				case LH:
					(*T)->bf=RH;
					L->bf=EH;
					break;
				case EH:
					(*T)->bf=L->bf=EH;
					break;
				case RH:
					(*T)->bf=EH;
					L->bf=LH;
					break;	
			}
			Lr->bf=EH;          
			L_Rotate(&(*T)->lch); //��T��������������ƽ�⴦�� 
			R_Rotate(T);          //��T������ƽ�⴦�� 
	}
} 

void RightBalance(BiTree *T){  //����ƽ�⴦�� ,���������� 
	BiTree R,Rl;
	R=(*T)->rch;               //Rָ��T�������������   
	switch(R->bf){             //���T����������ƽ��ȣ���ƽ�⴦��    
		case RH:               //�½�������T���Һ��ӵ���������,����������   
			(*T)->bf=R->bf=EH;
			L_Rotate(T);
			break;
		case LH:               //�½�������T���Һ��ӵ��������ϣ���˫������ 
			Rl=R->lch;         //Rlָ��T���Һ��ӵ���������   
			switch(Rl->bf)     //�޸�T�����Һ��ӵ�ƽ������ 
			{
				case RH:
					(*T)->bf=LH;
					R->bf=EH;
					break;
				case EH:
					(*T)->bf=R->bf=EH;
					break;
				case LH:
					(*T)->bf=EH;
					R->bf=RH;
					break;
			}
			Rl->bf=EH; 
			R_Rotate(&(*T)->rch); //��T��������������ƽ�⴦�� 
			L_Rotate(T);          //��T������ƽ�⴦��
	}
	
}

Status InsertAVL(BiTree *T,int e,Status *taller){
	if(!*T){                            
		*T=(BiTree)malloc(sizeof(BiTNode));  //�����½ڵ㣬�����ߣ�taller��TRUE 
		(*T)->data=e;
		(*T)->lch=(*T)->rch=NULL;
		(*T)->bf=EH;
		*taller=TRUE; 
	}
	else {                                   //���д�����e����ͬ�Ĺؼ��ֵĽ�����ٲ��� 
		if(e==(*T)->data){
			*taller=FALSE;
			return FALSE;
		}
		if(e<(*T)->data){                    //��T�������������� 
			if(!InsertAVL(&(*T)->lch,e,taller))   return FALSE;//δ���� 
			if(*taller){                     //�Ѳ���T��������������       
				switch((*T)->bf){
					case LH:
						LeftBalance(T);      //ԭ���������ߣ���ƽ�⴦�� 
						*taller=FALSE;
						break;
					case EH:                 //ԭ���ȸߣ������������ߵ��������� 
						(*T)->bf=LH;
						*taller=TRUE;
						break;
					case RH:                 //ԭ���������ߣ����ڵȸ� 
						(*T)->bf=EH;
						*taller=FALSE;
						break;
				}
			}
		}
		else if(e>(*T)->data){              //��T�������������� 
			if(!InsertAVL(&(*T)->rch,e,taller))   return FALSE;//δ���� 
			if(*taller){                     //�Ѳ���T��������������       
				switch((*T)->bf){
					case RH:                 //ԭ���������ߣ���ƽ�⴦�� 
						RightBalance(T);
						*taller=FALSE;
						break;
					case EH:                 //ԭ���ȸߣ������������ߵ��������� 
						(*T)->bf=RH;
						*taller=TRUE;
						break;
					case LH:                 //ԭ���������ߣ����ڵȸ� 
						(*T)->bf=EH;
						*taller=FALSE;
						break;
				}
			}
		}
	}
	return TRUE;
}

void InOrder_Traverse(BiTree T){
	if(T==NULL) return ;
	InOrder_Traverse(T->lch);
	printf("%d ",T->data);
	InOrder_Traverse(T->rch);
}

int main(){
	int n;
	cout<<"�������Ľڵ����ͽڵ�ֵ:"<<endl;
	cin>>n; 
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	
	BiTree T=NULL;
	int taller;
	for(int i=0;i<n;i++){
		InsertAVL(&T,a[i],&taller);
	}
	cout<<"����������Ϊ��"<<endl;
	InOrder_Traverse(T);
	return 0;
}
