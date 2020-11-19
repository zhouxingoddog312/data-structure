#include <stdio.h>
#include "splaytree.h"
#include "queue.h"
int main(void)
{
	int i;
	SplayTree T;
	T=Init(T);
	for(i=1;i<=7;i++)
	{
		T=Insert(i,T);
	}
	fputs("LevelOrder\n",stdout);
	LevelOrder(T);
	fputs("\n",stdout);
	puts("InOrder");
	InOrder(T);
	fputs("\nPreOrder\n",stdout);
	PreOrder(T);
	fputs("\nPostOrder\n",stdout);
	PostOrder(T);
	puts("-------------------------------------");
	T=Delete(1,T);	
	fputs("LevelOrder\n",stdout);
	LevelOrder(T);
	fputs("\n",stdout);
	puts("InOrder");
	InOrder(T);
	fputs("\nPreOrder\n",stdout);
	PreOrder(T);
	fputs("\nPostOrder\n",stdout);
	PostOrder(T);


	return 0;
}
