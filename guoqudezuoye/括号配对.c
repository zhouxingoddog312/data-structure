#include<stdio.h>
int main(){
	int i,j ,k,sign;
	i=0;
	j=0;
	k=0;
	printf("������'{}''()''[]'�е�һ�֣�");
	scanf("%c",&sign);
	while(sign!='#'){
		switch(sign){
			case '(':i++;break;                        //(������һ
			case ')':i--;break;                       //)������һ
			case '{':j++;break;                    //{������һ
			case '}':j--;break;                 //}������һ
			case '[':k++;break;               //[������һ
			case ']':k--;                       //]������һ
		}
	printf("������'{}''()''[]'�е�һ�֣�\n");	
	scanf("%c",&sign);
	}
	if(i>0)
	printf("�����ڣ�\n");
	else
	    if(i<0) 
	    printf("�����ڣ�\n");
	    else
	    printf("�����ڣ�\n");
	if(j>0)
	printf("{����}\n");
	    else
	    if(j<0)
	 	printf("{����}\n");
	 	else
	 	printf("{����}\n");
	if(k>0)
	printf("[����]\n");
	    else
	    if(k<0)
		printf("[����]\n");
		else
		printf("[����]\n"); 
	return 0;
} 
