#include<stdio.h>
int i,j,a[10],b[10];
int main(){
	for(i=0;i<10;i++)
	   scanf("%d",&b[i]);
	scanf("%d",&j);   
	for(i=0;i<10;i++){
		if((i+j)<=9&&(i+j)>=0)
	   a[i+j]=b[i];
	   else
	   a[(i+j-10)]=b[i];
	}  
	for(i=0;i<10;i++)
	printf("%d",a[i]);
	getchar();
	
}
