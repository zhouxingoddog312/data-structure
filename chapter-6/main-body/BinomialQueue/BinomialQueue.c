#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "BinomialQueue.h"
struct BinNode
{
	ElementType Element;
	Position LeftChild;
	Position NextSibling;
};
struct Collection
{
	int CurrentSize;
	BinTree TheTrees[MaxTrees];
};

static void Error(char *s);
static void FatalError(char *s);
static void DestroyBinTree(BinTree T);
static BinTree CombineTrees(BinTree T1,BinTree T2);
static BinTree MakeSingleNodeTree(ElementType X);


static void Error(char *s)
{
	fputs(s,stderr);
	putc('\n',stderr);
}
static void FatalError(char *s)
{
	fputs(s,stderr);
	putc('\n',stderr);
	exit(EXIT_FAILURE);
}
static void DestroyBinTree(BinTree T)
{
	if(T!=NULL)
	{
		DestroyBinTree(T->LeftChild);
		DestroyBinTree(T->NextSibling);
		free(T);
	}
}
static BinTree CombineTrees(BinTree T1,BinTree T2)
{
	if(T1->Element>T2->Element)
		return CombineTrees(T2,T1);
	T2->NextSibling=T1->LeftChild;
	T1->LeftChild=T2;
	return T1;
}
static BinTree MakeSingleNodeTree(ElementType X)
{
	BinTree T;
	T=malloc(sizeof(struct BinNode));
	if(T==NULL)
		FatalError("Out of space when create Binomial Tree!");
	T->LeftChild=T->NextSibling=NULL;
	T->Element=X;
	return T;
}


BinQueue Initialize(void)
{
	BinQueue H;
	H=malloc(sizeof(struct Collection));
	if(H==NULL)
		FatalError("Out of space when create BinomialQueue!");
	H->CurrentSize=0;
	for(int index=0;index<MaxTrees;index++)
		H->TheTrees[index]=NULL;
	return H;
}
void Destroy(BinQueue H)
{
	MakeEmpty(H);
	free(H);
}
int IsEmpty(BinQueue H)
{
	return H->CurrentSize==0;
}
void MakeEmpty(BinQueue H)
{
	H->CurrentSize=0;
	for(int index=0;index<MaxTrees;index++)
	{
		DestroyBinTree(H->TheTrees[index]);
		H->TheTrees[index]=NULL;
	}
}
BinQueue Merge(BinQueue H1,BinQueue H2)
{
	BinTree T1,T2,Carry=NULL;
	int i,j;
	if(H1->CurrentSize+H2->CurrentSize>Capacity)
	{
		Error("Merge would exceed capacity!");

	}
	H1->CurrentSize+=H2->CurrentSize;
	for(i=0,j=1;j<=H1->CurrentSize;i++,j=j<<1)
	{
		T1=H1->TheTrees[i];
		T2=H2->TheTrees[i];
		switch(!!T1+2*!!T2+4*!!Carry)
		{
			case 0:/*这个高度上没有树*/
			case 1:/*这个高度上只有H1的树存在，保持不变*/
			     break;
			case 2:/*这个高度上只有H2的树存在，交换到H1*/
			     H1->TheTrees[i]=T2;
			     H2->TheTrees[i]=NULL;
			     break;
			case 3:/*这个高度上H1和H2的树都存在*/
			     Carry=CombineTrees(T1,T2);
			     H1->TheTrees[i]=H2->TheTrees[i]=NULL;
			     break;
			case 4:/*这个高度只有Carry存在，放到H1*/
			     H1->TheTrees[i]=Carry;
			     Carry=NULL;
			     break;
			case 5:/*这个高度H1的树和Carry存在*/
			     Carry=CombineTrees(Carry,T1);
			     H1->TheTrees[i]=NULL;
			     break;
			case 6:/*这个高度H2的树和Carry存在*/
			     Carry=CombineTrees(Carry,T2);
			     H2->TheTrees[i]=NULL;
			     break;
			case 7:/*这个高度上三个都存在，将Carry放到H1*/
			     H1->TheTrees[i]=Carry;
			     Carry=CombineTrees(T1,T2);
			     H2->TheTrees[i]=NULL;
			     break;
		}
	}
	return H1;
}
BinQueue Insert(ElementType X,BinQueue H)
{
	BinQueue Temp;
	Temp=Initialize();
	Temp->TheTrees[0]=MakeSingleNodeTree(X);
	Temp->CurrentSize=1;
	return H=Merge(H,Temp);
}
ElementType FindMin(BinQueue H)
{
	ElementType MinItem=INT_MAX;
	if(IsEmpty(H))
	{
		Error("Binomial queue is empty!");
		return INT_MIN;
	}
	for(int index=0;index<MaxTrees;index++)
	{
		if(H->TheTrees[index]&&H->TheTrees[index]->Element<MinItem)
			MinItem=H->TheTrees[index]->Element;
	}
	return MinItem;
}
ElementType DeleteMin(BinQueue H)
{
	ElementType MinItem=INT_MAX;
	int MinTree;
	int i,j;
	BinQueue DeletedQueue;
	Position DeletedTree,OldRoot;
	if(IsEmpty(H))
	{
		Error("Empty binomial queue!");
		return INT_MIN;
	}
	for(i=0;i<MaxTrees;i++)
	{
		if(H->TheTrees[i]&&H->TheTrees[i]->Element<MinItem)
		{
			MinItem=H->TheTrees[i]->Element;
			MinTree=i;
		}
	}
	OldRoot=DeletedTree=H->TheTrees[MinTree];
	DeletedTree=DeletedTree->LeftChild;
	free(OldRoot);
	DeletedQueue=Initialize();
	DeletedQueue->CurrentSize=(1<<MinTree)-1;
	for(j=MinTree-1;j>=0;j--)
	{
		DeletedQueue->TheTrees[j]=DeletedTree;
		DeletedTree=DeletedTree->NextSibling;
		DeletedQueue->TheTrees[j]->NextSibling=NULL;
	}
	H->TheTrees[MinTree]=NULL;
	H->CurrentSize-=DeletedQueue->CurrentSize+1;
	Merge(H,DeletedQueue);
	return MinItem;
}
