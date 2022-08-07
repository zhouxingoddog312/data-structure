#include <stdio.h>
#include <limits.h>
#define ElementType int
#define Element_Max INT_MAX
int ScanForMin(ElementType A[],int i,int j)
{
	int index,index_min=0;
	ElementType Min=Element_Max;
	for(index=i;index<=j;index++)
	{
		if(A[index]<Min)
		{
			index_min=index;
			Min=A[index];
		}
	}
	return index_min;
}
void Swap(ElementType *A1,ElementType *A2)
{
        ElementType Tmp;
        Tmp=*A1;
        *A1=*A2;
        *A2=Tmp;
}
void SelectionSort(ElementType A[],int N)
{
	int i,MinPosition;
	for(i=0;i<N;i++)
	{
		MinPosition=ScanForMin(A,i,N-1);
		Swap(&A[i],&A[MinPosition]);
	}
}
int main(void)
{
	int A[10]={2,1,4,5,7,8,9,3,6,0};
	SelectionSort(A,10);
	for(int i=0;i<10;i++)
		printf("A[%d]=%d ",i,A[i]);
	return 0;
}
