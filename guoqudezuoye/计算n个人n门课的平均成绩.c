#include"stdio.h"
#define n 4                                       //�����Ŀ�� 
#define p 5                                      //�������� 
int main(void){
	float sum,m;                                 //�ܷ����뵥�ŷ��� 
	int i,j,k;
	for(i=1;i<=p;i++){                           //��������ѭ�� 
		sum=0;                                              
		k=1;
		do{                                                          
			printf("please input NO%2d-%2d achievement:",i,k);                   //���뵥�Ƴɼ� 
			scanf("%f",&m);
			sum=sum+m;
			k=k+1;
		}while(k<=n);                                                     
	printf("NO%2d:average achievement:%5.2f\n",i,sum/n);
	}
}
