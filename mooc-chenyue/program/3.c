#include <stdio.h>
#include <stdlib.h>
#define Compare(X,Y) ((X)>(Y)?1:(X)==(Y)?0:-1)
typedef struct PolyNode *Polynomial;
struct PolyNode
{
	int coef;
	int expon;
	Polynomial next;
};
Polynomial ReadPoly(void);
Polynomial Add(Polynomial P1,Polynomial P2);
Polynomial Mult(Polynomial P1,Polynomial P2);
void PrintPoly(Polynomial P);
void Attach(int c,int e,Polynomial *pRear);
int main(void)
{
	Polynomial P1,P2;
	P1=ReadPoly();
	P2=ReadPoly();
	PrintPoly(Mult(P1,P2));
	PrintPoly(Add(P1,P2));
	return 0;
}
void Attach(int c,int e,Polynomial *pRear)
{
	Polynomial tmp;
	tmp=(Polynomial)malloc(sizeof(struct PolyNode));
	tmp->coef=c;
	tmp->expon=e;
	tmp->next=NULL;
	(*pRear)->next=tmp;
	*pRear=tmp;
}
Polynomial ReadPoly(void)
{
	Polynomial P,Rear,tmp;
	int c,e,N;
	P=(Polynomial)malloc(sizeof(struct PolyNode));
	P->next=NULL;
	Rear=P;
	scanf("%d",&N);
	while(N--)
	{
		scanf("%d %d",&c,&e);
		Attach(c,e,&Rear);
	}
	tmp=P;
	P=P->next;
	free(tmp);
	return P;
}
Polynomial Add(Polynomial P1,Polynomial P2)
{
	Polynomial front,rear,tmp;
	int sum;
	front=(Polynomial)malloc(sizeof(struct PolyNode));
	front->next=NULL;
	rear=front;
	while(P1&&P2)
	{
		switch(Compare(P1->expon,P2->expon))
		{
			case 1:
				Attach(P1->coef,P1->expon,&rear);
				P1=P1->next;
				break;
			case -1:
				Attach(P2->coef,P2->expon,&rear);
				P2=P2->next;
				break;
			case 0:
				sum=P1->coef+P2->coef;
				if(sum)
				{
					Attach(sum,P1->expon,&rear);
				}
				P1=P1->next;
				P2=P2->next;
				break;
		}
	}
	for(;P1;P1=P1->next)
		Attach(P1->coef,P1->expon,&rear);
	for(;P2;P2=P2->next)
		Attach(P2->coef,P2->expon,&rear);
	rear->next=NULL;
	tmp=front;
	front=front->next;
	free(tmp);
	return front;
}
Polynomial Mult(Polynomial P1,Polynomial P2)
{
	Polynomial t1,t2,P,Rear,tmp;
	int c,e;
	if(!P1||!P2)
		return NULL;
	t1=P1;
	t2=P2;
	P=(Polynomial)malloc(sizeof(struct PolyNode));
	P->next=NULL;
	Rear=P;
	while(t2)
	{
		Attach(t1->coef*t2->coef,t1->expon+t2->expon,&Rear);
		t2=t2->next;
	}
	t1=t1->next;
	while(t1)
	{
		t2=P2;
		Rear=P;
		while(t2)
		{
			c=t1->coef*t2->coef;
			e=t1->expon+t2->expon;
			while(Rear->next&&Rear->next->expon>e)
				Rear=Rear->next;
			if(Rear->next&&Rear->next->expon==e)
			{
				if(Rear->next->coef+c)
					Rear->next->coef+=c;
				else
				{
					tmp=Rear->next;
					Rear->next=tmp->next;
					free(tmp);
				}
			}
			else
			{
				tmp=(Polynomial)malloc(sizeof(struct PolyNode));
				tmp->coef=c;
				tmp->expon=e;
				tmp->next=Rear->next;
				Rear->next=tmp;
				Rear=Rear->next;
			}
			t2=t2->next;
		}
		t1=t1->next;
	}
	tmp=P;
	P=P->next;
	free(tmp);
	return P;
}
void PrintPoly(Polynomial P)
{
	int flag=0;
	if(!P)
	{
		printf("0 0");
	}
	while(P)
	{
		if(!flag)
			flag=1;
		else
			printf(" ");
		printf("%d %d",P->coef,P->expon);
		P=P->next;
	}
	printf("\n");
}
