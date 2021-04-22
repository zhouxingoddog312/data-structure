#include"stdio.h"
int main(void){
	float xa,ya,xb,yb,xc,yc;         //保存ABC三点的XY轴坐标 
	float xd,yd,xe,ye;               //保存中点DE的XY轴坐标
	float a1,b1,a2,b2;               //保存中线AD BE的方程系数 
	float xo,yo;                   //保存重心O的XY轴坐标 
	printf("please input xa,ya,xb,yb,xc,yc:\n");          //输入三角形三个顶点的XY轴坐标
	scanf("%f%f%f%f%f%f",&xa,&ya,&xb,&yb,&xc,&yc);
	xd=(xb+xc)/2;              //BC边的中点D
	yd=(yb+yc)/2;
	a1=(ya-yd)/(xa-xd);        //求中线AD的直线方程 
	b1=ya-a1*xa; 
	xe=(xa+xc)/2;              //AC边的中点E
	ye=(ya+yc)/2;
	a2=(yb-ye)/(xb-xe);        //求中线BE的直线方程 
	b2=yb-a2*xb; 
	xo=-(b2-b1)/(a1-a2);        //求AD、BE的交点o 
	yo=a1*xo+b1;
	printf("三角形重心坐标是x=%10.3f,y=%10.3f",xo,yo);
	return 0;
}
