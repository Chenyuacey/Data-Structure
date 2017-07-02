#include<iostream>
#include<cstdio>
#include<algorithm>
#define LH +1        //左高 
#define EH 0         //等高 
#define RH -1        //右高 
#define TRUE 1
#define FALSE 0
using namespace std;

typedef int Status;
typedef struct BiTNode{
	int data;
	int bf;
	struct BiTNode *lch,*rch;
}BiTNode,*BiTree;

void R_Rotate(BiTree *p){   //右旋 对称左旋代码 
	BiTree L;
	L=(*p)->lch;             
	(*p)->lch=L->rch;
	L->rch=(*p);
	*p=L;
}

void L_Rotate(BiTree *p){   //左旋 与右旋代码对称 
	BiTree R;
	R=(*p)->rch;
	(*p)->rch=R->lch;
	R->lch=(*p);
	*p=R;
}

void LeftBalance(BiTree *T){ //左平衡旋转处理  
	BiTree L,Lr;              
	L=(*T)->lch;             //L指向T的左子树的根 
	switch(L->bf){           //检查T左子树的平衡度，作平衡处理 
		case LH:             //新结点插入在T的左孩子的左子树上，作右旋处理 
			(*T)->bf=L->bf=EH;
			R_Rotate(T);
			break;
		case RH:             //新结点插入在T的左孩子的右子树上，作双旋处理 
			Lr=L->rch;       //Lr指向T的左孩子的右子树根 
			switch(Lr->bf)   //修改T及其左孩子的平衡因子 
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
			L_Rotate(&(*T)->lch); //对T的左子树作左旋平衡处理 
			R_Rotate(T);          //对T作右旋平衡处理 
	}
} 

void RightBalance(BiTree *T){  //右旋平衡处理 ,与左旋类似 
	BiTree R,Rl;
	R=(*T)->rch;               //R指向T的右子树根结点   
	switch(R->bf){             //检查T的右子树的平衡度，作平衡处理    
		case RH:               //新结点插入在T的右孩子的右子树上,作左旋处理   
			(*T)->bf=R->bf=EH;
			L_Rotate(T);
			break;
		case LH:               //新结点插入在T的右孩子的左子树上，作双旋处理 
			Rl=R->lch;         //Rl指向T的右孩子的左子树根   
			switch(Rl->bf)     //修改T及其右孩子的平衡因子 
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
			R_Rotate(&(*T)->rch); //对T的右子树作右旋平衡处理 
			L_Rotate(T);          //对T作左旋平衡处理
	}
	
}

Status InsertAVL(BiTree *T,int e,Status *taller){
	if(!*T){                            
		*T=(BiTree)malloc(sizeof(BiTNode));  //插入新节点，树长高，taller变TRUE 
		(*T)->data=e;
		(*T)->lch=(*T)->rch=NULL;
		(*T)->bf=EH;
		*taller=TRUE; 
	}
	else {                                   //树中存在与e有相同的关键字的结点则不再插入 
		if(e==(*T)->data){
			*taller=FALSE;
			return FALSE;
		}
		if(e<(*T)->data){                    //在T的左子树中搜索 
			if(!InsertAVL(&(*T)->lch,e,taller))   return FALSE;//未插入 
			if(*taller){                     //已插入T左子树且树长高       
				switch((*T)->bf){
					case LH:
						LeftBalance(T);      //原本左子树高，左平衡处理 
						*taller=FALSE;
						break;
					case EH:                 //原本等高，现左子树增高导致树增高 
						(*T)->bf=LH;
						*taller=TRUE;
						break;
					case RH:                 //原本右子树高，现在等高 
						(*T)->bf=EH;
						*taller=FALSE;
						break;
				}
			}
		}
		else if(e>(*T)->data){              //在T的右子树中搜索 
			if(!InsertAVL(&(*T)->rch,e,taller))   return FALSE;//未插入 
			if(*taller){                     //已插入T左子树且树长高       
				switch((*T)->bf){
					case RH:                 //原本右子树高，右平衡处理 
						RightBalance(T);
						*taller=FALSE;
						break;
					case EH:                 //原本等高，现右子树增高导致树增高 
						(*T)->bf=RH;
						*taller=TRUE;
						break;
					case LH:                 //原本左子树高，现在等高 
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
	cout<<"输入树的节点数和节点值:"<<endl;
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
	cout<<"中序遍历结果为："<<endl;
	InOrder_Traverse(T);
	return 0;
}
