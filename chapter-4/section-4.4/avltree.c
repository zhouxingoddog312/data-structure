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
	K2->Height=Max(Height(K2->Left),Height(K2->Right))+1;
	K1->Height=Max(Height(K1->Left),Height(K1->Right))+1;
	return K1;
}
static Position SingleRotateWithRight(Position K1)
{
	Position K2;
	K2=K1->Right;
	K1->Right=K2->Left;
	K2->Left=K1;
	K1->Height=Max(Height(K1->Left),Height(K1->Right))+1;
	K2->Height=Max(Height(K2->Left),Height(K2->Right))+1;
	return K2;
}

static Position DoubleRotateWithLeft(Position K3)
{

}
