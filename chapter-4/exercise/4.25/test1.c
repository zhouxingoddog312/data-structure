#include <stdio.h>
#include "splaytree.h"
#include "queue.h"
int main(void)
{
	int i;
	SplayTree T;
	T=Init(T);
	for(i=1;i<=1024;i++)
	{
		T=Insert(i,T);
	}
	printf("Inside Path length is %d\n",InsidePath(T));
	for(i=1;i<=15;i++)
	{
		T=Find(i,T);
		printf("After Find(%d) ,Inside Path length is %d\n",i,InsidePath(T));
	}
	return 0;
}
