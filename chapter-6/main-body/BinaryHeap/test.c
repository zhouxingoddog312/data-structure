#include <stdio.h>
#include "BinaryHeap.h"
int main(void)
{
	PriorityQueue H=Initialize(13);
	Insert(8,H);
	Insert(3,H);
	Insert(4,H);
	Insert(2,H);
	Insert(5,H);
	printf("The minimum is %d\n",FindMin(H));
	while(!IsEmpty(H))
		printf("Now,the minimum is %d\n",DeleteMin(H));
	Destroy(H);
	return 0;
}
