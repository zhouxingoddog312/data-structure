#include <stdio.h>
int main(void)
{
	int win,mark;
	printf("输入你的考试成绩：");
	scanf("%d",&mark);
	printf("请选择你参加大奖赛的情况\n");
	printf("(0:未参赛，1:仅参赛，2:三等奖，3:二等奖，4:一等奖)：");
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
	printf("你的最终成绩是：%d",mark);
	return 0; 
}
