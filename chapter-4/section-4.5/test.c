#include <stdio.h>
#include "splaytree.h"
#include "queue.h"
int main(void)
{
	int i;
	SplayTree T;
	T=Init(T);
	for(i=2;i<=4;i++)
	{
		T=Insert(i,T);
	}
	T=Insert(1,T);
	T=Find(3,T);
	fputs("LevelOrder\n",stdout);
	LevelOrder(T);
	fputs("\n",stdout);
	puts("InOrder");
	InOrder(T);
	fputs("\nPreOrder\n",stdout);
	PreOrder(T);
	fputs("\nPostOrder\n",stdout);
	PostOrder(T);
//	T=Find(1,T);
//	LevelOrder(T);
	return 0;
}
