#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "SkewHeap.h"
struct TreeNode
{
	ElementType Element;
	PriorityQueue Left;
	PriorityQueue Right;
};
static void FatalError(char *string);
static void Error(char *string);
static void SwapChildren(PriorityQueue H);
static PriorityQueue  Merge1(PriorityQueue H1,PriorityQueue H2);


static void FatalError(char *string)
{
	fputs(string,stderr);
	putc('\n',stderr);
	exit(EXIT_FAILURE);
}
static void Error(char *string)
{
	fputs(string,stderr);
	putc('\n',stderr);
}
static void SwapChildren(PriorityQueue H)
{
	PriorityQueue Temp;
	Temp=H->Left;
	H->Left=H->Right;
	H->Right=Temp;
}
static PriorityQueue Merge1(PriorityQueue H1,PriorityQueue H2)
{
	if(H1->Left==NULL)
		H1->Left=H2;
	else
	{
		H1->Right=Merge(H1->Right,H2);
		SwapChildren(H1);
	}
	return H1;
}

PriorityQueue Initialize(void)
{
	PriorityQueue H=NULL;
	return H;
}
ElementType FindMin(PriorityQueue H)
{
	if(IsEmpty(H))
	{
		Error("Priority queue is empty!");
		return INT_MIN;
	}
	else
		return H->Element;
}
int IsEmpty(PriorityQueue H)
{
	return H==NULL;
}
PriorityQueue Merge(PriorityQueue H1,PriorityQueue H2)
{
	if(H1==NULL)
		return H2;
	if(H2==NULL)
		return H1;
	if(H1->Element<H2->Element)
		return Merge1(H1,H2);
	else
		return Merge1(H2,H1);
}
PriorityQueue Insert1(ElementType X,PriorityQueue H)
{
	PriorityQueue SingleNode;
	SingleNode=malloc(sizeof(struct TreeNode));
	if(SingleNode==NULL)
		FatalError("Out of space!");
	else
	{
		SingleNode->Element=X;
		SingleNode->Left=SingleNode->Right=NULL;
		H=Merge(SingleNode,H);
	}
	return H;
}
PriorityQueue DeleteMin1(PriorityQueue H)
{
	PriorityQueue LeftHeap,RightHeap;
	if(IsEmpty(H))
	{
		Error("Priority queue is empty!");
		return H;
	}
	LeftHeap=H->Left;
	RightHeap=H->Right;
	free(H);
	return Merge(LeftHeap,RightHeap);
}
PriorityQueue MakeEmpty(PriorityQueue H)
{
	while(!IsEmpty(H))
		H=DeleteMin1(H);
	return H;
}
