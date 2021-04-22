#include <stdio.h>
#include <conio.h>
int main(void)
{
	int n,year,b,c,yy;
	printf("注意，大师来给你算命了！\n");
    printf("请选择你的教育程度1：小学 2：初中 3：高中 4：大学:");
    scanf("%d",&b);
    switch(b){
    	case 1:printf("小学狗滚粗！\n");break;
    	case 2:printf("好歹完成义务教育了吧！\n");break;
    	case 3:printf("are you ok!\n");break;
    	case 4:printf("好吧，总算靠谱点了！\n");break;
    	default:printf("你可能是个王者！\n");
	}
	printf("请输入你现在的年龄（例如25）：");
	scanf("%d",&year);
	if(year>=30)
	printf("你已经老了啊！\n");
	else
	printf("小伙子，你还有美好的未来！\n");
	printf("请输入你现在的收入程度，例如（3650）：");
	scanf("%d",&c);
	if((c<3000)&&(year>30)&&(b<4))
	   printf("你没希望了，low B!\n");
	else
	   printf("虽然现在很穷，但是你还有希望！\n");
	printf("现在计算你可能发达的年份,请输入当前年如2017：");
	scanf("%d",&yy);
	printf("请输入一个任意整数:");
	scanf("%d",&n);
	yy=(yy/4+1)*4;
	do{
		if((yy%4==0)&&(yy%100!=0)||(yy%400==0)){ 
		printf("你在这几年会鸿运当头:%d\n",yy);
	n--;}
	yy=yy+4;
	}while(n>0);
	return 0;
}
