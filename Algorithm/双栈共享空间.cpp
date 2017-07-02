/*Ë«Õ»¹²Ïí¿Õ¼ä*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAXSIZE 10
#define Elemtype int

struct DStack {
	Elemtype data[MAXSIZE];
	int TOP1;
	int TOP2; 
}S;
void push(struct DStack *ptrl,Elemtype item,int Tag);
Elemtype pop(struct DStack *ptrl,int Tag);
void print(struct DStack *ptrl); 

/*Ö÷º¯Êý*/ 
int main(){
	/*´ý²¹³ä*/ 
    return 0;	
} 

/*Ëã·¨º¯Êý*/ 
void Push(struct DStack *ptrl,Elemtype item,int Tag){
	if(ptrl->TOP2-ptrl->TOP1==1) {
		printf("Õ»Âú");return; 
	}
	if(Tag==1) ptrl->data[++(ptrl->TOP1)]=item;
	else ptrl->data[--(ptrl->TOP2)]=item;
}  

Elemtype pop(struct DStack *ptrl,int Tag){
	if(Tag==1) {
		if(ptrl->TOP1==-1){
			printf("Õ»1¿Õ"); return NULL;
		} else{
			return ptrl->data[(ptrl->TOP1)--];
		}
	} else{
		if(ptrl->TOP2==MAXSIZE) {
			printf("Õ»2¿Õ");  return NULL;
		}
		else {
			return ptrl->data[(ptrl->TOP2)++];
		}
	}
}

void print(struct DStack *ptrl){

}
