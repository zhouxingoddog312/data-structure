#include <stdio.h>
int main(void)
{
	float a,b;
	char w;
	printf("please input like (a?b)\n");
	scanf("%f%c%f",&a,&w,&b);
	switch(w){
		case '+':a=a+b;break;
	case '-':a=a-b;break;
	case '*':a=a*b;break;
	case '/':a=a/b;
	}
printf("%.2f",a);
return 0;
 } 
