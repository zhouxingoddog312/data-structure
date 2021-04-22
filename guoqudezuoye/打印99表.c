#include"stdio.h"
int i,j,k;
int main(void){
	for(i=1;i<=9;i++){
		printf("%4d",i);                  //打印行标 
		for(j=1;j<=i;j++)       
			printf("%4d",i*j);             //分行打印数据结果 
			printf("\n");               //换行 
	}
	printf("%4c",'*');                 //打印*号 
	for(i=1;i<=9;i++){
	printf("%4d",i);                  //打印列标 
	} 
	getchar();
}
