
//COPY

#include<stdio.h> 
#include<stdlib.h>  
#include<math.h>  
struct HashTable;  
struct ListNote;  
typedef struct HashTable *HashTbl;  
typedef struct ListNote *Position;  
typedef Position List;  
int Hash(int key,int tablesize);  
int NextPrime(int x);  
HashTbl InitalizeTable(int TableSize);  
void DestroyTable(HashTbl H);  
Position Find(int key,HashTbl H);  
void Insert(int key, HashTbl H);  
void Delete(int key,HashTbl H);  
struct HashTable{   
    int TableSize;  
    Position *TheList;  
};  
struct ListNote{  
    int element;  
    Position next;  
};  
int Hash(int key,int tablesize){  
    return key%tablesize;  
}  
int NextPrime(int x){  
    int flag;  
    while(1){  
        flag = 0;  
        int i;  
        int n = sqrt((float)x);  
        for(i = 2 ;i <= n;i++){  
            if(x % i == 0){  
                flag = 1;  
                break;  
            }  
        }  
        if(flag == 0)  
            return x;  
        else  
            x++;  
    }  
}  
HashTbl InitalizeTable(int TableSize){  
    if(TableSize <= 0){  
        printf("散列大小有问题\n");  
        return NULL;  
    }  
    HashTbl table = (HashTbl)malloc(sizeof(struct HashTable));  
    if(table == NULL)  
        printf("分配失败");  
    table->TableSize = NextPrime(TableSize);  
    table->TheList = (Position*)malloc(sizeof(List) * table->TableSize);  
    if(table->TheList == NULL)  
        printf("分配失败");  
    table->TheList[0] = (Position)malloc(table->TableSize*sizeof(struct ListNote));  
    if(table->TheList == NULL)  
        printf("分配失败");  
    int i;  
    for(i = 0;i < table->TableSize;i++){  
        table->TheList[i] = table->TheList[0] + i;  
        table->TheList[i]->next = NULL;  
    }  
    return table;  
}  
Position Find(int key,HashTbl H){  
    Position p;  
    List L = H->TheList[Hash(key,H->TableSize)];  
    p = L->next;  
    while(p != NULL && p->element != key)  
        p = p->next;  
    if(p == NULL)  
        return L;  
    else  
        return p;  
}  
void Insert(int key,HashTbl H){  
    Position p,NewCell;  
    p = Find(key,H);  
    if(p->element != key){  
        NewCell = (Position)malloc(sizeof(struct ListNote));  
        if(NewCell == NULL)  
            printf("分配失败");  
        else{  
            p = H->TheList[Hash(key,H->TableSize)];  
            NewCell->next = p->next;  
            p->next = NewCell;  
            NewCell->element = key;  
        }  
    }  
    else  
        printf("已经存在该值了\n");  
}  
void Delete(int key,HashTbl H){  
    Position p ,NewCell;  
    p = Find(key,H);  
    if(p->element == key){  
        NewCell = H->TheList[Hash(key,H->TableSize)];  
        while(NewCell->next != p)  
            NewCell = NewCell->next;  
        NewCell->next = p->next;  
        free(p);  
    }  
    else  
        printf("没有该值");  
}  
int main(){  
    HashTbl table = InitalizeTable(10);  
    Position p = NULL;  
    p = Find(10,table);  
    printf("%d\n",p->element);  
    Insert(55,table);  
    Insert(90,table);  
    Insert(35,table);  
    Insert(33,table);  
    p = Find(55,table);  
    printf("%d\n",p->element);  
    p = Find(33,table);  
    printf("%d\n",p->element);  
    Delete(33,table);  
    Delete(44,table);  
    system( "pause" );  
    return 0 ;  
}
