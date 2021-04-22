#include<stdio.h>
int main(void){
	int i,k,ai,j[11];
	printf("please input 10 integer:\n");
	for(i=0;i<11;i++)
	   j[i]=0;
	for(i=0;i<10;i++){
		scanf("%d",&ai);
	   k=ai/10;
	   j[k]++;
	}
	printf("answer:\n");
	for(i=0;i<11;i++)
	   printf("%3d--%3d:%6d\n",i*10,(i+1)*10-1,j[i]);
	getchar();
}



