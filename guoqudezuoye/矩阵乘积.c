#include<stdio.h>
#define m 2
#define n 2
#define p 2
float a[m][p],b[p][n],c[m][n];
int main(void){
	int x,y,z;
	
	void matrixproduct(void);
    for(x=0;x<m;x++)
	   for(y=0;y<p;y++)
	      scanf("%f",&a[x][y]);
	for(x=0;x<m;x++)
	   for(y=0;y<p;y++)
	      scanf("%f",&b[x][y]);
	matrixproduct( );
	printf("\answer:\n");
    for(x=0;x<m;x++)
	   for(y=0;y<p;y++)
	   printf("%.0f",c[x][y]);
	   getchar();
		  	
}
void matrixproduct( ){
	float e;
	int i,j,k;
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			e=0;
			for(k=0;k<p;k++)
			   e+=a[i][k]*b[k][j];
			   c[i][j]=e;
		}
		   
	}   
}
