#include"stdio.h"
int main(void){
	float x,k,i,s;
	k=1;
	s=1;
	scanf("%f",&x);
	for(i=1;i<=99;i++){
		k=k*x/((float)i);
	s=s+k;
	}
	printf("%.2f",s);
	getchar();
}
