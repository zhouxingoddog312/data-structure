#include"stdio.h"
int i,j,k;
int main(void){
	for(i=1;i<=9;i++){
		printf("%4d",i);                  //��ӡ�б� 
		for(j=1;j<=i;j++)       
			printf("%4d",i*j);             //���д�ӡ���ݽ�� 
			printf("\n");               //���� 
	}
	printf("%4c",'*');                 //��ӡ*�� 
	for(i=1;i<=9;i++){
	printf("%4d",i);                  //��ӡ�б� 
	} 
	getchar();
}
