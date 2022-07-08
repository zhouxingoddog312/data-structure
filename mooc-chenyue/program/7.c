#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MaxSize 10
#define nil -1
typedef int Tree;
struct TreeNode
{
	char data;
	Tree left;
	Tree right;
};
struct TreeNode Tree1[MaxSize];
Tree BuildTree(struct TreeNode *T)
{
	char ch;
	int root[MaxSize]={0};
	int data_num,index;
	scanf("%d",&data_num);
	while((ch=getchar())!='\n')
		;
	if(data_num!=0)
	{
		for(index=0;index<data_num;index++)
		{
			T[index].data=index;
			scanf("%c %c",&(T[index].left),&(T[index].right));
			while((ch=getchar())!='\n')
				;
			if(T[index].left=='-')
				T[index].left=nil;
			else
			{
				T[index].left-=48;
				root[T[index].left]=1;
			}
			if(T[index].right=='-')
				T[index].right=nil;
			else
			{
				T[index].right-=48;
				root[T[index].right]=1;
			}
		}
		for(index=0;index<data_num;index++)
			if(root[index]==0)
				return index;
	}
	else
		return nil;
}



typedef Tree ElementType_Q;

struct QueueRecord;
typedef struct QueueRecord *Queue;
typedef struct QueueRecord *Position_Q;

bool IsEmpty(Queue Q);
Queue CreateQueue(Queue Q);
Queue DisposeQueue(Queue Q);
Queue EnQueue(ElementType_Q X,Queue Q);
Queue DeQueue(Queue Q);
ElementType_Q Front(Queue Q);


struct QueueRecord
{
	ElementType_Q Element;
	Position_Q Next;
};
static void FatalError(char *string);
static Position_Q MakeNode(ElementType_Q X);

static void FatalError(char *string)
{
	fputs(string,stderr);
	putchar('\n');
	exit(EXIT_FAILURE);
}
static Position_Q MakeNode(ElementType_Q X)
{
	Position_Q P;
	P=malloc(sizeof(struct QueueRecord));
	if(P==NULL)
		FatalError("No more space for queue!");
	else
	{
		P->Element=X;
		P->Next=NULL;
		return P;
	}
}
bool IsEmpty(Queue Q)
{
	if(Q==NULL)
		return true;
	else
		return false;
}
Queue CreateQueue(Queue Q)
{
	return NULL;
}
Queue DisposeQueue(Queue Q)
{
	while(!IsEmpty(Q))
		Q=DeQueue(Q);
	return Q;
}
Queue EnQueue(ElementType_Q X,Queue Q)
{
	Position_Q P,tmp;
	P=MakeNode(X);
	if(Q==NULL)
		return P;
	else
	{
		tmp=Q;
		while(Q->Next!=NULL)
			Q=Q->Next;
		Q->Next=P;
		return tmp; 
	}
}
Queue DeQueue(Queue Q)
{
	Position_Q tmp;
	tmp=Q;
	if(Q!=NULL)
	{
		Q=Q->Next;
		free(tmp);
		return Q;
	}
	else
	{
		puts("Queue is empty!");
		return Q;
	}
}
ElementType_Q Front(Queue Q)
{
	if(Q)
	{
		return Q->Element;
	}
	else
		puts("Queue is empty!");
}
int main(void)
{
	bool flag=false;
	Tree T1;
	Queue Q;
	Q=CreateQueue(Q);
	T1=BuildTree(Tree1);

	while(T1!=nil)
	{
		if(Tree1[T1].left==nil&&Tree1[T1].right==nil)
		{
			if(!flag)
			{
				printf("%d",Tree1[T1].data);
				flag=true;
			}
			else
				printf(" %d",Tree1[T1].data);
		}
		if(Tree1[T1].left!=nil)
			Q=EnQueue(Tree1[T1].left,Q);
		if(Tree1[T1].right!=nil)
			Q=EnQueue(Tree1[T1].right,Q);
		if(IsEmpty(Q))
			T1=nil;
		else
		{
			T1=Front(Q);
			Q=DeQueue(Q);
		}
	}

	Q=DisposeQueue(Q);
	return 0;
}
