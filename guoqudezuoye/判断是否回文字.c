#include<stdio.h>
#define L 21
char string[L];
bool test_st(char st[],int);
int readword();
int i,j;
char ch;
int main(void){
	ch=getchar();
	j=readword();
	while(j!=0){
		if(tese_st(string,j));
		printf("YES!--%s\n",string);
		else
		printf("NO!--%s\n",string);
	    j=readword();
	}
}
int readword(){   //读入一个单词的函数 
	int j=0;
	while(!((ch>=A)&&(ch<=Z))){      //滤掉前导空白
	if(ch=='#')
	   return 0;
	ch=getchar();
}
	while((ch>=A)&&(ch<=Z)){            //顺序读入 
		string[j++]=ch;
	ch=getchar();
	}
	string[j]='\0';
	return j-1;                  //带着位置返回 
}
bool test_st(char st[],int j){       //判断是否回文字的函数 
	int i;                   //i是字符数组st的头 
	while(i<j){
		if(st[i]!=st[j])          //判断对称相等 
		return false;
		j--;i++
	}
	return true;
}
