#include"stdio.h"
int main(void){
	int r,i,k,ari,j[5][10];                  //����һ����ά�������ڴ��5��11�������� 
	for(r=0;r<5;r++){                        //�����Ŀ 
		printf("please input 10 integer:\n");
		for(i=0;i<=10;i++)                   //�������� 
		   j[r][i]=0;
		for(i=0;i<=9;i++){                 //ʮ��ѧ�� 
			scanf("%d",&ari);
			k=ari/10;                     //�ֱ���11�������μ��� 
			j[r][k]++;
		}
		printf("answer R:%d\n",r);        //��ӡ̧ͷ 
		for(i=0;i<=10;i++)                 //���ÿ�� 
		   printf("%3d--%3d:%6d\n",(i*10),(i+1)*10-1,j[r][i]); 
	}
	getchar();
}
