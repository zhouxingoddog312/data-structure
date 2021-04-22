#include<stdio.h>
int yy,n;
int main(void){
	printf("please input the begin year:");
	scanf("%d",&yy);
	printf("please input the number of the leep year:");
	scanf("%d",&n);
	yy=(yy/4+1)*4;
	do{
		if((yy%4==0)&&(yy%100!=0)||(yy%400==0)){ 
		printf("year:%d\n",yy);
	n--;}
	yy=yy+4;
	}while(n>0);
	return 0;
}
