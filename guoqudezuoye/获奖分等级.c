#include <stdio.h>
int main(void)
{
	int win,mark;
	printf("������Ŀ��Գɼ���");
	scanf("%d",&mark);
	printf("��ѡ����μӴ��������\n");
	printf("(0:δ������1:��������2:���Ƚ���3:���Ƚ���4:һ�Ƚ�)��");
	scanf("%d",&win);
	switch(win)
	{
		case 0:break;
		case 1:mark=mark+5;break;
		case 2:mark=mark+10;break;
		case 3:mark=mark+15;break;
		case 4:mark=mark+20;
	}
	if(mark>100)
	mark=100;
	printf("������ճɼ��ǣ�%d",mark);
	return 0; 
}
