#include"stdio.h"
bool plus(int n){                  //����һ���������ж�һ�����Ƿ����� 
	int j;
	for(j=n/2;j>=2;j--){
		if(n%j==0)
        return false;
	}
		
        return true;
}
int main(void){
	int i;
	for(i=2;i<=100;i++){              //˳�����2��100��ÿ���� 
	if (plus(i))                    //���ú����ж� 
	printf("%5d\n",i);              
	}
	getchar();
}
