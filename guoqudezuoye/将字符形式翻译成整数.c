#include"stdio.h"
#define radix 10
int main(void){
	int n;                       //�͵�Ԫ�ı������ 
	char ch;
	ch=getchar();
	while(ch<'0'||ch>'9')         //����ǰ���ո� 
	   ch=getchar();
n=0;                              //�͵�Ԫ�������� 
	while(ch>'0'&&ch<'9'){
			n=n*radix+(int(ch)-'0');  //��chװ��������ֵ����� 
	        ch=getchar();
	}
printf("%d",n);
getchar();
}
