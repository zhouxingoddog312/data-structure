#include <stdio.h>
#define MaxSize 100000//用来模拟0～99999的链表
struct Node
{
	int Data;
	int Next;
};
typedef struct Node node;
typedef struct Node *ptn;
node Array[MaxSize+1];//多一个元素，最后一个元素用来作为head
void PrintLink(int Link);
int RecieveLink(int *link_len,int *K);//这里的link_len代表的是链表的长度，因为有的数据不在链表内
int Reverse(int head,int K,int *tmp_link);//这里tmp_link用来作为每一个要被逆转的子链表的头，亦即逆转后的尾巴
int main(void)
{
	int link,link_len,K;
	int tmp_link=-2,tmp,count;//因为tmp_link会在Reverse内被改变，所以用tmp来记录它
	int head=MaxSize;
	link=RecieveLink(&link_len,&K);
	for(count=0;count<link_len/K;count++)
	{
		if(tmp_link==-2)//tmp_link不等于-1的原因是它真的有可能是-1
		{
			link=Reverse(head,K,&tmp_link);
		}
		else
		{
			tmp=tmp_link;
			Array[tmp].Next=Reverse(head,K,&tmp_link);
		}
	}
	PrintLink(link);
	return 0;
}
void PrintLink(int link)
{
	while(link!=-1)
	{
		if(Array[link].Next!=-1)
			printf("%05d %d %05d\n",link,Array[link].Data,Array[link].Next);
		else
			printf("%05d %d %d\n",link,Array[link].Data,Array[link].Next);
		link=Array[link].Next;
	}
}
int RecieveLink(int *link_len,int *K)
{
	*link_len=0;
	int link=-1,Data_num,index,tmp_head;
	scanf("%d  %d %d",&link,&Data_num,K);
	Array[MaxSize].Next=link;
	for(;Data_num>0;Data_num--)
	{
		scanf("%d",&index);
		scanf("%d %d",&Array[index].Data,&Array[index].Next);
	}
	tmp_head=link;
	while(tmp_head!=-1)
	{
		tmp_head=Array[tmp_head].Next;
		(*link_len)++;
	}
	return link;
}
int Reverse(int head,int K,int *tmp_link)
{
	int new,old,tmp;
	new=Array[head].Next;
	*tmp_link=new;
	old=Array[Array[head].Next].Next;
	for(int count=0;count<K-1;count++)
	{
		tmp=Array[old].Next;
		Array[old].Next=new;
		new=old;
		old=tmp;
	}
	Array[Array[head].Next].Next=old;
	Array[head].Next=old;
	return new;
}
