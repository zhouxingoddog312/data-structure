#include <stdio.h>
struct Node
{
	int Address;
	int Data;
	int Next;
};
typedef struct Node node;
typedef struct Node *ptn;
void SwapNode(ptn p1,ptn p2);
void SwapData(ptn p1,ptn p2);
void PrintArray(node array[],int N);
int main(void)
{
	int array_len,K,first_address,index,count;
	scanf("%d %d %d",&first_address,&array_len,&K);
	node array[array_len];
	for(index=0;index<array_len;index++)
		scanf("%d %d %d",&array[index].Address,&array[index].Data,&array[index].Next);
	count=0;
	while(first_address!=-1)
	{
		for(index=0;index<array_len;index++)
		{
			if(array[index].Address==first_address)
			{
				SwapNode(&array[index],&array[count]);
				first_address=array[count].Next;
				count++;
			}
		}
	}
	for(count=0;count<array_len-K;count+=K)
	{
		for(index=count;index<count+K/2;index++)
		{
			SwapData(&array[index],&array[count+K-index-1]);
		}
	}
	for(index=0;index<array_len-1;index++)
		array[index].Next=array[index+1].Address;
	array[array_len-1].Next=-1;
	PrintArray(array,array_len);
	return 0;
}
void SwapNode(ptn p1,ptn p2)
{
	node tmp;
	tmp=*p1;
	*p1=*p2;
	*p2=tmp;
}
void SwapData(ptn p1,ptn p2)
{
	int tmp_Address,tmp_Data;
	tmp_Data=p1->Data;
	tmp_Address=p1->Address;
	p1->Data=p2->Data;
	p1->Address=p2->Address;
	p2->Data=tmp_Data;
	p2->Address=tmp_Address;
}
void PrintArray(node array[],int N)
{
	int i;
	for(i=0;i<N;i++)
	{
		if(array[i].Next!=-1)
			printf("%05d %d %05d\n",array[i].Address,array[i].Data,array[i].Next);
		else
			printf("%05d %d %d\n",array[i].Address,array[i].Data,array[i].Next);
	}
}
