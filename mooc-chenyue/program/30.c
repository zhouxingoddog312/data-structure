#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>


#define MinTableSize 3
typedef unsigned int Index;
typedef Index Position;
typedef char *ElementType;
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


void Travel(HashTable H);
void Delete_wrap(void);

enum KindOfEntry {Legitimate,Empty,Deleted};
struct HashEntry
{
	ElementType Element;
	int Count;
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
static Index Hash(const char *Key,int TableSize);
static bool IsPrime(int Number);
static int NextPrime(int Number);
int main(void)
{
	HashTable H;
	char tmp_str[12];
	int entries,index;
	scanf("%d\n",&entries);
	H=InitializeTable(entries*4);
	for(index=0;index<entries;index++)
	{
		scanf("%s",tmp_str);
		H=Insert(tmp_str,H);
		scanf("%s",tmp_str);
		H=Insert(tmp_str,H);
		Delete_wrap();
	}
	Travel(H);
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
static Index Hash(const char *Key,int TableSize)
{
	unsigned int HashVal=0;
	while(*Key!='\0')
		HashVal=(HashVal << 5)+*Key++;
	return HashVal%TableSize;
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
		H->TheCells[i].Element=NULL;
		H->TheCells[i].Count=0;
		H->TheCells[i].info=Empty;
	}
	return H;
}
void MakeEmpty(HashTable H)
{
	for(int i=0;i<H->TableSize;i++)
	{
		H->TheCells[i].info=Empty;
		H->TheCells[i].Count=0;
		free(H->TheCells[i].Element);
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
	while(H->TheCells[CurrentPos].info!=Empty&&strcmp(H->TheCells[CurrentPos].Element,Key)!=0)
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
		H=Rehash(H);
		H=Insert(Key,H);
	}
	else
	{
		if(H->TheCells[Pos].info!=Legitimate)
		{
			H->TheCells[Pos].info=Legitimate;
			H->TheCells[Pos].Element=malloc(sizeof(char)*(strlen(Key)+1));
			strcpy(H->TheCells[Pos].Element,Key);
			H->TheCells[Pos].Count=1;
		}
		else
		{
			H->TheCells[Pos].Count++;
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


void Travel(HashTable H)
{
	int Count_max=-1,Person_number=0;//最大通话次数、并列的人数
	long Temp_number=LONG_MAX;
	for(Position index=0;index<H->TableSize;index++)
	{
		if(H->TheCells[index].info==Legitimate)
			if(Count_max<H->TheCells[index].Count)
				Count_max=H->TheCells[index].Count;
	}
	for(Position index=0;index<H->TableSize;index++)
	{
		if(H->TheCells[index].Count==Count_max)
		{
			if(Temp_number>atol(H->TheCells[index].Element))
				Temp_number=atol(H->TheCells[index].Element);
			Person_number++;
		}
	}
	if(Person_number>1)
		printf("%ld %d %d",Temp_number,Count_max,Person_number);
	else
		printf("%ld %d",Temp_number,Count_max);
}
void Delete_wrap(void)
{
	char ch;
	while((ch=getchar())!='\n')
		;
}

