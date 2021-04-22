#include<stdio.h>
#define n 5
int i,j,k,r,a[n],c[n];
int b[n]={0,1,2,3,4};
int main(void){
	for(i=0;i<5;i++)
scanf("%d",&a[i]);
for(i=0;i<5;i++)
c[i]=a[i];
r=1;
while(r==1){
	r=0;
	for(i=0;i<4;i++)
	if(a[i]>a[i+1]){
		j=a[i];a[i]=a[i+1];a[i+1]=j;
		j=b[i];b[i]=b[i+1];b[i+1]=j;
		r=1;
	}
}
for(i=0;i<5;i++)
	printf("%d",c[i]);
printf("\n");
for(i=0;i<5;i++)
	printf("%d",b[i]);
}

