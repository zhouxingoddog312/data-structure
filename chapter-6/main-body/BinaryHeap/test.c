#include <stdio.h>
#include "BinaryHeap.h"
int main(void)
{
	int arr[]={31,41,59,26,53,58,97};
	PriorityQueue H=Initialize(13);
	BuildHeap(arr,7,H);
/*	for(i=0;i<13;i++)
		printf("The minimum is %d\n",FindMin(H));	*/
	while(!IsEmpty(H))
		printf("Now,the minimum is %d\n",DeleteMin(H));
	Destroy(H);
	return 0;
}
