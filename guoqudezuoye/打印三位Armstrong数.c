#include"stdio.h"
int main(void){
	int N,i,j,k;
	for(N=100;N<=999;N++){
		i=N%10;
	   j=(N/10)%10;
	   k=((N/10)/10)%10;
	   if(N==i*i*i+j*j*j+k*k*k)
	      printf("%d\n",N);
	}
	   
	return 0;
}
