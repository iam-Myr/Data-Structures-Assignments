#include <stdio.h>

#define QueueLimit 4

typedef struct {
    int Arrival, stayTime, startTime, endTime;
}Client;

typedef Client QueueElementType;

typedef struct {
	int Front, Rear;
	QueueElementType Element[QueueLimit];
} QueueType;

typedef enum {FALSE, TRUE} boolean;

void CreateQ(QueueType *Queue);
boolean EmptyQ(QueueType Queue);
boolean FullQ(QueueType Queue);
void RemoveQ(QueueType *Queue, QueueElementType *Item);
void AddQ(QueueType *Queue, QueueElementType Item);

void QueueInitialization(QueueType *Queue);
QueueType TimesInQueue(QueueType *Queue);
void printQueue(QueueType Queue, char name[]);

QueueElementType getClient();

int main() {

    QueueType waitingQueue, serviceQueue;

    QueueInitialization(&waitingQueue);

    printQueue(waitingQueue, "Waiting");


    CreateQ(&serviceQueue);
    serviceQueue = TimesInQueue(&waitingQueue);

    printQueue(waitingQueue, "Waiting");
    printQueue(serviceQueue, "Service");

    return 0;
}


void QueueInitialization(QueueType *Queue){
    CreateQ(Queue);
    int i = 0;

    while (!FullQ(*Queue))
    {
        i++;
        printf("Give: arrival time,stay time for client %d: ", i);
        AddQ(Queue, getClient());
    }
    
}


QueueElementType getClient() {
    QueueElementType client;

    scanf("%d,%d", &client.Arrival, &client.stayTime);

    client.startTime = -1;
    client.endTime = -1;

    return client;
}


QueueType TimesInQueue(QueueType *Queue) {
    QueueType serQueue;
    QueueElementType client;
    QueueElementType nextClient;

    CreateQ(&serQueue);

    RemoveQ(Queue, &client);
    client.startTime = client.Arrival;
    client.endTime = client.startTime + client.stayTime;

    AddQ(&serQueue, client);

    while (!EmptyQ(*Queue))
    {
        RemoveQ(Queue, &nextClient);
        if(nextClient.Arrival > client.endTime)
            nextClient.startTime = nextClient.Arrival;
        else
            nextClient.startTime = client.endTime;
        
        nextClient.endTime = nextClient.startTime + nextClient.stayTime;

        client = nextClient;
        AddQ(&serQueue, nextClient);
    }

    return serQueue;
    
}

void printQueue(QueueType Queue, char name[]) {
    QueueElementType temp;
    int i = 0;

    if(EmptyQ(Queue))
        printf("%s Queue is empty\n", name);
    else {
        printf("%s Queue\n", name);
        printf("Client              Start   End     Arrival Stay\n");

        while (!EmptyQ(Queue))
        {
            i++;
            RemoveQ(&Queue, &temp);
            printf("%-7s%d%-12s%-8d%-8d%-8d%-4d\n", "Client", i, " ", temp.startTime, temp.endTime, temp.Arrival, temp.stayTime);
        }
    }
}


void CreateQ(QueueType *Queue)
/*  ����������:  ���������� ��� ���� ����.
    ����������:  ���� ����
*/
{
	Queue->Front = 0;
	Queue->Rear = 0;
}

boolean EmptyQ(QueueType Queue)
/* �������:    ��� ����.
   ����������: ������� �� � ���� ����� ����.
   ����������: True �� � ���� ����� ����, False �����������
*/
{
	return (Queue.Front == Queue.Rear);
}

boolean FullQ(QueueType Queue)
/* �������:    ��� ����.
   ����������: ������� �� � ���� ����� ������.
   ����������: True �� � ���� ����� ������, False �����������
*/
{
	return ((Queue.Front) == ((Queue.Rear +1) % QueueLimit));
}

void RemoveQ(QueueType *Queue, QueueElementType *Item)
/* �������:    ��� ����.
   ����������: ������� �� �������� Item ��� ��� ������ ���� ��� �����
                �� � ���� ��� ����� ����.
   ����������: �� �������� Item ��� ��� ������������� ����.
   ������:     ������ ����� ���� �� � ���� ����� ����
*/
{
	if(!EmptyQ(*Queue))
	{
		*Item = Queue ->Element[Queue -> Front];
		Queue ->Front  = (Queue ->Front + 1) % QueueLimit;
	}
	else
		printf("Empty Queue");
}

void AddQ(QueueType *Queue, QueueElementType Item)
/* �������:    ��� ���� Queue ��� ��� �������� Item.
   ����������: ��������� �� �������� Item ���� ���� Queue
                �� � ���� ��� ����� ������.
   ����������: ��� ������������� ����.
   ������:     ������ ������� ����� �� � ���� ����� ������
*/
{
	if(!FullQ(*Queue))
	{
		Queue ->Element[Queue ->Rear] = Item;
		Queue ->Rear = (Queue ->Rear + 1) % QueueLimit;
	}
	else
		printf("Full Queue");
}