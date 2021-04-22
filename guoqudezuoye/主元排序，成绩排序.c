#include<stdio.h>
#define n 10       //定义学生个数 
int main(){
	int i,j,k,r,a[n];
	for(i=0;i<n;i++){              //输入学生成绩 
		printf("please input your number:");
		scanf("%d",&a[i]);
	}
    /*排序*/
	for(i=0;i<(n-1);i++){         
		j=i;
		for(k=i+1;k<(n-1);k++){
			if(a[k]<a[j])
			   j=k;
		}
    /*排序*/
		r=a[i];a[i]=a[j];a[j]=r;   //交换a[i]与a[j] 
	}
	for(i=0;i<n;i++){               //输出 
		if(i%5==0)
		   printf("\n");
		printf("%4d",a[i]);
	}
	   getchar();
	
}
