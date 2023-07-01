#include <stdio.h>

#define QueueLimit 10

typedef int QueueElementType;

typedef struct {
	int Front, Rear;
    int Count;
	QueueElementType Element[QueueLimit];
} QueueType;

typedef enum {FALSE, TRUE} boolean;

void CreateQ(QueueType *Queue);
boolean EmptyQ(QueueType Queue);
boolean FullQ(QueueType Queue);
void RemoveQ(QueueType *Queue, QueueElementType *Item);
void AddQ(QueueType *Queue, QueueElementType Item);
void TraverseQ(QueueType Queue);

void Initialize(QueueType *Queue);
void printq(QueueType Queue, boolean hasRemoved, QueueElementType item);


int main(){

    QueueType Queue;
    QueueElementType item;
    int tempCount;

    //Question a
    printf("---%c---", 'a');
    Initialize(&Queue);

    printf("\nQueue: ");
    printq(Queue, FALSE, item);

    //Question b
    printf("\n---%c---\n", 'b');
    AddQ(&Queue, 10);

    printf("\nQueue: ");
    printq(Queue, FALSE, item);

    //Question c
    printf("\n---%c---", 'c');
    RemoveQ(&Queue, &item);

    printf("\nQueue: ");
    printq(Queue, TRUE, item);

    //Question d
    printf("\n---%c---", 'd');

    AddQ(&Queue, 25);

    printf("\nQueue: ");
    printq(Queue, FALSE, item);

    //Question e
    printf("\n---%c---\n", 'e');
    
    AddQ(&Queue, 26);

    printf("\nQueue: ");
    printq(Queue, FALSE, item);

    //Question f
    printf("\n---%c---", 'f');
    
    
    while(!EmptyQ(Queue))
    {
        printf("\nQueue: ");
        RemoveQ(&Queue, &item);
        printq(Queue, TRUE, item);
    }
    
    return 0;
}


void Initialize(QueueType *Queue) {
    CreateQ(Queue);

    for(int i =0; i < QueueLimit; i++)
        AddQ(Queue, i);
}


void printq(QueueType Queue, boolean hasRemoved, QueueElementType item) {
    TraverseQ(Queue);

    if(hasRemoved)
        printf("Removed item=%d ", item);

    printf("Front=%d Rear=%d Count=%d", Queue.Front, Queue.Rear, Queue.Count);
}


void TraverseQ(QueueType Queue) {
	int current;
	current = Queue.Front;

    if(!EmptyQ(Queue)) {
	    for(int i = 1; i <= Queue.Count; i++) {
            printf("%d ", Queue.Element[current]);
		    current = (current + 1) % QueueLimit;
	    }
    }
    else {
        printf("Empty Queue");
    }
	printf("\n");
}


void CreateQ(QueueType *Queue)
/*  Initializes the QueueType item Queue
*/
{
	Queue->Front = 0;
	Queue->Rear = 0;
    Queue->Count = 0;
}

boolean EmptyQ(QueueType Queue)
/* Returns TRUE if the Queue is empty and FALSE if it is not.
*/
{
	return (Queue.Count == 0);
}

boolean FullQ(QueueType Queue)
/* Returns TRUE if the Queue is full and FALSE if the Queue is not full.
*/
{
	return (Queue.Count == QueueLimit);
}

void RemoveQ(QueueType *Queue, QueueElementType *Item)
/* Removes an item from the front part of the Queue, inserting it to the Item.
*/
{
	if(!EmptyQ(*Queue))
	{
		*Item = Queue ->Element[Queue -> Front];
		Queue ->Front  = (Queue ->Front + 1) % QueueLimit;
        Queue->Count -= 1;
	}
	else
		printf("Empty Queue");
}

void AddQ(QueueType *Queue, QueueElementType Item)
/* Adds the Item to the Queue in the Rear position.
*/
{
	if(!FullQ(*Queue))
	{
		Queue ->Element[Queue ->Rear] = Item;
		Queue ->Rear = (Queue ->Rear + 1) % QueueLimit;
        Queue ->Count += 1;
	}
	else
		printf("Full Queue");
}