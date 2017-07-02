/* 
 串的堆式存储表示 
 */  
#include<stdio.h>  
#include<stdlib.h>  
#define OVERFLOW   -2//堆溢出  
#define OK          1//函数执行成功  
#define ERROR      -1//函数执行失败  
typedef int datatype;  
typedef struct {  
    char* ch; //指针域，指向存放串值的存储空间基址  
    int len; // 整型域：存放串长  
} HString;  
//初始化一个空串  
datatype InitHString(HString* s) {  
    s->ch = (char*) malloc(sizeof(char));  
    if (NULL == s->ch)  
        return OVERFLOW;  
    s->ch = NULL;  
    s->len = 0;  
    return OK;  
}  
//为串赋值  
datatype assigment_string(HString* s, const char* str) {  
    if (s->ch)  
        free(s->ch);  
    int length = 0, i;  
    while (str[length] != '\0')  
        length++;  
    s->ch = (char*) malloc(length * sizeof(char));  
    if (!s->ch)  
        return OVERFLOW;  
    for (i = 0; i < length; i++)  
        *(s->ch + i) = *(str + i);  
    s->len = length;  
    *(s->ch + s->len) = '\0';  
    return OK;  
}  
//打印  
void PrintString(const HString* s) {  
    int i = 0;  
    while (*(s->ch + i) != '\0') {  
        printf("%c", *(s->ch + i));  
        i++;  
    }  
    printf("\n");  
}  
//求串的长度  
datatype GetLength(const HString* s) {  
    int len = 0;  
    while (*(s->ch + len) != '\0')  
        len++;  
    return len;  
}  
//查找某个字符的位置，返回位序  
datatype HSLocal(const HString* s, char c) {  
    int i;  
    for (i = 0; i < s->len; i++) {  
        if (c == *(s->ch + i))  
            return i + 1;  
    }  
    return -1;  
}  
//串的连接  
datatype HSCat(HString* s, const HString* t) {  
    int i = 0;  
    char* temp = (char*) malloc((s->len + t->len) * sizeof(char));  
    if (!temp)  
        return OVERFLOW;  
    for (i = 0; i < s->len; i++)  
        *(temp + i) = *(s->ch + i);  
    free(s->ch); //释放防止内存泄漏  
    for (i = 0; i < t->len; i++)  
        *(temp + i + s->len) = *(t->ch + i);  
    s->len += t->len;  
    s->ch = temp; //使s->ch重新指向temp  
    *(s->ch + s->len) = '\0';  
    return OK;  
}  
datatype HSCopy(HString* to, const HString* from) {  
    //如果目标串不为空则清空   if(to->ch)  
    {  
        free(to->ch);  
        to->ch = NULL;  
        to->len = 0;  
    }  
    int i = 0;  
    to->len = from->len;  
    to->ch = (char*) malloc(from->len * sizeof(char));  
    if (!to->ch)  
        return OVERFLOW;  
    for (i = 0; i < from->len; i++)  
        *(to->ch + i) = *(from->ch + i);  
    *(to->ch + to->len) = '\0';  
    return OK;  
  
}  
//在串s的pos位置处插入串t  
datatype HSInsert(HString* s, const HString *t, int pos) {  
    if (pos < 0 || pos > s->len)  
        return ERROR;  
    else {  
        s->ch = (char*) realloc(s->ch, (s->len + t->len) * sizeof(char));  
        int i, j = 1;  
        //后移  
        for (i = s->len + t->len - 1; i >= pos + t->len; i--) {  
            *(s->ch + i) = *(s->ch + (s->len - j));  
            j++;  
        }  
        //insert    
        for (i = 0; i < t->len; i++)  
            *(s->ch + i + pos) = *(t->ch + i);  
    }  
    s->len += t->len;  
    *(s->ch + s->len) = '\0';  
    return OK;  
}  
//在串s的index位置删除长度为x个字符  
datatype HSdel(HString* s, int index, int x) {  
    // index value invalid  
    if (index < 0 || index > s->len)  
        return ERROR;  
    //  if x+index> s->len  
    if ((index + x) >= s->len)  
        s->len = index;  
    else {  
        int i;  
        for (i = index; i < s->len; i++) {  
            *(s->ch + i) = *(s->ch + i + x);  
        }  
        s->len -= x;  
    }  
    *(s->ch + s->len) = '\0';  
    return OK;  
}  
//串比较  
datatype HScomp(const HString* s1, const HString* s2) {  
    int i = 0;  
    for (i = 0; i < s1->len && i < s2->len; i++) {  
        if (*(s1->ch + i) != *(s2->ch + i))  
            return *(s1->ch + i) - *(s2->ch + i);  
    }  
    if (i < s1->len) {  
        return 1;  
    } else if (i < s2->len) {  
        return -1;  
    } else {  
        return 0;  
    }  
}  
/*串的提取 
 *   在串s中的index开始长度为length的子串提取到temp串中 
 * */  
datatype HSsub(HString* temp, const HString* s, int index, int length) {  
    if (index < 0 || index > s->len)  
        return ERROR;  
    if (length > s->len)  
        length = s->len - index;  
    temp->len = length;  
    temp->ch = (char*) malloc(length * sizeof(char));  
    if (!temp->ch)  
        return OVERFLOW;  
    int i;  
    for (i = 0; i < length; i++) {  
        *(temp->ch + i) = *(s->ch + index + i);  
    }  
    *(temp->ch + temp->len) = '\0';  
    return OK;  
}  
//串的替换，把串s的从index开始长度为length的子串，用串t替换掉  
datatype HSReplace(HString* s, int index, int length, const HString*t) {  
    if (index < 0 || index > s->len)  
        return ERROR;  
    //如果length大于串s的长度就替换掉从index后的所有字符  
    if (length > s->len)  
        length = s->len;  
    int i;  
    for (i = 0; i < length; i++) {  
        *(s->ch + i + index) = *(t->ch + i);  
    }  
    *(s->ch + s->len) = '\0';  
    return OK;  
}  
int main(int argc, char** argv) {  
    // bulid string  
    HString S;  
    InitHString(&S);  
    assigment_string(&S, "hello world!");  
    PrintString(&S);  
    printf("length=%d\n", GetLength(&S));  
  
#if 0  
    //localion  
    int local=HSLocal(&S,'w');  
    printf("local=%d\n",local);  
    free(S.ch);  
#endif   
  
#if 0  
    // insert  
    HString S1;  
    InitHString(&S1);  
    assigment_string(&S1,"****");  
    HSInsert(&S,&S1,2);  
    PrintString(&S);  
    printf("length=%d\n",GetLength(&S));  
    free(S1.ch);  
#endif  
#if 0     
    // copy  
    HString S2;  
    InitHString(&S2);  
    assigment_string(&S2,"beijing");  
    HSCopy(&S,&S2);  
    PrintString(&S);  
    printf("length=%d\n",GetLength(&S));  
    free(S.ch);  
    free(S2.ch);  
#endif  
#if 0  
    //cat   
    HString S3;  
    InitHString(&S3);  
    assigment_string(&S3,"////");  
    HSCat(&S,&S3);  
    PrintString(&S);  
    printf("length=%d\n",GetLength(&S));  
    free(S3.ch);  
    free(S.ch);  
#endif   
  
#if 0  
    // delete   
    HSdel(&S,2,5);  
    PrintString(&S);  
    printf("length=%d\n",GetLength(&S));  
    free(S.ch);  
#endif   
  
#if 0  
    // complar   
    HString S4;  
    InitHString(&S4);  
    assigment_string(&S4,"hello world!");  
    datatype ret=HScomp(&S,&S4);  
    if(ret>0)  
    printf("S>S4\n");  
    else if(ret<0)  
    printf("S<S4\n");  
    else  
    printf("S=S4\n");  
    free(S4.ch);  
    free(S.ch);  
#endif  
  
#if 0  
    // sub  
    HString S5;  
    HSsub(&S5,&S,2,5);  
    PrintString(&S5);  
    printf("length=%d\n",GetLength(&S5));  
    free(S.ch);  
    free(S5.ch);  
#endif  
  
#if 1         
    // replace  
    HString S6;  
    InitHString(&S6);  
    assigment_string(&S6, "************************************");  
    HSReplace(&S, 2, 50, &S6);  
    PrintString(&S);  
    printf("length=%d\n", GetLength(&S));  
    free(S6.ch);  
    free(S.ch);  
  
#endif  
    //      free(S.ch);  
    return 0;  
}
