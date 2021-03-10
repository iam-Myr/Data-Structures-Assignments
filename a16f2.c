#include <stdio.h>

#define StackLimit 15

//typedef int StackElementType;

typedef struct  {
    int price;
    char size;
} StackElementType;

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

main(){

    StackType Stack, TempStack;
    int plithosFanelakia,i;
    char sizeRequest;
    StackElementType shirt;
    boolean Found;

    CreateStack(&Stack);

    printf("Give number of items: ");
    scanf("%d",&plithosFanelakia);

    printf("Give the items to store\n");
    for(i = 0; i < plithosFanelakia; i++){
        printf("Give price: ");
        scanf("%d", &shirt.price);
        printf("Give size: ");
        scanf(" %c", &shirt.size);
        Push(&Stack, shirt);
    }

    printf("Items in the box:\n");
    TraverseStack(Stack);

    printf("What size do you want? ");
    scanf(" %c",&sizeRequest);

    //Search
    CreateStack(&TempStack);
    Found = FALSE;
    while(!Found && !EmptyStack(Stack)){
        Pop(&Stack, &shirt);
        if(shirt.size == sizeRequest)
            Found = TRUE;
        else
            Push(&TempStack, shirt);
    }

    if (Found)
        printf("Found the size %c\n\n",sizeRequest);
    else
        printf("Not found the size %c\n\n",sizeRequest);


    printf("Items in the box:\n");
    TraverseStack(Stack);
    printf("Items out of the box:\n");
    TraverseStack(TempStack);

    while(!EmptyStack(TempStack)){
        Pop(&TempStack, &shirt);
        Push(&Stack, shirt);
    }

    printf("Items in the box:\n");
    TraverseStack(Stack);
    printf("Items out of the box:\n");
    TraverseStack(TempStack);

}

void TraverseStack(StackType Stack)
{
    int i;
    printf("plithos sto stack %d\n",Stack.Top+1);
    for (i=0;i<=Stack.Top;i++)
        printf("%d, %c\n", Stack.Element[i].price, Stack.Element[i].size);
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
