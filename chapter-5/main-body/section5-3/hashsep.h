#ifndef _HashSep_H
#define _HashSep_H
#define MinTableSize 3
typedef int ElementType;
struct ListNode;
typedef struct ListNode *Position;
struct HashTabl;
typedef struct HashTabl *HashTable;
HashTable InitializeTable(int TableSize);
void MakeEmpty(HashTable H);
void DestroyTable(HashTable H);
Position Find(ElementType Key,HashTable H);
void Insert(ElementType Key,HashTable H);
void Delete(ElementType Key,HashTable H);
ElementType Retrieve(Position P);
void Travel(HashTable H);

#endif
