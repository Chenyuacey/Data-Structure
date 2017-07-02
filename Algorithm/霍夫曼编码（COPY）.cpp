#include<stdio.h>  
#include<stdlib.h>  
#include<string.h>  
typedef struct Node{  
    int weight;//Ȩֵ   
    int parent;//���ڵ����ţ�Ϊ0��ʾ���ڵ�  
    int lchild,rchild;//���Һ��ӽڵ����ţ�Ϊ0����Ҷ�ӽڵ�   
}HTNode,*HuffmanTree;//�����洢ÿ��Ҷ�ӽڵ�Ļ���������  
typedef char **HuffmanCode;//�����洢ÿ���ڵ�Ļ���������   
  
//��HT�����ǰk��Ԫ����ѡ��weight��С��parentΪ0��Ԫ�أ�������Ԫ�ص��±귵��  
int min(HuffmanTree HT,int k)  
{  
    int i=0;  
    int min;//�������weight��С��parentΪ0��Ԫ�ص��±�   
    int min_weight;//�������weight��С��parentΪ0��Ԫ�ص�weightֵ��temp   
      
    //ע��Ӧ�Ƚ���һ��parentΪ0��Ԫ�ص�weightֵ����min_weight,�����Ժ�Ƚ���  
    //��Ҫֱ�ӽ�HT[0].weight����min_weight�ˣ����Ǹ����õļ��ɣ�  
    while(HT[i].parent!=0) i++;  
    min_weight=HT[i].weight;  
    min=i;  
      
    //ѡ��weight��С��parentΪ0��Ԫ�أ���������Ÿ���min  
    for(;i<k;++i){  
        if(HT[i].weight<min_weight&&HT[i].parent==0){  
            min_weight=HT[i].weight;  
            min=i;  
        }  
    }  
      
    //ע�⣬ѡ��weight��С��Ԫ�غ󣬽���parent��1��ʹ����һ����ڶ�Сʱ�����ų�����  
    HT[min].parent=1;  
    return min;//�����±�      
}  
  
void select_min(HuffmanTree HT,int k,int &min1,int &min2)//&Ϊ����   
{  
    min1=min(HT,k);  
    min2=min(HT,k);  
}  
  
HuffmanTree create_HuffmanTree(int *wet,int n)  
{  
    //һ����n��Ҷ�ӽڵ�Ļ�����������2n-1���ڵ�(�ص�)   
    int total=2*n-1;  
    HuffmanTree HT=(HuffmanTree)malloc(total*sizeof(HTNode));  
    if(!HT){  
        printf("HuffmanTree malloc failed!\n");  
    }  
      
    int i;  
    for(i=0;i<n;++i){//�ȹ���n��Ҷ�ڵ�   
        HT[i].parent=0;//parent�����ı�   
        HT[i].lchild=0;  
        HT[i].rchild=0;  
        HT[i].weight=*wet;  
        wet++;  
    }  
      
    //HT[n],HT[n+1]...HT[2n-2]�д�ŵ����м乹�����ÿ�ö������ĸ��ڵ�  
    for(;i<total;++i){  
        HT[i].parent=0;  
        HT[i].lchild=0;  
        HT[i].rchild=0;  
        HT[i].weight=0;  
    }  
      
    int min1,min2;//��������ÿһ��ѡ��������weight��С��parentΪ0�Ľڵ��±�   
      
      
    //ÿһ�ֱȽϺ�ѡ���min1��min2����һ�ζ�����,��󹹳�һ�úշ�����  
    for(i=n;i<total;++i){  
        select_min(HT,i,min1,min2);//Ѱ��i֮ǰ�Ľ��   
        HT[min1].parent=i;  
        HT[min2].parent=i;//������СȨֵ�Ľ�㹹������  
          
        //ע���������Ӻ��Һ��ӿ��Է����������ɵ�Ҳ��һ�úշ�������ֻ�����õı��벻ͬ  
        HT[i].lchild=min1;  
        HT[i].rchild=min2;  
        HT[i].weight=HT[min1].weight+HT[min2].weight;   
    }  
    return HT;   
}  
  
void HuffmanCoding(HuffmanTree HT,HuffmanCode &HC,int n)  
{  
    //��������ָ��ÿ�����������봮��ָ�루ָ���ָ�룩  
    HC=(HuffmanCode)malloc(n*sizeof(char *));//ע��char *  
    if(!HC){  
        printf("HuffmanCode malloc failed!\n");  
        exit(-1);  
    }  
      
    //��ʱ�ռ䣬��������ÿ����õ�һ���շ������봮  
    char *code=(char *)malloc(30*sizeof(char));//30Ӧ�ù�����  
    if(!code){  
        printf("code malloc failed!\n");  
        exit(-1);  
    }    
    code[29]='\0';//����������������ַ�����Ľ�����־  
      
    //������ÿ���ַ��ĺշ�������  
    int i;  
    for(int i=0;i<n;++i){//��Ҷ�������Ҹ�   
        int current=i;//���嵱ǰ���ʵĽ��  
        int fa=HT[i].parent;//���嵱ǰ�ڵ�ĸ��ڵ�  
        int start=29;//ÿ�α����λ�ã���ʼΪ�����������λ��  
        //��Ҷ�ӽڵ�����շ�����ֱ�����ڵ�  
        while(fa!=0)  
        {  
            if(HT[fa].lchild==current)  
                code[--start]='0';  
            else code[--start]='1';  
            current=fa;  
            fa=HT[current].parent;  
        }  
          
        //Ϊ��i���ַ��ı��봮����洢�ռ�  
        HC[i]=(char *)malloc((29-start+1)*sizeof(char));//+1��Ϊ�˴�'\0'   
        if(!HC[i]){  
            printf("HC[i] malloc failed!\n");  
            exit(-1);  
        }  
        strcpy(HC[i],code+start);//�����봮������start����~\0���Ƶ�HC��   
    }  
    free(code);//�ͷű���ÿһ���ַ��������������ʱ�ռ�  
}  
  
int main()  
{  
    int n;//��Ҫ������ַ���  
    printf("��������Ҫ������ַ��ĸ���(>1):\n");  
    scanf("%d",&n);  
    while(n<=1){  
        printf("�ַ������������1����������룺");  
        scanf("%d",&n);  
    }  
       
    int *wet=(int *)malloc(n*sizeof(int));//wet�ڴ���Ȩֵ  
    printf("��������%d���ַ���Ȩֵ�����ͣ�:",n);  
    for(int i=0;i<n;++i){//���ڱ��룬Ȩֵ�ͳ���Ƶ���й�   
        scanf("%d",wet+i);  
    }  
      
    HuffmanCode HC;//��������ÿ���ַ��Ļ���������,ָ���ָ��   
    HuffmanTree HT=create_HuffmanTree(wet,n);//���������ɻ�������   
    HuffmanCoding(HT,HC,n);//���ÿ���ַ��Ļ���������  
      
    printf("���ַ���ӦȨֵ�Ļ���������Ϊ(��������˳��):\n");  
    for(int i=0;i<n;++i){  
        printf("%d : ",*(wet+i));  
        puts(HC[i]);  
    }  
    free(wet);  
    return 0;   
}
