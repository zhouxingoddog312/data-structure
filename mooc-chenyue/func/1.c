Position BinarySearch(List L,ElementType X)
{
    int lower,upper,mid;
    lower=1;
    upper=L->Last;
    while(lower<=upper)
    {
        mid=(lower+upper)/2;
        if(L->Data[mid]==X)
            return mid;
        else if(L->Data[mid]<X)
        {
            lower=mid+1;
        }
        else if(L->Data[mid]>X)
            upper=mid-1;
    }
    return NotFound;
}
