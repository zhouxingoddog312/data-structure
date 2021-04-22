#include <stdio.h>
#define n 5
int main(void)
{
	float sum;
	int k,m;
	k=1;
	sum=0;
	do{
		printf("please input 你的成绩：");
		scanf("%d",&m);
		sum=sum+m;
		k=k+1;
		
	}while(k<=n);
	printf("你的平均成绩是：%0.2f",sum/n);
	return 0;
} 
