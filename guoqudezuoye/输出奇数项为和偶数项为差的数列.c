#include <stdio.h>
int main(void){
	int u,v,k,w,flag;
	u=0;
	v=1;
	k=3;
	flag=1;
	printf("%5d\n%5d\n",u,v);
	do{
		w=v+flag*u;                                               //if(k%2==0)
		flag=-flag;                                              // w=v-u;
		printf("%5d\n",w);                                               //else
		u=v;                                              // w=v+u;
		v=w;                                              // printf("%5d\n",w);
		                                              // u=v;
		                                              // v=w;
		k=k+1;
	}while(k<=50);
	getchar();
}
