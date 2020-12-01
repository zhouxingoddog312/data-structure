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
	fputs("S\n",stdout);
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
		CursorSpace[index].ElementType=INT_MIN;
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
	if(T==NULL)
		Error("Element not found!");
	else
	if(X>T->Element)
		T->Right=Delete(X,T->Right);
	else
	if(X<T->Element)
		T->Left=Delete(X,T->Left);
	else
	{
		if(T->Left && T->Right)
		{
			Tmpcell=FindMin(T->Right);
			T->Element=Tmpcell->Element;
			T->Right=Delete(T->Element,T->Right);
		}
		else
		{
			Tmpcell=T;
			if(T->Left==NULL)
				T=T->Right;
			else
			if(T->Right==NULL)
				T=T->Left;
			free(Tmpcell);
		}
	}
	return T;
}

ElementType Retrieve(Position P)
{
	if(P==NULL)
		Error("Error position!");
	else
		return P->Element;
}

void PreOrder(SearchTree T)
{
	if(T!=NULL)
	{
		printf("%-5d",T->Element);
		PreOrder(T->Left);
		PreOrder(T->Right);
	}
}
void InOrder(SearchTree T)
{
	if(T!=NULL)
	{
		InOrder(T->Left);
		printf("%-5d",T->Element);
		InOrder(T->Right);
	}
}
void PostOrder(SearchTree T)
{
	if(T!=NULL)
	{
		PostOrder(T->Left);
		PostOrder(T->Right);
		printf("%-5d",T->Element);
	}
}

void LevelOrder(SearchTree T)
{
	Queue Q;
	Q=CreateQueue(Q);
	while(T!=NULL)
	{
		printf("%-5d",T->Element);
		if(T->Left!=NULL)
			Q=EnQueue(T->Left,Q);
		if(T->Right!=NULL)
			Q=EnQueue(T->Right,Q);
		if(IsEmpty(Q))
			T=NULL;
		else
		{
			T=Front(Q);
			Q=DeQueue(Q);
		}
	}
	Q=DisposeQueue(Q);
}
