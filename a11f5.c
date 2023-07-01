#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef char BinTreeElementType[20];        /*� ����� ��� ��������� ��� ���
                                        ���������� ����� int */
typedef struct BinTreeNode *BinTreePointer;
 struct BinTreeNode {
    BinTreeElementType Data;
    BinTreePointer LChild, RChild;
} ;

typedef enum {
    FALSE, TRUE
} boolean;


void CreateBST(BinTreePointer *Root);
boolean EmptyBST(BinTreePointer Root);
void BSTInsert(BinTreePointer *Root, BinTreeElementType Item);
void BSTSearch(BinTreePointer Root, BinTreeElementType KeyValue, boolean *Found, BinTreePointer *LocPtr);
void BSTSearch2(BinTreePointer Root, BinTreeElementType KeyValue, boolean *Found, BinTreePointer *LocPtr, BinTreePointer *Parent);
void BSTDelete(BinTreePointer *Root, BinTreeElementType KeyValue);
void InorderTraversal(BinTreePointer Root);

void CreateDictionary(BinTreePointer *Root, FILE *fp);
int SpellingCheck(BinTreePointer Root, FILE *fp);
void printmee(BinTreePointer tree);


int main() {
    FILE *fp1, *fp2;
    BinTreePointer myTree;
    int notInWords;

    fp1 = fopen("i112f5.txt", "r");
    fp2 = fopen("i111f5.txt", "r");

    CreateBST(&myTree);

    CreateDictionary(&myTree, fp1);

    printf("**********Dictionary**********\n");
    InorderTraversal(myTree);

    printf("\n**********Not in Dictionary**********\n");
    notInWords = SpellingCheck(myTree, fp2);
    printf("Number of words not in Dictionary: %d", notInWords);

    fclose(fp1);
    fclose(fp2); 
    return 0;
}



void CreateDictionary(BinTreePointer *Root, FILE *fp) {
    BinTreeElementType item;

    while(!feof(fp)) {
        fscanf(fp, "%s", item);

        BSTInsert(Root, item);
    }
}


int SpellingCheck(BinTreePointer Root, FILE *fp) {
    BinTreeElementType item;
    BinTreePointer LocPtr, Parent;
    int x = 0;
    boolean found;

    while(!feof(fp)) {
        fscanf(fp, "%s", item);

        BSTSearch2(Root, item, &found, &LocPtr, &Parent);
        if(!found) {
            x++;
            printf("%s\n", item);
        }
    }

    return x;
}

//Given Functions

void CreateBST(BinTreePointer *Root)
{
    *Root = NULL;
}

boolean EmptyBST(BinTreePointer Root)
{   
    return (Root==NULL);
}

void BSTInsert(BinTreePointer *Root, BinTreeElementType Item)
{
    BinTreePointer LocPtr, Parent;
    boolean Found;

    LocPtr = *Root;
    Parent = NULL;
    Found = FALSE;
    while (!Found && LocPtr != NULL) {
        Parent = LocPtr;
        if ( strcmp( Item, LocPtr->Data) < 0 )
            LocPtr = LocPtr ->LChild;
        else if ( strcmp( Item, LocPtr->Data) > 0 )
            LocPtr = LocPtr ->RChild;
        else
            Found = TRUE;
    }
    if (Found)
        printf("To %d EINAI HDH STO DDA\n", Item);
    else {
        LocPtr = (BinTreePointer)malloc(sizeof (struct BinTreeNode));
        strcpy(LocPtr ->Data, Item);
        LocPtr ->LChild = NULL;
        LocPtr ->RChild = NULL;
        if (Parent == NULL)
            *Root = LocPtr;
        else if (strcmp( Item, Parent->Data) < 0)
            Parent ->LChild = LocPtr;
        else
            Parent ->RChild = LocPtr;
    }
}

void BSTSearch(BinTreePointer Root, BinTreeElementType KeyValue, boolean *Found, BinTreePointer *LocPtr)
{

    (*LocPtr) = Root;
    (*Found) = FALSE;
    while (!(*Found) && (*LocPtr) != NULL)
    {
        if (strcmp(KeyValue, (*LocPtr)->Data) < 0)
            (*LocPtr) = (*LocPtr)->LChild;
        else
            if (strcmp(KeyValue, (*LocPtr)->Data) > 0)
                (*LocPtr) = (*LocPtr)->RChild;
            else (*Found) = TRUE;
    }
}

void BSTSearch2(BinTreePointer Root, BinTreeElementType KeyValue, boolean *Found,
    BinTreePointer *LocPtr, BinTreePointer *Parent)
/* �������:    ��� ��� �� �� ������ Root �� ������� ��� ���� ��� ��� ��� ���� KeyValue.
   ����������: ������� ��� ��� ���� ����� �� ���� KeyValue ��� ����� ������ ���
                ��� ��� ������ ��� ������ �����.
   ����������: � Found ���� ���� TRUE, � ������� LocPtr ������� ���� ����� ���
                �������� ��� ���� KeyValue ��� � Parent ������� ���� ������
                ����� ��� ������, �� � ��������� ����� ��������.
                ����������� � Found ���� ���� FALSE.
*/
{
    *LocPtr = Root;
    *Parent=NULL;
    *Found = FALSE;
    while (!(*Found) && *LocPtr != NULL)
    {
        if (strcmp(KeyValue, (*LocPtr)->Data) < 0) {
            *Parent=*LocPtr;
            *LocPtr = (*LocPtr)->LChild;
        }
        else
            if (strcmp(KeyValue, (*LocPtr)->Data) > 0) {
                *Parent=*LocPtr;
                *LocPtr = (*LocPtr)->RChild;
            }
            else *Found = TRUE;
    }

}

void BSTDelete(BinTreePointer *Root, BinTreeElementType KeyValue)
/* �������:  ��� ��� �� �� ������ Root �� ������� ��� ���� ��� ��� ��� ���� KeyValue.
  ����������: ��������� �� ���� ���� ����� ��� ��� ��� �� �������� ��� ����
                KeyValue ��� ����� ������ ��� �������� ��������� ��� ���,
                �� ��� ����, ��� ��������� ��� �� ���.
  ����������: �� ������������� ��� �� ��� ������ Root �� ������� ��� ���� ���.
*/
{

   BinTreePointer
   n,                   //������� ���� ����� ��� �������� ��� ���� KeyValue *)
   Parent,              // ������� ��� n � ��� nNext
   nNext,               // ����������������� �������� ��� n
   SubTree;             // ������� ���� ��������� ��� n
   boolean Found;       // TRUE AN TO �������� KeyValue EINAI ������� ��� ��� *)

     BSTSearch2(*Root, KeyValue, &Found , &n, &Parent);
     if (!Found)
        printf("TO STOIXEIO %d DEN EINAI STO DDA\n", KeyValue);
     else {
          if (n->LChild != NULL && n->RChild != NULL)
          {  // ������ ���� �������� �� ��� ������
                 //���� ��� ���������������� ������� ��� ��� ������ ���
                 nNext = n->RChild;
                 Parent = n;
                 while (nNext->LChild !=NULL)  //* DIASXISH PROS TA ARISTERA *)
                 {
                      Parent = nNext;
                      nNext = nNext->LChild;
                 }
                /* ��������� ��� ������������ ��� nNext ���� n ���
                ������ ��� n ���� �� ������� ���� ������� */
                strcpy(n->Data, nNext->Data);
                n = nNext;
          }
          SubTree = n->LChild;
          if (SubTree == NULL)
             SubTree = n->RChild;
          if (Parent == NULL)                 //* 8A DIAGRAFEI H RIZA *)
             *Root = SubTree;
          else if (Parent->LChild == n)
                  Parent->LChild = SubTree;
               else
                   Parent->RChild = SubTree;
          free(n);
     }
}

void InorderTraversal(BinTreePointer Root)
{
    if (Root!=NULL) {
        InorderTraversal(Root->LChild);
        printf("%s\n",Root->Data);
        InorderTraversal(Root->RChild);
    }
}