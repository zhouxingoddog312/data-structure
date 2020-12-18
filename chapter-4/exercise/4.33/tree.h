#ifndef _Tree_H
#define _Tree_H
struct TreeNode;
typedef struct TreeNode *Position;
typedef struct TreeNode *SearchTree;
typedef int ElementType;

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


int NodeCount(SearchTree T);
int LeafCount(SearchTree T);
int FullNodeCount(SearchTree T);
SearchTree MakeRandomTree(int N);
int Deep(Position P,SearchTree T)
int InsidePath(SearchTree T)
#endif
