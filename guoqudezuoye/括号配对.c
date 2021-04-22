#include<stdio.h>
int main(){
	int i,j ,k,sign;
	i=0;
	j=0;
	k=0;
	printf("请输入'{}''()''[]'中的一种：");
	scanf("%c",&sign);
	while(sign!='#'){
		switch(sign){
			case '(':i++;break;                        //(计数加一
			case ')':i--;break;                       //)计数减一
			case '{':j++;break;                    //{计数加一
			case '}':j--;break;                 //}计数减一
			case '[':k++;break;               //[计数加一
			case ']':k--;                       //]计数减一
		}
	printf("请输入'{}''()''[]'中的一种：\n");	
	scanf("%c",&sign);
	}
	if(i>0)
	printf("（多于）\n");
	else
	    if(i<0) 
	    printf("（少于）\n");
	    else
	    printf("（等于）\n");
	if(j>0)
	printf("{多于}\n");
	    else
	    if(j<0)
	 	printf("{少于}\n");
	 	else
	 	printf("{等于}\n");
	if(k>0)
	printf("[多于]\n");
	    else
	    if(k<0)
		printf("[少于]\n");
		else
		printf("[等于]\n"); 
	return 0;
} 
