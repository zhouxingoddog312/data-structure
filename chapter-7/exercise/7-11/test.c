#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "BinaryHeap.h"
int main(void)
{
	ElementType arr[]={142,543,123,65,453,879,572,434,111,242,811,102};
	PriorityQueue H=Initialize(24);
	BuildHeap(arr,12,H);
	PrintHeap(H);
	while(!IsEmpty(H))
	{
		printf("delete %d\n",DeleteMin(H));
		PrintHeap(H);
	}

	Destroy(H);
	return 0;
}
