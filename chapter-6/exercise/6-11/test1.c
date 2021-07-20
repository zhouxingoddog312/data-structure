#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "BinaryHeap.h"
int main(void)
{
	srand((unsigned int)time(0));
	fputs("指定一个整数M，随机生成M个元素作为输入:",stdout);
	int M,index;
	fscanf(stdin,"%d",&M);
	ElementType *arr;
	arr=malloc(sizeof(ElementType)*M);
	for(index=0;index<M;index++)
		arr[index]=rand()%10000+1;
	PriorityQueue H=Initialize(2*M);

	clock_t start,end;
	start=clock();
	BuildHeap(arr,M,H);
	end=clock();
	printf("时间%ld",(end-start));

	Destroy(H);
	return 0;
}
