#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <limits.h>
#include "Btree.h"
struct BNode
{
	Position Parent;
	int Number;	//在非叶节点中，指子树的数量。在叶节点中指元素的数量。
	ElementType KeyWord[M+1];
	BTree Child[M+1];
};
static const ElementType Unused=INT_MIN;


static Erorr(char *string);
static FatalErorr(char *string);
static ElementType FindMin(Btree T);
static Position MakeNode(void);
static Position FindLeaf(ElementType X,Btree T);
static Position InsertLeaf(ElementType X,Position P);
static Position DeleteLeaf(ElementType X,Position P);
static Position NeedAdjustForInsert(Position T);
static Position NeedAdjustForDelete(Position T);


static void AdjustSiblingForInsert(Position T,Position target);
static void AdjustSiblingForDelete(Position T,Position target);

static void SplitNode(Position P);
static void MergeNode(Position P);


static Erorr(char *string)
{
	fputs("string\n",stderr);
}
static FatalErorr(char *string)
{
	fputs("string\n",stderr);
	exit(EXIT_FAILURE);
}
static ElementType FindMin(Btree T)	//返回子树的最小元素
{
	while(T->Child[0]!=NULL)
		T=T->Child[0];
	return T->KeyWord[0];
}
static Position MakeNode(void)
{
	int i;
	Position P;
	P=malloc(sizeof(struct BNode));
	if(P==NULL)
		FatalErorr("Out of space!");
	P->Parent=NULL;
	P->Number=0;
	for(i=0;i<M+1;i++)
	{
		P->KeyWord[i]=Unused;
		P->Child[i]=NULL;
	}
	return P;
}

/*元素存在时打印已存在信息，返回NULL。元素不存在时返回应当插入的叶节点*/
static Position FindLeaf(ElementType X,Btree T)
{
	bool found=false;
	int index=0;
	while(T->Child[0]!=NULL)
	{
		for(index=0;index<T->Number-1;index++)
		{
			if(X<T->KeyWord[index])
			{
				T=T->Child[index];
				break;
			}
			else if(index=T->Number-2)
			{
				T=T->Child[index+1];
				break;
			}
		}
	}
	for(index=0;index<T->Number;index++)
	{
		if(X==T->KeyWord[index])
		{
			found=true;
			break;
		}
	}
	if(found)
	{
		Erorr("Element exist!");
		return NULL;
	}
	else
		return T;
}

/*两个参数，插入的元素及被插入的叶节点*/
static Position InsertLeaf(ElementType X,Position P)
{
	int index,i;
	for(index=0;index<P->Number;index++)	//找到插入点
	{
		if(P->KeyWord[index]>X)
			break;
	}
	for(i=P->Number;i>index;i--)	//插入点后的元素都向后移一位
	{
		P->KeyWord[i]=P->KeyWord[i-1];
	}
	P->KeyWord[index]=X;
	P->Number++;
	return P;
}

/*两个参数，删除的元素及存在该元素的叶节点*/
static Position DeleteLeaf(ElementType X,Position P)
{
	int index;
	for(index=0;index<P->Number;index++)
	{
		if(P->KeyWord[index]==X)
			break;
	}
	for(;index<P->Number-1;index++)
		P->KeyWord[index]=P->KeyWord[index+1];
	P->Number--;
	return P;
}

/*T指进行了增删操作的节点,返回供调整的目标节点,若不可以调整则返回NULL*/
static Position NeedAdjustForInsert(Position T)
{
	Position P=T->Parent;
	int index;
	Position need=NULL;
	if(P!=NULL)
	{
		for(index=0;index<P->Number;index++)
		{
			if(P->Child[index]->Number<M)
			{
				need=P->Child[index];
				break;
			}
		}
	}
	return need;
}
static Position NeedAdjustForDelete(Position T)
{
	Position P=T->Parent;
	int index;
	Position need=NULL;
	if(P!=NULL)
	{
		for(index=0;index<P->Number;index++)
		{
			if(P->Child[index]->Number>Min_M)
			{
				need=P->Child[index];
				break;
			}
		}
	}
	return need;
}

/*T指进行了增删操作的叶节点，target指供调整的目标节点*/
static void AdjustSiblingForInsert(Position T,Position target)
{
	Position P=T->Parent;
	int total,index,i,j;
	for(index=0,total=0;index<P->Number;index++)
	{
		total+=P->Childe[index]->Number;
	}
	if(T->Child[0]==NULL)
		ElementType trans[total];
	else
		Btree trans[total];
	for(index=0,i=0;i<P->Number;i++)
	{
		for(j=0;j<P->Child[i]->Number;index++,j++)
		{
			if(T->Child[0]==NULL)
				trans[index]=P->Child[i]->KeyWord[j];
			else
				trans[index]=P->Child[i]->Child[j];
		}
	}
	target->Number+=1;
	T->Number-=1;
	for(index=0,i=0;i<P->Number;i++)
	{
		for(j=0;j<P->Child[i]->Number;index++,j++)
		{
			if(T->Child[0]==NULL)
				P->Child[i]->KeyWord[j]=trans[index];
			else
				P->Child[i]->Child[j]=trans[index];
		}
	}
	for(index=0;index<P->Number-1;index++)	//更新父节点的关键字
	{
		P->KeyWord[index]=FindMin(P->Child[index+1]);
	}
	/*更新儿子节点的父节点*/
	if(T->Child[0]!=NULL)
	{
		for(i=0;i<P->Number;i++)
		{
			for(j=0;j<P->Child[i]->Number;j++)
				P->Child[i]->Child[j]->Parent=P->Child[i];
		}
	}
}


static void AdjustSiblingForDelete(Position T,Position target)
{
	Position P=T->Parent;
	int total,index,i,j;
	for(index=0,total=0;index<P->Number;index++)
	{
		total+=P->Childe[index]->Number;
	}
	if(T->Child[0]==NULL)
		ElementType trans[total];
	else
		Btree trans[total];
	for(index=0,i=0;i<P->Number;i++)
	{
		for(j=0;j<P->Child[i]->Number;index++,j++)
		{
			if(T->Child[0]==NULL)
				trans[index]=P->Child[i]->KeyWord[j];
			else
				trans[index]=P->Child[i]->Child[j];
		}
	}
	target->Number-=1;
	T->Number+=1;
	for(index=0,i=0;i<P->Number;i++)
	{
		for(j=0;j<P->Child[i]->Number;index++,j++)
		{
			if(T->Child[0]==NULL)
				P->Child[i]->KeyWord[j]=trans[index];
			else
				P->Child[i]->Child[j]=trans[index];
		}
	}
	for(index=0;index<P->Number-1;index++)	//更新父节点的关键字
	{
		P->KeyWord[index]=FindMin(P->Child[index+1]);
	}
	/*更新儿子节点的父节点*/
	if(T->Child[0]!=NULL)
	{
		for(i=0;i<P->Number;i++)
		{
			for(j=0;j<P->Child[i]->Number;j++)
				P->Child[i]->Child[j]->Parent=P->Child[i];
		}
	}
}

static void SplitNode(Position P)
{
	Position temp,root;
	int index,i;
	if(P->Child[0]==NULL)
	{
		ElementType trans[P->Number];
		for(index=0;index<P->Number;index++)
			trans[index]=P->KeyWord[index];
		temp=MakeNode();
		i=P->Number;
		temp->Number=P->Number-Min_M;
		temp->Parent=P->Parent;
		P->Number=Min_M;
		for(index=0;index<i;index++)
		{
			if(index<Min_M)
				P->KeyWord[index]=trans[index];
			else
				temp->KeyWord[index-Min_M]=trans[index];
		}
		if(P->Parent!=NULL)
		{
			/*更新父节点指向儿子的指针*/
			for(index=0;index<P->Parent->Number;index++)
			{
				if(P->Parent->Child[index]==P)
					break;
			}
			for(i=P->Parent->Number;i>index+1;i--)
				P->Parent->Child[i]=P->Parent->Child[i-1];
			P->Parent->Child[index+1]=temp;
			/*更新父节点儿子数*/
			P->Parent->Number++;
			/*更新父节点关键字*/
			for(index=0;index<P->Parent->Number-1;index++)
				P->Parent->KeyWord[index]=FindMin(P->Parent->Child[index+1]);
		}
		else	/*仅有叶节点的情况*/
		{
			root=MakeNode();
			root->Number=2;
			root->Child[0]=P;
			root->Child[1]=temp;
			root->KeyWord[0]=temp->KeyWord[0];
			P->Parent=temp->Parent=root;
		}
	}
	else
	{
		Btree trans[P->Number];
		for(index=0;index<P->Number;index++)
			trans[index]=P->Child[index];
		temp=MakeNode();
		i=P->Number;
		temp->Number=P->Number-Min_M;
		temp->Parent=P->Parent;
		P->Number=Min_M;
		for(index=0;index<i;index++)
		{
			if(index<Min_M)
				P->Child[index]=trans[index];
			else
				temp->Child[index-Min_M]=trans[index];
		}
		/*更新两个节点的关键字及各自儿子节点的父节点*/
		for(index=0;index<P->Number;index++)
		{
			P->Child[index]->Parent=P;
		}
		for(index=0;index<P->Number-1;index++)
		{
			P->KeyWord[index]=FindMin(P->Child[index+1]);
		}
		for(index=0;index<temp->Number;index++)
		{
			temp->Child[index]->Parent=temp;
		}
		for(index=0;index<P->Number-1;index++)
		{
			temp->KeyWord[index]=FindMin(temp->Child[index+1]);
		}
		if(P->Parent!=NULL)
		{
			/*更新父节点指向儿子的指针*/
			for(index=0;index<P->Parent->Number;index++)
			{
				if(P->Parent->Child[index]==P)
					break;
			}
			for(i=P->Parent->Number;i>index+1;i--)
				P->Parent->Child[i]=P->Parent->Child[i-1];
			P->Parent->Child[index+1]=temp;
			/*更新父节点儿子数*/
			P->Parent->Number++;
			/*更新父节点关键字*/
			for(index=0;index<P->Parent->Number-1;index++)
				P->Parent->KeyWord[index]=FindMin(P->Parent->Child[index+1]);
		}
		else
		{
			root=MakeNode();
			root->Number=2;
			root->Child[0]=P;
			root->Child[1]=temp;
			root->KeyWord[0]=temp->KeyWord[0];
			P->Parent=temp->Parent=root;
		}
	}
}

static void  MergeNode(Position P)
{
	Position temp;
	int total,index,i,j;
	if(P->Child[0]==NULL)	//P是叶节点
	{
		if(P->Parent!=NULL)
		{
			for(index=0;index<P->Parent->Nunber;index++)
			{
				if(P->Parent->Child[index]==P)
					break;
			}
			if(index!=0)	//P不是父节点最左边的儿子，与P的左边那个兄弟合并
			{
				temp=P->Parent->Child[index-1];
				total=temp->Number+P->Number;
				ElementType trans[total];
				for(i=0;i<temp->Number;i++)
					trans[i]=temp->KeyWord[i];
				for(;i-temp->Number<P->Number;i++)
					trans[i]=P->KeyWord[i-temp->Number];
				P->Number=total;
				for(i=0;i<P->Number;i++)
					P->KeyWord[i]=trans[i];
				for(i=index-1;i<P->Parent-Number-1;i++)		//删除被合并的兄弟在父节点的指针
					P->Parent->Child[i]=P->Parent->Child[i+1];
				P->Parent->Number-=1;
				for(i=0;i<P->Parent->Number-1;i++)
					P->Parent->KeyWord[i]=FindMin(P->Parent->Child[i+1]);	//更新父节点关键字
				free(temp);	//删除废弃叶节点
			}
			else	//P与右边的兄弟合并
			{
				temp=P->Parent->Child[index+1];
				total=temp->Number+P->Number;
				ElementType trans[total];
				for(i=0;i<P->Number;i++)
					trans[i]=P->KeyWord[i];
				for(;i-P->Number<temp->Number;i++)
					trans[i]=temp->KeyWord[i-P->Number];
				P->Number=total;
				for(i=0;i<P->Number;i++)
					P->KeyWord[i]=trans[i];
				for(i=index+1;i<P->Parent->Number-1;i++)	//删除被合并的兄弟在父节点的指针
					P->Parent->Child[i]=P->Parent->Child[i+1];
				P->Parent->Number-=1;
				for(i=0;i<P->Parent->Number-1;i++)	//更新父节点关键字
					P->Parent->KeyWord[i]=FindMin(P->Parent->Child[i+1]);
				free(temp);	//删除废弃叶节点
			}
		}
		else
		{
			Erorr("The only leaf has too little keyword!");
		}
	}
	else	//P是非叶节点
	{
		if(P->Parent!=NULL)
		{
			for(index=0;index<P->Parent->Number;index++)
			{
				if(P==P->Parent->Child[index])
					break;
			}
			if(index!=0)	//P不是最左边的节点，与P左边的兄弟合并
			{
				temp=P->Parent->Child[index-1];
				total=P->Number+temp->Number;
				Btree trans[total];
				for(i=0;i<temp->Number;i++)
					trans[i]=temp->Child[i];
				for(;i-temp->Number<P->Number;i++)
					trans[i]=P->Child[i-temp->Number];
				P->Number=total;
				for(i=0;i<P->Number;i++)
				{
					P->Child[i]=trans[i];
					P->Child[i]->Parent=P;	//更新P的所有儿子节点的父节点
				}
				for(i=0;i<P->Number-1;i++)	//更新P节点的关键字
				{
					P->KeyWord[i]=FindMin(P->Child[i+1]);
				}
				for(i=index-1;i<P->Parent->Number-1;i++)	//删除被合并的兄弟在父节点的指针
					P->Parent->Child[i]=P->Parent->Child[i+1];
				P->Parent->Number-=1;
				for(i=0;i<P->Parent->Number-1;i++)	//更新父节点的关键字
					P->Parent->KeyWord[i]=FindMin(P->Parent->Child[i+1]);
				free(temp);	//删除废弃节点
			}
			else	//P与右边的兄弟合并
			{
				temp=P->Parent->Child[index+1];
				total=P->Number+temp->Number;
				Btree trans[total];
				for(i=0;i<P->Number;i++)
					trans[i]=P->Child[i];
				for(;i-P->Number<temp->Number;i++)
					trans[i]=temp->Child[i-P->Number];
				P->Number=total;
				for(i=0;i<P->Number;i++)
				{
					P->Child[i]=trans[i];
					P->Child[i]->Parent=P;	//更新P的所有儿子节点的父节点
				}
				for(i=0;i<P->Number-1;i++)	//更新P节点的关键字
				{
					P->KeyWord[i]=FindMin(P->Child[i+1]);
				}
				for(i=index+1;i<P->Parent->Number-1;i++)	//删除被合并的兄弟在父节点的指针
					P->Parent->Child[i]=P->Parent->Child[i+1];
				P->Parent->Number-=1;
				for(i=0;i<P->Parent->Number-1;i++)	//更新父节点的关键字
					P->Parent->KeyWord[i]=FindMin(P->Parent->Child[i+1]);
				free(temp);	//删除废弃节点
			}
		}
		else	//处理根节点少于两个儿子的情况
		{
			temp=P;
			P->Child[0]->Parent=NULL;
			free(temp);
		}
	}
}












/*初始化为一个单独的叶节点*/
Btree Init(Btree T)
{
	if(M<3)
		FatalErorr("Need more than three order!");
	T=MakeNode();
	return T;
}

/*如果找到则返回所在叶节点，否则返回NULL*/
Btree Find(ElementType X,Btree T)
{
	bool found=false;
	int index=0;
	while(T->Child[0]!=NULL)
	{
		for(index=0;index<T->Number-1;index++)
		{
			if(X<T->KeyWord[index])
			{
				T=T->Child[index];
				break;
			}
			else if(index==T->Number-2)
			{
				T=T->Child[index+1];
				break;
			}
		}
	}
	for(index=0;index<T->Number;index++)
	{
		if(X==T->KeyWord[index])
		{
			found=true;
			break;
		}
	}
	if(found)
		return T;
	else
		return NULL;
}
