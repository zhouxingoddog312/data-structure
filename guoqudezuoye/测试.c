#include"stdio.h"
int main(){
	int i,j,a[10],b[10];           //数组a，b为相邻两行 
	for(i=0;i<10;i++){             //i为计数器，打印10行 
		for(j=1;j<i;j++)           // 除a[0]、a[i]外的其余赋值为上一行的两项和 
		   a[j]=b[j-1]+b[j];
		  
		a[i]=1;               //a[0]、a[i]赋值为1 
	
	    for(j=0;j<=i;j++)        //a[0]至a[i]送到数组b中去 
	       b[j]=a[j];
	    for(j=0;j<=(40-i*(4/2));j++)   //i代表当前行数字个数，打印空格数 
	       printf(" ");
	    for(j=0;j<=i;j++)            //打印a[0]到a[i] 
	       printf("%-4d",a[j]);
	    printf("\n");                //打印换行 
	}
	getchar(); 
}
