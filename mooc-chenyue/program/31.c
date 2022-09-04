#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>



#define MinTableSize 1
typedef unsigned int Index;
typedef Index Position;
typedef unsigned int ElementType;
struct HashTabl;
typedef struct HashTabl *HashTable;
HashTable InitializeTable(int TableSize);
void MakeEmpty(HashTable H);
void DestroyTable(HashTable H);
Position Find(ElementType Key,HashTable H);
HashTable Insert(ElementType Key,HashTable H);
void Delete(ElementType Key,HashTable H);
ElementType Retrieve(Position P,HashTable H);
HashTable Rehash(HashTable H);


void Travel(HashTable H,ElementType Array[],int N);



enum KindOfEntry {Legitimate,Empty,Deleted};
struct HashEntry
{
	ElementType Element;
	enum KindOfEntry info;
};
typedef struct HashEntry Cell;
struct HashTabl
{
	int TableSize;
	Cell *TheCells;
};

static void FatalError(char *string);
static void Error(char *string);
static Index Hash(const unsigned int Key,int TableSize);
static bool IsPrime(int Number);
static int NextPrime(int Number);


int main(void)
{
	int i,suggest_tablesize,input_number;
	HashTable H;
	scanf("%d %d\n",&suggest_tablesize,&input_number);
	H=InitializeTable(suggest_tablesize);
	ElementType arr[input_number];
	for(i=0;i<input_number;i++)
	{
		scanf("%u",&arr[i]);
		H=Insert(arr[i],H);
	}
	Travel(H,arr,input_number);
	return 0;
}







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
static Index Hash(const unsigned int Key,int TableSize)
{
	return Key%TableSize;
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
	H->TheCells=malloc(sizeof(struct HashEntry)*(H->TableSize));
	if(H->TheCells==NULL)
		FatalError("Out of space!");
	for(int i=0;i<H->TableSize;i++)
	{
		H->TheCells[i].Element=UINT_MAX;
		H->TheCells[i].info=Empty;
	}
	return H;
}
void MakeEmpty(HashTable H)
{
	for(int i=0;i<H->TableSize;i++)
	{
		H->TheCells[i].info=Empty;
		H->TheCells[i].Element=UINT_MAX;
	}
}
void DestroyTable(HashTable H)
{
	MakeEmpty(H);
	free(H->TheCells);
	free(H);
}
Position Find(ElementType Key,HashTable H)
{
	Position CurrentPos;
	int CollisionNum=0;
	CurrentPos=Hash(Key,H->TableSize);
	while(H->TheCells[CurrentPos].info!=Empty&&H->TheCells[CurrentPos].Element!=Key)
	{
		if(CollisionNum<H->TableSize)
		{
			CurrentPos+=2*++CollisionNum-1;
			while(CurrentPos>=H->TableSize)
				CurrentPos-=H->TableSize;
		}
		if(CollisionNum>=H->TableSize-1)	//表过满，插入将失败，调用再散列
		{
			return UINT_MAX;
		}
	}
	return CurrentPos;
}
HashTable Insert(ElementType Key,HashTable H)
{
	Position Pos;
	Pos=Find(Key,H);
	if(Pos==UINT_MAX)	//由find的返回值判断表满了，插入失败，再散列
	{
		;
	}
	else
	{
		if(H->TheCells[Pos].info!=Legitimate)
		{
			H->TheCells[Pos].info=Legitimate;
			H->TheCells[Pos].Element=Key;
		}
	}
	return H;
}
void Delete(ElementType Key,HashTable H)
{
	Position Pos;
	Pos=Find(Key,H);
	H->TheCells[Pos].info=Deleted;
}
ElementType Retrieve(Position P,HashTable H)
{
	return H->TheCells[P].Element;
}
HashTable Rehash(HashTable H)
{
	HashTable OldTable=H;
	H=InitializeTable(NextPrime(OldTable->TableSize*2));
	for(Position index=0;index<OldTable->TableSize;index++)
		if(OldTable->TheCells[index].info==Legitimate)
			H=Insert(OldTable->TheCells[index].Element,H);
	DestroyTable(OldTable);	//销毁旧表
	return H;
}


void Travel(HashTable H,ElementType Array[],int N)
{
	Position P;
	int index;
	for(index=0;index<N;index++)
	{
		P=Find(Array[index],H);
		if(P==UINT_MAX)
			printf("-");
		else
			printf("%d",P);
		if(index<N-1)
			printf(" ");
	}
}
