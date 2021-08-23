#ifndef _BinaryHeap_H
#define _BinaryHeap_H
typedef int ElementType;
struct HeapStruct;
typedef struct HeapStruct *PriorityQueue;

PriorityQueue Initialize(int MaxElements);
void Destroy(PriorityQueue H);
void MakeEmpty(PriorityQueue H);
void Insert(ElementType X,PriorityQueue H);
ElementType DeleteMin(PriorityQueue H);
ElementType FindMin(PriorityQueue H);
int IsEmpty(PriorityQueue H);
int IsFull(PriorityQueue H);

void BuildHeap(ElementType Data[],int Length,PriorityQueue H);
void DecreaseKey(int index,int delta,PriorityQueue H);
void IncreaseKey(int index,int delta,PriorityQueue H);
void Delete(int index,PriorityQueue H);
void PrintHeap(PriorityQueue H);
#endif
