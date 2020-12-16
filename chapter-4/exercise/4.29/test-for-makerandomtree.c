#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "tree.h"
#include "queue.h"
SearchTree MakeRandomTree(int N);
int main(void)
{
	int index;
	SearchTree T;
	T=MakeRandomTree(10);
	printf("NodeCount is %d\n",NodeCount(T));
	printf("LeafCount is %d\n",LeafCount(T));
	printf("FullNodeCount is %d\n",FullNodeCount(T));
	puts("LevelOrder!");
	LevelOrder(T);
	return 0;
}
SearchTree MakeRandomTree(int N)
{
	int index,Sum=0;
	int array[N];
	srand(time(0));
	for(index=0;index<N;index++)
		array[index]=0;
	SearchTree T;
	T=Init(T);
	while(Sum<N)
	{
		index=rand()%N;
		if(array[index]==0)
		{
			T=Insert(index+1,T);
			array[index]=1;
			Sum++;
		}
	}
	return T;
}
