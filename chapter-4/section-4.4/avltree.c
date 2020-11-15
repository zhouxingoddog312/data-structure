#include <stdio.h>
#include <stdlib.h>
#include "avltree.h"
struct AvlNode
{
	ElementType Element;
	AvlTree Left;
	AvlTree Right;
	int Height;
};

static void FatalErorr(char *string);
static void Erorr(char *string);
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

static void FatalErorr(char *string)
{
	fputs("string\n",stderr);
	exit(EXIT_FAILURE);
}
static void Erorr(char *string)
{
	fputs("string\n",stderr);
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
		Erorr("Element not found!");
	else if(X<T->Element)
	{
		T->Left=Delete(X,T->Left);
		if(CatchHeight(T->Right)-CatchHeight(T->Left)==2)
		{
			TmpNode=T->Right;
			if(CatchHeight(TmpNode->Left)>CatchHeight(TmpNode->Rgiht))
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
AvlTree Insert(ElementType X,AvlTree T)
{
	if(T==NULL)
	{
		T=malloc(sizeof(struct AvlNode));
		if(T==NULL)
			FatalErorr("Out of space!");
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
AvlTree Delete(ElementType X,AvlTree T)
{

}
ElementType Retrieve(Position P)
{
	if(P==NULL)
		Erorr("Wrong position!");
	else
		return P->Element;
}
