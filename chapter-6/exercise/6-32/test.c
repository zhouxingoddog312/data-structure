#include <stdio.h>
#include "BinomialQueue.h"
int main(void)
{
	BinQueue H;
	H=Initialize();
	Insert(1,H);
	Insert(6,H);
	Insert(3,H);
	Insert(9,H);
	Insert(11,H);
	printf("The min is %d\n",FindMin(H));
	DeleteMin(&H);
	printf("The min is %d\n",FindMin(H));
	MakeEmpty(H);
	Insert(13,H);
	printf("The minist is %d\n",DeleteMin(&H));
	Destroy(H);
	return 0;
}
