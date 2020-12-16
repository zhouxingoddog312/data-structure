#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
#include "queue.h"
int main(void)
{
	int index;
	SearchTree T;
	T=Init(T);
	for(index=1;index<=80;index++)
	{
		T=Insert(rand()%index,T);
	}
	printf("NodeCount is %d\n",NodeCount(T));
	printf("LeafCount is %d\n",LeafCount(T));
	printf("FullNodeCount is %d\n",FullNodeCount(T));
	puts("LevelOrder!");
	LevelOrder(T);
	return 0;
}
