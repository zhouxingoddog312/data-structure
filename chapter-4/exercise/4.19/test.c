#include <stdio.h>
#include "avltree.h"
#include "queue.h"
#include "stack.h"
int main(void)
{
	AvlTree T;
	T=Init(T);
	int Array[]={2,1,4,5,9,3,6,7};
	int i;
	for(i=0;i<8;i++)
	{
		T=Insert(Array[i],T);
	}
	//T=Insert(6,T);
	LevelOrder(T);
	
	return 0;
}
