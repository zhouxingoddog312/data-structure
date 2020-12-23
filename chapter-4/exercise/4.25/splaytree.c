#include <stdio.h>
#include <stdlib.h>
#include "splaytree.h"
#include "queue.h"

struct SplayNode
{
	ElementType Element;
	Position Parent;
	Position Left;
	Position Right;
};

static void FatalError(char *string);
static Position SearchValue(ElementType X,SplayTree T);
static void SingleRotateWithLeft(Position P);
static void SingleRotateWithRight(Position P);
static void DoubleRotateTwiceLeft(Position P);
static void DoubleRotateTwiceRight(Position P);
static void DoubleRotateLeftRight(Position P);
static void DoubleRotateRightLeft(Position P);
static SplayTree Splay(Position P,SplayTree T);
static Position MakeNode(ElementType X);

static int Deep(Position P,SplayTree T);

static void FatalError(char *string)
{
	fputs(string,stderr);
	putchar('\n');
	exit(EXIT_FAILURE);
}
static Position MakeNode(ElementType X)
{
	Position P;
	P=malloc(sizeof(struct SplayNode));
	if(P==NULL)
		FatalError("Out of space!");
	P->Parent=P->Left=P->Right=NULL;
	P->Element=X;
	return P;
}
static Position SearchValue(ElementType X,SplayTree T)
{
	if(T==NULL)
		return NULL;
	if(X<T->Element)
		return SearchValue(X,T->Left);
	else if(X>T->Element)
		return SearchValue(X,T->Right);
	else
		return T;
}
static void SingleRotateWithLeft(Position P)
{
	Position Parent_node,GrandParent_node;
	Parent_node=P->Parent;
	GrandParent_node=Parent_node->Parent;
	if(GrandParent_node)
	{
		if(GrandParent_node->Left==Parent_node)
			GrandParent_node->Left=P;
		else
			GrandParent_node->Right=P;
	}
	Parent_node->Parent=P;
	P->Parent=GrandParent_node;
	Parent_node->Left=P->Right;
	if(P->Right)
	{
		P->Right->Parent=Parent_node;
	}
	P->Right=Parent_node;
}
static void SingleRotateWithRight(Position P)
{
	Position Parent_node,GrandParent_node;
	Parent_node=P->Parent;
	GrandParent_node=Parent_node->Parent;
	if(GrandParent_node)
	{
		if(GrandParent_node->Left==Parent_node)
			GrandParent_node->Left=P;
		else
			GrandParent_node->Right=P;
	}
	Parent_node->Parent=P;
	P->Parent=GrandParent_node;
	Parent_node->Right=P->Left;
	if(P->Left)
	{
		P->Left->Parent=Parent_node;
	}
	P->Left=Parent_node;
}
static void DoubleRotateTwiceLeft(Position P)
{
	SingleRotateWithLeft(P->Parent);
	SingleRotateWithLeft(P);
}
static void DoubleRotateTwiceRight(Position P)
{
	SingleRotateWithRight(P->Parent);
	SingleRotateWithRight(P);
}
static void DoubleRotateLeftRight(Position P)
{
	SingleRotateWithLeft(P);
	SingleRotateWithRight(P);
}
static void DoubleRotateRightLeft(Position P)
{
	SingleRotateWithRight(P);
	SingleRotateWithLeft(P);
}
static SplayTree Splay(Position P,SplayTree T)
{
	Position Parent_node,GrandParent_node;
	while(P->Parent!=NULL)
	{
		Parent_node=P->Parent;
		GrandParent_node=Parent_node->Parent;
		if(T->Left==P)
			SingleRotateWithLeft(P);
		else if(T->Right==P)
			SingleRotateWithRight(P);
		else if(GrandParent_node->Left==Parent_node&&Parent_node->Left==P)
			DoubleRotateTwiceLeft(P);
		else if(GrandParent_node->Right==Parent_node&&Parent_node->Right==P)
			DoubleRotateTwiceRight(P);
		else if(GrandParent_node->Left==Parent_node&&Parent_node->Right==P)
			DoubleRotateRightLeft(P);
		else if(GrandParent_node->Right==Parent_node&&Parent_node->Left==P)
			DoubleRotateLeftRight(P);
	}
	return P;
}

SplayTree Init(SplayTree T)
{
	return NULL;
}
SplayTree MakeEmpty(SplayTree T)
{
	if(T!=NULL)
	{
		MakeEmpty(T->Left);
		MakeEmpty(T->Right);
		free(T);
	}
	return NULL;
}
Position FindMin(SplayTree T)
{
	Position P=T;
	if(T!=NULL)
		while(T->Left!=NULL)
			T=T->Left;
	else
		return NULL;
	return Splay(T,P);
}
Position FindMax(SplayTree T)
{
	Position P=T;
	if(P==NULL)
		return P;
	else
		while(P->Right!=NULL)
			P=P->Right;
	return Splay(P,T);
}
Position Find(ElementType X,SplayTree T)
{
	Position P;
	P=SearchValue(X,T);
	if(P==NULL)
	{
		puts("Not found!");
		return NULL;
	}
	P=Splay(P,T);
	return P;
}
SplayTree Insert(ElementType X,SplayTree T)
{
	Position P,Temp=T;
	if(Temp==NULL)
	{
		P=MakeNode(X);
		return P;
	}
	while(Temp!=NULL)
	{
		if(X>Temp->Element)
		{
			if(Temp->Right!=NULL)
				Temp=Temp->Right;
			else
			{
				P=MakeNode(X);
				Temp->Right=P;
				P->Parent=Temp;
				P=Splay(P,T);
				return P;
			}
		}
		else if(X<Temp->Element)
		{
			if(Temp->Left!=NULL)
				Temp=Temp->Left;
			else
			{
				P=MakeNode(X);
				Temp->Left=P;
				P->Parent=Temp;
				P=Splay(P,T);
				return P;
			}
		}
		else
		{
			puts("Exist!");
			break;
		}
	}
}

SplayTree Delete(ElementType X,SplayTree T)
{
	Position P,Temp,L,R;
	P=Find(X,T);
	if(P->Left==NULL&&P->Right==NULL)
		return NULL;
	else if(P->Left==NULL)
	{
		Temp=P;
		P=P->Right;
		free(Temp);
		return P;
	}
	else if(P->Right==NULL)
	{
		Temp=P;
		P=P->Left;
		free(Temp);
		return P;
	}
	else
	{
		L=P->Left;
		R=P->Right;
		L->Parent=NULL;
		R->Parent=NULL;
		free(P);
		L=FindMax(L);
		L->Right=R;
		return L;
	}
}
ElementType Retrieve(Position P)
{

	if(P==NULL)
		puts("Error position!");
	else
		return P->Element;
}
void PreOrder(SplayTree T)
{
	if(T!=NULL)
	{
		printf("%-5d",T->Element);
		PreOrder(T->Left);
		PreOrder(T->Right);
	}
}
void InOrder(SplayTree T)
{
	if(T!=NULL)
	{
		InOrder(T->Left);
		printf("%-5d",T->Element);
		InOrder(T->Right);
	}
}
void PostOrder(SplayTree T)
{
	if(T!=NULL)
	{
		PostOrder(T->Left);
		PostOrder(T->Right);
		printf("%-5d",T->Element);
	}
}

void LevelOrder(SplayTree T)
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
static int Deep(Position P,SplayTree T)
{
	Position Temp=T;
	int deep=0;
	while(Temp!=P)
	{
		if(P->Element>Temp->Element)
			Temp=Temp->Right;
		else if(P->Element<Temp->Element)
			Temp=Temp->Left;
		deep++;
	}
	return deep;
}
int InsidePath(SplayTree T)
{
	SplayTree Temp=T;
	int Sum=0;
	Queue Q;
	Q=CreateQueue(Q);
	while(T!=NULL)
	{
		Sum+=Deep(T,Temp);
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
	return Sum;
}
