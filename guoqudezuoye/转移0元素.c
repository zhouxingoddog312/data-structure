#include<stdio.h>
int i,j,a[10],b[10];

int main(){
j=0;
	for(i=0;i<10;i++){
		a[i]=0;
		scanf("%d",&b[i]);
	}
	   



	for(i=0;i<10;i++){          
	   if(b[i]!=0){
	   	a[j]=b[i];	
	        j++;
	   }
	   
		    
	   } 



	for(i=0;i<10;i++)       
	   printf("%d",a[i]);
getchar();
}
