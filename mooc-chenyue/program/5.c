#include <stdio.h>
int verify(int *array,int sequence_len,int stack_capacity);
int main(void)
{
	int count,index;
	int stack_capacity,sequence_len,sequence_num;
	scanf("%d %d %d",&stack_capacity,&sequence_len,&sequence_num);
	int array[sequence_len];
	for(count=0;count<sequence_num;count++)
	{
		for(index=0;index<sequence_len;index++)
		{
			scanf("%d",&array[index]);
		}
		if(verify(array,sequence_len,stack_capacity))
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
int verify(int *array,int sequence_len,int stack_capacity)
{
	int index;
	int push_index=0,pop_index=0,stack_num=0;
	int pushseq[sequence_len+1];
	int stack[stack_capacity+1];
	for(index=0;index<sequence_len;index++)
		pushseq[index]=index+1;
	while(stack_num||push_index<sequence_len||pop_index<sequence_len)
	{
		if(stack_num==0)
			stack[stack_num++]=pushseq[push_index++];
		if(stack[stack_num-1]==array[pop_index])
		{
			pop_index++;
			stack_num--;
		}
		else
			stack[stack_num++]=pushseq[push_index++];
		if(stack_num>stack_capacity)
			return 0;
	}
	return 1;
}
