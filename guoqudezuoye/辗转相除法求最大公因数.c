#include<stdio.h>
int main(void){
	int u,v,r;
	printf("������������������23 33��");
	scanf("%d%d",&u,&v);
	r=v;
	while(r!=0){
		r=u%v;
		u=v;
		v=r;
	}
	printf("%d",u);
	getchar();
}
