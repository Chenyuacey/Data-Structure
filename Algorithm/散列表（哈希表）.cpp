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
	int *elem;    //数据元素储存基址，动态分配数组 
	int count;    //当前数据元素个数 
}HashTable;
int m=0;          //全局变量定义的散列（哈希）表表长 

Status InitHashTable(HashTable *H){  //初始化散列（哈希）表 
	int i;
	m=HASHSIZE;
	H->count=m;
	H->elem=(int *)malloc(m*sizeof(int));
	for(i=0;i<m;i++)
		H->elem[i]=NULLKEY;
	return OK;
}  

int Hash(int key){        //散列(哈希)函数 
	return key%m;         //除留余数法 
}

void InsertHash(HashTable *H,int key){
	int addr=Hash(key);
	while(H->elem[addr]!=NULLKEY)   //开放定址法线性探测，若不为空，则为冲突，向后逐个探测（可改成其他探测方法） 
          addr=(addr+1)%m;
	H->elem[addr]=key;              //有空位，插入关键字 
} 

Status SearchHash(HashTable H,int key,int *addr){
	*addr=Hash(key);                //求散列地址 
 	while(H.elem[*addr]!=key){      //不为空，则冲突 
		*addr=(*addr+1)%m;          //开放定址法线性探测 
		if(H.elem[*addr]==NULLKEY||*addr==Hash(key)){
			return UNSUCCESS;       //关键字不存在   
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
	if(result) printf("%d 的位置为 %d\n",key,p);
	else printf("%d 不在表中\n",key);
	for(i=0;i<m;i++){
		key=arr[i];
		SearchHash(H,key,&p);
		printf("%d 的位置为 %d\n",key,p);
		
	}
    return 0;
}
