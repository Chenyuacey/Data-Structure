#include<iostream>
#include<cstdio>
#include<malloc.h> 
using namespace std;
//tip:all is ues the address of struct 
//"&"  and * of struct to recerive and ->to change 

#define MAX_SIZE 30

typedef struct 
{
	char *str;
	int length;
}HeapString;

bool IsEmpty(HeapString *s){
	return s->length==0;
}

void InintString(HeapString *s){
	s->length=0;
	s->str='\0';
}

int Length(HeapString *s){
	return s->length;
}

bool StrAssign(HeapString *s,char cstr[]){
	int len=0;
	
	if(s->str) free(s->str);
	
	for(int i=0;cstr[i]!='\0';i++){
		len++;
	}
	
	if(len==0) s->str='\0';
	else{
		s->str=(char *)malloc(sizeof(char)*(len+1));
		if(s->str==NULL) return false;
		for(int i=0;i<len;i++){
			s->str[i]=cstr[i];
		}
		//s->length=len;
	}
	s->str[len]='\0';
	s->length=len;
}

void StrPrint(HeapString *s){
	int i=0;
	for(i=0;i<s->length;i++){
		cout<<s->str[i]; 
	}
	cout<<endl;
}

bool StrInsert(HeapString *s,int pos,HeapString *T){
	//int i=0;
	int s_len=s->length;
	int t_len=T->length;
	
	if(pos<0||pos-1>=s->length) return false;
	
	s->str=(char *)realloc(s->str,(s->length +T->length)*sizeof(char));
	if(s->str==NULL)
	{
		cout<<"there is false"<<endl;
		return false;
	}
	
	for(int i=s->length-1;i>=pos-1;--i){
		s->str[i+T->length]=s->str[i];
	}
	
	for(int i=0;i<T->length;++i){
		s->str[i+pos-1]=T->str[i];
	}
	s->length+=T->length;
	s->str[s->length]='\0';
	return 1;
}

//bool StrDelete(HeapString *s,int pos,int len);

//void ClearString(HeapString *s);

//void Destroy(HeapString *s);

//bool SubString(HeapString *sub,HeapString *s,int pos,int len);

//bool StringConcat(HeapString *T,HeapString *s,HeapString *s2);

int main()
{
	HeapString s1,s2,sub,T;
	char ch[MAX_SIZE+1];
	char a[]="abcdefg";
	char b[]="de";
	char c[]="xy";
	
	InintString(&s1);
	//you can gets_s to ch[] and assign as well
	StrAssign(&s1,a);
	cout<<"next print string s1"<<endl;
	StrPrint(&s1);
	
	InintString(&s2);
	StrAssign(&s2,b);
	cout<<"next print string s2"<<endl;
	StrPrint(&s2);
	
	
	cout<<"~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
	
	StrInsert(&s1,2,&s2);
	StrPrint(&s1);
	return 0;
}
