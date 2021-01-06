#include <stdio.h>
#include <stdlib.h>
#include "polynomial.h"
static int Compare(Position P1,Position P2);  /*Return 0 equal,-1 when P1 less than P2,1 when P1 more than P2*/
static void FataError(char *S);
static int Compare(Position P1,Position P2)
{
        int result;
        if(P1->Exponent<P2->Exponent)
                result=-1;
        else if(P1->Exponent>P2->Exponent)
                result=1;
        else
                result=0;
        return result;
}
static void FataError(char *S)
{
        fputs(S,stderr);
        putchar('\n');
        exit(EXIT_FAILURE);
}

Polynomial Initiate(Polynomial A)
{
        PtrToNode P;
        P=(PtrToNode)malloc(sizeof(struct Node));
        if(P==NULL)
                FataError("Fail to create polynomial!");
        P->Next=NULL;
        return P;
}
int IsEmpty(Polynomial A)
{
        return A->Next==NULL;
}
int IsLast(Position P,Polynomial A)
{
        return P->Next==NULL;
}
void Insert(int Coef,int Exp,Polynomial A,Position P)
{
        Position Ptr;
        Ptr=(PtrToNode)malloc(sizeof(struct Node));
        if(Ptr==NULL)
                FataError("Fail to create Node.");
        Ptr->Coefficient=Coef;
        Ptr->Exponent=Exp;
        Ptr->Next=P->Next;
        P->Next=Ptr;
}
void Print(Polynomial A)
{
        Position P;
        if(IsEmpty(A))
                puts("Polynomial is empty!");
        else
        {
                P=A->Next;
                while(P!=NULL)
                {
                        printf(" %dX^%d ",P->Coefficient,P->Exponent);
                        P=Advance(P);
                        if(P!=NULL)
                                putchar('+');
                }
        }
        putchar('\n');
        fputs("Polynomial print done!",stdout);
}
int CountSize(Polynomial A)     /*the result is exclude header*/
{
        int Count=0;
        Position P;
        P=A->Next;
        while(P!=NULL)
        {
                Count++;
                P=Advance(P);
        }
        return Count;
}
Position Advance(Position P)
{
        return P->Next;
}
void Delete(Polynomial A)
{
        Position Temp,P;
        P=A->Next;
        A->Next=NULL;
        while(P!=NULL)
        {
                Temp=P;
                P=Advance(P);
                free(Temp);
        }
}
void Sort(Polynomial A)
{
        Position P,Temp;
        int Sorted=0;
        while(Sorted==0)
        {
                P=A;
                Sorted=1;
                while(P->Next->Next!=NULL)
                {
                        if(Compare(P->Next,P->Next->Next)==1)
                        {
                                Temp=P->Next->Next;
                                P->Next->Next=Temp->Next;
                                Temp->Next=P->Next;
                                P->Next=Temp;
                                Sorted=0;
                        }
                        else if(Compare(P->Next,P->Next->Next)==0)
                        {
                                Temp=P->Next->Next;
                                P->Next->Next=Temp->Next;
                                P->Next->Coefficient+=Temp->Coefficient;
                                Sorted=0;
                                free(Temp);
                                continue;
                        }
                        P=Advance(P);
                }
        }
}
Polynomial Add(Polynomial A,Polynomial B)       /*assumed Polynomial A and B are sorted from less to large*/
{
        Polynomial Sum;
        Sum=Initiate(Sum);
        Position Pa,Pb,Psum;
        Pa=A->Next;
        Pb=B->Next;
        Psum=Sum;
        while(Pa!=NULL&&Pb!=NULL)
        {
                if(Compare(Pa,Pb)==-1)
                {
                        Insert(Pa->Coefficient,Pa->Exponent,Sum,Psum);
                        Pa=Advance(Pa);
                        Psum=Advance(Psum);
                }
                else if(Compare(Pa,Pb)==1)
                {
                        Insert(Pb->Coefficient,Pb->Exponent,Sum,Psum);
                        Pb=Advance(Pb);
                        Psum=Advance(Psum);
                }
                else
                {
                        Insert(Pa->Coefficient+Pb->Coefficient,Pa->Exponent,Sum,Psum);
                        Pa=Advance(Pa);
                        Pb=Advance(Pb);
                        Psum=Advance(Psum);
                }
        }
        while(Pa!=NULL)
        {
                Insert(Pa->Coefficient,Pa->Exponent,Sum,Psum);
                Pa=Advance(Pa);
                Psum=Advance(Psum);
        }
        while(Pb!=NULL)
        {
                Insert(Pb->Coefficient,Pb->Exponent,Sum,Psum);
                Pb=Advance(Pb);
                Psum=Advance(Psum);
        }
        return Sum;
}
Polynomial Multiply(Polynomial A,Polynomial B)  //O(MN^2),not O(M^2N),i think
{
        int index,M,N;
        Position Pa,Pb,Pp,Temp;
        M=CountSize(A);
        N=CountSize(B);
        M=M<=N?M:N;
        Position Parray[M];
        for(index=0;index<M;index++)
        {
                Parray[index]=Initiate(Parray[index]);
        }
        Pa=A->Next;
        index=0;
        while(Pa!=NULL)
        {
                Pp=Parray[index];
                Pb=B->Next;
                while(Pb!=NULL)
                {
                        Insert(Pa->Coefficient*Pb->Coefficient,Pa->Exponent+Pb->Exponent,Parray[index],Pp);
                        Pb=Advance(Pb);
                        Pp=Advance(Pp);
                }
                Sort(Parray[index]);
                Pa=Advance(Pa);
                index++;
        }
        Pp=Initiate(Pp);
        for(index=0;index<M;index++)
        {
                Temp=Pp;
                Pp=Add(Parray[index],Pp);
                Delete(Temp);
        }
        return Pp;

}
