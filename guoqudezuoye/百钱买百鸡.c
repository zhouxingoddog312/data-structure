#include"stdio.h"
int main(void){
	int x,y,z;
	for(x=1;x<=20;x++)                         //穷举鸡翁的数量 
	   for(y=1;y<=33;y++)                      //穷举鸡母的数量 
	      for(z=3;z<=99;z=z+3)                 //穷举鸡雏的数量 
	         if((5*x+3*y+z/3==100)&&(x+y+z==100))            //验证是否符合条件 
	         printf("鸡翁鸡母鸡雏各有%5d%5d%5d\n",x,y,z);    
	         getchar();
			 getchar(); 
}
