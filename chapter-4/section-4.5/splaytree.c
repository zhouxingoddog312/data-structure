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
}

static void FatalErorr(char *string);
static Position SearchValue(ElementType X,SplayTree T);
static Position SingleRotateWithLeft(Position P);
static Position SingleRotateWithRight(Position P);
static Position DoubleRotateWithLeft(Position P);
static Position DoubleRotateWithRight(Position P);
static Position DoubleRotateLeftRight(Position P);
static Position DoubleRotateRightLeft(Position P);

