#ifndef _HashSep_H
#define _HashSep_H
#define MinTableSize 3
#include "polynomial.h"
typedef int ElementType;
typedef Position List;
struct HashTabl
{
	int TableSize;
	List *TheLists;
};
typedef struct HashTabl *HashTable;
HashTable InitializeTable(int TableSize);
void MakeEmpty(HashTable H);
void DestroyTable(HashTable H);
Position Find(ElementType Coefficient,ElementType Exponent,HashTable H);
void Insert_table(ElementType Coefficient,ElementType Exponent,HashTable H);
/*
void Delete(ElementType Key,HashTable H);	//这里用不到未修改
ElementType Retrieve(Position P);	//同样未修改
void Travel(HashTable H);
*/
#endif
