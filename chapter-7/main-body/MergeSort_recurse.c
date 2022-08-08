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
void Msort(ElementType A[],ElementType TmpArray[],int Left,int Right)
{
	int Center;
	if(Left<Right)
	{
		Center=(Left+Right)/2;
		Msort(A,TmpArray,Left,Center);
		Msort(A,TmpArray,Center+1,Right);
		Merge(A,TmpArray,Left,Center+1,Right);
	}
}
void MergeSort(ElementType A[],int N)
{
	ElementType *TmpArray;
	TmpArray=malloc(N*sizeof(ElementType));
	if(TmpArray!=NULL)
	{
		Msort(A,TmpArray,0,N-1);
		free(TmpArray);
	}
	else
		FataError("No space for tmp array!");
}
