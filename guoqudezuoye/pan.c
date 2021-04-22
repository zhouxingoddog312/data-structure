#include"stdio.h"
#include"math.h"
int main(void){
	int a,b,c,d;
	scanf("%d",&d);
	c=(d%10);
	a=(d/100);
	b=(d-100*a-c)/10;
	if((a*a*a+b*b*b+c*c*c)==(a*100+b*10+c*1))
	printf("yes");
	else
	printf("no");
	return 0;
}
