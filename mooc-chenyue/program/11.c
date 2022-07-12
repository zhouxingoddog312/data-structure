#include <stdio.h>
#include <math.h>
#define MaxSize 1100
int OriginData[MaxSize];
int CompleteTree[MaxSize];
int compare(const void *a,const void *b)
{
	return *(int *)a-*(int *)b;
}
int LeftSubTreeCount(int totalnode)
{
	int index;
	int height;
	int leftnode;
	int bottomlevelnode,upperlevelnode;
	height=(int)log2(totalnode)+1;
	upperlevelnode=(pow(2,height-1)-2)/2;
	bottomlevelnode=totalnode-(pow(2,height-1)-1);
	if(bottomlevelnode<=(pow(2,height-1)/2))
		leftnode=upperlevelnode+bottomlevelnode;
	else
		leftnode=upperlevelnode+(pow(2,height-1)/2);
	return leftnode;
}
void CreateTree(int left,int right,int root)
{
	int leftroot,rightroot,tree_node_count,left_subtree_count;
	tree_node_count=right-left+1;
	if(!tree_node_count)
		return;
	left_subtree_count=LeftSubTreeCount(tree_node_count);
	CompleteTree[root]=OriginData[left+left_subtree_count];
	leftroot=root*2+1;
	rightroot=leftroot+1;
	CreateTree(left,left+tree_node_count-1,leftroot);
	CreateTree(left+tree_node_count+1,right,rightroot);
}
int main(void)
{
	int N,index;
	scanf("%d",&N);
	for(index=0;index<N;index++)
		scanf("%d",&OriginData[index]);
	qsort(OriginData,N,sizeof(int),compare);
	CreateTree(0,N-1,0);
	for(index=0;index<N;index++)
	{
		if(!index)
			printf("%d",CompleteTree[index]);
		else
			printf(" %d",CompleteTree[index]);
	}
	return 0;
}
