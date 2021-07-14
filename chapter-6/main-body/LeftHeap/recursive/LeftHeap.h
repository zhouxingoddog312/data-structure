#ifndef _LeftHeap_H
#define _LeftHeap_H

#define Insert(X,H) (H=Insert1((X),H))
#define DeleteMin(M) ({int i=FindMin(M);M=DeleteMin1(M);i;})//返回值和二叉堆一样
typedef int ElementType;
struct TreeNode;
typedef struct TreeNode *PriorityQueue;
PriorityQueue Initialize(void);
ElementType FindMin(PriorityQueue H);
int IsEmpty(PriorityQueue H);
/*make sure to not use the old leftist heap*/
PriorityQueue Merge(PriorityQueue H1,PriorityQueue H2);
PriorityQueue Insert1(ElementType X,PriorityQueue H);
PriorityQueue DeleteMin1(PriorityQueue H);
PriorityQueue MakeEmpty(PriorityQueue H);
#endif
