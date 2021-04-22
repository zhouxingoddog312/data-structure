#include"stdio.h"
int main(void){
	float a,b,c;
	scanf("%f%f%f",&a,&b,&c);
	if(a<b&&b<c)
	    printf("%.2f %.2f %.2f",a,b,c);
	else
	    if(a<c&&c<b)
	       printf("%.2f %.2f %.2f",a,c,b);
	    else
	       if(b<a&&a<c)
	           printf("%.2f %.2f %.2f",b,a,c);
	        else
	           if(b<c&&c<a)
	               printf("%.2f %.2f %.2f",b,c,a);
	            else
	               if(c<b&&b<a)
	                   printf("%.2f %.2f %.2f",c,b,a);
	                else
	                    printf("%.2f %.2f %.2f",c,a,b);
return 0;
}
