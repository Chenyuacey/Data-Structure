#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int num[10000],F[10000];


int Binary_Search(int *a,int n,int key){  //折半查找 
	int low,high,mid;
	low=1;
	high=n;
	while(low<=high){
		mid=(low+high)/2;
		if(key<a[mid]) high=mid-1;
		else if(key>a[mid]) low=mid+1;
		else if(key==a[mid]) return mid;
	}
	return 0;
}

int Interpolation_Search(int *a,int n,int key){  //插值查找，适用于表长大，关键字分布均匀 
	int low,high,mid;
	low=1;
	high=n;
	while(low<=high){
		mid=low+(high-low)*(key-a[low])/(a[high]-a[low]);   //与折半查找的区别只有这一句 
		if(key<a[mid]) high=mid-1;
		else if(key>a[mid]) low=mid+1;
		else if(key==a[mid]) return mid;
	}
	return 0;
}
//斐波那契查找 三个函数 
int fib(int n){
	if(n==1||n==2)
	 return 1;
	return fib(n-1)+fib(n-2);
}
int Fibonacci(int n){
	for(int i=1;i<n;i++){
		F[i]=fib(i); 
	}
}

int Fibonacci_Search(int *a,int n,int key){  //斐波那契查找 
	int low,high,mid,i,k;
	low=1;
	high=n;
	k=0;
	while(n>F[k]-1)
		k++;
	for(i=n;i<F[k]-1;i++)
		a[i]=a[n];
		
	while(low<=high){
		mid=low+F[k-1]-1;
		if(key<a[mid]){
			high=mid-1;
			k=k-1;
		}
		else if(key>a[mid]){
			low=mid+1;
			k=k-2;
		}
		else {
			if(mid<=n)
				return mid;
			else 
				return n;
		}
	}
	return 0;
}
int main(){
	int *ar;
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>num[i];
	ar=num;
	int key;
	cin>>key;
	Fibonacci(5); 
	int ans=Fibonacci_Search(ar,n,key);
	cout<<ans;
	return 0;
}
