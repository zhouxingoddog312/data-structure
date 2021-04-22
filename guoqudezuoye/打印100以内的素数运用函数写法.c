#include"stdio.h"
bool plus(int n){                  //定义一个函数，判断一个数是否素数 
	int j;
	for(j=n/2;j>=2;j--){
		if(n%j==0)
        return false;
	}
		
        return true;
}
int main(void){
	int i;
	for(i=2;i<=100;i++){              //顺序测试2到100的每个数 
	if (plus(i))                    //调用函数判断 
	printf("%5d\n",i);              
	}
	getchar();
}
