#include <stdio.h>
#include <stdlib.h>

typedef char StackElementType;
typedef struct StackNode *StackPointer;
typedef struct StackNode
{
    StackElementType Data;
    StackPointer Next;
} StackNode;

typedef char QueueElementType;
typedef struct QueueNode *QueuePointer;
typedef struct QueueNode
{
    QueueElementType Data;
    QueuePointer Next;
} QueueNode;
typedef struct
{
    QueuePointer Front;
    QueuePointer Rear;
}QueueType;

typedef enum {
FALSE, TRUE
} boolean;

void CreateStack(StackPointer *Stack);
boolean EmptyStack(StackPointer Stack);
void Push(StackPointer *Stack, StackElementType Item);
void Pop(StackPointer *Stack, StackElementType *Item);
void TraverseStack(StackPointer Stack);

void CreateQ(QueueType *Queue);
boolean EmptyQ(QueueType Queue);
void AddQ(QueueType *Queue, QueueElementType Item);
void RemoveQ(QueueType *Queue, QueueElementType *Item);
void TraverseQ(QueueType Queue);

int main(){
    StackPointer AStack;
    QueueType AQueue;
    char str[40];
    char ch1, ch2;
    boolean flag;

    CreateStack(&AStack);
    CreateQ(&AQueue);

    printf("DWSE TO ALFARITHMITIKO:");
    gets(str);

    for(int i = 0; i < strlen(str); i++){
        Push(&AStack, str[i]);
        AddQ(&AQueue, str[i]);
    }

    TraverseStack(AStack);
    TraverseQ(AQueue);

    int i = 0;
    flag = TRUE;

    while(flag && i < strlen(str)){
        Pop(&AStack, &ch1);
        RemoveQ(&AQueue, &ch2);
        if(ch1 != ch2)
            flag = FALSE;
        i++;
    }

    if(flag)
        printf("ACCEPTED\n");
    else
        printf("REJECTED\n");
    return 0;
}



//STACK
void CreateStack(StackPointer *Stack){
	*Stack = NULL;
}

boolean EmptyStack(StackPointer Stack){
	return (Stack==NULL);
}

void Push(StackPointer *Stack, StackElementType Item){
	StackPointer TempPtr;

    TempPtr= (StackPointer)malloc(sizeof(struct StackNode));
    TempPtr->Data = Item;
    TempPtr->Next = *Stack;
    *Stack = TempPtr;
}

void Pop(StackPointer *Stack, StackElementType *Item){
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
   	    printf("-------Stack of characters-------\n");
        while ( CurrPtr!=NULL )
        {
      	     printf("%c ", CurrPtr->Data);
             CurrPtr = CurrPtr->Next;
        }
   }
    printf("\n");
}

//QUEUE
void CreateQ(QueueType *Queue){
	Queue->Front = NULL;
	Queue->Rear = NULL;
}

boolean EmptyQ(QueueType Queue){
	return (Queue.Front==NULL);
}

void AddQ(QueueType *Queue, QueueElementType Item){
	QueuePointer TempPtr;

    TempPtr= (QueuePointer)malloc(sizeof(struct QueueNode));
    TempPtr->Data = Item;
    TempPtr->Next = NULL;
    if (Queue->Front==NULL)
        Queue->Front=TempPtr;
    else
        Queue->Rear->Next = TempPtr;
    Queue->Rear=TempPtr;
}

void RemoveQ(QueueType *Queue, QueueElementType *Item){
    QueuePointer TempPtr;

    if (EmptyQ(*Queue)) {
   	    printf("EMPTY Queue\n");
    }
   else
   {
        TempPtr = Queue->Front;
        *Item=TempPtr->Data;
        Queue->Front = Queue->Front->Next;
        free(TempPtr);
        if (Queue->Front==NULL) Queue->Rear=NULL;
    }
}

void TraverseQ(QueueType Queue){
    QueuePointer CurrPtr;
    if (EmptyQ(Queue))
        printf("EMPTY Queue\n");
    else{
        printf("-------Queue of characters-------\n");
        CurrPtr = Queue.Front;
        while (CurrPtr!=NULL ){
            printf("%c ", CurrPtr->Data);
            CurrPtr = CurrPtr->Next;
        }
        printf("\n");
    }
}
