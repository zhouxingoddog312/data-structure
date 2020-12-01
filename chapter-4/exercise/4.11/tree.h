#ifndef _Tree_H
#define _Tree_H
#define SpaceSize 100
struct TreeNode;
typedef int PtrToNode;
typedef  PtrToNode Position;
typedef PtrToNode SearchTree;
typedef int ElementType;

void InitCursorSpace(void);
SearchTree Init(SearchTree T);
SearchTree MakeEmpty(SearchTree T);
Position Find(ElementType X,SearchTree T);
Position FindMin(SearchTree T);
Position FindMax(SearchTree T);
SearchTree Insert(ElementType X,SearchTree T);
SearchTree Delete(ElementType X,SearchTree T);
ElementType Retrieve(Position P);

void PreOrder(SearchTree T);
void InOrder(SearchTree T);
void PostOrder(SearchTree T);

void LevelOrder(SearchTree T);
#endif
