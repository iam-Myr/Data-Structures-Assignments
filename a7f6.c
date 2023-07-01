#include <stdio.h>
#include <stdlib.h>


#define HMax 5

#define VMax 30

#define EndOfList -1

typedef int KeyType;

typedef struct {
    char name[20];
    int cost;
}GymT;

typedef GymT ListElementType;

typedef struct {
	KeyType RecKey;
	ListElementType Data;
	int Link;
} ListElm;

typedef struct  {
	int HashTable[HMax];
    int Size;
	int SubListPtr;
    int StackPtr;
	ListElm List[VMax];
} HashListType;

typedef enum {
    FALSE, TRUE
} boolean;

void CreateHashList(HashListType *HList);
int HashKey(KeyType Key);
boolean FullHashList(HashListType HList);
void SearchSynonymList(HashListType HList,KeyType KeyArg,int *Loc,int *Pred);
void SearchHashList(HashListType HList,KeyType KeyArg,int *Loc,int *Pred);
void AddRec(HashListType *HList,ListElm InRec);
void DeleteRec(HashListType *HList,KeyType DelKey);

void Print_HashList(HashListType HList);
void PrintPinakes(HashListType HList);
void PrintListOfSynonyms(HashListType HList, KeyType key);
char getCharacter();
ListElm getListElm();


int main() {
    HashListType myHashList;
    ListElm temp;
    char ans;
    KeyType k;
    int Loc, Pred, ammountOfCash;

    //Question 1
    printf("1. Create hashlist\n");
    CreateHashList(&myHashList);
    Print_HashList(myHashList);
    PrintPinakes(myHashList);

    //Question 2
    printf("2. Insert new member\n");

    do {
        temp = getListElm();
        AddRec(&myHashList, temp);
        printf("\n");

        printf("Continue Y/N: ");

        do {
            ans = getCharacter();
        }while(ans != 'Y' && ans != 'N');
    }while(ans == 'Y');

    Print_HashList(myHashList);
    PrintPinakes(myHashList);

    //Question 3
    printf("3. Search for a member\n");

    do
    {
        printf("Give code: ");
        scanf("%d", &k);
        SearchHashList(myHashList, k, &Loc, &Pred);
        if(Loc != -1) {
             printf("[%d, %s, %d, %d]\n",myHashList.List[Loc].RecKey,myHashList.List[Loc].Data.name, myHashList.List[Loc].Data.cost, myHashList.List[Loc].Link);
        }
        else {
            printf("DEN YPARXEI EGGRAFH ME KLEIDI %d\n", k);
        }

        printf("\nContinue Y/N: ");
        do {
            ans = getCharacter();
        }while(ans != 'Y' && ans != 'N');

    } while (ans != 'N');

    printf("4. Update member amount\n");

    do {
        printf("Give code: ");
        scanf("%d", &k);
        SearchHashList(myHashList, k, &Loc, &Pred);

        if(Loc != -1) {
            printf("[%d, %s, %d, %d]\n",myHashList.List[Loc].RecKey,myHashList.List[Loc].Data.name, myHashList.List[Loc].Data.cost, myHashList.List[Loc].Link);

            printf("Give amount: ");
            scanf("%d", &ammountOfCash);

            if(myHashList.List[Loc].Data.cost >= ammountOfCash) {
                myHashList.List[Loc].Data.cost -= ammountOfCash;
            }
        }
        else {
            printf("DEN YPARXEI EGGRAFH ME KLEIDI %d", k);
        }
        printf("\nContinue Y/N: ");

        do {
            ans =getCharacter();
        }while(ans != 'Y' && ans != 'N');

    }while(ans == 'Y');
    Print_HashList(myHashList);
    PrintPinakes(myHashList);

    //Question 5
    printf("5. Delete a member\n");
    do
    {
        printf("Give code: ");
        scanf("%d", &k);
        SearchHashList(myHashList, k, &Loc, &Pred);
        if(Loc != -1) {
             if(myHashList.List[Loc].Data.cost <= 0)
                 DeleteRec(&myHashList, Loc);
             else
                 printf("Not deleted arrange amount\n");
        }
        else {
            printf("DEN YPARXEI EGGRAFH ME KLEIDI %d\n", k);
        }

        printf("\nContinue Y/N: ");
        do {
            ans = getCharacter();
        }while(ans != 'Y' && ans != 'N');

    } while (ans != 'N');
    Print_HashList(myHashList);
    PrintPinakes(myHashList);
    
    //Question 6
    printf("6. Print list of synonyms\n");
    do {
        printf("Give code: ");
        scanf("%d", &k);
        SearchHashList(myHashList, k, &Loc, &Pred);

        if(Loc != -1) {
            printf("[%d, %s, %d, %d]\n",myHashList.List[Loc].RecKey,myHashList.List[Loc].Data.name, myHashList.List[Loc].Data.cost, myHashList.List[Loc].Link);
            PrintListOfSynonyms(myHashList, k);
        }
        else {
            printf("DEN YPARXEI EGGRAFH ME KLEIDI %d", k);
        }
        printf("\nContinue Y/N: ");

        do {
            ans =getCharacter();
        }while(ans != 'Y' && ans != 'N');

    }while(ans == 'Y');


    return 0;
}


char getCharacter() {
    char x;

    scanf(" %c", &x);

    return x;
}


ListElm getListElm() {
    ListElm x;

    printf("Give code: ");
    scanf("%d", &x.RecKey);

    printf("Give name: ");
    scanf("%s", &x.Data.name );

    printf("Give amount: ");
    scanf("%d", &x.Data.cost);

    return x;
}

void PrintListOfSynonyms(HashListType HList, KeyType key) {
    KeyType SubIndex, Hval;

    Hval = HashKey(key);

    SubIndex = HList.HashTable[Hval];
    while ( SubIndex != EndOfList )
    {
        printf("%d: [%d, %s, %d]\n",SubIndex, HList.List[SubIndex].RecKey,HList.List[SubIndex].Data.name, HList.List[SubIndex].Data.cost);
        SubIndex = HList.List[SubIndex].Link;
    }
}


//Given functions

void PrintPinakes(HashListType HList)
{
    int i;
	printf("Hash table\n");
	for (i=0; i<HMax;i++)
              printf("%d| %d\n",i,HList.HashTable[i]);

	printf("Hash List\n");
    for (i=0;i<HList.Size;i++)
	   printf("%d) %d, %s, %d, %d\n",i,HList.List[i].RecKey, HList.List[i].Data.name, HList.List[i].Data.cost, HList.List[i].Link);
	printf("\n");
}

void Print_HashList(HashListType HList)
{
   int i, SubIndex;

     printf("HASHLIST STRUCTURE with SYNONYM CHAINING\n");
     printf("========================================\n");

          printf("PINAKAS DEIKTWN STIS YPO-LISTES SYNWNYMWN EGGRAFWN:\n");
            for (i=0; i<HMax;i++)
              printf("%d| %d\n",i,HList.HashTable[i]);

          printf("OI YPO-LISTES TWN SYNWNYMWN EGGRAFWN:\n");
          for (i=0; i<HMax;i++)
          {
              SubIndex = HList.HashTable[i];
              while ( SubIndex != EndOfList )
              {
                   printf("[%d, %s, %d, %d]",HList.List[SubIndex].RecKey,HList.List[SubIndex].Data.name, HList.List[SubIndex].Data.cost, HList.List[SubIndex].Link);
                   printf(" -> ");
                   SubIndex = HList.List[SubIndex].Link;
               } //* while *)
              printf("TELOS % dHS YPO-LISTAS\n", i);
          }

          /*printf("H STOIBA TWN ELEY8ERWN 8ESEWN THS LISTAS:\n");
          SubIndex = HList.StackPtr;
          while ( SubIndex != EndOfList )
          {
                printf("%d <= ",SubIndex);
                SubIndex = HList.List[SubIndex].Link;
          }
          printf("TELOS\n"); */

          printf("MEGE8OS THS LISTAS = %d\n", HList.Size);
          printf("========================================\n");
}


int HashKey(KeyType Key)
{
	return Key%HMax;
}

void CreateHashList(HashListType *HList)
{
	int index;

	HList->Size=0;
	HList->StackPtr=0;

    index=0;
	while (index<HMax)
	{
		HList->HashTable[index]=EndOfList;
		index=index+1;
    }

    index=0;
	while(index < VMax-1)
	{
		HList->List[index].Link=index+1;
		index=index+1;
	}
	HList->List[index].Link=EndOfList;
}

boolean FullHashList(HashListType HList)
{
	return(HList.Size==VMax);
}

void SearchSynonymList(HashListType HList,KeyType KeyArg,int *Loc,int *Pred)
{
	int Next;
	Next=HList.SubListPtr;
	*Loc=-1;
	*Pred=-1;
	while(Next!=EndOfList)
	{
		if (HList.List[Next].RecKey==KeyArg)
		{
			*Loc=Next;
			Next=EndOfList;
		}
		else
		{
			*Pred=Next;
			Next=HList.List[Next].Link;
		}
	}
}
void SearchHashList(HashListType HList,KeyType KeyArg,int *Loc,int *Pred)
{
	int HVal;
	HVal=HashKey(KeyArg);
    if (HList.HashTable[HVal]==EndOfList)
	{
		*Pred=-1;
		*Loc=-1;
	}
	else
	{
		HList.SubListPtr=HList.HashTable[HVal];
		SearchSynonymList(HList,KeyArg,Loc,Pred);
	}
}

void AddRec(HashListType *HList,ListElm InRec)
{
	int Loc, Pred, New, HVal;

   // New=0;
	if(!(FullHashList(*HList)))
	{
		Loc=-1;
		Pred=-1;
		SearchHashList(*HList,InRec.RecKey,&Loc,&Pred);
		if(Loc==-1)
		{
			HList->Size=HList->Size +1;
			New=HList->StackPtr;
			HList->StackPtr=HList->List[New].Link;
			HList->List[New]=InRec;
			if (Pred==-1)
			{
			    HVal=HashKey(InRec.RecKey);
                HList->HashTable[HVal]=New;
				HList->List[New].Link=EndOfList;
			}
			else
			{
                HList->List[New].Link=HList->List[Pred].Link;
				HList->List[Pred].Link=New;
			}
		}

		else
		{
			printf("YPARXEI HDH EGGRAFH ME TO IDIO KLEIDI \n");
		}
	}
	else
	{
		printf("Full list...");
	}
}
void DeleteRec(HashListType *HList,KeyType DelKey)
{
	int Loc, Pred, HVal;

	SearchHashList(*HList,DelKey,&Loc,&Pred);
	if(Loc!=-1)
	{
		if(Pred!=-1)
		{
			HList->List[Pred].Link=HList->List[Loc].Link;
		}
		else
		{
			HVal=HashKey(DelKey);
		    HList->HashTable[HVal]=HList->List[Loc].Link;
		}
		HList->List[Loc].Link=HList->StackPtr;
		HList->StackPtr=Loc;
		HList->Size=HList->Size -1;
	}
	else
	{
		printf("DEN YPARXEI  EGGRAFH ME KLEIDI %d \n",DelKey);
	}
}