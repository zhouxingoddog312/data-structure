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
int readword(){   //����һ�����ʵĺ��� 
	int j=0;
	while(!((ch>=A)&&(ch<=Z))){      //�˵�ǰ���հ�
	if(ch=='#')
	   return 0;
	ch=getchar();
}
	while((ch>=A)&&(ch<=Z)){            //˳����� 
		string[j++]=ch;
	ch=getchar();
	}
	string[j]='\0';
	return j-1;                  //����λ�÷��� 
}
bool test_st(char st[],int j){       //�ж��Ƿ�����ֵĺ��� 
	int i;                   //i���ַ�����st��ͷ 
	while(i<j){
		if(st[i]!=st[j])          //�ж϶Գ���� 
		return false;
		j--;i++
	}
	return true;
}
