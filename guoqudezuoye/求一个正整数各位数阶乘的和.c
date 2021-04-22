#include<stdio.h>
int main(void){
	int N,S,P,r,u;
	printf("请输入一个正整数：");
	scanf("%d",&N);
	S=0;
	while(N!=0){
		r=N%10;                //分离正整数的个位数 
		N=N/10;                //去除正整数的个位数 
		P=1;                 //在这个循环中p，u必须重新归为1 
	    u=1;                 //在这个循环中p，u必须重新归为1 
         /*下面这个循环用来求阶乘*/
		while(u<=r){
		P=P*u;               
		u=u+1;	
		}
		S=S+P;
	}
	printf("正整数各位数阶乘的和为：%d",S);
	getchar();
} 
