#include<stdio.h>
#define n 5             //定义常量n，即有几个数字 
int main(){
	int i,r,a[n];
	bool flag;          //定义布尔数flag 
	flag=true;            //赋值为真 
	printf("please input your number:");
	for(i=0;i<n;i++)     //输入 
	scanf("%d",&a[i]);
	while(flag==true){      //利用flag判断是否继续循环 
		flag=false;
		for(i=0;i<(n-1);i++){          //从下标0到n-1依次判断 
			if(a[i]>a[i+1]){
				r=a[i];a[i]=a[i+1];a[i+1]=r;flag=true;     //交换 
			}
		}
	}
	for(i=0;i<n;i++)            //打印 
	printf("%4d",a[i]);
	getchar();
}
