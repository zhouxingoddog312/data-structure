#include <stdio.h>
#include <stdlib.h>
#include "avltree.h"
#include "queue.h"
#include "stack.h"
struct AvlNode
{
	ElementType Element;
	AvlTree Left;
	AvlTree Right;
	int Height;
};

static void FatalError(char *string);
static void Error(char *string);
static int CatchHeight(Position P);
/*return zhe height of the node*/

static Position SingleRotateWithLeft(Position K2);
/*This function can be call only if K2 has a left child.
  Perform a rotate between a node (k2) and its left child.
  Update heights, then return new root*/

static Position SingleRotateWithRight(Position K1);
/*This function can be call only if k1 has a right child.
  Perform a rotate between a node(k1) and its right child.
  Update height, then return new root*/

static Position DoubleRotateWithLeft(Position K3);
/*This function can be called only if k3 has a left child and
  k3's left child has a right child.
  Do the left-right double rotation.
  Update heights, then return new root.*/

static Position DoubleRotateWithRight(Position K1);
/*This function can be called only if k1 has a right child and
  k1's right child has a left child.
  Do the right-left double rotation.
  Update heights, then return new root.*/

static void FatalError(char *string)
{
	fputs(string,stderr);
	putchar('\n');
	exit(EXIT_FAILURE);
}
static void Error(char *string)
{
	puts(string);
}

static int CatchHeight(Position P)
{
	if(P==NULL)
		return -1;
	else
		return P->Height;
}

static Position SingleRotateWithLeft(Position K2)
{
	Position K1;
	K1=K2->Left;
	K2->Left=K1->Right;
	K1->Right=K2;
	K2->Height=Max(CatchHeight(K2->Left),CatchHeight(K2->Right))+1;
	K1->Height=Max(CatchHeight(K1->Left),CatchHeight(K1->Right))+1;
	return K1;
}
static Position SingleRotateWithRight(Position K1)
{
	Position K2;
	K2=K1->Right;
	K1->Right=K2->Left;
	K2->Left=K1;
	K1->Height=Max(CatchHeight(K1->Left),CatchHeight(K1->Right))+1;
	K2->Height=Max(CatchHeight(K2->Left),CatchHeight(K2->Right))+1;
	return K2;
}

static Position DoubleRotateWithLeft(Position K3)
{
	K3->Left=SingleRotateWithRight(K3->Left);
	return SingleRotateWithLeft(K3);
}
static Position DoubleRotateWithRight(Position K1)
{
	K1->Right=SingleRotateWithLeft(K1->Right);
	return SingleRotateWithRight(K1);
}
AvlTree Delete(ElementType X,AvlTree T)
{
	Position TmpNode;
	if(T==NULL)
		Error("Element not found!");
	else if(X<T->Element)
	{
		T->Left=Delete(X,T->Left);
		if(CatchHeight(T->Right)-CatchHeight(T->Left)==2)
		{
			TmpNode=T->Right;
			if(CatchHeight(TmpNode->Left)>CatchHeight(TmpNode->Right))
				T=DoubleRotateWithRight(T);
			else
				T=SingleRotateWithRight(T);
		}
	}
	else if(X>T->Element)
	{
		T->Right=Delete(X,T->Right);
		if(CatchHeight(T->Left)-CatchHeight(T->Right)==2)
		{
			TmpNode=T->Left;
			if(CatchHeight(TmpNode->Left)>CatchHeight(TmpNode->Right))
				T=SingleRotateWithLeft(T);
			else
				T=DoubleRotateWithRight(T);
		}
	}
	else
	{
		if(T->Left&&T->Right)	/*two child*/
		{
			if(CatchHeight(T->Left)>CatchHeight(T->Right))
			{
				TmpNode=FindMax(T->Left);
				T->Element=TmpNode->Element;
				T->Left=Delete(TmpNode->Element,T->Left);
			}
			else
			{
				TmpNode=FindMin(T->Right);
				T->Element=TmpNode->Element;
				T->Right=Delete(TmpNode->Element,T->Right);
			}
		}
		else	/*only one or no child*/
		{
			TmpNode=T;
			T=(T->Left==NULL?T->Right:T->Left);
			free(TmpNode);
		}
	}
	return T;
}

AvlTree Init(AvlTree T)
{
	return NULL;
}
AvlTree MakeEmpty(AvlTree T)
{
	if(T!=NULL)
	{
		MakeEmpty(T->Left);
		MakeEmpty(T->Right);
		free(T);
	}
	return NULL;
}
Position Find(ElementType X,AvlTree T)
{
	if(T!=NULL)
	{
		if(T->Element>X)
			return Find(X,T->Left);
		else if(T->Element<X)
			return Find(X,T->Right);
		else
			return T;
	}
	else
		return T;
}
Position FindMin(AvlTree T)
{
	if(T!=NULL)
		while(T->Left!=NULL)
			T=T->Left;
	return T;
}
Position FindMax(AvlTree T)
{
	if(T==NULL)
		return T;
	else
	{
		if(T->Right!=NULL)
			return FindMax(T->Right);
		else
			return T;
	}
}
/*
AvlTree Insert(ElementType X,AvlTree T)
{
	if(T==NULL)
	{
		T=malloc(sizeof(struct AvlNode));
		if(T==NULL)
			FatalError("Out of space!");
		else
		{
			T->Element=X;
			T->Left=T->Right=NULL;
		}
	}
	else if(X<T->Element)
	{
		T->Left=Insert(X,T->Left);
		if(CatchHeight(T->Left)-CatchHeight(T->Right)==2)
			if(X<T->Left->Element)
				T=SingleRotateWithLeft(T);
			else
				T=DoubleRotateWithLeft(T);
	}
	else if(X>T->Element)
	{
		T->Right=Insert(X,T->Right);
		if(CatchHeight(T->Right)-CatchHeight(T->Left)==2)
			if(X>T->Right->Element)
				T=SingleRotateWithRight(T);
			else
				T=DoubleRotateWithRight(T);
	}
//else X==T->Element ,there will do nothing
	T->Height=Max(CatchHeight(T->Left),CatchHeight(T->Right))+1;
	return T;
}
*/
AvlTree Insert(ElementType X,AvlTree T)
{
	Position Ptr;
	Position Temp=T;
	Stack S;
	S=CreateStack();
	while(Temp!=NULL)
	{
		Push(Temp,S);
		if(X<Temp->Element)
			Temp=Temp->Left;
		else if(X>Temp->Element)
			Temp=Temp->Right;
	//else X==T->Element ,there will do nothing
	}	
	Temp=malloc(sizeof(struct AvlNode));
	if(Temp==NULL)
		FatalError("Out of space!");
	else
	{
		Temp->Element=X;
		Temp->Left=Temp->Right=NULL;
		Temp->Height=Max(CatchHeight(Temp->Left),CatchHeight(Temp->Right))+1;
	}
	if(StackIsEmpty(S))
		return Temp;
	else
	{
		Ptr=Top(S);
		if(X<Ptr->Element)
			Ptr->Left=Temp;
		else if(X>Ptr->Element)
			Ptr->Right=Temp;
	}
	while(!StackIsEmpty(S))
	{
		Temp=Top(S);
		Pop(S);
		if(!StackIsEmpty(S))
		{
			Ptr=Top(S);
			if(CatchHeight(Temp->Left)-CatchHeight(Temp->Right)==2)
			{
				if(CatchHeight(Temp->Left->Left)>CatchHeight(Temp->Left->Right))
				{
					if(Ptr->Left==Temp)
						Ptr->Left=SingleRotateWithLeft(Temp);
					else
						Ptr->Right=SingleRotateWithLeft(Temp);
				}
				else if(CatchHeight(Temp->Left->Left)<CatchHeight(Temp->Left->Right))
				{
					if(Ptr->Left==Temp)
						Ptr->Left=DoubleRotateWithLeft(Temp);
					else
						Ptr->Right=DoubleRotateWithLeft(Temp);
				}
			}
			else if(CatchHeight(Temp->Right)-CatchHeight(Temp->Left)==2)
			{
				if(CatchHeight(Temp->Right->Left)>CatchHeight(Temp->Right->Right))
				{
					if(Ptr->Left==Temp)
						Ptr->Left=DoubleRotateWithRight(Temp);
					else
						Ptr->Right=DoubleRotateWithRight(Temp);
				}
				else if(CatchHeight(Temp->Right->Left)<CatchHeight(Temp->Right->Right))
				{
					if(Ptr->Left==Temp)
						Ptr->Left=SingleRotateWithRight(Temp);
					else
						Ptr->Right=SingleRotateWithRight(Temp);
				}
			}
			Ptr->Height=Max(CatchHeight(Ptr->Left),CatchHeight(Ptr->Right))+1;
		}
		else
		{
			if(CatchHeight(Temp->Left)-CatchHeight(Temp->Right)==2)
			{
				if(CatchHeight(Temp->Left->Left)>CatchHeight(Temp->Left->Right))
				{
						return SingleRotateWithLeft(Temp);
				}
				else if(CatchHeight(Temp->Left->Left)<CatchHeight(Temp->Left->Right))
				{
						return DoubleRotateWithLeft(Temp);
				}
			}
			else if(CatchHeight(Temp->Right)-CatchHeight(Temp->Left)==2)
			{
				if(CatchHeight(Temp->Right->Left)>CatchHeight(Temp->Right->Right))
				{
						return DoubleRotateWithRight(Temp);
				}
				else if(CatchHeight(Temp->Right->Left)<CatchHeight(Temp->Right->Right))
				{
						return SingleRotateWithRight(Temp);
				}
			}
		}
	}
	return T;
}
ElementType Retrieve(Position P)
{
	if(P==NULL)
		Error("Wrong position!");
	else
		return P->Element;
}


void PreOrder(AvlTree T)
{
	if(T!=NULL)
	{
		printf("%-5d",T->Element);
		PreOrder(T->Left);
		PreOrder(T->Right);
	}
}
void InOrder(AvlTree T)
{
	if(T!=NULL)
	{
		InOrder(T->Left);
		printf("%-5d",T->Element);
		InOrder(T->Right);
	}
}
void PostOrder(AvlTree T)
{
	if(T!=NULL)
	{
		PostOrder(T->Left);
		PostOrder(T->Right);
		printf("%-5d",T->Element);
	}
}
void LevelOrder(AvlTree T)
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
