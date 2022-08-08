#include <stdio.h>
#define Cutoff (3)
#define ElementType int
void Swap(ElementType *A1,ElementType *A2)
{
	ElementType Tmp;
	Tmp=*A1;
	*A1=*A2;
	*A2=Tmp;
}
ElementType Median3(ElementType A[],int Left,int Right)
{
	int Center=(Left+Right)/2;
	if(A[Left]>A[Center])
		Swap(&A[Left],&A[Center]);
	if(A[Left]>A[Right])
		Swap(&A[Left],&A[Right]);
	if(A[Center]>A[Right])
		Swap(&A[Center],&A[Right]);
	Swap(&A[Center],&A[Right-1]);
	return A[Right-1];
}
void InsertionSort(ElementType A[],int N)
{
	int j,p;
	ElementType tmp;
	for(p=1;p<N;p++)
	{
		tmp=A[p];
		for(j=p;j>0&&A[j-1]>tmp;j--)
			A[j]=A[j-1];
		A[j]=tmp;
	}
}
void Qsort(ElementType A[],int Left,int Right)
{
	int i,j;
	ElementType Pivot;
	if(Left+Cutoff<=Right)
	{
		Pivot=Median3(A,Left,Right);
		i=Left;
		j=Right-1;
		for(;;)
		{
			while(A[++i]<Pivot);
			while(A[--j]>Pivot);
			if(i<j)
				Swap(&A[i],&A[j]);
			else
				break;
		}
		Swap(&A[i],&A[Right-1]);
		Qsort(A,Left,i-1);
		Qsort(A,i+1,Right);
	}
	else
		InsertionSort(A+Left,Right-Left+1);
}
void QuickSort(ElementType A[],int N)
{
	Qsort(A,0,N-1);
}
int main(void)
{
	int N,i;
	scanf("%d\n",&N);
	int array[N];
	for(i=0;i<N;i++)
		scanf("%d",&array[i]);
	QuickSort(array,N);
	for(i=0;i<N;i++)
	{
		if(i<N-1)
			printf("%d ",array[i]);
		else
			printf("%d",array[i]);
	}
	return 0;
}
