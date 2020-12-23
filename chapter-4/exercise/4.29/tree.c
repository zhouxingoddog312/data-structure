#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
#include "queue.h"
struct TreeNode
{
	ElementType Element;
	SearchTree Left;
	SearchTree Right;
};

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

SearchTree Init(SearchTree T)
{
	return NULL;
}
SearchTree MakeEmpty(SearchTree T)
{
	if(T!=NULL)
	{
		MakeEmpty(T->Left);
		MakeEmpty(T->Right);
		free(T);
	}
	return NULL;
}

Position Find(ElementType X,SearchTree T)
{
	Position P=T;
	if(P!=NULL)
	{
		if(P->Element<X)
			return Find(X,P->Right);
		else if(P->Element>X)
			return Find(X,P->Left);
		else
			return P;
	}
	else
		return P;
}

Position FindMin(SearchTree T)
{
	Position P=T;
	if(P==NULL)
		return NULL;
	if(P->Left!=NULL)
		return FindMin(P->Left);
	else
		return P;
}

Position FindMax(SearchTree T)
{
	Position P=T;
	if(P==NULL)
		return NULL;
	if(P->Right!=NULL)
		return FindMax(P->Right);
	else
		return P;
}

SearchTree Insert(ElementType X,SearchTree T)
{
	if(T==NULL)
	{
		T=malloc(sizeof(struct TreeNode));
		if(T==NULL)
			FatalError("Out of space!");
		else
		{
			T->Element=X;
			T->Left=T->Right=NULL;
		}
	}
	else
	if(T->Element>X)
		T->Left=Insert(X,T->Left);
	else
	if(T->Element<X)
		T->Right=Insert(X,T->Right);
/*	else

if T->Element==X,there will do nothing
*/
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
int NodeCount(SearchTree T)
{
	if(T!=NULL)
	{
		return NodeCount(T->Left)+NodeCount(T->Right)+1;
	}
	else
		return 0;
}
int LeafCount(SearchTree T)
{
	if(T==NULL)
		return 0;
	else if(T->Left==NULL && T->Right==NULL)
		return 1;
	return LeafCount(T->Left)+LeafCount(T->Right);
}
int FullNodeCount(SearchTree T)
{
	if(T==NULL)
		return 0;
	return (T->Left!=NULL && T->Right!=NULL)+FullNodeCount(T->Left)+FullNodeCount(T->Right);
}
