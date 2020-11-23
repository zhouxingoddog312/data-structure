#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <limits.h>
#include "Btree.h"
struct BNode
{
	Position Parent;
	int Number;
	ElementType KeyWord[M+1];
	BTree Child[M+1];
};
static const ElementType Unused=INT_MIN;


static Erorr(char *string);
static FatalErorr(char *string);
static Position MakeNode(void);
static FindLeaf(ElementType X,Btree T);

static Erorr(char *string)
{
	fputs("string\n",stderr);
}
static FatalErorr(char *string)
{
	fputs("string\n",stderr);
	exit(EXIT_FAILURE);
}
static Position MakeNode(void)
{
	int i;
	Position P;
	P=malloc(sizeof(struct BNode));
	if(P==NULL)
		FatalErorr("Out of space!");
	P->Parent=NULL;
	P->Number=0;
	for(i=0;i<M+1;i++)
	{
		P->KeyWord[i]=Unused;
		P->Child[i]=NULL;
	}
	return P;
}

/*元素存在时打印已存在信息，返回NULL。元素不存在时返回叶节点*/
static FindLeaf(ElementType X,Btree T)
{
	bool found=false;
	int index=0;
	while(T->Child[0]!=NULL)
	{
		for(index=0;index<T->Number;index++)
		{
			if(X<T->KeyWord[index])
			{
				T=T->Child[index];
				break;
			}
		}
	}
	for(index=0;index<T->Number;index++)
	{
		if(X==T->KeyWord[index])
		{
			found=true;
			break;
		}
	}
	if(found)
	{
		Erorr("Element exist!");
		return NULL;
	}
	else
		return T;
}




















/*初始化为一个单独的叶节点*/
Btree Init(Btree T)
{
	if(M<3)
		FatalErorr("Need more than three order!");
	T=MakeNode();
	return T;
}

/*如果找到则返回所在叶节点，否则返回NULL*/
Btree Find(ElementType X,Btree T)
{
	bool found=false;
	int index=0;
	while(T->Child[0]!=NULL)
	{
		for(index=0;index<T->Number;index++)
		{
			if(X<T->KeyWord[index])
			{
				T=T->Child[index];
				break;
			}
		}
	}
	for(index=0;index<T->Number;index++)
	{
		if(X==T->KeyWord[index])
		{
			found=true;
			break;
		}
	}
	if(found)
		return T;
	else
		return NULL;
}
