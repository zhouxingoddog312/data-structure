#include<stdio.h>
int year;
char mark; 
int main(){
	scanf("%d",&year);
	mark='n';
	if(((year%4==0)&&(year%100!=0))||(year%400==0))
	mark='y';
	printf("%c\n",mark);
	return 0;
}
