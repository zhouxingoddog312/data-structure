#include<stdio.h>
int main(void){
int a[5],b[5]={1,2,3,4,5}/*�����ֵ*/,i,j,k;
bool flag;
printf("please input your number:");
for(i=0;i<5;i++)          //��ȡ�ɼ� 
scanf("%d",&a[i]);
flag=true;
while(flag){               //ð������
	flag=false;
	for(i=1;i<5;i++){
		if(a[i-1]>a[i]){
			flag=true;
			k=a[i];a[i]=a[i-1];a[i-1]=k;
			j=b[i];b[i]=b[i-1];b[i-1]=j;      //�ɼ������ͬʱ��ѧ������Ҳ�䶯 
		}
	} 

}
	printf("answer:\n");
	for(i=0;i<5;i++)
	printf("%4d   %4d\n",b[i],a[i]);
	getchar(); 	
} 

