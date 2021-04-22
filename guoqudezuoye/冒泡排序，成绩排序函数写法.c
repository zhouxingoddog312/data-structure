#include"stdio.h"
#define M 5
int i,a[M];
void sortofup(int s[],int n){     //对数组s进行冒泡排序 
	int i,r;
	bool flag;
	flag=true;
	while(flag){
		flag=false;
		for(i=0;i<n-1;i++){
		if(a[i]>a[i+1]){
			r=a[i];a[i]=a[i+1];a[i+1]=r;
			flag=true;
		}
	}
	}	
}
int main(){
	printf("please input your number:");
	for(	i=0;i<M;i++)         //输入
	scanf("%d",&a[i]);
	sortofup(a,M);         //调用函数 
	for(i=0;i<M;i++)             //打印
	printf("%4d",a[i]);
	getchar();
}
