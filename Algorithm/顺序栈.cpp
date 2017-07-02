#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define ERROR -1 
#define MAXSIZE 10
#define Elemtype int
typedef struct SNode *Stack;
struct SNode{
	Elemtype data[MAXSIZE];
	int Top;
}; 
void push(Stack ptrl,Elemtype item);
Elemtype pop(Stack ptrl);
void print(Stack ptrl); 
/*Ö÷º¯Êý*///´íÎó 

int main(){
	int i,j,a;
	Stack top;
	srand(time(0));
	top->Top=-1;
	for(i=0;i<MAXSIZE;i++){ 
	a=rand()/1000;
	printf("%d ",a);
	push(top,a);
	} 
	print(top);
	return 0;
}

/*Ëã·¨º¯Êý*/ 
void push(Stack ptrl,Elemtype item){
	if(ptrl->Top==MAXSIZE-1) {
	printf("Õ»Âú");
	return ;
    }
    else {
    	ptrl->data[++(ptrl->Top)]=item;
	}
}

Elemtype pop(Stack ptrl){
	if(ptrl->Top==-1) {
		printf("Õ»¿Õ");
		return ERROR;
	}
	else return (ptrl->data[(ptrl->Top)--]);
}

void print(Stack ptrl){
	while(ptrl->Top!=-1){
		printf("%d ",ptrl->data[(ptrl->Top)--]);
	}
}
