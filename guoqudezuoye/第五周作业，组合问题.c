#include<stdio.h>
int m,n,i,j,e,a[11];
int zuhe(int i,int j){
	for(i=0;i<10;i++)        
		a[i]=1;             
		for(j=i-1;j>0;j--)    
		   a[j]=a[j]+a[j-1];
		   
return a[j];		   
}
int main(void){
	scanf("%d%d",&m,&n);
	if(m<n&&m>0&&n>0)
	   e=0;
    else
       if((m=n)&&m>0&&n>0)
          e=1;
        else
           if(m>n&&m>0&&n>0)
           	  e=zuhe(m,n);		    
           else
               e=(-1);
    printf("%d",e);
}


