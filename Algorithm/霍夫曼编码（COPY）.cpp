#include<stdio.h>  
#include<stdlib.h>  
#include<string.h>  
typedef struct Node{  
    int weight;//权值   
    int parent;//父节点的序号，为0表示根节点  
    int lchild,rchild;//左右孩子节点的序号，为0的是叶子节点   
}HTNode,*HuffmanTree;//用来存储每个叶子节点的霍夫曼编码  
typedef char **HuffmanCode;//用来存储每个节点的霍夫曼编码   
  
//从HT数组的前k个元素中选出weight最小且parent为0的元素，并将该元素的下标返回  
int min(HuffmanTree HT,int k)  
{  
    int i=0;  
    int min;//用来存放weight最小且parent为0的元素的下标   
    int min_weight;//用来存放weight最小且parent为0的元素的weight值的temp   
      
    //注意应先将第一个parent为0的元素的weight值赋给min_weight,留作以后比较用  
    //不要直接将HT[0].weight赋给min_weight了（这是个常用的技巧）  
    while(HT[i].parent!=0) i++;  
    min_weight=HT[i].weight;  
    min=i;  
      
    //选出weight最小且parent为0的元素，并将其序号赋给min  
    for(;i<k;++i){  
        if(HT[i].weight<min_weight&&HT[i].parent==0){  
            min_weight=HT[i].weight;  
            min=i;  
        }  
    }  
      
    //注意，选出weight最小的元素后，将其parent置1，使得下一次求第二小时将其排除在外  
    HT[min].parent=1;  
    return min;//返回下标      
}  
  
void select_min(HuffmanTree HT,int k,int &min1,int &min2)//&为引用   
{  
    min1=min(HT,k);  
    min2=min(HT,k);  
}  
  
HuffmanTree create_HuffmanTree(int *wet,int n)  
{  
    //一颗有n个叶子节点的霍夫曼树共有2n-1个节点(特点)   
    int total=2*n-1;  
    HuffmanTree HT=(HuffmanTree)malloc(total*sizeof(HTNode));  
    if(!HT){  
        printf("HuffmanTree malloc failed!\n");  
    }  
      
    int i;  
    for(i=0;i<n;++i){//先构造n个叶节点   
        HT[i].parent=0;//parent后面会改变   
        HT[i].lchild=0;  
        HT[i].rchild=0;  
        HT[i].weight=*wet;  
        wet++;  
    }  
      
    //HT[n],HT[n+1]...HT[2n-2]中存放的是中间构造出的每棵二叉树的根节点  
    for(;i<total;++i){  
        HT[i].parent=0;  
        HT[i].lchild=0;  
        HT[i].rchild=0;  
        HT[i].weight=0;  
    }  
      
    int min1,min2;//用来保存每一轮选出的两个weight最小且parent为0的节点下标   
      
      
    //每一轮比较后选择出min1和min2构成一课二叉树,最后构成一棵赫夫曼树  
    for(i=n;i<total;++i){  
        select_min(HT,i,min1,min2);//寻找i之前的结点   
        HT[min1].parent=i;  
        HT[min2].parent=i;//两个最小权值的结点构成子树  
          
        //注意这里左孩子和右孩子可以反过来，构成的也是一棵赫夫曼树，只是所得的编码不同  
        HT[i].lchild=min1;  
        HT[i].rchild=min2;  
        HT[i].weight=HT[min1].weight+HT[min2].weight;   
    }  
    return HT;   
}  
  
void HuffmanCoding(HuffmanTree HT,HuffmanCode &HC,int n)  
{  
    //用来保存指向每个霍夫曼编码串的指针（指针的指针）  
    HC=(HuffmanCode)malloc(n*sizeof(char *));//注意char *  
    if(!HC){  
        printf("HuffmanCode malloc failed!\n");  
        exit(-1);  
    }  
      
    //临时空间，用来保存每次求得的一个赫夫曼编码串  
    char *code=(char *)malloc(30*sizeof(char));//30应该够用了  
    if(!code){  
        printf("code malloc failed!\n");  
        exit(-1);  
    }    
    code[29]='\0';//编码结束符，亦是字符数组的结束标志  
      
    //下面求每个字符的赫夫曼编码  
    int i;  
    for(int i=0;i<n;++i){//从叶子向上找根   
        int current=i;//定义当前访问的结点  
        int fa=HT[i].parent;//定义当前节点的父节点  
        int start=29;//每次编码的位置，初始为编码结束符的位置  
        //从叶子节点遍历赫夫曼树直到根节点  
        while(fa!=0)  
        {  
            if(HT[fa].lchild==current)  
                code[--start]='0';  
            else code[--start]='1';  
            current=fa;  
            fa=HT[current].parent;  
        }  
          
        //为第i个字符的编码串分配存储空间  
        HC[i]=(char *)malloc((29-start+1)*sizeof(char));//+1是为了存'\0'   
        if(!HC[i]){  
            printf("HC[i] malloc failed!\n");  
            exit(-1);  
        }  
        strcpy(HC[i],code+start);//将编码串从最后的start编码~\0复制到HC上   
    }  
    free(code);//释放保存每一个字符霍夫曼编码的临时空间  
}  
  
int main()  
{  
    int n;//需要编码的字符数  
    printf("请输入需要编码的字符的个数(>1):\n");  
    scanf("%d",&n);  
    while(n<=1){  
        printf("字符个数必须大于1，请从新输入：");  
        scanf("%d",&n);  
    }  
       
    int *wet=(int *)malloc(n*sizeof(int));//wet内存存放权值  
    printf("请输入这%d个字符的权值（整型）:",n);  
    for(int i=0;i<n;++i){//对于编码，权值和出现频率有关   
        scanf("%d",wet+i);  
    }  
      
    HuffmanCode HC;//用来保存每个字符的霍夫曼编码,指针的指针   
    HuffmanTree HT=create_HuffmanTree(wet,n);//用数组生成霍夫曼树   
    HuffmanCoding(HT,HC,n);//求解每个字符的霍夫曼编码  
      
    printf("各字符对应权值的霍夫曼编码为(按照输入顺序):\n");  
    for(int i=0;i<n;++i){  
        printf("%d : ",*(wet+i));  
        puts(HC[i]);  
    }  
    free(wet);  
    return 0;   
}
