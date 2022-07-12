#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define nil -1
#define MaxSize 30
typedef int tree;
typedef tree position;
struct TreeNode
{
	int data;
	tree left;
	tree right;
};
struct TreeNode Global_Tree[MaxSize];
int node_count;
tree BuildTree(void)
{
	int stack[MaxSize];
	int stack_top=-1;
	char ch;
	char operate[5];
	tree root=nil;
	tree position;
	int index,value;
	scanf("%d",&node_count);
	while((ch=getchar())!='\n');
		;
	for(index=0;index<node_count*2;index++)
	{
		scanf("%s",operate);
		if(!strcmp(operate,"Push"))
		{
			scanf("%d",&value);
			if(root==nil)
				root=value;
			else
			{
				if(Global_Tree[position].left==nil)
					Global_Tree[position].left=value;
				else if(Global_Tree[position].right==nil)
					Global_Tree[position].right=value;
			}
			while((ch=getchar())!='\n');
				;
			stack[++stack_top]=value;
			position=stack[stack_top];
			Global_Tree[position].data=position;
			Global_Tree[position].left=nil;
			Global_Tree[position].right=nil;
		}
		else if(!strcmp(operate,"Pop"))
		{
			position=stack[stack_top--];
		}
	}
	return root;
}
void PostOrderTraversal(tree index)
{
	if(index!=nil)
	{
		PostOrderTraversal(Global_Tree[index].left);
		PostOrderTraversal(Global_Tree[index].right);
		if(--node_count)
			printf("%d ",Global_Tree[index].data);
		else
			printf("%d",Global_Tree[index].data);
	}
	else
		return;
}
int main(void)
{
	tree t=BuildTree();
	PostOrderTraversal(t);
	return 0;
}
