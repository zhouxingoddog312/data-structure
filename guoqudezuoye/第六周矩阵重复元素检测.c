#include<stdio.h>
int a[3][3],i,j,k,r,s;
int main(void){
	for(i=0;i<3;i++)
	   for(j=0;j<3;j++)
	      scanf("%d",&a[i][j]);
	for(i=0;i<3;i++)
	   for(j=0;j<3;j++)
	      for(k=i+1;k<3;k++)
	         for(r=j+1;r<3;r++){ 
	            if(a[i][j]!=a[k][r])
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


/*int search(int n,int a[],int key)
int j;
for(j=n-1;(j>=0)&&(key!=a[j]);j--);
return j;*/

