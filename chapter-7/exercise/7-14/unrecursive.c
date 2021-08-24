#include <stdio.h>
#include <stdlib.h>
#define min(x,y) (x)<(y)?(x):(y)
typedef int ElementType;
void FataError(char *s)
{
	fputs(s,stderr);
	putc('\n',stderr);
}
void Merge(ElementType A[],ElementType TmpArray[],int Lpos,int Rpos,int RightEnd)
{
	int i,LeftEnd,NumElements,TmpPos;
	LeftEnd=Rpos-1;
	TmpPos=Lpos;
	NumElements=RightEnd-Lpos+1;
	while(Lpos<=LeftEnd&&Rpos<=RightEnd)
	{
		if(A[Lpos]<=A[Rpos])
			TmpArray[TmpPos++]=A[Lpos++];
		else
			TmpArray[TmpPos++]=A[Rpos++];
	}
	while(Lpos<=LeftEnd)
		TmpArray[TmpPos++]=A[Lpos++];
	while(Rpos<=RightEnd)
		TmpArray[TmpPos++]=A[Rpos++];
	for(i=0;i<NumElements;i++,RightEnd--)
		A[RightEnd]=TmpArray[RightEnd];
}
void MergeSort(ElementType A[],int N)
{
	ElementType *TmpArray;
	int SubListSize,Part1Start,Part2Start,Part2End;
	TmpArray=malloc(N*sizeof(ElementType));
	if(TmpArray!=NULL)
	{
		for(SubListSize=1;SubListSize<N;SubListSize*=2)
		{
			Part1Start=0;
			while(Part1Start+SubListSize<N)
			{
				Part2Start=Part1Start+SubListSize;
				Part2End=min(N-1,Part2Start+SubListSize-1);
				Merge(A,TmpArray,Part1Start,Part2Start,Part2End);
				Part1Start=Part2Start+1;
			}
		}



		free(TmpArray);
	}
	else
		FataError("No space for tmp array!");
}
int main(void)
{
	int arr[]={2,5,3};
	MergeSort(arr,3);
	for(int i=0;i<3;i++)
		printf("%d ",arr[i]);
	return 0;
}
