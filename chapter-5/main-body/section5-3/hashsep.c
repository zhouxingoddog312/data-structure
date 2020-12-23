#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include "hashsep.h"
/*assume no header*/
struct ListNode
{
	ElementType Element;
	Position Next;
};
typedef Position List;
struct HashTabl
{
	int TableSize;
	List *TheLists;
};
static void FatalError(char *string);
static void Error(char *string);
static bool IsPrime(int Number);
static int NextPrime(int Number);
static int Hash(ElementType Key,int TableSize);
static void FreeList(List L);
static Position FindList(ElementType Key,List L);
static void FatalError(char *string)
{
	fputs(string,stderr);
	putchar('\n');
	exit(EXIT_FAILURE);
}
static void Error(char *string)
{
	puts(string);
}
static bool IsPrime(int Number)
{
	bool result=true;
	if(Number<2)
		result=false;
	else
	{
		for(int i=2;i<=sqrt(Number);i++)
			if(Number%i==0)
			{
				result=false;
				break;
			}
	}
	return result;
}
static int NextPrime(int Number)
{
	int Prime=2;
	while(Prime<Number||!IsPrime(Prime))
		Prime++;
	return Prime;
}
static int Hash(ElementType Key,int TableSize)
{
	return Key%TableSize;
}
static void FreeList(List L)
{
	Position P;
	while(L!=NULL)
	{
		P=L;
		L=L->Next;
		free(P);
	}
}
static Position FindList(ElementType Key,List L)
{
	while(L!=NULL&&L->Element!=Key)
		L=L->Next;
	return L;
}
HashTable InitializeTable(int TableSize)
{
	HashTable H;
	if(TableSize<MinTableSize)
	{
		Error("Table size too small!");
		return NULL;
	}
	H=malloc(sizeof(struct HashTabl));
	if(H==NULL)
		FatalError("Out of space!");
	H->TableSize=NextPrime(TableSize);
	H->TheLists=malloc(sizeof(List)*H->TableSize);
	if(H->TheLists==NULL)
		FatalError("Out of space!");
	for(int index=0;index<H->TableSize;index++)
		H->TheLists[index]=NULL;
	return H;
}
void MakeEmpty(HashTable H)
{
	for(int index=0;index<H->TableSize;index++)
	{
		FreeList(H->TheLists[index]);
		H->TheLists[index]=NULL;
	}
}
void DestroyTable(HashTable H)
{
	MakeEmpty(H);
	free(H->TheLists);
	free(H);
}
Position Find(ElementType Key,HashTable H)
{
	List L=H->TheLists[Hash(Key,H->TableSize)];
	return FindList(Key,L);
}
void Insert(ElementType Key,HashTable H)
{
	int index=Hash(Key,H->TableSize);
	List L;
	Position P;
	P=Find(Key,H);
	if(P)
		Error("Element was exist!");
	else
	{
		P=malloc(sizeof(struct ListNode));
		if(P==NULL)
			FatalError("Out of space!");
		else
		{
			P->Element=Key;
			P->Next=H->TheLists[index];
			H->TheLists[index]=P;
		}
	}
}
void Delete(ElementType Key,HashTable H)
{
	Position temp;
	int index=Hash(Key,H->TableSize);
	List L=H->TheLists[index];
	if(L->Element==Key)
	{
		H->TheLists[index]=L->Next;
		free(L);
	}
	else
	{
		while(L->Next!=NULL&&L->Next->Element!=Key)
			L=L->Next;
		if(L->Next==NULL)
			Error("Element haven't found!");
		else
		{
			temp=L->Next;
			L->Next=L->Next->Next;
			free(temp);
		}
	}
}
ElementType Retrieve(Position P)
{
	return P->Element;
}
void Travel(HashTable H)
{
	Position temp;
	for(int index=0;index<H->TableSize;index++)
	{
		temp=H->TheLists[index];
		while(temp!=NULL)
		{
			printf("%5d",Retrieve(temp));
			temp=temp->Next;
		}
		printf("\n");
	}
}
