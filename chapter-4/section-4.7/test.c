#include <stdio.h>
#include "btree.h"
int main(void)
{
	Btree T;
	T=Init(T);
	T=Insert(1,T);
	T=Insert(2,T);
	T=Insert(3,T);
	T=Insert(4,T);
	T=Insert(5,T);
	Travel(T);
	Delete(3,T);
	Travel(T);
	return 0;
}
