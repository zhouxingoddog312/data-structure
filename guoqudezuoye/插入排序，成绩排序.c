#include"stdio.h"
#define M 5
int s,t[M];
void sort(int a[],int n){           //��������ĺ��� 
	int i,j,k,r;
	for(i=1;i<n-1;i++){
		j=i-1;
		while((a[j]>a[i])&&j>=0){    //��λ�ã�a[i]����a[j]��a[j+1]֮�� 
			j--;
		}
		r=a[i];
		for(k=i-1;k>=j+1;k--)         //a[j+1]��a[i-1]���������һλ 
		   a[k+1]=a[k];
		a[j+1]=r;                  //a[i]����a[j+1] 
	}
} 
int main(){
	printf("please input your number:");
	for(	s=0;s<M;s++)          //����
	scanf("%d",&t[s]);
	sort(t,M);         //���ú��� 
	for(s=0;s<M;s++)             //��ӡ
	printf("%4d",t[s]);
	getchar();
}
