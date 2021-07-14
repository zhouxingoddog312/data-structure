#include <stdio.h>
#include "BinaryHeap.h"
int main(void)
{
	int arr[]={8,3,4,2,5};
	PriorityQueue H=Initialize(13);
	BuildHeap(arr,5,H);
	Insert(11,H);
	printf("The minimum is %d\n",FindMin(H));
	while(!IsEmpty(H))
		printf("Now,the minimum is %d\n",DeleteMin(H));
	Destroy(H);
	return 0;
}
