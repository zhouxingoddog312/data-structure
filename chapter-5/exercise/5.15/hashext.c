#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdarg.h>
#include <math.h>
#include "hashext.h"

typedef int ElementType;
struct LeafNode
{
	int Inserted;
	int Dl;
	ElementType Store[M+1];
};
//叶子，插入数据个数，共有的最高位位数，用于储存数据的数组（M+1）,多一个位置，以存储分裂前多出来的一个元素


struct DirectoryNode
{
	ElementType Mask;
	Leaf Ptl;
};
//目录中的每一项，包含用于验证的数和指向叶子的指针

struct ExtendibleHash
{
	int D;
	Directory Root;
};
//D代表目录中用于验证的数所使用的位数，Directory代表目录的项的数组

struct Location
{
	int RootIndex;
	int LeafIndex;
};
//用在Directory中的索引和store中的索引可以定位数据


static void FatalError(char *string);
static void Error(char *string);
static int Hash(ElementType Element,Hashext H);
static Leaf MakeLeaf(void);
static void DestoryLeaf(Leaf L);

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
	return (Element>>((int)sizeof(ElementType)*CHAR_BIT-H->D))&(1<<H->D-1);
}	
//Root中的mask使用末尾的D位，Element作hash运算时先右移总位数减去D位，再与末尾有D个1其余位为0的数做与运算，得到Hashext中的Directory中的索引

static Leaf MakeLeaf(int number,...)//当有leaf参数时复制该leaf，没有时创建新的leaf
{
	Leaf L,Temp;
	L=malloc(sizeof(struct LeafNode));
	if(L==NULL)
		FatalError("Not enough space for leaf!");
	L->Inserted=0;
	L->Dl=1;	//新的leaf
	for(int i=0;i<=M;i++)
		L->store[i]=INT_MIN;	//这样的话就不能处理INT_MIN这个值了
	if(number!=0)
	{
		va_list arg;
		va_start(arg,number);
		Temp=va_arg(arg,Leaf);
		L->Dl=Temp->Dl;	//只从旧的leaf中复制Dl
		va_end(arg);
	}
	return L;
}
static void DestoryLeaf(Leaf L)
{
	free(L);
}
Hashext Initialize(void)
{
	Hashext H;
	int rootsize;
	H=malloc(sizeof(struct ExtendibleHash));
	if(H==NULL)
		FatalError("Out of space,when create extendible hashtable!");
	H->D=1;
	rootsize=(int)pow(2,H->D);
	H->Root=malloc(sizeof(struct DirectoryNode)*rootsize);
	if(H->Root==NULL)
		FatalError("Out of space,when create directories!");
	for(int i=0;i<rootsize;i++)
	{
		H->Root[i].Mask=i;
		H->Root[i].Ptl=MakeLeaf(0);
	}
	return H;
}
void MakeEmpty(Hashext H)
{

}
void DestroyTable(Hashext H)	//此时extendible table应该已经进行了MakeEmpty操作,所有的DirectoryNode分别指向两个空的leaf
{
	DestoryLeaf(H->Root[0].Ptl);
	DestoryLeaf(H->Root[(int)pow(2,H->D)-1].Ptl);
	free(H->Root);
	free(H);
}
Position Find(ElementType Element,Hashext H)
{
	Position P;
	P=malloc(sizeof(struct Location));
	if(P==NULL)
		FatalError("Create position failed!");

	Leaf temp;
	P->RootIndex=Hash(Element,H);
	temp=H->Root[P->RootIndex].Ptl;
	for(int index=0;index<temp->Inserted;index++)
	{
		if(temp->Store[index]==Element)
		{
			P->LeafIndex=index;
			return P;
		}
	}
	P->LeafIndex=index;
	return P;	//P->LeafIndex大于H->Root[P->RootIndex].Ptl->Inserted就说明没有找到，小于等于就说明找到了
}
void Insert(ElementType Element,Hashext H)
{
	ElementType Trans[M+1];
	Leaf Temp;
	Position P=Find(Element,H);
	if(H->Root[P->RootIndex].Ptl->Inserted>P->LeafIndex)
		Error("Element exist!");
	else
	{
		Temp=H->Root[P->RootIndex].Ptl;
		Temp->Store[P->LeafIndex]=Element;
		Temp->Inserted++;
		if(Temp->Inserted>M)
		{
			if(Temp->Dl<H->D)//只需要分裂leaf
			{
			
			}else if(Temp->Dl==H->D)//需要先分裂directory
			{
			
			}
		}
	}
}
