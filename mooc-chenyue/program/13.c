#include <stdio.h>
#include <limits.h>
#define MaxSize 10000
int Array[MaxSize+1];
void DeleteWrap(void);
int Find(int index);
void Union(int val1,int val2);
int main(void)
{
	char opt;
	int index,N,val1,val2,count=0;
	for(index=0;index<MaxSize+1;index++)
		Array[index]=INT_MIN;
	scanf("%d",&N);
	DeleteWrap();
	for(index=1;index<=N;index++)
		Array[index]=-1;
	opt=getchar();
	while(opt!='S')
	{
		scanf("%d %d",&val1,&val2);
		DeleteWrap();
		if(opt=='C')
		{
			if(Find(val1)==Find(val2))
				puts("yes");
			else
				puts("no");
		}
		else if(opt=='I')
		{
			Union(Find(val1),Find(val2));
		}
		else
			fprintf(stderr,"Program error!\n");
		opt=getchar();
	}
	for(index=1;index<=N;index++)
	{
		if(Array[index]<0)
			count++;
	}
	if(count==1)
		printf("The network is connected.\n");
	else
		printf("There are %d components.\n",count);
	return 0;
}
void DeleteWrap(void)
{
	char ch;
	while((ch=getchar())!='\n')
		;
}
int Find(int index)
{
	while(Array[index]>=0)
		index=Array[index];
	return index;
}
void Union(int val1,int val2)
{
	int root1,root2;
	root1=Find(val1);
	root2=Find(val2);
	if(Array[root1]>Array[root2])
	{
		Array[root1]=root2;
	}
	else if(Array[root1]<=Array[root2])
	{
		if(Array[root1]==Array[root2])
			Array[root1]--;
		Array[root2]=root1;
	}
}
