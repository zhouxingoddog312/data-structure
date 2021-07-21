#ifndef _BinomialQueue_H
#define _BinomialQueue_H

#define MaxTrees 8	//代表二项队列中可以有8个二项树，高度从0至7
#define Capacity (1<<MaxTrees-1)	//代表二项队列中可以容纳的节点数

typedef int ElementType;
typedef struct BinNode *Position;
typedef struct BinNode *BinTree;
typedef struct Collection *BinQueue;

BinQueue Initialize(void);
void Destroy(BinQueue H);
int IsEmpty(BinQueue H);
void MakeEmpty(BinQueue H);
BinQueue Merge(BinQueue H1,BinQueue H2);
BinQueue Insert(ElementType X,BinQueue H);
ElementType FindMin(BinQueue H);
ElementType DeleteMin(BinQueue *H);


#endif
