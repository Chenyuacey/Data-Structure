#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

typedef struct Node{
	int weight;  //权值 
	int parent;  //父节点序号，0表示根节点 
	int lch,rch; //左右孩子节点序号，0为叶子节点 
}HTNode ,*HuffmanTree;//储存每个叶子节点的哈夫曼编码 
typedef char **HuffmanCode;  //储存每个节点的哈夫曼编码 

int min(HuffmanTree HT,int k){
	int i=0;
	int min;// 用来存放weight最小且parent为0的元素的下标 
	int min_weight;//temp值
	while(HT[i].parent!=0) i++;
	min_weight=HT[i].weight;
	min=i;
	
	//选出weight最小的且parent为0的元素 ，将其序号赋值给min
	for(;i<k;i++){
		if(HT[i].weight<min_weight&&HT[i].parent==0 ){
			min_weight=HT[i].weight;
			min=i;
		} 
	} 
	//将weight最小的元素的parent置为1，下一次求第二小时将其排除在外 
	HT[min].parent=1;
	return min;
}

int select_min(HuffmanTree HT,int k,int &min1,int &min2){
	min1=min(HT,k);
	min2=min(HT,k);
}

HuffmanTree create_HuffmanTree(int *wet,int n){
	//哈夫曼树特点：N个叶子节点，共有2N-1个节点
	int total=2*n-1;
	HuffmanTree HT=(HuffmanTree )malloc(total*sizeof(HTNode));
	if(!HT){
		cout<<"Malloc Failue!";
	} 
	int i;
	
	//建立N个叶节点 
	for(i=0;i<n;i++){
		HT[i].parent=0;  //parent之后会改变（在建立哈夫曼树时，产生根节点）
		HT[i].lch=HT[i].rch=0;
		HT[i].weight=*wet;
		wet++; 
	}
	//HT[n],HT[n+1]...HT[2n-2]中存放的是中间构造出的每棵二叉树的根节点
	for(;i<total;i++) {
		HT[i].parent=0;
		HT[i].lch=HT[i].rch=0;
		HT[i].weight=0;
	}
	
	int min1,min2;//保存每一轮选出的两个weight值最小（哈夫曼的意义）且parent为0（无根节点，筛选作用）的节点下标 
	//每一轮比较之后选出min1,min2构成一颗二叉树，最后成为一颗树（即为所求哈夫曼树）
	for(i=n;i<total;i++){
		select_min(HT,i,min1,min2);  //在i之前寻找叶节点（前文）,min由于用了引用&，可带回值 
		//将i赋min1，min2 的根节点 
		HT[min1].parent=i;
		HT[min2].parent=i;
		//给i的左右孩子赋值 ，即为刚求出的min1,min2 
		HT[i].lch=min1;
		HT[i].rch=min2;
		HT[i].weight=HT[min1].weight+HT[min2].weight;//权值为左右孩子的和 
	} 
	return HT;
}

void HuffmanCoding(HuffmanTree HT,HuffmanCode &HC,int n){
	//用来保存指向每个哈夫曼编码串的指针
	HC=(HuffmanCode)malloc(n*sizeof(char *));  //注意申请的指针类型char *
	if(!HC ) {
		cout<<"HuffmanCode malloc FAILED"<<endl;
		exit(0);
	} 
	
	//临时空间，保存每一次求得的一个哈夫曼编码串
	char *code=(char *)malloc(30*sizeof(char));
	if(!code) {
		cout<<"Code malloc FAILED"<<endl;
		exit(0);
	} 
	code[29]='\0';
	//求每个字符的哈夫曼编码
	int i;
	for(int i=0;i<n;i++){
		int current=i;//定义当前访问的节点 
		int fa=HT[i].parent;//定义当前节点的父节点 
		int start = 29;//每次编码位置，初始为编码结束符的位置
		//从叶子节点开始遍历到根节点为止
		while(fa!=0){
			if(HT[fa].lch==current) code[--start]='0';
			else code[--start]='1';
			current=fa;
			fa=HT[current].parent;
		}
		 HC[i]=(char *)malloc((29-start+1)*sizeof(char));
		 if(!HC) {
		 	cout<<"HC[i] malloc failed"<<endl;
			exit(0); 
		 }
		 strcpy(HC[i],code+start);
	} 
	free(code);
}



int main(){
	int n;           //需要编码的字符个数 
	cout<<"输入要编码的字符个数：";
	cin>>n;
	while(n<=1){
		cout<<"字符个数必须大于1！请重新输入：";
		cin>>n;
	}
	int *wet=(int *)malloc(n*sizeof(int));  //wet存放权值 
	cout<<"请输入这"<<n<<"个字符的权值(int型) :";
	for(int i=0;i<n;i++) cin>>*(wet+i);
	
	HuffmanCode HC;   //保存每个字符的哈夫曼编码 （HuffmanCode为指针的指针类型） 
	HuffmanTree HT=create_HuffmanTree(wet,n);//生成哈夫曼树（数组） 
	HuffmanCoding(HT,HC,n);//求解每个字符的哈夫曼编码 
	
	cout<<"各个字符对应权值的哈夫曼编码为："<<endl;
	for(int i=0;i<n;i++){
		cout<<(*(wet+i))<<" ";
		//puts(HC[i]);
		cout<<HC[i]<<endl; 
	} 
	free(wet);
	return 0;
}
