#include<stdio.h>
#define n 5             //���峣��n�����м������� 
int main(){
	int i,r,a[n];
	bool flag;          //���岼����flag 
	flag=true;            //��ֵΪ�� 
	printf("please input your number:");
	for(i=0;i<n;i++)     //���� 
	scanf("%d",&a[i]);
	while(flag==true){      //����flag�ж��Ƿ����ѭ�� 
		flag=false;
		for(i=0;i<(n-1);i++){          //���±�0��n-1�����ж� 
			if(a[i]>a[i+1]){
				r=a[i];a[i]=a[i+1];a[i+1]=r;flag=true;     //���� 
			}
		}
	}
	for(i=0;i<n;i++)            //��ӡ 
	printf("%4d",a[i]);
	getchar();
}
