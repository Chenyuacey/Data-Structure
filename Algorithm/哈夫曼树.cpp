#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

typedef struct Node{
	int weight;  //Ȩֵ 
	int parent;  //���ڵ���ţ�0��ʾ���ڵ� 
	int lch,rch; //���Һ��ӽڵ���ţ�0ΪҶ�ӽڵ� 
}HTNode ,*HuffmanTree;//����ÿ��Ҷ�ӽڵ�Ĺ��������� 
typedef char **HuffmanCode;  //����ÿ���ڵ�Ĺ��������� 

int min(HuffmanTree HT,int k){
	int i=0;
	int min;// �������weight��С��parentΪ0��Ԫ�ص��±� 
	int min_weight;//tempֵ
	while(HT[i].parent!=0) i++;
	min_weight=HT[i].weight;
	min=i;
	
	//ѡ��weight��С����parentΪ0��Ԫ�� ��������Ÿ�ֵ��min
	for(;i<k;i++){
		if(HT[i].weight<min_weight&&HT[i].parent==0 ){
			min_weight=HT[i].weight;
			min=i;
		} 
	} 
	//��weight��С��Ԫ�ص�parent��Ϊ1����һ����ڶ�Сʱ�����ų����� 
	HT[min].parent=1;
	return min;
}

int select_min(HuffmanTree HT,int k,int &min1,int &min2){
	min1=min(HT,k);
	min2=min(HT,k);
}

HuffmanTree create_HuffmanTree(int *wet,int n){
	//���������ص㣺N��Ҷ�ӽڵ㣬����2N-1���ڵ�
	int total=2*n-1;
	HuffmanTree HT=(HuffmanTree )malloc(total*sizeof(HTNode));
	if(!HT){
		cout<<"Malloc Failue!";
	} 
	int i;
	
	//����N��Ҷ�ڵ� 
	for(i=0;i<n;i++){
		HT[i].parent=0;  //parent֮���ı䣨�ڽ�����������ʱ���������ڵ㣩
		HT[i].lch=HT[i].rch=0;
		HT[i].weight=*wet;
		wet++; 
	}
	//HT[n],HT[n+1]...HT[2n-2]�д�ŵ����м乹�����ÿ�ö������ĸ��ڵ�
	for(;i<total;i++) {
		HT[i].parent=0;
		HT[i].lch=HT[i].rch=0;
		HT[i].weight=0;
	}
	
	int min1,min2;//����ÿһ��ѡ��������weightֵ��С�������������壩��parentΪ0���޸��ڵ㣬ɸѡ���ã��Ľڵ��±� 
	//ÿһ�ֱȽ�֮��ѡ��min1,min2����һ�Ŷ�����������Ϊһ��������Ϊ�������������
	for(i=n;i<total;i++){
		select_min(HT,i,min1,min2);  //��i֮ǰѰ��Ҷ�ڵ㣨ǰ�ģ�,min������������&���ɴ���ֵ 
		//��i��min1��min2 �ĸ��ڵ� 
		HT[min1].parent=i;
		HT[min2].parent=i;
		//��i�����Һ��Ӹ�ֵ ����Ϊ�������min1,min2 
		HT[i].lch=min1;
		HT[i].rch=min2;
		HT[i].weight=HT[min1].weight+HT[min2].weight;//ȨֵΪ���Һ��ӵĺ� 
	} 
	return HT;
}

void HuffmanCoding(HuffmanTree HT,HuffmanCode &HC,int n){
	//��������ָ��ÿ�����������봮��ָ��
	HC=(HuffmanCode)malloc(n*sizeof(char *));  //ע�������ָ������char *
	if(!HC ) {
		cout<<"HuffmanCode malloc FAILED"<<endl;
		exit(0);
	} 
	
	//��ʱ�ռ䣬����ÿһ����õ�һ�����������봮
	char *code=(char *)malloc(30*sizeof(char));
	if(!code) {
		cout<<"Code malloc FAILED"<<endl;
		exit(0);
	} 
	code[29]='\0';
	//��ÿ���ַ��Ĺ���������
	int i;
	for(int i=0;i<n;i++){
		int current=i;//���嵱ǰ���ʵĽڵ� 
		int fa=HT[i].parent;//���嵱ǰ�ڵ�ĸ��ڵ� 
		int start = 29;//ÿ�α���λ�ã���ʼΪ�����������λ��
		//��Ҷ�ӽڵ㿪ʼ���������ڵ�Ϊֹ
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
	int n;           //��Ҫ������ַ����� 
	cout<<"����Ҫ������ַ�������";
	cin>>n;
	while(n<=1){
		cout<<"�ַ������������1�����������룺";
		cin>>n;
	}
	int *wet=(int *)malloc(n*sizeof(int));  //wet���Ȩֵ 
	cout<<"��������"<<n<<"���ַ���Ȩֵ(int��) :";
	for(int i=0;i<n;i++) cin>>*(wet+i);
	
	HuffmanCode HC;   //����ÿ���ַ��Ĺ��������� ��HuffmanCodeΪָ���ָ�����ͣ� 
	HuffmanTree HT=create_HuffmanTree(wet,n);//���ɹ������������飩 
	HuffmanCoding(HT,HC,n);//���ÿ���ַ��Ĺ��������� 
	
	cout<<"�����ַ���ӦȨֵ�Ĺ���������Ϊ��"<<endl;
	for(int i=0;i<n;i++){
		cout<<(*(wet+i))<<" ";
		//puts(HC[i]);
		cout<<HC[i]<<endl; 
	} 
	free(wet);
	return 0;
}
