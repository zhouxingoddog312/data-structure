#include"stdio.h"
#define eps 1e-5
int main(void){
	int n;
	float e,r;
	n=1;
	e=1.0;
	r=1.0;
	while(r>eps){
		e=e+r;
		n++;
		r=r/n;
	}
	printf("%f",e);
	return 0;
}
