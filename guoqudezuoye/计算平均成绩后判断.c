#include <stdio.h>
#define n 5
int main(void)
{
	float sum;
	int k,m;
	k=1;
	sum=0;
	do{
		printf("please input ��ĳɼ���");
		scanf("%d",&m);
		sum=sum+m;
		k=k+1;
		
	}while(k<=n);
	printf("���ƽ���ɼ��ǣ�%0.2f",sum/n);
	return 0;
} 
