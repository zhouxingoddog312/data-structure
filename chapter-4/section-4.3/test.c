#include <stdio.h>
#include "tree.h"
int main(void)
{
	Position P;
	SearchTree T;
	T=MakeEmpty(T);
	T=Insert(4,T);
	T=Insert(2,T);
	T=Insert(3,T);
	T=Insert(5,T);
	T=Insert(6,T);
	printf("the min is %d\n",Retrieve(FindMin(T)));
	printf("the max is %d\n",Retrieve(FindMax(T)));
	P=Find(3,T);
	printf("find %d success\n",Retrieve(P));
	T=Delete(3,T);
	P=Find(3,T);
	if(P==NULL)
		puts("NOt found!");
	return 0;
}
