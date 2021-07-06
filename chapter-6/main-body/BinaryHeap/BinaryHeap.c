#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "BinaryHeap.h"
#define MinPQSize 1

struct HeapStruct
{
	int Capacity;
	int Size;
	ElementType *Elements;
};
static void FatalError(char *string);
static void Error(char *string);

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


PriorityQueue Initialize(int MaxElements)
{
	PriorityQueue H;
	if(MaxElements<MinPQSize)
		Error("Priority queue is too small!");
	H=malloc(sizeof(struct HeapStruct));
	if(H==NULL)
		FatalError("Out of space to create Priority queue!");
	H->Elements=malloc(sizeof(ElementType)*(MaxElements+1));
	if(H->Elements==NULL)
		FatalError("Out of space for elements!");
	H->Capacity=MaxElements;
	H->Size=0;
	H->Elements[0]=INT_MIN;
	return H;
}
void Destroy(PriorityQueue H)
{
	if(H==NULL)
		Error("Priority queue isn't exist!");
	else
	{		
		free(H->Elements);
		free(H);
	}
}
void MakeEmpty(PriorityQueue H)
{
	if(H==NULL)
		Error("Initiate first!");
	else
	{
		H->Size=0;
	}
}
void Insert(ElementType X,PriorityQueue H)
{
	int i;
	if(IsFull(H))
	{
		Error("Priority queue is full!");
		return;
	}
	for(i=++H->Size;X<H->Elements[i/2];i/=2)
		H->Elements[i]=H->Elements[i/2];
	H->Elements[i]=X;
}
ElementType DeleteMin(PriorityQueue H)
{
	int i,child;
	ElementType MinElement,LastElement;
	if(IsEmpty(H))
	{
		Error("Priority queue is empty!");
		return H->Elements[0];
	}
	MinElement=H->Elements[1];
	LastElement=H->Elements[H->Size--];
	for(i=1;i*2<=H->Size;i=child)
	{
		child=i*2;
		if(child!=H->Size&&H->Elements[child]>H->Elements[child+1])
			child++;
		if(LastElement>H->Elements[child])
			H->Elements[i]=H->Elements[child];
		else
			break;
	}
	H->Elements[i]=LastElement;
	return MinElement;
}
ElementType FindMin(PriorityQueue H)
{
	if(IsEmpty(H))
	{
		Error("Priority queue is empty!");
		return INT_MIN;
	}
	return H->Elements[1];
}
int IsEmpty(PriorityQueue H)
{
	return H->Size==0;
}
int IsFull(PriorityQueue H)
{
	return H->Size==H->Capacity;
}
