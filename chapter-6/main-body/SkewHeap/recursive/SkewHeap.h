#ifndef _SkewHeap_H
#define _SkewHeap_H
#define Insert(X,H) (H=Insert1((X),H))
#define DeleteMin(M) ({int i=FindMin(M);M=DeleteMin1(M);i;})
typedef int ElementType;
struct TreeNode;
typedef struct TreeNode *PriorityQueue;
PriorityQueue Initialize(void);
int IsEmpty(PriorityQueue H);
PriorityQueue MakeEmpty(PriorityQueue H);
ElementType FindMin(PriorityQueue H);
PriorityQueue Merge(PriorityQueue H1,PriorityQueue H2);
PriorityQueue Insert1(ElementType X,PriorityQueue H);
PriorityQueue DeleteMin1(PriorityQueue H);

#endif
