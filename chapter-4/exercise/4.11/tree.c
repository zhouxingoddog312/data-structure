#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include "tree.h"
#include "queue.h"
struct TreeNode
{
	ElementType Element;
	SearchTree Left;
	SearchTree Right;
};
struct TreeNode CursorSpace[SpaceSize];

static void FatalError(char *S);
static void Error(char *S);
static Position CursorMalloc(void);
static void CursorFree(Position P);



static void FatalError(char *S)
{
	fputs(S,stdout);
	putchar('\n');
	exit(EXIT_FAILURE);
}
static void Error(char *S)
{
	puts(S);
}
static Position CursorMalloc(void)
{
	Position P;
	P=CursorSpace[0].Left;
	CursorSpace[0].Left=CursorSpace[0].Right=CursorSpace[P].Left;
	return P;
}
static void CursorFree(Position P)
{
	CursorSpace[P].Left=CursorSpace[P].Right=CursorSpace[0].Left;
	CursorSpace[0].Left=CursorSpace[0].Right=P;
}

void InitCursorSpace(void)
{
	int index;
	for(index=0;index<SpaceSize;index++)
	{
		CursorSpace[index].Element=INT_MIN;
		if(index<SpaceSize-1)
			CursorSpace[index].Left=CursorSpace[index].Right=index+1;
		else
			CursorSpace[index].Left=CursorSpace[index].Right=0;
	}
}

SearchTree Init(SearchTree T)
{
	return 0;
}
SearchTree MakeEmpty(SearchTree T)
{
	if(T!=0)
	{
		MakeEmpty(CursorSpace[T].Left);
		MakeEmpty(CursorSpace[T].Right);
		CursorFree(T);
	}
	return 0;
}


Position Find(ElementType X,SearchTree T)
{
	Position P=T;
	if(P!=0)
	{
		if(CursorSpace[P].Element<X)
			return Find(X,CursorSpace[P].Right);
		else if(CursorSpace[P].Element>X)
			return Find(X,CursorSpace[P].Left);
		else
			return P;
	}
	else
		return P;
}

Position FindMin(SearchTree T)
{
	Position P=T;
	if(P==0)
		return 0;
	if(CursorSpace[P].Left!=0)
		return FindMin(CursorSpace[P].Left);
	else
		return P;
}

Position FindMax(SearchTree T)
{
	Position P=T;
	if(P==0)
		return 0;
	if(CursorSpace[P].Right!=0)
		return FindMax(CursorSpace[P].Right);
	else
		return P;
}
SearchTree Insert(ElementType X,SearchTree T)
{
	if(T==0)
	{
		T=CursorMalloc();
		if(T==0)
			FatalError("Out of space!");
		else
		{
			CursorSpace[T].Element=X;
			CursorSpace[T].Left=CursorSpace[T].Right=0;
		}
	}
	else if(CursorSpace[T].Element>X)
		CursorSpace[T].Left=Insert(X,CursorSpace[T].Left);
	else if(CursorSpace[T].Element<X)
		CursorSpace[T].Right=Insert(X,CursorSpace[T].Right);
//	else if CursorSpace[T].Element==X,there will do nothing
	return T;
}



SearchTree Delete(ElementType X,SearchTree T)
{
	Position Tmpcell;
	if(T==0)
		Error("Element not found!");
	else
	if(X>CursorSpace[T].Element)
		CursorSpace[T].Right=Delete(X,CursorSpace[T].Right);
	else
	if(X<CursorSpace[T].Element)
		CursorSpace[T].Left=Delete(X,CursorSpace[T].Left);
	else
	{
		if(CursorSpace[T].Left&&CursorSpace[T].Right)
		{
			Tmpcell=FindMin(CursorSpace[T].Right);
			CursorSpace[T].Element=CursorSpace[Tmpcell].Element;
			CursorSpace[T].Right=Delete(CursorSpace[T].Element,CursorSpace[T].Right);
		}
		else
		{
			Tmpcell=T;
			if(CursorSpace[T].Left==0)
				T=CursorSpace[T].Right;
			else
			if(CursorSpace[T].Right==0)
				T=CursorSpace[T].Left;
			CursorFree(Tmpcell);
		}
	}
	return T;
}

ElementType Retrieve(Position P)
{
	if(P==0)
		Error("Error position!");
	else
		return CursorSpace[P].Element;
}

void PreOrder(SearchTree T)
{
	if(T!=0)
	{
		printf("%-5d",CursorSpace[T].Element);
		PreOrder(CursorSpace[T].Left);
		PreOrder(CursorSpace[T].Right);
	}
}
void InOrder(SearchTree T)
{
	if(T!=0)
	{
		InOrder(CursorSpace[T].Left);
		printf("%-5d",CursorSpace[T].Element);
		InOrder(CursorSpace[T].Right);
	}
}
void PostOrder(SearchTree T)
{
	if(T!=0)
	{
		PostOrder(CursorSpace[T].Left);
		PostOrder(CursorSpace[T].Right);
		printf("%-5d",CursorSpace[T].Element);
	}
}

void LevelOrder(SearchTree T)
{
	Queue Q;
	Q=CreateQueue(Q);
	while(T!=0)
	{
		printf("%-5d",CursorSpace[T].Element);
		if(CursorSpace[T].Left!=0)
			Q=EnQueue(CursorSpace[T].Left,Q);
		if(CursorSpace[T].Right!=0)
			Q=EnQueue(CursorSpace[T].Right,Q);
		if(IsEmpty(Q))
			T=0;
		else
		{
			T=Front(Q);
			Q=DeQueue(Q);
		}
	}
	Q=DisposeQueue(Q);
}
