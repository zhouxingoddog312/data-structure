#include <stdio.h>
#include <math.h>

#define A 3

void print(void)
{
 double x,y;

 for(y=-4;y<=0;y+=0.3)
 {
 	for(x=-4;x<=4;x+=0.2)
 		if(fabs(sqrt(x*x+y*y)-A*sin(2*atan(y/x)))<=1 ||fabs(sqrt(x*x+y*y)-A*sin(2*atan(-y/x)))<=1)     //抄的别人的，不要乱发 
 		printf("*");
 	else	printf(" ");
 	printf("\n");
 }                                                              //抄的别人的，不要乱发 
 for(y=-1;y<=0;y+=0.2)
 {                                                           //抄的别人的，不要乱发 
 	for(x=-4;x<=4;x+=0.2)
		if(fabs(y)-0.65*x*x>=0.2)
 		printf("*");                                      //抄的别人的，不要乱发 
 	else 	printf(" ");
 	printf("\n");
 }
}

int main(void)
{
 print();
 getchar();
 return 0;
}
