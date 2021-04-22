#include"stdio.h"
    float xa,ya,xb,yb,xc,yc;         //保存ABC三点的XY轴坐标 
	float xd,yd,xe,ye;               //保存中点DE的XY轴坐标
	float a1,b1,a2,b2,a;               //保存中线AD BE的方程系数 
	float xo,yo;                   //保存重心O的XY轴坐标 
float lines(float xr,float yr,float xs,float ys,float xt,float yt){                //求中线方程的函数 
	float xu,yu;
	xu=(xs+xt)/2;
	yu=(ys+yt)/2;
	a=(yr-yu)/(xr-xu);
	return yr-a*xr;
}
int main(void){
	printf("please input xa,ya,xb,yb,xc,yc:\n");          //输入三角形三个顶点的XY轴坐标
    scanf("%f%f%f%f%f%f",&xa,&ya,&xb,&yb,&xc,&yc);
    
	
	b1=lines(xa,ya,xb,yb,xc,yc);                          //调用函数求出两中线方程 
    a1=a;
    b2=lines(xb,yb,xa,ya,xc,yc);
    a2=a;
    xo=-(b2-b1)/(a1-a2);        //求AD、BE的交点o 
	yo=a1*xo+b1;
	printf("三角形重心坐标是x=%10.3f,y=%10.3f",xo,yo);
	return 0;
}
