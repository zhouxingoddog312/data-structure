#include<stdio.h>
#define n 10       //����ѧ������ 
int main(){
	int i,j,k,r,a[n];
	for(i=0;i<n;i++){              //����ѧ���ɼ� 
		printf("please input your number:");
		scanf("%d",&a[i]);
	}
    /*����*/
	for(i=0;i<(n-1);i++){         
		j=i;
		for(k=i+1;k<(n-1);k++){
			if(a[k]<a[j])
			   j=k;
		}
    /*����*/
		r=a[i];a[i]=a[j];a[j]=r;   //����a[i]��a[j] 
	}
	for(i=0;i<n;i++){               //��� 
		if(i%5==0)
		   printf("\n");
		printf("%4d",a[i]);
	}
	   getchar();
	
}
