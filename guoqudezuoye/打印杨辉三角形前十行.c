#include"stdio.h"
int main(){
	int i,j,a[10],b[10];           //����a��bΪ�������� 
	for(i=0;i<10;i++){             //iΪ����������ӡ10�� 
		for(j=1;j<i;j++)           // ��a[0]��a[i]������ำֵΪ��һ�е������ 
		   a[j]=b[j-1]+b[j];
		  
		a[i]=1;               //a[0]��a[i]��ֵΪ1 
	
	    for(j=0;j<=i;j++)        //a[0]��a[i]�͵�����b��ȥ 
	       b[j]=a[j];
	    for(j=0;j<=(40-i*(4/2));j++)   //i����ǰ�����ָ�������ӡ�ո��� 
	       printf(" ");
	    for(j=0;j<=i;j++)            //��ӡa[0]��a[i] 
	       printf("%-4d",a[j]);
	    printf("\n");                //��ӡ���� 
	}
	getchar(); 
}
