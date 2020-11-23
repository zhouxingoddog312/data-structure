#ifndef _BTree_H
#define _BTree_H
#define M 4
#define Min_M ((M)%2?(((M)+1)/2):((M)/2))
typedef int ElementType;
struct BNode;
typedef struct BNode *Position;
typedef struct BNode *Btree;
Btree Init(Btree T);
Btree Find(ElementType X,Btree T);
Btree Insert(ElementType X,Btree T);
Btree Delete(ElementType X,Btree T);
Btree Dispose(Btree T);
void Travel(Btree T);


#endif
