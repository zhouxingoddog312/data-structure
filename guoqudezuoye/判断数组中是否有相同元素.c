#include<stdio.h>
int a[3][3],i,j,k,r,s;
int main(void){
	for(i=0;i<3;i++)
	   for(j=0;j<3;j++)
	      scanf("%d",&a[i][j]);
	for(i=0;i<3;i++)
	for(j=0;j<3;j++){ 
	            if(a[i][j]!=a[i+1][j+1])
	                s=0;
	            else
	                s=1;
				}
	if(s==0)
	printf("no");
	else
	printf("yes"); 
	      getchar();
}
