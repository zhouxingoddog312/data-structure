#include <stdio.h>
#include <math.h>
int main(void)
{
	float x1,x2,b,d;
	float length,width,area;
	printf("please input length,width,area:");
	scanf("%f%f%f",&length,&width,&area);
	b=-2.0*(length+width);
	d=sqrt(b*b-4.0*4.0*(length*width-area));
	x1=(-b+d)/(2*4);
	x2=(-b-d)/(2*4);
	if
	((x1>0)&&(2*x1<length)&&(2*x1<width))
	printf("�̻������Ϊ��%.2f\n",x1);
	else{
	if((x2>0)&&(2*x2<length)&&(2*x2<width))
	printf("�̻������Ϊ��%.2f\n",x2);
	else
	printf("ԭʼ���ݴ���\n");
	}
}
