#include"stdio.h"
#define M 5
int s,t[M];
void sort(int a[],int n){           //插入排序的函数 
	int i,j,k,r;
	for(i=1;i<n-1;i++){
		j=i-1;
		while((a[j]>a[i])&&j>=0){    //找位置，a[i]插入a[j]与a[j+1]之间 
			j--;
		}
		r=a[i];
		for(k=i-1;k>=j+1;k--)         //a[j+1]至a[i-1]整体向后移一位 
		   a[k+1]=a[k];
		a[j+1]=r;                  //a[i]送入a[j+1] 
	}
} 
int main(){
	printf("please input your number:");
	for(	s=0;s<M;s++)          //输入
	scanf("%d",&t[s]);
	sort(t,M);         //调用函数 
	for(s=0;s<M;s++)             //打印
	printf("%4d",t[s]);
	getchar();
}
