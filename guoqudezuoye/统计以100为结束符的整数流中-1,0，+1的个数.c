#include"stdio.h"
#define n 100
int main(){
	int i,j,k,num;
	i=0;               //�趨������ 
	j=0;              //�趨������ 
	k=0;            //�趨������ 
	printf("����һ��������");
	scanf("%d",&num);
	while(num!=n){                    //�����ֲ�����100ִ��ѭ�� 
		switch(num){                   //���֧�ṹ���ֱ�ͳ��-1,0��+1���� 
		case -1:i++;break;
		case 0:j++;break;
		case +1:k++;
		} 
	printf("����һ��������");          //������������ 
	scanf("%d",&num); 
	}
	printf("-1�ĸ�����%d\n",i);              //��ӡ��� 
	printf("0�ĸ�����%d\n",j);
	printf("+1�ĸ�����%d\n",k);
	return 0;
}
