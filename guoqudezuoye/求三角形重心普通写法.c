#include"stdio.h"
int main(void){
	float xa,ya,xb,yb,xc,yc;         //����ABC�����XY������ 
	float xd,yd,xe,ye;               //�����е�DE��XY������
	float a1,b1,a2,b2;               //��������AD BE�ķ���ϵ�� 
	float xo,yo;                   //��������O��XY������ 
	printf("please input xa,ya,xb,yb,xc,yc:\n");          //�������������������XY������
	scanf("%f%f%f%f%f%f",&xa,&ya,&xb,&yb,&xc,&yc);
	xd=(xb+xc)/2;              //BC�ߵ��е�D
	yd=(yb+yc)/2;
	a1=(ya-yd)/(xa-xd);        //������AD��ֱ�߷��� 
	b1=ya-a1*xa; 
	xe=(xa+xc)/2;              //AC�ߵ��е�E
	ye=(ya+yc)/2;
	a2=(yb-ye)/(xb-xe);        //������BE��ֱ�߷��� 
	b2=yb-a2*xb; 
	xo=-(b2-b1)/(a1-a2);        //��AD��BE�Ľ���o 
	yo=a1*xo+b1;
	printf("����������������x=%10.3f,y=%10.3f",xo,yo);
	return 0;
}
