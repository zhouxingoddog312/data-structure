#include<stdio.h>
#define L 21
int i,j;
char ch;
char string[L];
bool test_st(char st[],int);
int readword();
int main(void){
	ch=getchar();
	j=readword();
	while(j!=0){
		if(test_st(string,j))
		printf("YES--%s\n",string);
		else
		printf("NO--%s\n",string);
		j=readword();
	}
}
int readword(){
	j=0;
	while(!(ch>='a')&&(ch<='z')){
		if(ch=='#')
		return 0;
		ch=getchar();
	}
	while((ch>='a')&&(ch<='z')){
		string[j++]=ch;
		ch=getchar();
	}
	string[j]='\0';
	return j-1;
}
bool test_st(char st[],int j){
	i=0;
	while(i<j){
		if(st[i]!=st[j])
		return false;
		i++;
		j--;
	}
	return true;
}
