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
void Merge_loop(ElementType A[],ElementType TmpArray[],int N,int length)
{
	int i,j;
	for(i=0;i<N-2*length;i+=2*length)
	{
		Merge(A,TmpArray,i,i+length,i+2*length-1);
	}
	if(i+length<N)
		Merge(A,TmpArray,i,i+length,N-1);
	else
	{
		for(j=i;j<N;j++)
			TmpArray[j]=A[j];
	}
}
void MergeSort(ElementType A[],int N)
{
	int length=1;
	ElementType *TmpArray=malloc(sizeof(ElementType)*N);
	if(TmpArray)
	{
		while(length<N)
		{
			Merge_loop(A,TmpArray,N,length);
			length*=2;
			Merge_loop(TmpArray,A,N,length);
			length*=2;
		}
		free(TmpArray);
	}
	else
		FataError("out of space!");
}
