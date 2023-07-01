#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HMax 9

#define VMax 30

#define EndOfList -1


typedef struct {
    char name[11];
    char surname[21];
    char telephone[11];
    int code;
} teacherT;

typedef struct {
    char str[40];
}String;

typedef teacherT ListElementType;

typedef String KeyType;

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


void buildHashList(HashListType *HList);
void PrintPinakes(HashListType HList);
void getKey(char key[], char name[], char surname[]);
char getCharacter();
void Search_HashList_By_Subject(HashListType HList, int code);

int main() {
    HashListType myHashList;
    ListElm temp;
    char x;
    int Loc, Pred;

    //Question 1
    printf("1. BuildHashList\n");
    CreateHashList(&myHashList);
    buildHashList(&myHashList);
    PrintPinakes(myHashList);

    //Question 2
    printf("2. Insert new teacher\n");

    do {
        printf("Enter teacher's name: ");
        scanf("%s", &temp.Data.name);

        printf("Enter teacher's surname: ");
        scanf("%s", &temp.Data.surname);

        printf("Enter teacher's phone: ");
        scanf("%s", &temp.Data.telephone);

        printf("Enter teacher code: ");
        scanf("%d", &temp.Data.code);

        getKey(temp.RecKey.str, temp.Data.name, temp.Data.surname);

        AddRec(&myHashList, temp);

        printf("\nContinue Y/N: ");
        do {
            x = getCharacter();
        } while(x != 'y' && x != 'n');

    }while(x == 'y');
    PrintPinakes(myHashList);


    //Question 3
    printf("3. Delete a teacher\n");

    printf("Enter teacher's name: ");
    scanf("%s", &temp.Data.name);
    printf("Enter teacher's surname: ");
    scanf("%s", &temp.Data.surname);

    getKey(temp.RecKey.str, temp.Data.name, temp.Data.surname);

    SearchHashList(myHashList, temp.RecKey, &Loc, &Pred);

    if(Loc == -1) {
        printf("DEN YPARXEI EGGRAFH ME KLEIDI %s\n", temp.RecKey.str);
    }
    else {
        DeleteRec(&myHashList, temp.RecKey);
    }
    PrintPinakes(myHashList);

    //Question 4
    printf("4. Search for a teacher\n");

    printf("Enter teacher's name: ");
    scanf("%s", &temp.Data.name);
    printf("Enter teacher's surname: ");
    scanf("%s", &temp.Data.surname);

    getKey(temp.RecKey.str, temp.Data.name, temp.Data.surname);

    SearchHashList(myHashList, temp.RecKey, &Loc, &Pred);

    if(Loc == -1) {
        printf("DEN YPARXEI EGGRAFH ME KLEIDI %s\n", temp.RecKey.str);
    }
    else {
        printf("[%s, %s, %d]\n", temp.RecKey.str, myHashList.List[Loc].Data.telephone, myHashList.List[Loc].Data.code);
    }

    //Question 5
    printf("\n5. Search by subject\n");
    printf("Enter code: ");
    scanf("%d", &temp.Data.code);
    Search_HashList_By_Subject(myHashList, temp.Data.code);

    return 0;
}


char getCharacter() {
    char x;

    scanf(" %c", &x);

    return x;
}


void buildHashList(HashListType *HList) {
    FILE *fp;
    int nscan;
    char termch;
    ListElm teacher;

    fp = fopen("i4f6.txt", "r");

    if(fp != NULL) {
        while(TRUE) {
            String temp;
            int j = 0;

            nscan = fscanf(fp, "%10[^,],%20[^,],%10[^,],%d%c", &teacher.Data.name, &teacher.Data.surname, &teacher.Data.telephone, &teacher.Data.code, &termch);
            if(nscan == EOF) break;
            if(termch != '\n') printf("Error\n");
            else {
                getKey(teacher.RecKey.str, teacher.Data.name, teacher.Data.surname);

                AddRec(HList, teacher);
            }
        }
    }    

    fclose(fp);
}


 void getKey(char key[], char name[], char surname[]) {
     int j = 0;

     for(int i = 0; i < strlen(name); i++) {
                    key[j] = name[i];
                    j += 1;
                }

                key[j] = ' ';
                j += 1;

                for(int i = 0; i < strlen(surname); i++) {
                    key[j] = surname[i];
                    j += 1;
                }

                key[j] = '\0';
 }

int findAverage(KeyType hielu) {
    int firsti, lasti;

    firsti = hielu.str[0];

    lasti = hielu.str[strlen(hielu.str) - 1];

    if(firsti >= 97) firsti -= 32;
    if(lasti >= 97) lasti -= 32;

    firsti -= 64;
    lasti -= 64;

    return (firsti + lasti) / 2;
}


void PrintPinakes(HashListType HList)
{
    int i;
	printf("Hash table\n");
	for (i=0; i<HMax;i++)
              printf("%d, ",HList.HashTable[i]);

	printf("\nHash List\n");
    for (i=0;i<HList.Size;i++)
	   printf("%d) %s, %d\n",i,HList.List[i].RecKey.str,HList.List[i].Link);
	printf("\n");
}


void Search_HashList_By_Subject(HashListType HList, int code) {
    int i, SubIndex;

    printf("List of teachers with subject code %d:\n", code);
    for (i=0; i<HMax;i++)
          {
              SubIndex = HList.HashTable[i];
              while ( SubIndex != EndOfList )
              {
                  if(HList.List[SubIndex].Data.code == code)
                    printf("%d: [%s, %s, %d]\n", SubIndex, HList.List[SubIndex].RecKey.str ,HList.List[SubIndex].Data.telephone, HList.List[SubIndex].Data.code);

                   SubIndex = HList.List[SubIndex].Link;
               }
          }
}

//Given functions

int HashKey(KeyType Key)
{
    int hello = findAverage(Key);
	return hello%HMax;
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
		if (strcmp(HList.List[Next].RecKey.str, KeyArg.str) == 0)
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