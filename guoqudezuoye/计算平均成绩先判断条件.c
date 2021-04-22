#include<stdio.h>
#define n 5
int k,m;
float sum;
int main(void){
sum=0;
k=1;
	while(k<=n){
		printf("please input:");
		scanf("%d",&m);
		sum=sum+m;
		k++;
	}
	printf("平均成绩是：%.2f",sum/n);
	return 0;
}
