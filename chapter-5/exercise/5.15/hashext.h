#ifndef _Hashext_H
#define _Hashext_H
#define M 4
typedef int ElememntType;

struct LeafNode
{
	int Inserted;
	int Dl;
	ElementType Store[M+1];
};	//叶子，插入数据个数，共有的最高位位数，用于储存数据的数组（M+1）,多一个位置，以存储分裂前多出来的一个元素

typedef structLeafNode *Leaf;

struct DirectoryNode
{
	ElementType Mask;
	Leaf Ptl;
};	//目录中的每一项，包含用于验证的数和指向叶子的指针
typedef struct DirectoryNode *Directory;

struct ExtendibleHash
{
	int D;
	Directory Root;
};	//D代表目录中用于验证的数所使用的位数，Directory代表目录的项的数组
typedef struct ExtendibleHash *Hashext;

struct Location
{
	int RootIndex;
	int LeafIndex;
};
typedef struct Location Position;


Hashext Initialize(void);
void MakeEmpty(Hashext H);
void DestroyTable(Hashext H);
Position Find(ElementType Element,Hashext H);
void Insert(ElementType Element,Hashext H);
void Delete(ElementType Element,Hashext H);
ElementType Retrieve(Position P,Hashext H);
void Travel(Hashext H);

#endif
