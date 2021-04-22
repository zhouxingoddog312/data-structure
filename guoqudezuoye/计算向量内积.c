#include"stdio.h"
int main(void){
	int n,i;
	float xy,xi,yi;
	xy=0;
	printf("please input n:");
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		printf("please input xi yi:");
		scanf("%f%f",&xi,&yi);
		xy=xy+xi*yi;
	}
	printf("xy=%f",xy);
	return 0;
}
