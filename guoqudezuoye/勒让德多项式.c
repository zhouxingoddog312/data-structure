#include"stdio.h"
int main(void){
	float x,a,b,s,j;
	int n,i;
	scanf("%f%d",&x,&n);
	if(n==0)
	   b=1;
	else
	   if(n==1)
	      b=x;
	    else{
	    	a=1;b=x;s=0;
	    	for(i=2;i<=n;i++){
	    		j=b;
	    		b=((2*n-1)/(float)n)*x*b-((n-1)/(float)n)*a;
	    		a=j;
			}
		}
	printf("%.2f",b); 
}                 //结果未通过 
