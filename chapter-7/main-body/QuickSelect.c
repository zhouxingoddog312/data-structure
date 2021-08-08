#define Cutoff (3)
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
void Qselect(ElementType A[],int k,int Left,int Right)
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
		if(k<=i)
			Qselect(A,k,Left,i-1);
		else if(k>i+1)
			Qselect(A,k,i+1,Right);
	}
	else
		InsertionSort(A+Left,Right-Left+1);
}	//第k个最小元就在下标k-1处
