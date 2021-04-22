#include"stdio.h"
#define n 100
int main(){
	int i,j,k,num;
	i=0;               //设定计数器 
	j=0;              //设定计数器 
	k=0;            //设定计数器 
	printf("输入一个整数：");
	scanf("%d",&num);
	while(num!=n){                    //当数字不等于100执行循环 
		switch(num){                   //多分支结构，分别统计-1,0，+1个数 
		case -1:i++;break;
		case 0:j++;break;
		case +1:k++;
		} 
	printf("输入一个整数：");          //继续输入数字 
	scanf("%d",&num); 
	}
	printf("-1的个数是%d\n",i);              //打印结果 
	printf("0的个数是%d\n",j);
	printf("+1的个数是%d\n",k);
	return 0;
}
