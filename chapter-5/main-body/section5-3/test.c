#include <stdio.h>
#include "hashsep.h"
int main(void)
{
	HashTable H;
	H=InitializeTable(10);
	int array[]={0,1,81,4,64,25,16,36,9,49};
	for(int index=0;index<10;index++)
		Insert(array[index],H);
	Travel(H);
	Delete(0,H);
	if(Find(36,H)!=NULL)
		puts("found 36.");
	if(Find(0,H)!=NULL)
		puts("found bug.");
	Delete(36,H);
	Travel(H);
	DestroyTable(H);
	return 0;
}
