#include"stdio.h"
    float xa,ya,xb,yb,xc,yc;         //����ABC�����XY������ 
	float xd,yd,xe,ye;               //�����е�DE��XY������
	float a1,b1,a2,b2,a;               //��������AD BE�ķ���ϵ�� 
	float xo,yo;                   //��������O��XY������ 
float lines(float xr,float yr,float xs,float ys,float xt,float yt){                //�����߷��̵ĺ��� 
	float xu,yu;
	xu=(xs+xt)/2;
	yu=(ys+yt)/2;
	a=(yr-yu)/(xr-xu);
	return yr-a*xr;
}
int main(void){
	printf("please input xa,ya,xb,yb,xc,yc:\n");          //�������������������XY������
    scanf("%f%f%f%f%f%f",&xa,&ya,&xb,&yb,&xc,&yc);
    
	
	b1=lines(xa,ya,xb,yb,xc,yc);                          //���ú�����������߷��� 
    a1=a;
    b2=lines(xb,yb,xa,ya,xc,yc);
    a2=a;
    xo=-(b2-b1)/(a1-a2);        //��AD��BE�Ľ���o 
	yo=a1*xo+b1;
	printf("����������������x=%10.3f,y=%10.3f",xo,yo);
	return 0;
}
