#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "avltree.h"
#include "queue.h"
#define Height 3	//欲生成AVL树高度
int HeightToNode(int H);	//将高度转换成对应的AVL树最少节点数
AvlTree MakeRandomTree(int N);	//随机生成节点数为N的Avl树
int main(void)
{
	int index,i;
	int NodeCount=HeightToNode(Height);
	AvlTree T;
	T=MakeRandomTree(NodeCount);
	LevelOrder(T);
	return 0;
}
int HeightToNode(int H)
{
	if(H==0)
		return 1;
	else if(H==1)
		return 2;
	else
		return HeightToNode(H-2)+HeightToNode(H-1)+1;
}
AvlTree MakeRandomTree(int N)
{
	int index,Sum=0;
	int array[N];	//变长数组，用来记录该数值是否已插入AVL树
	srand(time(0));
	for(index=0;index<N;index++)
		array[index]=0;
	AvlTree T;
	T=Init(T);
	while(Sum<N)
	{
		index=rand()%N;
		if(array[index]==0)
		{
			T=Insert(index+1,T);
			array[index]=1;
			Sum++;		//插入了N个节点即退出
		}
	}
	return T;
}
