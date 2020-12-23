#ifndef _Hashline_H
#define _Hashline_H
typedef unsigned int Index;
typedef Index Position;
typedef char *ElementType;
struct HashTabl;
typedef struct HashTabl *HashTable;
HashTable InitializeTable(int TableSize);
void MakeEmpty(HashTable H);
void DestroyTable(HashTable H);
Position Find(ElementType Key,HashTable H);
void Insert(ElementType Key,HashTable H);
void Delete(ElementType Key,HashTable H);
ElementType Retrieve(Position P,HashTable H);
HashTable Rehash(HashTable H);


void Travel(HashTable H);
#endif
