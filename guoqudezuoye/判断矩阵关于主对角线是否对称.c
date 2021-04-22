#include "math.h"
#include "stdio.h"
int m=1,i,j,a[3][3];
int main(){
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			scanf("%d",&a[i][j]);
		}
	}
	for(i=0;i<3;i++){
		for(j=0;j<=i;j++){
	        if(a[i][j]==a[j][i]) 
	          m=0;
			else
			{
				m=1;
				break;
			}
		}
	}
	if(m==0)
	{
		printf("no");
	}
	else
	{
		printf("yes");
	}
}
