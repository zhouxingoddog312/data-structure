#ifndef _AvlTree_H
#define _AvlTree_H

#define Max(X,Y) ((X)>=(Y)?(X):(Y))

typedef int ElementType;
struct AvlNode;
typedef struct AvlNode *Position;
typedef struct AvlNode *AvlTree;

AvlTree Init(AvlTree T);
AvlTree MakeEmpty(AvlTree T);
Position Find(ElementType X,AvlTree T);
Position FindMin(AvlTree T);
Position FindMax(AvlTree T);
AvlTree Insert(ElementType X,AvlTree T);
AvlTree Delete(ElementType X,AvlTree T);
ElementType Retrieve(Position P);

void PreOrder(AvlTree T);
void InOrder(AvlTree T);
void PostOrder(AvlTree T);
void LevelOrder(AvlTree T);
#endif
