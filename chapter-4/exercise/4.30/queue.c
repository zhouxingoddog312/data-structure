#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
struct QueueRecord
{
	ElementType_Q Element;
	Position_Q Next;
};

static void FatalError(char *string);
static Position_Q MakeNode(ElementType_Q X);


static void FatalError(char *string)
{
	fputs(string,stderr);
	putchar('\n');
	exit(EXIT_FAILURE);
}
static Position_Q MakeNode(ElementType_Q X)
{
	Position_Q P;
	P=malloc(sizeof(struct QueueRecord));
	if(P==NULL)
		FatalError("No more space for queue!");
	else
	{
		P->Element=X;
		P->Next=NULL;
		return P;
	}
}

bool IsEmpty(Queue Q)
{
	if(Q==NULL)
		return true;
	else
		return false;
}
Queue CreateQueue(Queue Q)
{
	return NULL;
}
Queue DisposeQueue(Queue Q)
{
	while(!IsEmpty(Q))
		Q=DeQueue(Q);
	return Q;
}
Queue EnQueue(ElementType_Q X,Queue Q)
{
	Position_Q P,tmp;
	P=MakeNode(X);
	if(Q==NULL)
		return P;
	else
	{
		tmp=Q;
		while(Q->Next!=NULL)
			Q=Q->Next;
		Q->Next=P;
		return tmp; 
	}
}
Queue DeQueue(Queue Q)
{
	Position_Q tmp;
	tmp=Q;
	if(Q!=NULL)
	{
		Q=Q->Next;
		free(tmp);
		return Q;
	}
	else
	{
		puts("Queue is empty!");
		return Q;
	}
}

ElementType_Q Front(Queue Q)
{
	if(Q)
	{
		return Q->Element;
	}
	else
		puts("Queue is empty!");
}
