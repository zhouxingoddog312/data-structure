#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define MinPQSize 1
typedef int ElementType;
struct HeapStruct;
typedef struct HeapStruct *PriorityQueue;

PriorityQueue Initialize(int MaxElements);
void BuildHeap(ElementType Data[],int Length,PriorityQueue H);
void Destroy(PriorityQueue H);
void MakeEmpty(PriorityQueue H);
void Insert(ElementType X,PriorityQueue H);
ElementType DeleteMin(PriorityQueue H);
ElementType FindMin(PriorityQueue H);
int IsEmpty(PriorityQueue H);
int IsFull(PriorityQueue H);

struct HeapStruct
{
	int Capacity;
	int Size;
	ElementType *Elements;
};
static void FatalError(char *string);
static void Error(char *string);
static void PercolateDown(int index,ElementType Data[],int Length);

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
static void PercolateDown(int index,ElementType Data[],int Length)
{
	ElementType Temp;
	int i,Child;
	for(i=index;i*2<=Length;i=Child)
	{
		Child=i*2;
		if((Child!=Length)&&(Data[Child]>Data[Child+1]))
			Child++;
		if(Data[i]>Data[Child])
		{
			Temp=Data[i];
			Data[i]=Data[Child];
			Data[Child]=Temp;
		}
		else
			break;
	}
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
void BuildHeap(ElementType Data[],int Length,PriorityQueue H)
{
	if(!IsEmpty(H))
	{
		Error("Make PriorityQueue be initialized!");
		return;
	}
	for(int index=1;index<=Length;index++)
		H->Elements[index]=Data[index-1];
	H->Size=Length;
	for(int index=Length/2;index>0;index--)
		PercolateDown(index,H->Elements,Length);
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
		if((child!=H->Size)&&(H->Elements[child]>H->Elements[child+1]))
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
int main(void)
{
	int heap_node_count,path_count;
	int temp_index,index,print_count;
	scanf("%d %d",&heap_node_count,&path_count);
	if(heap_node_count)
	{
		PriorityQueue H=Initialize(heap_node_count);
		int OriginData[heap_node_count];
		for(index=0;index<heap_node_count;index++)
			scanf("%d",&OriginData[index]);
		for(index=0;index<heap_node_count;index++)
			Insert(OriginData[index],H);
		for(print_count=0;print_count<path_count;print_count++)
		{
			scanf("%d",&temp_index);
			for(;temp_index>=1;temp_index/=2)
			{
				if(temp_index!=1)
					printf("%d ",H->Elements[temp_index]);
				else
					printf("%d\n",H->Elements[temp_index]);
			}
		}
	}
	return 0;
}
