#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "tree.h"
#include "queue.h"
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
