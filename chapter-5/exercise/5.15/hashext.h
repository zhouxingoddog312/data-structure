#ifndef _Hashext_H
#define _Hashext_H
#define M 4
struct LeafNode;
typedef struct LeafNode *Leaf;

struct DirectoryNode;
typedef struct DirectoryNode *Directory;

struct ExtendibleHash;
typedef struct ExtendibleHash *Hashext;

struct Location;
typedef struct Location *Position;


Hashext Initialize(void);
void MakeEmpty(Hashext H);
void DestroyTable(Hashext H);
Position Find(ElementType Element,Hashext H);
void Insert(ElementType Element,Hashext H);
void Delete(ElementType Element,Hashext H);
ElementType Retrieve(Position P,Hashext H);
void Travel(Hashext H);

#endif
