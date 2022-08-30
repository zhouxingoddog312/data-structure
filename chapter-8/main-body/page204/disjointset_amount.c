#include "disjointset.h"
void Initialize(DisjSet S)
{
	int i;
	for(i=NumSets;i>0;i--)
		S[i]=-1;
}
void SetUnion(DisjSet S,ElementType X1,ElementType X2)//按大小求并
{
	SetType Root1,Root2;
	Root1=Find(X1,S);
	Root2=Find(X2,S);
	if(Root1!=Root2)
	{
		if(S[Root1]<=S[Root2])
		{
			S[Root1]+=S[Root2];
			S[Root2]=Root1;
		}
		else
		{
			S[Root2]+=S[Root1];
			S[Root1]=Root2;
		}
	}
}
SetType Find(ElementType X,DisjSet S)
{
	if(S[X]<=0)
		return X;
	else
		return Find(S[X],S);
}
