#include <stdio.h>
#include <stdlib.h>

typedef int ListElementType;
typedef struct ListNode *ListPointer;

typedef struct ListNode
{
ListElementType Data;
ListPointer Next;
} ListNode;

typedef enum {
 FALSE, TRUE
} boolean;

void CreateList(ListPointer *List);
boolean EmptyList(ListPointer List);
void LinkedInsert(ListPointer *List, ListElementType Item, ListPointer PredPtr);
void LinkedDelete(ListPointer *List, ListPointer PredPtr);
void LinkedTraverse(ListPointer List);
void LinearSearch(ListPointer List, ListElementType Item, ListPointer *PredPtr, boolean *Found);
void OrderedLinearSearch(ListPointer List, ListElementType Item, ListPointer *PredPtr, boolean *Found);
void concat_list(ListPointer AList, ListPointer BList, ListPointer *FinalList);

int main(){
    ListPointer AList, BList, FinalList, PredPtr;
    ListElementType Item;
    int size;

    CreateList(&AList);
    CreateList(&BList);
    CreateList(&FinalList);

    PredPtr = NULL;
    printf("DWSE TON PLH8OS TWN STOIXEIWN THS LISTAS 1:");
    scanf("%d",&size);
    for (int i = 0; i < size; i++){
        printf("DWSE TON ARI8MO GIA EISAGWGH STH ARXH THS LISTAS 1:");
        scanf("%d",&Item);
        LinkedInsert(&AList, Item, PredPtr);
    }
    printf("DWSE TON PLH8OS TWN STOIXEIWN THS LISTAS 2:");
    scanf("%d", &size);
    for (int i = 0; i < size; i++){
        printf("DWSE TON ARI8MO GIA EISAGWGH STH ARXH THS LISTAS 2:");
        scanf("%d",&Item);
        LinkedInsert(&BList, Item, PredPtr);
    }

    printf("LISTA 1:\n");
    LinkedTraverse(AList);
    printf("LISTA 2:\n");
    LinkedTraverse(BList);

    concat_list(AList, BList, &FinalList);
    printf("SYNENWMENH LISTA:\n");
    LinkedTraverse(FinalList);

    return 0;
}

void concat_list(ListPointer AList, ListPointer BList, ListPointer *FinalList){
    ListPointer CurrPtr, PredPtr;
    ListElementType Item;

    CurrPtr = AList;
    PredPtr = NULL;
    while (CurrPtr != NULL){
        Item = CurrPtr->Data;
        LinkedInsert(FinalList, Item, PredPtr);
        CurrPtr = CurrPtr->Next;
    }
    CurrPtr = BList;
    while (CurrPtr != NULL){
        Item = CurrPtr->Data;
        LinkedInsert(FinalList, Item, PredPtr);
        CurrPtr = CurrPtr->Next;
    }
}

void CreateList(ListPointer *List)
{
	*List = NULL;
}

boolean EmptyList(ListPointer List)
{
	return (List==NULL);
}

void LinkedInsert(ListPointer *List, ListElementType Item, ListPointer PredPtr)
{
	ListPointer TempPtr;

   TempPtr= (ListPointer)malloc(sizeof(struct ListNode));
   TempPtr->Data = Item;
	if (PredPtr==NULL) {
        TempPtr->Next = *List;
        *List = TempPtr;
    }
    else {
        TempPtr->Next = PredPtr->Next;
        PredPtr->Next = TempPtr;
    }
}

void LinkedDelete(ListPointer *List, ListPointer PredPtr)
{
    ListPointer TempPtr;

    if (EmptyList(*List))
   	    printf("EMPTY LIST\n");
   else
   {
   	    if (PredPtr == NULL)
        {
      	      TempPtr = *List;
              *List = TempPtr->Next;
        }
        else
        {
      	     TempPtr = PredPtr->Next;
             PredPtr->Next = TempPtr->Next;
        }
        free(TempPtr);
    }
}

void LinkedTraverse(ListPointer List)
{
	ListPointer CurrPtr;

   if (EmptyList(List))
   	    printf("EMPTY LIST\n");
   else
   {
   	    CurrPtr = List;
   	 //   printf("%p\n",CurrPtr);
         while ( CurrPtr!=NULL ){
             printf("%d ", (*CurrPtr).Data);
             CurrPtr = CurrPtr->Next;
        }
        printf("\n");
   }
}

void LinearSearch(ListPointer List, ListElementType Item, ListPointer *PredPtr, boolean *Found)
{
   ListPointer CurrPtr;
   boolean stop;

   CurrPtr = List;
    *PredPtr=NULL;
   stop= FALSE;
   while (!stop && CurrPtr!=NULL )
    {
         if (CurrPtr->Data==Item )
         	stop = TRUE;
         else
         {
         	*PredPtr = CurrPtr;
            CurrPtr = CurrPtr->Next;
         }
	}
	*Found=stop;
}

void OrderedLinearSearch(ListPointer List, ListElementType Item, ListPointer *PredPtr, boolean *Found)
{
   ListPointer CurrPtr;
   boolean DoneSearching;

   CurrPtr = List;
   *PredPtr = NULL;
   DoneSearching = FALSE;
   *Found = FALSE;
   while (!DoneSearching && CurrPtr!=NULL )
    {
         if (CurrPtr->Data>=Item )
         {
         	DoneSearching = TRUE;
         	*Found = (CurrPtr->Data==Item);
         }
         else
         {
         	*PredPtr = CurrPtr;
            CurrPtr = CurrPtr->Next;
         }
	}
}
