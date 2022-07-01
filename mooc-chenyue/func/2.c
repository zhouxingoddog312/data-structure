List Merge(List L1,List L2)
{
    List result=malloc(sizeof(struct Node));
    result->Next=NULL;
    List ptr=result;
    List tmpL1=L1;
    List tmpL2=L2;
    L1=L1->Next;
    L2=L2->Next;
    tmpL1->Next=NULL;
    tmpL2->Next=NULL;
    while(L1!=NULL||L2!=NULL)
    {
        if(L1!=NULL&&L2!=NULL)
        {
            if(L1->Data>L2->Data)
            {
                ptr->Next=L2;
                L2=L2->Next;
                ptr=ptr->Next;
            }
            else if(L1->Data<L2->Data)
            {
                ptr->Next=L1;
                L1=L1->Next;
                ptr=ptr->Next;
            }
            else if(L1->Data==L2->Data)
            {
                ptr->Next=L1;
                L1=L1->Next;
                L2=L2->Next;
                ptr=ptr->Next;
            }
        }
        else if(L1!=NULL)
        {
            ptr->Next=L1;
            L1=L1->Next;
            ptr=ptr->Next;
        }
        else if(L2!=NULL)
        {
            ptr->Next=L2;
            L2=L2->Next;
            ptr=ptr->Next;
        }
    }
    return result;
}
