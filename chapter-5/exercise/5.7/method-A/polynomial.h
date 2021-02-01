#ifndef _POLYNOMIAL_H
#define _POLYNOMIAL_H

typedef struct Node *PtrToNode;
struct Node
{
        int Coefficient;
        int Exponent;
        PtrToNode Next;
};
typedef PtrToNode Polynomial;  /*Node will sorted by Exponent from less to large*/
typedef PtrToNode Position;


Polynomial Initiate(Polynomial A);
int IsEmpty(Polynomial A);
int IsLast(Position P,Polynomial A);
void Insert(int Coef,int Exp,Polynomial A,Position P);
void Print(Polynomial A);
int CountSize(Polynomial A);
void Sort(Polynomial A);
Position Advance(Position P);
void Delete(Polynomial A);
Polynomial Add(Polynomial A,Polynomial B);
Polynomial Multiply(Polynomial A,Polynomial B);





#endif