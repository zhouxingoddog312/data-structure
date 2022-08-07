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
				flag=1;
			}
		}
		if(flag==0)
			break;
	}
}
