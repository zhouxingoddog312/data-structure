#include <stdio.h>
#define NumSets 17
typedef int DisjSet[NumSets+1];
typedef int SetType;
typedef int ElementType;

void Initialize(DisjSet S);
void SetUnion(DisjSet S,ElementType X1,ElementType X2);
SetType Find(ElementType X,DisjSet S);

void process(DisjSet S);
int main(void)
{
	int i;
	DisjSet S;
	Initialize(S);
	process(S);
	for(i=1;i<=NumSets;i++)
	{
		printf("S[%d]=%d",i,S[i]);
		if(i!=NumSets)
			printf(" ");
		else
			printf("\n");
	}
	return 0;
}
void process(DisjSet S)
{
	SetUnion(S,1,2);
	SetUnion(S,3,4);
	SetUnion(S,3,5);
	SetUnion(S,1,7);
	SetUnion(S,3,6);
	SetUnion(S,8,9);
	SetUnion(S,1,8);
	SetUnion(S,3,10);
	SetUnion(S,3,11);
	SetUnion(S,3,12);
	SetUnion(S,3,13);
	SetUnion(S,14,15);
	SetUnion(S,16,17);
	SetUnion(S,14,16);
	SetUnion(S,1,3);
	SetUnion(S,1,14);
	Find(13,S);
}



void Initialize(DisjSet S)
{
	int i;
	for(i=NumSets;i>0;i--)
		S[i]=0;
}
void SetUnion(DisjSet S,ElementType X1,ElementType X2)
{
	SetType Root1,Root2;
	Root1=Find(X1,S);
	Root2=Find(X2,S);
	if(Root1!=Root2)
	{
		if(S[Root1]<S[Root2])
		{
			S[Root2]=Root1;
		}
		else
		{
			if(S[Root1]==S[Root2])
				S[Root2]--;
			S[Root1]=Root2;
		}
	}
}
SetType Find(ElementType X,DisjSet S)
{
	if(S[X]<=0)
		return X;
	else
		return S[X]=Find(S[X],S);
}
