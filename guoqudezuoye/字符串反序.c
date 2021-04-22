#include<stdio.h>
#define L 21
int i,j;
char ch;
char string[L];

int readword();
int main(void){
	ch=getchar();
	j=readword();
	for(i=j;i>=0;i--)
	printf("%c",string[i]);
	}

int readword(){
	j=0;

	while((ch>=0)&&(ch<='Z')){
		string[j++]=ch;
		ch=getchar();
	}
		
	
	string[j]='\0';
	return j-1;
}

