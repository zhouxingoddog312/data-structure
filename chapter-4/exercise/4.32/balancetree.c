#include <stdio.h>
#include <math.h>
#include "tree.h"
#include "queue.h"
#define H 4
int NodeCount(int Height);
int main(void)
{
	SearchTree T;
	T=Init(T);
	T=MakeBalanceTree(1,NodeCount(H),T);
	LevelOrder(T);
	puts("print interval.");
	PrintInterval(6,20,T);
	return 0;
}
int NodeCount(int Height)
{
	return ((int)pow(2,Height+1)-1);
}

