#include<stdio.h>
#define n 10             //���峣��10�У�ÿ���ַ����Ϊ4 
#define wide 4
int main(void){
	int i,j,a[10]; 
	for(i=0;i<n;i++){        //0~9ʮ��ѭ������ӡʮ�� 
		a[i]=1;             //a[0]��a[i]��ֵΪ1
		for(j=i-1;j>0;j--)    //�Ӻ���ǰ�㣬������һ�� 
		   a[j]=a[j]+a[j-1];
		for(j=0;j<(40-i*(wide/2));j++)//i����ǰ�����ָ�������ӡ�ո���
		   printf(" ");
		for(j=0;j<=i;j++)          //��ӡa[0]��a[i] 
		   printf("%4d",a[j]);
		printf("\n");
	}
	getchar();
} 
