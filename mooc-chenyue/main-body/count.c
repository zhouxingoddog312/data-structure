#include <stdio.h>
#define ElementType int
int count=0;
void InsertionSort(ElementType A[],int N)
{
	int j,p;
	ElementType tmp;
	for(p=1;p<N;p++)
	{
		tmp=A[p];
		for(j=p;j>0&&A[j-1]>tmp;j--)
		{
			A[j]=A[j-1];
			count++;
		}
		A[j]=tmp;
	}
}
void Swap(ElementType *A1,ElementType *A2)
{
        ElementType Tmp;
        Tmp=*A1;
        *A1=*A2;
        *A2=Tmp;
}
void BubbleSort(ElementType A[],int N)
{
	int P,flag,i;
	for(P=N-1;P>=0;P--)
	{
		flag=0;
		for(i=0;i<P;i++)
		{
			if(A[i]>A[i+1])
			{
				Swap(&A[i],&A[i+1]);
				count++;
				flag=1;
			}
		}
		if(flag==0)
			break;
	}
}
int main(void)
{
	int A[6]={34,8,64,51,32,21};
	int B[6]={34,8,64,51,32,21};
	BubbleSort(A,6);
	printf("BubbleSort swap %d times\n",count);
	count=0;
	InsertionSort(B,6);
	printf("InsertSort swap %d times\n",count);
	return 0;
}
