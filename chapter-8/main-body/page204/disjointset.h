#ifndef _DisjSet_H
#define _DisjSet_H
#define NumSets 10
typedef int DisjSet[NumSets+1];
typedef int SetType;
typedef int ElementType;

void Initialize(DisjSet S);
void SetUnion(DisjSet S,ElementType X1,ElementType X2);
SetType Find(ElementType X,DisjSet S);

#endif
