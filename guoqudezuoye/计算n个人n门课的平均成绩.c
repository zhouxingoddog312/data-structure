#include"stdio.h"
#define n 4                                       //定义科目数 
#define p 5                                      //定义人数 
int main(void){
	float sum,m;                                 //总分数与单门分数 
	int i,j,k;
	for(i=1;i<=p;i++){                           //人数计数循环 
		sum=0;                                              
		k=1;
		do{                                                          
			printf("please input NO%2d-%2d achievement:",i,k);                   //输入单科成绩 
			scanf("%f",&m);
			sum=sum+m;
			k=k+1;
		}while(k<=n);                                                     
	printf("NO%2d:average achievement:%5.2f\n",i,sum/n);
	}
}
