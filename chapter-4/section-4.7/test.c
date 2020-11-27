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
	T=Delete(3,T);
	Travel(T);
	T=Insert(8,T);
	T=Insert(6,T);
	T=Insert(7,T);
	Travel(T);
	T=Delete(1,T);
	Travel(T);
	T=Insert(11,T);
	T=Insert(18,T);
	T=Insert(20,T);
	Travel(T);
	T=Dispose(T);
	return 0;
}
