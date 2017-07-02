#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 100 
typedef char Elemtype; 
typedef struct stack{
	Elemtype data[MAX];
	int top;
}Stack; 
void push(Stack *s,Elemtype e);
char pop(Stack *s);
bool priority(Elemtype a,Elemtype b);
void before(Elemtype *str);
int main()
{
	char str[100];
	while(scanf("%s",str)!=EOF)
	{
		before(str);
	}
}

void push(Stack *s,Elemtype e){
	if(s->top!=MAX-1) {
	s->top++;
	s->data[s->top]=e;
	}
	else {
	printf("Stack full.\n");
	exit(0); 
	}
}
char pop(Stack *s){
	if(s->top!=-1){
	char e=s->data[s->top] ;
	s->data[s->top]=0;
	s->top--;
	return e;
	}
	else{
		printf("Stack empty.\n");
		exit(0); 
	}
}

void before(Elemtype *str){
	int len=strlen(str);
	Stack s1,s2;
	memset(s1.data,0,sizeof(s1.data));
	memset(s2.data,0,sizeof(s2.data));
	s1.top=-1;s2.top=-1;
	for(int i=0;i<len;i++){
		if(str[i]>='0'&&str[i]<='9')
			 push(&s1,str[i]);
		else {
			if(s2.top!=-1){
				int j=s2.top;
				while(priority(s2.data[j],str[i])){
					if(j==-1) 
					break;
					push(&s1,pop(&s2));
					j--;
				}
				if(s2.data[j]=='('&&str[i]==')'){
					pop(&s2);
					continue;
				}
			}
			push(&s2,str[i]);
		}
	}
	while(s2.top!=-1){
		push(&s1,pop(&s2));
	}
	for(int i=0;i<len;i++){
		printf("%c",s1.data[i]);
	}
	printf("\n");
	double ar[100];
	int j=0;
	for(int i=0;i<len;i++){
		if(s1.data[i]>='0'&&s1.data[i]<='9') ar[j++]=s1.data[i]-'0';
		else {
			switch(s1.data[i]){
				case '+':ar[j-2]=ar[j-2]+ar[j-1];break;
				case '-':ar[j-2]=ar[j-2]-ar[j-1];break;
				case '*':ar[j-2]=ar[j-2]*ar[j-1];break;
				case '/':ar[j-2]=ar[j-2]/ar[j-1];break;
			}
			j--;
		}
	}
	printf("%.2f\n",ar[0]);
} 
bool priority(Elemtype a,Elemtype b)
{
	if((b=='+'||b=='-')&&a!='(')
		return true;
	if((b=='*'||b=='/')&&(a=='*'||a=='/'))
		return true;
	if(b==')'&&a!='(')
		return true;
	else
		return false;
}


