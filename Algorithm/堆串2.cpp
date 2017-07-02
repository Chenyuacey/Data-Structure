#include<stdio.h>  
#include<string.h>  
#include<stdlib.h>  
#include<malloc.h>   
typedef char Elemtype;  
typedef int Datatype;  
typedef struct {  
    Elemtype *ch;   //指针域，指向存放串值的存储空间基址  
    int length;  // 整型域：存放串长   
}HString;  
  
Datatype Init(HString *s);  
Datatype Assign(HString *s,Elemtype str[]);  
void Print(HString* s);  
Datatype Concat(HString *s,HString *q);//连接 malloc版   
Datatype Concat2(HString *s,HString *t);//连接 realloc版   
Datatype Replace(HString *S,HString T,HString V);//替换  
Datatype Insert(HString *S,int pos,HString *T);//插入  
  
int main(){  
    Elemtype ar[]="aaabcc**d",br[]="$$$",cr[]="bc";  
    HString t,p,q;  
    Init(&t);
	printf("将ar赋值并打印：\n");  
    Assign(&t,ar);  
    Print(&t) ;  
    Init(&p);  
    printf("将br赋值并链接在ar后：\n");
    Assign(&p,br);  
    Init(&q);  
    Assign(&q,cr);  
    Concat2(&t,&p);  
    Print(&t);  
    printf("插入第二个元素后的结果：\n"); 
    Insert(&t,2,&p);  
    Print(&t);  
    printf("将bc替代：\n"); 
    Replace(&t,q,p);  
    Print(&t);  
    return 0;  
}  
Datatype Init(HString *s){  
    s->ch=(Elemtype *)malloc(sizeof(Elemtype));  
    if(s->ch==NULL) return 0;  
    s->ch='\0';  
    s->length=0;  
    return 1;  
}  
  
Datatype Assign(HString *s,Elemtype str[]){  
    if(s->ch) free(s->ch);  
    int lenth=0,i;  
    while(str[lenth]!='\0')  
        lenth++;  
    s->ch=(Elemtype *)malloc(sizeof(Elemtype) * lenth);  
    if(!s->ch) return 0;  
    for(i=0;i<lenth;i++)  
        *(s->ch+i)=str[i];  
    s->length=lenth;  
    *(s->ch+s->length)='\0';  
    return 1;  
}  
  
void Print(HString* s){  
    int i = 0;    
    while (*(s->ch + i) != '\0') {    
        printf("%c", *(s->ch + i));    
        i++;    
    }    
    printf("\n");    
}  
  
Datatype Concat(HString *s,HString *t){  
    Elemtype *temp;  
    temp=(Elemtype *)malloc(sizeof(Elemtype) * (s->length+t->length));  
    int i=0;  
    if(!temp ) return 0;  
    for(i=0;i<s->length;i++)  
        *(temp+i)=*(s->ch+i);  
    free(s->ch);  
    for(i=0;i<t->length;i++)  
        *(temp+s->length+i)=*(t->ch+i);  
    s->length+=t->length;  
    s->ch=temp;  
    *(s->ch+s->length)='\0';  
    return 1;  
}  
  
Datatype Concat2(HString *s,HString *t){  
    int len=s->length;  
    s->ch=(Elemtype *)realloc(s->ch,sizeof(Elemtype) * (s->length+t->length));  
    int i=0;  
    for(i=0;i<t->length;i++){  
        *(s->ch+s->length+i)=*(t->ch+i);  
    }  
    s->length+=t->length;  
    *(s->ch+s->length)='\0';  
    return 1;  
}  
  
Datatype Replace(HString *S,HString T,HString V){  
    int k,count=0,i=count,j=0;  
    while(i>=0&&i<S->length&&j<T.length){  
        if(*(S->ch+i)==*(T.ch+j)) {  
            i++;j++;  
        }  
        else {  
            i=i-j+1;  
            j=0;  
        }  
    }  
    if(j>=T.length) count=i-T.length;  
    else count=0;  
    Elemtype *temp;  
    temp=(Elemtype *)malloc(sizeof(Elemtype) * (S->length-count-T.length));  
    int y=0;  
    for(i=count+T.length;i<S->length;i++)  
    {  
            *(temp+y)=*(S->ch+i);  
            y++;  
    }  
  
    S->ch=(Elemtype *)realloc(S->ch,sizeof(Elemtype)*(S->length-T.length+V.length));  
      
    y=0;  
    for(i=count;i<count+V.length;i++)   
    {  
        *(S->ch+i)=*(V.ch+y);  
        y++;  
    }  
    y=0;  
    for(i=count+V.length;i<S->length-T.length+V.length;i++){  
        *(S->ch+i)=*(temp+y);  
        y++;  
    }  
          
    S->length=S->length-T.length+V.length;  
    *(S->ch+S->length)='\0';  
    return 1;  
}  
  
Datatype Insert(HString *S,int pos,HString *T){  
    if(pos>S->length||pos<0) return 0;  
    else {  
        S->ch=(Elemtype *)realloc(S->ch,(S->length+T->length)*sizeof(Elemtype));  
        int i,j=1;  
        for(i=S->length+T->length-1;i>=pos+T->length;i--){  
            *(S->ch+i)=*(S->ch+S->length-j);  
            j++;  
        }  
        for(i=0;i<T->length;i++)  
            *(S->ch+i+pos)=*(T->ch+i);  
    }  
    S->length+=T->length;  
    *(S->ch+S->length)='\0';  
}  
