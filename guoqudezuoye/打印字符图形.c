#include"stdio.h"
int main(void){
	char x;                           //x作为行标 
	int i;                        //i作计数器用 
	for(x='A';x<='F';x++){           //前6行 
		for(i=1;i<=(5-(x-'A'))*2;i++)         //打印多少个空格的计数器 
	       printf(" ");
	    for(i=1;i<=2*(x-'A')+1;i++)          //打印多少个字母的计数器 
	       printf(" %c",x);
	printf("\n");
	}
	for(x='E';x>='A';x--){            //后五行 
		for(i=1;i<=(5-(x-'A'))*2;i++)             //打印多少个空格的计数器 
	       printf(" ");
	    for(i=1;i<=2*(x-'A')+1;i++)              //打印多少个字母的计数器 
	       printf(" %c",x);
	printf("\n");
	}   
	getchar();
}
