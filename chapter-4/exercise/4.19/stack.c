#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

struct Node
{
        ElementType_S Element;
        PtrToNode Next;
};

static void FatalError(char *S);
static void Error(char *S);

static void FatalError(char *S)
{
        fputs(S,stderr);
        exit(EXIT_FAILURE);
}
static void Error(char *S)
{
        fputs(S,stderr);
}

int StackIsEmpty(Stack S)
{
        return S->Next==NULL;
}

Stack CreateStack(void)
{
        Stack S;
        S=malloc(sizeof(struct Node));
        if(S==NULL)
                FatalError("Out of space!");
        S->Element=NULL;
        S->Next=NULL;
        StackMakeEmpty(S);
        return S;
}

void StackMakeEmpty(Stack S)
{
        if(S==NULL)
                Error("Must usr CreateStack first.");
        else
                while(!StackIsEmpty(S))
                        Pop(S);
}

void Push(ElementType_S X,Stack S)
{
        PtrToNode Tmp;
        Tmp=malloc(sizeof(struct Node));
        if(Tmp==NULL)
                FatalError("Out of space!");
        Tmp->Element=X;
        Tmp->Next=S->Next;
        S->Next=Tmp;
}

ElementType_S Top(Stack S)
{
        if(!StackIsEmpty(S))
                return S->Next->Element;
        Error("Empty stack!");
        return 0;
}

void Pop(Stack S)
{
        PtrToNode P;
        if(StackIsEmpty(S))
                Error("Empty stack!");
        else
        {
                P=S->Next;
                S->Next=S->Next->Next;
                free(P);
        }
}
