#include <stdio.h>
#include "queue.h"
int main(void)
{
	Queue Q;
	Q=CreateQueue(Q);
	Q=EnQueue(1,Q);
	Q=EnQueue(3,Q);
	printf("%d\n",Front(Q));
	Q=DeQueue(Q);
	printf("%d\n",Front(Q));
	Q=DisposeQueue(Q);
	if(IsEmpty(Q))
		puts("Well done!");
	return 0;
}
