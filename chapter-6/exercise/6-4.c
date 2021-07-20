void PercolateUp(int index,ElementType Data[],int Length)//假设在数组下标为零的位置设置了值为INT_MIN的sentinel
{
	int i,parent;
	ElementType Temp;
	for(i=index;i>0;i=parent)
	{
		parent=i/2;
		if(Data[i]<Data[parent])
		{
			Temp=Data[i];
			Data[i]=Data[parent];
			Data[parent]=Temp;
		}
	}
}
