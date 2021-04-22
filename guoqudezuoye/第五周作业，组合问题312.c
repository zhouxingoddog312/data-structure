#include<stdio.h>
int m,n,i,j,k,e,x,a,b;
int zuhe(int a,int b){
	i=1;
	for(x=1;x<=(a-b);x++)        
		i=i*x;             
	j=1;
	for(x=1;x<=b;x++)    
	    j=j*x;
	k=1;
	for(x=1;x<=a;x++)
	    k=k*x;		   
return k/(i*j);		   
}
int main(void){
	scanf("%d%d",&m,&n);
	if(m<n&&m>0&&n>0)
	    e=0;
    else if(m>n&&m>0&&n>0)        //1
        e=zuhe(m,n);
	else if(m=n&&m>0&&n>0)        //2
        e=1;             
    		    
    else
        e=-1;	      
    printf("%d",e);
}


