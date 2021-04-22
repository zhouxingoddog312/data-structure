#include <stdio.h>
#include <math.h>

#define A 3

void print(void)
{
 double x,y;

 for(y=-4;y<=0;y+=0.3)
 {
 	for(x=-4;x<=4;x+=0.2)
 		if(fabs(sqrt(x*x+y*y)-A*sin(2*atan(y/x)))<=1 ||fabs(sqrt(x*x+y*y)-A*sin(2*atan(-y/x)))<=1)
 		printf("*");
 	else	printf(" ");
 	printf("\n");
 }
 for(y=-1;y<=0;y+=0.2)
 {
 	for(x=-4;x<=4;x+=0.2)
		if(fabs(y)-0.65*x*x>=0.2)
 		printf("*");
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
