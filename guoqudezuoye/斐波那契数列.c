#include"stdio.h"
int main(void){
	int i,n,A,a,x;
	A=0;
	a=1;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		x=A;
		A=A+a;
		a=x;
	}
	printf("%d",(A+a));
}
