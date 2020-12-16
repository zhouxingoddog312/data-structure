#ifndef _SplayTree_H
#define _SplayTree_H

typedef int ElementType;


struct SplayNode;
typedef struct SplayNode *SplayTree;
typedef struct SplayNode *Position;

SplayTree Init(SplayTree T);
SplayTree MakeEmpty(SplayTree T);
Position FindMin(SplayTree T);
Position FindMax(SplayTree T);
Position Find(ElementType X,SplayTree T);
SplayTree Insert(ElementType X,SplayTree T);
SplayTree Delete(ElementType X,SplayTree T);
ElementType Retrieve(Position P);
int InsidePath(SplayTree T);

void PreOrder(SplayTree T);
void InOrder(SplayTree T);
void PostOrder(SplayTree T);
void LevelOrder(SplayTree T);
#endif
