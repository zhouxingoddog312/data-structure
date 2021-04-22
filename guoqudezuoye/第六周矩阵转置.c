#include<stdio.h>
int a[3][3],i,j,k,r;
int main(void){
	for(i=0;i<3;i++)
	   for(j=0;j<3;j++)
	      scanf("%d",&a[i][j]);
	for(i=0;i<3;i++)
	   for(j=0;j<3;j++){
	   	k=a[i][j];
	   	a[i][j]=a[2-i][2-j];
	   	a[2-i][2-j]=k;
	   }
	for(i=0;i<3;i++)
	   for(j=0;j<3;j++) 
	      printf("%d",a[i][j]);	      
} 
