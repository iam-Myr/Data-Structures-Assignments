#include <stdio.h>
#include <stdlib.h>

typedef int StackElementType;           /*� ����� ��� ��������� ��� �������
                                        ���������� ����� int */
typedef struct StackNode *StackPointer;
typedef struct StackNode
{
	StackElementType Data;
    StackPointer Next;
} StackNode;

typedef enum {
    FALSE, TRUE
} boolean;

void CreateStack(StackPointer *Stack);
boolean EmptyStack(StackPointer Stack);
void Push(StackPointer *Stack, StackElementType Item);
void Pop(StackPointer *Stack, StackElementType *Item);
void TraverseStack(StackPointer Stack);

main(){

    StackElementType Item;
    StackPointer AStack1, AStack2, TempPtr;
    int n, i;

    CreateStack(&AStack1);
    printf("Plithos stoixeiwn ouras:");
    scanf("%d", &n);

    for(i=0; i<n; i++){
        printf("Eisagete to %do stoixeio:", i+1);
        scanf("%d", &Item);
        Push(&AStack1, Item);
    }

    printf("*********1i stoiva***********\n");
    TraverseStack(AStack1);

    CreateStack(&AStack2);

    while(!EmptyStack(AStack1)){
        TempPtr = AStack1;
        Item = TempPtr->Data;
        Pop(&AStack1, &Item);
        Push(&AStack2, Item);
    }

    printf("\n*********2i stoiva***********\n");
    TraverseStack(AStack2);

return 0;
}

void CreateStack(StackPointer *Stack)
/* ����������: ���������� ��� ���� ����������� ������.
   ����������: ��� ���� ����������� ������, Stack
*/
{
	*Stack = NULL;
}

boolean EmptyStack(StackPointer Stack)
/* �������:     ��� ����������� ������, Stack.
   ����������:  ������� �� � Stack ����� ����.
   ����������:  TRUE �� � ������ ����� ����, FALSE �����������
*/
{
	return (Stack==NULL);
}

void Push(StackPointer *Stack, StackElementType Item)
/* �������:    ��� ����������� ������ ��� � ������ ��� �������������� ��� ���
                ������ Stack ��� ��� �������� Item.
   ����������: ������� ���� ������ ��� ������������ �������, �� �������� Item.
   ����������: ��� ������������� ����������� ������
*/
{
	StackPointer TempPtr;

    TempPtr= (StackPointer)malloc(sizeof(struct StackNode));
    TempPtr->Data = Item;
    TempPtr->Next = *Stack;
    *Stack = TempPtr;
}

void Pop(StackPointer *Stack, StackElementType *Item)
/* �������:    ��� ����������� ������ ��� � ������ ��� �������������� ��� ��� ������ Stack.
   ����������: ������� ��� ��� ������ ��� ������������ �������,
                �� � ������ ��� ����� ����, �� �������� Item.
   ����������: ��� ������������� ����������� ������ ��� �� �������� Item.
   ������:     ������ ����� �������, �� � ����������� ������ ����� ����
*/
{
    StackPointer TempPtr;

    if (EmptyStack(*Stack)) {
   	    printf("EMPTY Stack\n");
    }
   else
   {
        TempPtr = *Stack;
        *Item=TempPtr->Data;
        *Stack = TempPtr->Next;
        free(TempPtr);
    }
}

void TraverseStack(StackPointer Stack){
    StackPointer CurrPtr;

   if (EmptyStack(Stack))
   {
           printf("EMPTY Stack\n");
    }
   else
   {
           CurrPtr = Stack;
         while ( CurrPtr!=NULL )
        {
               printf("%d ", CurrPtr->Data);
             CurrPtr = CurrPtr->Next;
        }
   }
    printf("\n");
}
