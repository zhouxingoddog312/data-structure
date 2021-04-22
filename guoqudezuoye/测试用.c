#include<stdio.h>
int m,n,i,j,k,e,x,a,b;

int main(){
	scanf("%d%d",&a,&b);
	i=1;
	for(x=1;x<=(a-b);x++)        
		i=i*x;             
	j=1;
	for(x=1;x<=b;x++)    
	    j=j*x;
	k=1;
	for(x=1;x<=a;x++)
	    k=k*x;		   
	e=k/(i*j);	
	printf("%d",e);
	getchar();}
