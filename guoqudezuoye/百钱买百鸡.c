#include"stdio.h"
int main(void){
	int x,y,z;
	for(x=1;x<=20;x++)                         //��ټ��̵����� 
	   for(y=1;y<=33;y++)                      //��ټ�ĸ������ 
	      for(z=3;z<=99;z=z+3)                 //��ټ��������� 
	         if((5*x+3*y+z/3==100)&&(x+y+z==100))            //��֤�Ƿ�������� 
	         printf("���̼�ĸ��������%5d%5d%5d\n",x,y,z);    
	         getchar();
			 getchar(); 
}
