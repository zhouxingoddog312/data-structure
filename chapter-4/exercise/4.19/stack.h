#ifndef _Stack_H
#define _Stack_H
#include "avltree.h"
struct Node;
typedef AvlTree ElementType_S;
typedef struct Node *PtrToNode;
typedef PtrToNode Stack;


int StackIsEmpty(Stack S);
Stack CreateStack(void);
void StackMakeEmpty(Stack S);
void Push(ElementType_S X,Stack S);
ElementType_S Top(Stack S);
void Pop(Stack S);



#endif
