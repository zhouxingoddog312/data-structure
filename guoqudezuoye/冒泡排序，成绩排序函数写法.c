#include"stdio.h"
#define M 5
int i,a[M];
void sortofup(int s[],int n){     //������s����ð������ 
	int i,r;
	bool flag;
	flag=true;
	while(flag){
		flag=false;
		for(i=0;i<n-1;i++){
		if(a[i]>a[i+1]){
			r=a[i];a[i]=a[i+1];a[i+1]=r;
			flag=true;
		}
	}
	}	
}
int main(){
	printf("please input your number:");
	for(	i=0;i<M;i++)         //����
	scanf("%d",&a[i]);
	sortofup(a,M);         //���ú��� 
	for(i=0;i<M;i++)             //��ӡ
	printf("%4d",a[i]);
	getchar();
}
