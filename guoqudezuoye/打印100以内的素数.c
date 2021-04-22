#include<stdio.h>
int i,j,flag;
int main(void){
	for(i=2;i<=100;i++)
	{flag=true;
	for(j=i/2;j>=2;j--){
	if(i%j==0)
	flag=false;
	}	
	if(flag)
	printf("%5d\n",i); 
	}
	getchar();
} 
