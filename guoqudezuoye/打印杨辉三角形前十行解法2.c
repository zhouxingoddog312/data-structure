#include<stdio.h>
#define n 10             //定义常量10行，每个字符宽度为4 
#define wide 4
int main(void){
	int i,j,a[10]; 
	for(i=0;i<n;i++){        //0~9十次循环，打印十行 
		a[i]=1;             //a[0]、a[i]赋值为1
		for(j=i-1;j>0;j--)    //从后向前算，计算下一行 
		   a[j]=a[j]+a[j-1];
		for(j=0;j<(40-i*(wide/2));j++)//i代表当前行数字个数，打印空格数
		   printf(" ");
		for(j=0;j<=i;j++)          //打印a[0]到a[i] 
		   printf("%4d",a[j]);
		printf("\n");
	}
	getchar();
} 
