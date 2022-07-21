#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <stdbool.h>
#define MinPQSize 1
struct HuffmanTreeNode;
typedef struct HuffmanTreeNode *HuffmanTree;

struct HuffmanTreeNode
{
	int weight;
	HuffmanTree left;
	HuffmanTree right;
};
typedef struct HuffmanTreeNode ElementType;
struct HeapStruct;
typedef struct HeapStruct *PriorityQueue;

PriorityQueue Initialize(int MaxElements);
void BuildHeap(ElementType Data[],int Length,PriorityQueue H);
void Destroy(PriorityQueue H);
void MakeEmpty(PriorityQueue H);
void Insert(ElementType X,PriorityQueue H);
ElementType DeleteMin(PriorityQueue H);
ElementType FindMin(PriorityQueue H);
int IsEmpty(PriorityQueue H);
int IsFull(PriorityQueue H);

struct HeapStruct
{
	int Capacity;
	int Size;
	ElementType *Elements;
};
static void FatalError(char *string);
static void Error(char *string);
static void PercolateDown(int index,ElementType Data[],int Length);

static void FatalError(char *string)
{
	fputs(string,stderr);
	putc('\n',stderr);
	exit(EXIT_FAILURE);
}
static void Error(char *string)
{
	fputs(string,stderr);
	putc('\n',stderr);
}
static void PercolateDown(int index,ElementType Data[],int Length)
{
	ElementType Temp;
	int i,Child;
	for(i=index;i*2<=Length;i=Child)
	{
		Child=i*2;
		if((Child!=Length)&&(Data[Child].weight>Data[Child+1].weight))
			Child++;
		if(Data[i].weight>Data[Child].weight)
		{
			Temp=Data[i];
			Data[i]=Data[Child];
			Data[Child]=Temp;
		}
		else
			break;
	}
}

PriorityQueue Initialize(int MaxElements)
{
	PriorityQueue H;
	if(MaxElements<MinPQSize)
		Error("Priority queue is too small!");
	H=malloc(sizeof(struct HeapStruct));
	if(H==NULL)
		FatalError("Out of space to create Priority queue!");
	H->Elements=malloc(sizeof(ElementType)*(MaxElements+1));
	if(H->Elements==NULL)
		FatalError("Out of space for elements!");
	H->Capacity=MaxElements;
	H->Size=0;
	H->Elements[0].weight=INT_MIN;
	return H;
}
void BuildHeap(ElementType Data[],int Length,PriorityQueue H)
{
	if(!IsEmpty(H))
	{
		Error("Make PriorityQueue be initialized!");
		return;
	}
	for(int index=1;index<=Length;index++)
		H->Elements[index]=Data[index-1];
	H->Size=Length;
	for(int index=Length/2;index>0;index--)
		PercolateDown(index,H->Elements,Length);
}
void Destroy(PriorityQueue H)
{
	if(H==NULL)
		Error("Priority queue isn't exist!");
	else
	{		
		free(H->Elements);
		free(H);
	}
}
void MakeEmpty(PriorityQueue H)
{
	if(H==NULL)
		Error("Initiate first!");
	else
	{
		H->Size=0;
	}
}
void Insert(ElementType X,PriorityQueue H)
{
	int i;
	if(IsFull(H))
	{
		Error("Priority queue is full!");
		return;
	}
	for(i=++H->Size;X.weight<H->Elements[i/2].weight;i/=2)
		H->Elements[i]=H->Elements[i/2];
	H->Elements[i]=X;
}
ElementType DeleteMin(PriorityQueue H)
{
	int i,child;
	ElementType MinElement,LastElement;
	if(IsEmpty(H))
	{
		Error("Priority queue is empty!");
		return H->Elements[0];
	}
	MinElement=H->Elements[1];
	LastElement=H->Elements[H->Size--];
	for(i=1;i*2<=H->Size;i=child)
	{
		child=i*2;
		if((child!=H->Size)&&(H->Elements[child].weight>H->Elements[child+1].weight))
			child++;
		if(LastElement.weight>H->Elements[child].weight)
			H->Elements[i]=H->Elements[child];
		else
			break;
	}
	H->Elements[i]=LastElement;
	return MinElement;
}
ElementType FindMin(PriorityQueue H)
{
	if(IsEmpty(H))
	{
		Error("Priority queue is empty!");
		return H->Elements[0];
	}
	return H->Elements[1];
}
int IsEmpty(PriorityQueue H)
{
	return H->Size==0;
}
int IsFull(PriorityQueue H)
{
	return H->Size==H->Capacity;
}
HuffmanTree CreatHuffmanTree(PriorityQueue H);//已由输入数据建立最小堆
HuffmanTree MakeHuffmanTreeNode(void)
{
	HuffmanTree T=malloc(sizeof(struct HuffmanTreeNode));
	T->weight=-1;
	T->left=T->right=NULL;
}
void DestoryHuffmanTree(HuffmanTree T)
{
	if(T->left)
		DestoryHuffmanTree(T->left);
	if(T->right)
		DestoryHuffmanTree(T->right);
	free(T);
}
int WestPathLength(HuffmanTree T,int Height);
int WestPathLength(HuffmanTree T,int Height)
{
	if(!T->left&&!T->right)
		return Height*T->weight;
	else
		return WestPathLength(T->left,Height+1)+WestPathLength(T->right,Height+1);
}
HuffmanTree CreatHuffmanTree(PriorityQueue H)
{
	int index,size;
	size=H->Size;
	HuffmanTree T;
	for(index=1;index<size;index++)
	{
		T=malloc(sizeof(struct HuffmanTreeNode));
		T->left=malloc(sizeof(struct HuffmanTreeNode));
		T->right=malloc(sizeof(struct HuffmanTreeNode));
		*(T->left)=DeleteMin(H);
		*(T->right)=DeleteMin(H);
		T->weight=T->left->weight+T->right->weight;
		Insert(*T,H);
	}
	*T=DeleteMin(H);
	return T;
}
static void DeleteWrap(void)
{
	char ch;
	while((ch=getchar())!='\n')
		;
}
int main(void)
{
	bool flag=true;
	HuffmanTree OriginTree,TmpTree,Position;
	PriorityQueue H;
	char ch;
	int tmp,index,origintree_length;
	int TreeNodeCount,test_case_count,i;
	int wpl,x,y;
	scanf("%d",&TreeNodeCount);
	DeleteWrap();
	H=Initialize(TreeNodeCount);
	ElementType Data[TreeNodeCount];
	for(index=0;index<TreeNodeCount;index++)
	{
		scanf("%c %d",&ch,&tmp);
		Data[index].weight=tmp;
		Data[index].left=Data[index].right=NULL;
		ch=getchar();
	}
	BuildHeap(Data,TreeNodeCount,H);
	OriginTree=CreatHuffmanTree(H);
	origintree_length=WestPathLength(OriginTree,0);

	scanf("%d",&test_case_count);
	char test_case[TreeNodeCount][TreeNodeCount];
	DeleteWrap();

	for(i=0;i<test_case_count;i++)
	{
		wpl=0;
		for(index=0;index<TreeNodeCount;index++)
		{
			getchar();
			getchar();
			scanf("%s",test_case[index]);
			DeleteWrap();
		}
		for(index=0;index<TreeNodeCount;index++)
			wpl+=strlen(test_case[index])*Data[index].weight;
		if(wpl!=origintree_length)
		{
			flag=false;
		}
		else
		{
			TmpTree=MakeHuffmanTreeNode();
			for(x=0;x<TreeNodeCount;x++)
			{
				Position=TmpTree;
				for(y=0;y<=strlen(test_case[x]);y++)
				{
					if(test_case[x][y]=='0')
					{
						if(!Position->left)
							Position->left=MakeHuffmanTreeNode();
						Position=Position->left;
						if(Position->weight>=0)
							flag=false;
					}
					else if(test_case[x][y]=='1')
					{
						if(!Position->right)
							Position->right=MakeHuffmanTreeNode();
						Position=Position->right;
						if(Position->weight>=0)
							flag=false;
					}
					else if(test_case[x][y]=='\0')
					{
						if(Position->left||Position->right)
							flag=false;
					}
				}
			}
			DestoryHuffmanTree(TmpTree);
		}
		if(flag)
			printf("Yes\n");
		else
			printf("No\n");
		flag=true;
	}
	return 0;
}
