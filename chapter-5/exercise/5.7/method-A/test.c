#include <stdio.h>
#include "polynomial.h"
int main(void)
{
        int Coef,Exp;
        Polynomial A,B,Sum,Product;
        Position Temp;
        A=Initiate(A);
        B=Initiate(B);
        puts("Start to create polynomial A:");
        Temp=A;
        fputs("Enter two integers for Coefficient and Exponent(q to quit):",stdout);
        while(scanf("%d%d",&Coef,&Exp)==2)
        {
                Insert(Coef,Exp,A,Temp);
                Temp=Advance(Temp);
                fputs("another two integers(q to quit):",stdout);
        }
        puts("Polynomial A created done!We will print it.");
        Print(A);
        puts("Now sort polynomial A.Print it.");
        Sort(A);
        Print(A);
        while(getchar()!='\n')
                continue;
        puts("Start to create polynomial B:");
        Temp=B;
        fputs("Enter two integers for Coefficient and Exponent(q to quit):",stdout);
        while(scanf("%d%d",&Coef,&Exp)==2)
        {
                Insert(Coef,Exp,B,Temp);
                Temp=Advance(Temp);
                fputs("another two integers(q to quit):",stdout);
        }
        puts("Polynomial B created done!We will print it.");
        Print(B);
        puts("Now sort polynomial B.Print it.");
        Sort(B);
        Print(B);
        puts("A plus B:");
        Sum=Add(A,B);
        Print(Sum);
        puts("A multiply B:");
        Product=Multiply(A,B);
        Print(Product);
        puts("Well done!");
        Delete(A);
        Delete(B);
        Delete(Sum);
        Delete(Product);
        return 0;
}
