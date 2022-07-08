typedef struct TNode *Position;
typedef Position BinTree;
struct TNode
{
    ElementType Data;
    BinTree Left;
    BinTree Right;
};
BinTree Insert( BinTree BST, ElementType X )
{
	if(BST==NULL)
	{
		BST=malloc(sizeof(struct TNode));
		BST->Data=X;
		BST->Left=NULL;
		BST->Right=NULL;
	}
	else if(BST->Data>X)
	{
		BST->Left=Insert(BST->Left,X);
	}
	else if(BST->Data<X)
	{
		BST->Right=Insert(BST->Right,X);
	}
	return BST;
}
BinTree Delete( BinTree BST, ElementType X )
{
	Position Tmpcell;
	if(BST==NULL)
		printf("Not Found\n");
	else if(BST->Data>X)
		BST->Left=Delete(BST->Left,X);
	else if(BST->Data<X)
		BST->Right=Delete(BST->Right,X);
	else
	{
		if(BST->Left&&BST->Right)
		{
			Tmpcell=FindMin(BST->Right);
			BST->Data=Tmpcell->Data;
			BST->Right=Delete(BST->Right,BST->Data);
		}
		else
		{
			Tmpcell=BST;
			if(BST->Left==NULL)
				BST=BST->Right;
			else if(BST->Right==NULL)
				BST=BST->Left;
			free(Tmpcell);
		}
	}
	return BST;
}
Position Find( BinTree BST, ElementType X )
{
	Position P=BST;
	if(P!=NULL)
	{
		if(P->Data>X)
			return Find(P->Left,X);
		else if(P->Data<X)
			return Find(P->Right,X);
		else
			return P;
	}
	else
		return P;
}
Position FindMin( BinTree BST )
{
	Position P=BST;
	if(P==NULL)
		return NULL;
	if(P->Left!=NULL)
		return FindMin(P->Left);
	else
		return P;
}
Position FindMax( BinTree BST )
{
	Position P=BST;
	if(P==NULL)
		return NULL;
	if(P->Right!=NULL)
		return FindMax(P->Right);
	else
		return P;
}
