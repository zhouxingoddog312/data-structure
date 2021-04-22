#include<stdio.h>
int main(){
	int data,n;
	scanf("%d",&data);
	for(n=1;n<data;++n)
	if(n%11==0)
	printf("%d",n);
	return 0;
}
