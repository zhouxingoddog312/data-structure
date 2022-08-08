#include <stdio.h>
int main(void)
{
	int array[51]={0};
	int N,i,tmp;
	scanf("%d\n",&N);
	for(i=0;i<N;i++)
	{
		scanf("%d",&tmp);
		array[tmp]++;
	}
	for(i=0;i<51;i++)
	{
		if(array[i]!=0)
			printf("%d:%d\n",i,array[i]);
	}
	return 0;
}
