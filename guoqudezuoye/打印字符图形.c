#include"stdio.h"
int main(void){
	char x;                           //x��Ϊ�б� 
	int i;                        //i���������� 
	for(x='A';x<='F';x++){           //ǰ6�� 
		for(i=1;i<=(5-(x-'A'))*2;i++)         //��ӡ���ٸ��ո�ļ����� 
	       printf(" ");
	    for(i=1;i<=2*(x-'A')+1;i++)          //��ӡ���ٸ���ĸ�ļ����� 
	       printf(" %c",x);
	printf("\n");
	}
	for(x='E';x>='A';x--){            //������ 
		for(i=1;i<=(5-(x-'A'))*2;i++)             //��ӡ���ٸ��ո�ļ����� 
	       printf(" ");
	    for(i=1;i<=2*(x-'A')+1;i++)              //��ӡ���ٸ���ĸ�ļ����� 
	       printf(" %c",x);
	printf("\n");
	}   
	getchar();
}
