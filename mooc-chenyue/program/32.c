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
HashTable Insert(ElementType Key,char *Pw,HashTable H);
void Delete(ElementType Key,HashTable H);

HashTable New(ElementType Key,char *pw,HashTable H);
HashTable Login(ElementType Key,char *pw,HashTable H);




enum KindOfEntry {Legitimate,Empty,Deleted};
struct HashEntry
{
	ElementType Element;
	char *password;
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
	char ch;
	char operator;
	char account[11];
	char passwd[17];
	int i,suggest_tablesize;
	HashTable H;
	scanf("%d\n",&suggest_tablesize);
	H=InitializeTable(suggest_tablesize*4);
	for(i=0;i<suggest_tablesize;i++)
	{
		scanf("%c %s %s",&operator,account,passwd);
		switch(operator)
		{
			case 'L':
				H=Login(atol(account),passwd,H);
				break;
			case 'N':
				H=New(atol(account),passwd,H);
				break;
		}
		while((ch=getchar())!='\n')
			;
	}
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
		H->TheCells[i].Element=0;
		H->TheCells[i].password=NULL;
		H->TheCells[i].info=Empty;
	}
	return H;
}
void MakeEmpty(HashTable H)
{
	for(int i=0;i<H->TableSize;i++)
	{
		H->TheCells[i].info=Empty;
		free(H->TheCells[i].password);
		H->TheCells[i].password=NULL;
		H->TheCells[i].Element=0;
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
HashTable Insert(ElementType Key,char *Pw,HashTable H)
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
			H->TheCells[Pos].password=malloc(sizeof(char)*(strlen(Pw)+1));
			strcpy(H->TheCells[Pos].password,Pw);
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
HashTable New(ElementType Key,char *pw,HashTable H)
{
	Position Pos;
	Pos=Find(Key,H);
	if((H->TheCells[Pos].info==Legitimate)||(Pos==UINT_MAX))
	{
		printf("ERROR: Exist\n");
	}
	else
	{
		H=Insert(Key,pw,H);
		printf("New: OK\n");
	}
	return H;
}
HashTable Login(ElementType Key,char *pw,HashTable H)
{
	Position Pos;
	Pos=Find(Key,H);
	if((H->TheCells[Pos].info!=Legitimate)||(Pos==UINT_MAX))
	{
		printf("ERROR: Not Exist\n");
	}
	else
	{
		if(strcmp(H->TheCells[Pos].password,pw)==0)
		{
			printf("Login: OK\n");
		}
		else
		{
			printf("ERROR: Wrong PW\n");
		}
	}
	return H;
}
