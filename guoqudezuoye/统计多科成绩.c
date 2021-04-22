#include"stdio.h"
int main(void){
	int r,i,k,ari,j[5][10];                  //声明一个二维数组用于存放5科11个分数段 
	for(r=0;r<5;r++){                        //五个科目 
		printf("please input 10 integer:\n");
		for(i=0;i<=10;i++)                   //所有清零 
		   j[r][i]=0;
		for(i=0;i<=9;i++){                 //十个学生 
			scanf("%d",&ari);
			k=ari/10;                     //分别在11个分数段计数 
			j[r][k]++;
		}
		printf("answer R:%d\n",r);        //打印抬头 
		for(i=0;i<=10;i++)                 //输出每科 
		   printf("%3d--%3d:%6d\n",(i*10),(i+1)*10-1,j[r][i]); 
	}
	getchar();
}
