#include"stido.h"
#define size 20
char x,stack[size];
int top;
top=0;
bool push(char x);
bool pop(void);
int main(void){
	char ch;
	char name[size];
	
	ch=getchar();
	while(ch!='#'){
		
	}
}
bool push(char x){
	if(top>size-1)
	return false;
	else{
		stack[top]=x;
		top=top+1;
		return true;
	}
}
bool pop(void){
	if(top<0)
	return false;
	else{
		top=top-1;
		x=stack[top];
		return true;
	}
}
