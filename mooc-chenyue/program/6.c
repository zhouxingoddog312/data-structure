#include <stdio.h>
#define MaxSize 10
#define nil -1
typedef int Tree;
struct TreeNode
{
	char data;
	Tree left;
	Tree right;
};
struct TreeNode Tree1[MaxSize],Tree2[MaxSize];
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
			scanf("%c %c %c",&(T[index].data),&(T[index].left),&(T[index].right));
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
int Isomorphic(Tree T1,Tree T2)
{
	if((T1==nil)^(T2==nil))
		return 0;
	if(T1==nil&&T2==nil)
		return 1;
	if(Tree1[T1].data==Tree2[T2].data)
	{
		if(Isomorphic(Tree1[T1].left,Tree2[T2].left)&&Isomorphic(Tree1[T1].right,Tree2[T2].right))
			return 1;
		if(Isomorphic(Tree1[T1].left,Tree2[T2].right)&&Isomorphic(Tree1[T1].right,Tree2[T2].left))
			return 1;
	}
	return 0;
}
int main(void)
{
	Tree T1,T2;
	T1=BuildTree(Tree1);
	T2=BuildTree(Tree2);
	if(Isomorphic(T1,T2))
		printf("Yes\n");
	else
		printf("No\n");
	return 0;
}
