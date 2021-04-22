#include<stdio.h>
int main(void){
	int u,v,r;
	printf("请输入两个整数例如23 33：");
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
