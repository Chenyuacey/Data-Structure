#include<iostream>
#include<cstdio>
#include<algorithm>
#define OK 1
#define SUCCESS 1
#define UNSUCCESS 0
#define HASHSIZE 12
#define NULLKEY -32768 
using namespace std;

typedef int Status;
typedef struct {
	int *elem;    //����Ԫ�ش����ַ����̬�������� 
	int count;    //��ǰ����Ԫ�ظ��� 
}HashTable;
int m=0;          //ȫ�ֱ��������ɢ�У���ϣ����� 

Status InitHashTable(HashTable *H){  //��ʼ��ɢ�У���ϣ���� 
	int i;
	m=HASHSIZE;
	H->count=m;
	H->elem=(int *)malloc(m*sizeof(int));
	for(i=0;i<m;i++)
		H->elem[i]=NULLKEY;
	return OK;
}  

int Hash(int key){        //ɢ��(��ϣ)���� 
	return key%m;         //���������� 
}

void InsertHash(HashTable *H,int key){
	int addr=Hash(key);
	while(H->elem[addr]!=NULLKEY)   //���Ŷ�ַ������̽�⣬����Ϊ�գ���Ϊ��ͻ��������̽�⣨�ɸĳ�����̽�ⷽ���� 
          addr=(addr+1)%m;
	H->elem[addr]=key;              //�п�λ������ؼ��� 
} 

Status SearchHash(HashTable H,int key,int *addr){
	*addr=Hash(key);                //��ɢ�е�ַ 
 	while(H.elem[*addr]!=key){      //��Ϊ�գ����ͻ 
		*addr=(*addr+1)%m;          //���Ŷ�ַ������̽�� 
		if(H.elem[*addr]==NULLKEY||*addr==Hash(key)){
			return UNSUCCESS;       //�ؼ��ֲ�����   
		}
	}
	return SUCCESS;
}

int main()
{
    int arr[HASHSIZE]={20,14,15,16,17,6,12,10,5,1,100,28};
    int i,p,key,result;
    key=101;
    HashTable H;
    InitHashTable(&H);
    for(i=0;i<m;i++){
    	InsertHash(&H,arr[i]);
	}
	result=SearchHash(H,key,&p);
	if(result) printf("%d ��λ��Ϊ %d\n",key,p);
	else printf("%d ���ڱ���\n",key);
	for(i=0;i<m;i++){
		key=arr[i];
		SearchHash(H,key,&p);
		printf("%d ��λ��Ϊ %d\n",key,p);
		
	}
    return 0;
}
