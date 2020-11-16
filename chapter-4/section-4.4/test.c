#include <stdio.h>
#include "avltree.h"
#include "queue.h"
int main(void)
{
	AvlTree T;
	T=Init(T);
	int Array[]={3,2,1,4,5,6,7};
	int i;
	for(i=0;i<7;i++)
	{
		T=Insert(Array[i],T);
	}
	//T=Insert(6,T);
	LevelOrder(T);
	
	return 0;
}
