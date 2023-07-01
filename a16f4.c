#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int code;
    int priority;
}QItems;


typedef QItems QueueElementType;

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
} QueueType;

typedef enum {
    FALSE, TRUE
} boolean;


void CreateQ(QueueType *Queue);
boolean EmptyQ(QueueType Queue);
void AddQ(QueueType *Queue, QueueElementType Item);
void RemoveQ(QueueType *Queue, QueueElementType *Item);

void insert_prot(QueueType *Queue, QueueElementType Item);
QueueElementType getQItem(int x);
void TraverseQ(QueueType Queue);

int main() {
    QueueType myQueue;
    int nodeNum;
    QueueElementType item;

    CreateQ(&myQueue);

    printf("DWSE TO PLITHOS: ");
    scanf("%d", &nodeNum);
    
    for(int i = 0; i < nodeNum; i++) {
        item = getQItem(i+1);
        insert_prot(&myQueue, item);
    }
    
    printf("----------Priority Queue-------------\n");
    TraverseQ(myQueue);

    return 0;
}

QueueElementType getQItem(int x) {
    QueueElementType item;

    printf("DWSE TON KODIKO TOU %dou KOMVOU: ", x);
    scanf("%d", &item.code);

    printf("DWSE TO VATHMO PROTERAIOTITAS TOU %dou KOMVOU: ", x);
    scanf("%d", &item.priority);

    return item;
}

void insert_prot(QueueType *Queue, QueueElementType Item) {
    QueuePointer currPtr;
    QueuePointer temp;
    QueuePointer predPtr;
    boolean hasNotBeenEntered = TRUE;

    temp = (QueuePointer)malloc(sizeof(struct QueueNode));

    temp->Data = Item;
    temp->Next = NULL;

    if(EmptyQ(*Queue)){
        Queue->Front = temp;
        Queue->Rear = temp;
    }
    else {
        predPtr = Queue->Front;
        currPtr = Queue->Front;
        
        if(currPtr->Data.priority > temp->Data.priority) {
            Queue->Front = temp;
            temp->Next = currPtr;
        }
        else {
            while (currPtr!=NULL && hasNotBeenEntered)
            {
                if(currPtr->Data.priority > temp->Data.priority) {
                    predPtr->Next = temp;
                    temp->Next = currPtr;
                    hasNotBeenEntered = FALSE;
                }

                predPtr = currPtr;
                currPtr = currPtr->Next;
            }

            if(hasNotBeenEntered) {
                predPtr->Next = temp;
                Queue->Rear = temp;
            }
        }
    }
}


//Given Functions


void CreateQ(QueueType *Queue)
{
	Queue->Front = NULL;
	Queue->Rear = NULL;
}

boolean EmptyQ(QueueType Queue)
{
	return (Queue.Front==NULL);
}

void AddQ(QueueType *Queue, QueueElementType Item)
{
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

void RemoveQ(QueueType *Queue, QueueElementType *Item)
{
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
        if (Queue->Front== NULL) Queue->Rear=NULL;
    }   
}

void TraverseQ(QueueType Queue)
{
	QueuePointer CurrPtr;

   if (EmptyQ(Queue))
    {
   	    printf("EMPTY Queue\n");
    }
   else
   {
   	    CurrPtr = Queue.Front;
         while ( CurrPtr!=NULL )
        {
      	     printf("%d %d\n", CurrPtr->Data.priority, CurrPtr->Data.code);
             CurrPtr = CurrPtr->Next;
        }
   }
    printf("\n");
}