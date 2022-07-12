#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>



struct TreeNode;
typedef struct TreeNode *Position;
typedef struct TreeNode *SearchTree;
typedef int ElementType;

SearchTree Init(SearchTree T);
SearchTree MakeEmpty(SearchTree T);
Position Find(ElementType X,SearchTree T);
Position FindMin(SearchTree T);
Position FindMax(SearchTree T);
SearchTree Insert(ElementType X,SearchTree T);
SearchTree Delete(ElementType X,SearchTree T);
ElementType Retrieve(Position P);
bool IsSame(SearchTree T1,SearchTree T2);

void PreOrder(SearchTree T);
void InOrder(SearchTree T);
void PostOrder(SearchTree T);





struct TreeNode
{
	ElementType Element;
	SearchTree Left;
	SearchTree Right;
};

static void FatalError(char *S)
{
	fputs(S,stdout);
	putchar('\n');
	exit(EXIT_FAILURE);
}
static void Error(char *S)
{
	puts(S);
}

SearchTree Init(SearchTree T)
{
	return NULL;
}
SearchTree MakeEmpty(SearchTree T)
{
	if(T!=NULL)
	{
		MakeEmpty(T->Left);
		MakeEmpty(T->Right);
		free(T);
	}
	return NULL;
}

Position Find(ElementType X,SearchTree T)
{
	Position P=T;
	if(P!=NULL)
	{
		if(P->Element<X)
			return Find(X,P->Right);
		else if(P->Element>X)
			return Find(X,P->Left);
		else
			return P;
	}
	else
		return P;
}

Position FindMin(SearchTree T)
{
	Position P=T;
	if(P==NULL)
		return NULL;
	if(P->Left!=NULL)
		return FindMin(P->Left);
	else
		return P;
}

Position FindMax(SearchTree T)
{
	Position P=T;
	if(P==NULL)
		return NULL;
	if(P->Right!=NULL)
		return FindMax(P->Right);
	else
		return P;
}

SearchTree Insert(ElementType X,SearchTree T)
{
	if(T==NULL)
	{
		T=malloc(sizeof(struct TreeNode));
		if(T==NULL)
			FatalError("Out of space!");
		else
		{
			T->Element=X;
			T->Left=T->Right=NULL;
		}
	}
	else
	if(T->Element>X)
		T->Left=Insert(X,T->Left);
	else
	if(T->Element<X)
		T->Right=Insert(X,T->Right);
/*	else

if T->Element==X,there will do nothing
*/
	return T;
}

SearchTree Delete(ElementType X,SearchTree T)
{
	Position Tmpcell;
	if(T==NULL)
		Error("Element not found!");
	else
	if(X>T->Element)
		T->Right=Delete(X,T->Right);
	else
	if(X<T->Element)
		T->Left=Delete(X,T->Left);
	else
	{
		if(T->Left && T->Right)
		{
			Tmpcell=FindMin(T->Right);
			T->Element=Tmpcell->Element;
			T->Right=Delete(T->Element,T->Right);
		}
		else
		{
			Tmpcell=T;
			if(T->Left==NULL)
				T=T->Right;
			else
			if(T->Right==NULL)
				T=T->Left;
			free(Tmpcell);
		}
	}
	return T;
}

ElementType Retrieve(Position P)
{
	if(P==NULL)
		Error("Error position!");
	else
		return P->Element;
}

void PreOrder(SearchTree T)
{
	if(T!=NULL)
	{
		printf("%-5d",T->Element);
		PreOrder(T->Left);
		PreOrder(T->Right);
	}
}
void InOrder(SearchTree T)
{
	if(T!=NULL)
	{
		InOrder(T->Left);
		printf("%-5d",T->Element);
		InOrder(T->Right);
	}
}
void PostOrder(SearchTree T)
{
	if(T!=NULL)
	{
		PostOrder(T->Left);
		PostOrder(T->Right);
		printf("%-5d",T->Element);
	}
}
bool IsSame(SearchTree T1,SearchTree T2)
{
	if((T1==NULL)^(T2==NULL))
		return false;
	if((T1==NULL)&&(T2==NULL))
		return true;
	if(T1->Element==T2->Element)
		return (IsSame(T1->Left,T2->Left))&&(IsSame(T1->Right,T2->Right));
	return false;
}
void DeleteWrap(void)
{
	char ch;
	while((ch=getchar())!='\n')
		;
}
int main(void)
{
	int N,L;
	int node_count,check_count;
	int temp_value;
	SearchTree Origin,Check;
	Origin=Init(Origin);
	Check=Init(Check);
	scanf("%d",&N);
	while(N!=0)
	{
		scanf("%d",&L);
		DeleteWrap();
		for(node_count=0;node_count<N;node_count++)
		{
			scanf("%d",&temp_value);
			Origin=Insert(temp_value,Origin);
		}
		DeleteWrap();
		for(check_count=0;check_count<L;check_count++)
		{
			for(node_count=0;node_count<N;node_count++)
			{
				scanf("%d",&temp_value);
				Check=Insert(temp_value,Check);
			}
			DeleteWrap();
			if(IsSame(Origin,Check))
				printf("Yes\n");
			else
				printf("No\n");
			Check=MakeEmpty(Check);
		}
		Origin=MakeEmpty(Origin);
		scanf("%d",&N);
	}
}
