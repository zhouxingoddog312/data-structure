#include<stdio.h>
int main(void){
	int i;
	i=7;
	while((i%2!=1)||(i%3!=2)||(i%5!=4)||(i%7!=0))
	i++;
	printf("%d",i);
}
