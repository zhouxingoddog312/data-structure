#include<stdio.h>
//异或代替加法
int sum(int a,int b)
{
	int c;
	c=a^b;
	b=(a&b)<<1;
	while(b!=0)
	{
		a=c;
		c=a^b;
		b=(a&b)<<1;
	}
	return c;
}
int main(void)
{
	printf("%d\n",sum(5,3));
	return 0;
}
