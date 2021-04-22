#include <stdio.h>
#include <math.h>
float a,b,c,delta;
int main(void){
	printf("please input three coefients of the equation(a,b,c):");
	scanf("%f%f%f",&a,&b,&c);
	if(a!=0){
		delta=b*b-4*a*c;
		if(delta>=0)
		if(delta>0)
		printf("x1=%f,x2=%f\n",
		-b+sqrt(delta)/(2*a),
		-b-sqrt(delta)/(2*a));
		else
		printf("x1=x2=%f\n",-b/(2*a));
		else
		printf("x1=%f+%fi,x2=%f-%fi\n",
		-b/(2*a),sqrt(-delta)/(2*a)
		-b/(2*a),sqrt(-delta)/(2*a));
	}else
	if(b!=0)
	printf("x=%f\n",-c/b);
	else
	if(c==0)
	printf("0=0!\n");
	else
	printf("%f=0!\n",c);
getchar();
getchar();
}
