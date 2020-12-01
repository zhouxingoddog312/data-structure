#include <stdio.h>
#include "tree.h"
#include "queue.h"
int main(void)
{
	InitCursorSpace();
	SearchTree T;
	int index;
	T=Init(T);
	for(index=1;index<10;index++)
		T=Insert(index,T);
	LevelOrder(T);
	T=Delete(3,T);
	LevelOrder(T);
	return 0;
}
