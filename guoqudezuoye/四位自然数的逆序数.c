#include<stdio.h>
int x,a,b,c,d,e;
int  nixu(int x);
int main(void){
	scanf("%d",&x);
	if(x>=1000&&x<=9999){
		e=nixu(x);
		printf("%d",e);
    }
	else
       printf("0");
}
int  nixu(int x){
	a=(x/1000)%10;
	b=(x/100)%10;
	c=(x/10)%10;
	d=(x)%10;
	return (1000*d+100*c+10*b+a);
}
