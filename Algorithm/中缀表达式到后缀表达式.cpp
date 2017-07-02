#include<iostream>
#include<cstring>
#include<cctype>
#include<cstdlib>
using namespace std;
typedef struct strack{
	char a[100];
	int top;
} Strack;
bool priority(char a,char b)
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
void push(Strack *s,char e)
{
	s->top++;
	s->a[s->top]=e;
}
char pop(Strack *s)
{
	char e=s->a[s->top];
	s->a[s->top]=0;
	s->top--;
	return e;
}
void before1(char *str)
{
	int len=strlen(str);
	Strack s1,s2;
	memset(s1.a,0,sizeof(s1.a));
	memset(s2.a,0,sizeof(s2.a));
	s1.top=-1;//s1??¡¤?????¡¤?
	s2.top=-1;//s2??¡¤???¡Á?
	for(int i=0;i<len;i++){
		if(isdigit(str[i])){
			push(&s2,str[i]);
		}else {
			if(s1.top!=-1){
				int j=s1.top;
				while(priority(s1.a[j],str[i]))
				{
					if(j==-1)
					break;
					push(&s2,pop(&s1));
					j--;
				}
				if(s1.a[j]=='('&&str[i]==')'){
					pop(&s1);
					continue;
				}
			}
			push(&s1,str[i]);
		}
	}
	while(s1.top!=-1)
	{
		push(&s2,pop(&s1));
	}
	for(int i=0;i<len;i++){

		cout<<s2.a[i];
	}

	cout<<endl;
}
int main()
{
	//freopen("in.txt","r",stdin);
	char str[100];
	while(cin>>str)
	{
		before1(str);
	//	cout<<str<<endl;
	}
}

