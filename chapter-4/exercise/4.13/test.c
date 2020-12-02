#include <stdio.h>
#include "tree.h"
#include "queue.h"
int main(void)
{
	int index;
	SearchTree T;
	T=Init(T);
	for(index=1;index<19;index++)
		T=Insert(index,T);
	LevelOrder(T);
	for(index=2;index<19;index+=2)
		T=Delete(index,T);
	putchar('\n');
	LevelOrder(T);
	return 0;
}
