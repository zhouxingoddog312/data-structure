#include<stdio.h>
int main(void)
{
int n,k;
float sum;
sum=0;
k=1;
printf("please input n:");
scanf("%d",&n);
do{
	sum+=1.0/(k*(k+1));
	k++;
}while(k<=n);
printf("sum=%f\n",sum);
return 0;
}
