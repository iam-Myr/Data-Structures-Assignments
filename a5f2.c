#include <stdio.h>

#define StackLimit 15

typedef int StackElementType;

typedef struct  {
    int Top;
    StackElementType Element[StackLimit];
} StackType;

typedef enum {
    FALSE, TRUE
} boolean;

void TraverseStack(StackType Stack);
void CreateStack(StackType *Stack);
boolean EmptyStack(StackType Stack);
boolean FullStack(StackType Stack);
void Push(StackType *Stack, StackElementType Item);
void Pop(StackType *Stack, StackElementType *Item);
void GetNthElement(StackType *Stack, StackElementType *X, StackElementType n);
void GetNthElementNoChange(StackType *Stack, StackElementType *X, StackElementType n);

main(){

    StackType Stack;
    StackElementType n, X, i;

    CreateStack(&Stack);

    for(i = 0; i <= 140; i+=10)
        Push(&Stack, i);
    TraverseStack(Stack);

    do {
        printf("Please enter n (n<=6): ");
        scanf("%d",&n);
    } while(n>(Stack.Top-1)/2); //Added check anyway

    //Question A
    GetNthElement(&Stack,&X,2);
    printf("\nQuestion A: x=%d\n",X);
    TraverseStack(Stack);

    //Question B
    GetNthElementNoChange(&Stack,&X,2);
    printf("\nQuestion B: x=%d\n",X);
    TraverseStack(Stack);

    //Question C
    GetNthElement(&Stack,&X,n);
    printf("\nQuestion C: x=%d\n",X);
    TraverseStack(Stack);

    //Question D
    GetNthElementNoChange(&Stack,&X,n);
    printf("\nQuestion D: x=%d\n",X);
    TraverseStack(Stack);

    //Question E
    GetNthElementNoChange(&Stack,&X,Stack.Top+1);
    printf("\nQuestion E: x=%d",X);
    TraverseStack(Stack);

    //Question F
    GetNthElementNoChange(&Stack,&X,Stack.Top-1);
    printf("\nQuestion F: x=%d\n",X);
    TraverseStack(Stack);

    //Question G
    GetNthElement(&Stack,&X,Stack.Top+1);
    printf("\nQuestion G: x=%d\n",X);
    TraverseStack(Stack);
}

void TraverseStack(StackType Stack)
{
 int i;
 printf("plithos sto stack %d\n",Stack.Top+1);
 for (i=0;i<=Stack.Top;i++)
 printf("%d ",Stack.Element[i]);
 printf("\n");
}

void CreateStack(StackType *Stack)
{
    Stack -> Top = -1;
   // (*Stack).Top = -1;
}

boolean EmptyStack(StackType Stack)
{
    return (Stack.Top == -1);
}

boolean FullStack(StackType Stack)
{
    return (Stack.Top == (StackLimit - 1));
}

void Push(StackType *Stack, StackElementType Item)
{
    if (!FullStack(*Stack)) {
        Stack -> Top++;
        Stack -> Element[Stack -> Top] = Item;
    } else
        printf("Full Stack...");
}

void Pop(StackType *Stack, StackElementType *Item)
{
    if (!EmptyStack(*Stack)) {
        *Item = Stack -> Element[Stack -> Top];
        Stack -> Top--;
    } else
        printf("Empty Stack...");
}


void GetNthElement(StackType *Stack, StackElementType *X, StackElementType n){
    StackElementType Item, i;

    for (i=0; i<n; i++)
        Pop(Stack, &Item);

    *X = Item;
}

//Question B
void GetNthElementNoChange(StackType *Stack, StackElementType *X, StackElementType n)
{
    StackType TempStack;
    StackElementType Item, i;

    CreateStack(&TempStack);

    for (i=0; i<n; i++)
    {
        Pop(Stack, &Item);
        Push(&TempStack, Item);
    }

    *X = Item;

    while(!EmptyStack(TempStack))
    {
        Pop(&TempStack, &Item);
        Push(Stack, Item);
    }

}
