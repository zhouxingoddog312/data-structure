#include <stdio.h>
#include <conio.h>
int main(void)
{
	int n,year,b,c,yy;
	printf("ע�⣬��ʦ�����������ˣ�\n");
    printf("��ѡ����Ľ����̶�1��Сѧ 2������ 3������ 4����ѧ:");
    scanf("%d",&b);
    switch(b){
    	case 1:printf("Сѧ�����֣�\n");break;
    	case 2:printf("�ô������������˰ɣ�\n");break;
    	case 3:printf("are you ok!\n");break;
    	case 4:printf("�ðɣ����㿿�׵��ˣ�\n");break;
    	default:printf("������Ǹ����ߣ�\n");
	}
	printf("�����������ڵ����䣨����25����");
	scanf("%d",&year);
	if(year>=30)
	printf("���Ѿ����˰���\n");
	else
	printf("С���ӣ��㻹�����õ�δ����\n");
	printf("�����������ڵ�����̶ȣ����磨3650����");
	scanf("%d",&c);
	if((c<3000)&&(year>30)&&(b<4))
	   printf("��ûϣ���ˣ�low B!\n");
	else
	   printf("��Ȼ���ں�������㻹��ϣ����\n");
	printf("���ڼ�������ܷ�������,�����뵱ǰ����2017��");
	scanf("%d",&yy);
	printf("������һ����������:");
	scanf("%d",&n);
	yy=(yy/4+1)*4;
	do{
		if((yy%4==0)&&(yy%100!=0)||(yy%400==0)){ 
		printf("�����⼸�����˵�ͷ:%d\n",yy);
	n--;}
	yy=yy+4;
	}while(n>0);
	return 0;
}
