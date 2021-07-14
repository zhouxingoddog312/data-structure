#include <stdio.h>
#include "LeftHeap.h"
int main(void)
{
	int i;
	PriorityQueue H=Initialize();
	i=DeleteMin(H);
	H=Insert(1,H);
	H=Insert(3,H);
	H=Insert(12,H);
	H=Insert(7,H);
	H=Insert(8,H);
	H=Insert(9,H);
	while(!IsEmpty(H))
		printf("%d\n",DeleteMin(H));
	return 0;
}
