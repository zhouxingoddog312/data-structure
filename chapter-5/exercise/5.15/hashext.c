#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "hashext.h"


static void FatalError(char *string);
static void Error(char *string);
static Leaf MakeLeaf(void);
static int Hash(ElementType Element,Hashext H);

static void FatalError(char *string)
{
	fputs(string,stderr);
	fputc('\n',stderr);
	exit(EXIT_FAILURE);
}
static void Error(char *string)
{
	fputs(string,stderr);
	fputc('\n',stderr);
}
static int Hash(ElementType Element,Hashext H)
{
	return (Element>>(sizeof(ElementType)*8-H->D))&((int)pow(2,H->D)-1);	//root中的mask使用末尾的D位，Element作hash运算时先右移总位数减去D位，再与末尾有D个1其余位为0的数做与运算，得到Hashext中的Root的index
}
static Leaf MakeLeaf(void)
{
	Leaf L;
	L=malloc(sizeof(struct LeafNode));
	if(L==NULL)
		FatalError("Not enough space for leaf!");
	L->Inserted=0;
	L->Dl=1;	//初始状态，调用该函数时再改变算了
	return L;
}

Hashext Initialize(void)
{
	Hashext H;
	int rootsize;
	H=malloc(sizeof(struct ExtendibleHash));
	if(H==NULL)
		FatalError("Out of space!");
	H->D=1;
	rootsize=(int)pow(2,H->D);
	H->Root=malloc(sizeof(struct DirectoryNode)*rootsize);
	if(H->Root==NULL)
		FatalError("Out of space!");
	for(int i=0;i<rootsize;i++)
	{
		H->Root[i].Mask=i;
		H->Root[i].Ptl=NULL;
	}
	return H;
}
void MakeEmpty(Hashext H)
{
	Leaf temp;
	int rootsize=(int)pow(2,H->D);
	temp=H->Root[0].Ptl;
	for(int index=1;index<rootsiez;index++)
	{
		if(temp!=H->Root[index].Ptl)
		{
			free(temp);
			temp=H->Root[index].Ptl;
		}
	}
	free(temp);
	free(H->Root);
	H->D=1;
	rootsize=(int)pow(2,H->D);
	H->Root=malloc(sizeof(struct DirectoryNode)*rootsize);
	if(H->Root==NULL)
		FatalError("Out of space!");
	for(index=0;index<rootsize;index++)
	{
		H->Root[index].Mask=i;
		H->Root[index].Ptl=NULL;
	}
}
void DestroyTable(Hashext H)
{
	Leaf temp;
	int rootsize=(int)pow(2,H->D);
	temp=H->Root[0].Ptl;
	for(int index=1;index<rootsiez;index++)
	{
		if(temp!=H->Root[index].Ptl)
		{
			free(temp);
			temp=H->Root[index].Ptl;
		}
	}
	free(temp);
	free(H->Root);
	free(H);
}
Position Find(ElementType Element,Hashext H)
{
	Position P;
	Leaf temp;
	P.RootIndex=Hash(Element,H);
	temp=H->Root[P.RootIndex].Ptl;
	if(temp==NULL)
	{
		P.LeafIndex=-1;
		return P;
	}
	else
		for(int index=0;index<temp->Inserted;index++)
		{
			if(temp->Store[index]==Element)
			{
				P.LeafIndex=index;
				return P;
			}
		}
	P.LeafIndex=index;
	return P;	//P.LeafIndex大于H->Root[P.RootIndex].Ptl->Inserted就说明没有找到，小于等于就说明找到了，等于-1说明该树叶未创建
}
void Insert(ElementType Element,Hashext H)
{
	Leaf temp;
	Position P;
	P=Find(Element,H);
	if(P.LeafIndex==-1)
	{
		temp=H->Root[P.RootIndex].Ptl=MakeLeaf();
		temp->Store[temp->Inserted]=Element;
		temp->Inserted++;
	}
	else if(P.LeafIndex<H->Root[P.RootIndex].Ptl->Inserted)
		Error("Element exist!");
	else
	{
		temp=H->Root[P.RootIndex].Ptl;
		temp->Store[temp->Inserted]=Element;
		temp->Inserted++;
		if(temp->Inserted>M)
		{
			if(temp->Dl<H->D)
			{
set :
				
			}
			else
			{
				
				goto set;
			}
		}
	}	
}
