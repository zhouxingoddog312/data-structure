#include"stdio.h"
#define radix 10
int main(void){
	int n;                       //和单元的保存变量 
	char ch;
	ch=getchar();
	while(ch<'0'||ch>'9')         //过滤前导空格 
	   ch=getchar();
n=0;                              //和单元变量归零 
	while(ch>'0'&&ch<'9'){
			n=n*radix+(int(ch)-'0');  //把ch装换成数字值再相加 
	        ch=getchar();
	}
printf("%d",n);
getchar();
}
