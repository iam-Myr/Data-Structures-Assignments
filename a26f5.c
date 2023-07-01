 #include <stdio.h>
 #include <stdlib.h>

 typedef struct {
     int AM;
     int line;
 }Foithtes;

typedef Foithtes BinTreeElementType;

typedef struct BinTreeNode *BinTreePointer;
typedef struct BinTreeNode {
    BinTreeElementType Data;
    BinTreePointer LChild, RChild;
} BinTreeNode;

typedef enum {
    FALSE, TRUE
} boolean;


void CreateBST(BinTreePointer *Root);
boolean BSTEmpty(BinTreePointer Root);
void RecBSTInsert(BinTreePointer *Root, BinTreeElementType Item);
void RecBSTSearch(BinTreePointer Root, BinTreeElementType KeyValue, boolean *Found, BinTreePointer *LocPtr);
void RecBSTDelete(BinTreePointer *Root, BinTreeElementType KeyValue);
void RecBSTInorder(BinTreePointer Root);
void RecBSTPreorder(BinTreePointer Root);
void RecBSTPostorder(BinTreePointer Root);

int BuildBST(BinTreePointer *Root);
void writeNewStudents(BinTreePointer *Root, int *size);
void printBST(BinTreePointer Root);
void PrintStudent(int recNum);
void printStudentsWithGrade (float theGrade);
char getCharacter();

int main() {
    BinTreePointer ARoot, LocPtr;
    int size;
    BinTreeElementType student;
    boolean found;
    float theGrade;

    //1
    printf("Q1. Build BST from a file\n");
    size = BuildBST(&ARoot);

    //2
    printf("Q2. Print size and BST\n");
    printf("Size=%d\n", size);
    printBST(ARoot);

    //3
    printf("Q3. Write new students, update file and BST\n");
    writeNewStudents(&ARoot, &size);

    //4
    printf("Q4. Print size and BST\n");
    printf("Size=%d\n", size);
    printBST(ARoot);

    //5
    printf("Q5. Search for a student\n");
    printf("Give student's code? ");
    scanf("%d", &student.AM);
    RecBSTSearch(ARoot, student, &found, &LocPtr);
    if(found) {
        PrintStudent(LocPtr->Data.line+1);
    }
    else {
        printf("Student not found\n");
    }

    //6
    printf("Q6. Print size and BST\n");
    printf("Size=%d\n", size);
    printBST(ARoot);

    //7
    printf("Q7. Print students with grades >= given grade\n");
    printf("Give the grade: ");
    scanf("%f", &theGrade);
    printStudentsWithGrade (theGrade);

    return 0;
}

void printBST(BinTreePointer Root) {
    printf("Nodes of BST\n");
    RecBSTInorder(Root);
    printf("\n");
}

int BuildBST(BinTreePointer *Root) {
    FILE *fp;
    int nscan;
    char termch;
    BinTreeElementType student;
    char name[20];
    char surname[20];
    char gender;
    int year;
    float grade;
    BinTreePointer indexRec;
    int size = 0;

    CreateBST(Root);

    fp = fopen("foitites.dat", "r");

    if(fp != NULL) {
        while(TRUE) {
            nscan = fscanf(fp, "%d,%15[^,],%15[^,],%c,%d,%f,%c", &student.AM, name, surname, &gender, &year, &grade, &termch);
            if(nscan == EOF) break;

            student.line = size;
            RecBSTInsert(Root, student);
            size+= 1;
        }
    }    

    fclose(fp);

    return size;
}

void writeNewStudents(BinTreePointer *Root, int *size) {
    FILE *fp;
    BinTreeElementType student;
    BinTreePointer indexRec;
    boolean found;
    BinTreePointer LocPtr;
    char name[20];
    char surname[20];
    char gender;
    int year;
    float grade;

    fp = fopen("foitites.dat", "a");

    if(fp != NULL) {
        while (TRUE)
        {
            printf("Give student's AM? ");
            scanf("%d", &student.AM);
            RecBSTSearch(*Root, student, &found, &LocPtr);
            if(!found) {
                printf("Give student surname? ");
                scanf("%s", surname);
                printf("Give student name? ");
                scanf("%s", name);
                printf("Give student sex F/M? ");
                gender = getCharacter();
                printf("Give student's registration year? ");
                scanf("%d", &year);
                printf("Give student's grade? ");
                scanf("%f", &grade);
                student.line = *size;
                RecBSTInsert(Root, student);
                fprintf(fp, "%d,%s,%s,%c,%d,%.1f\n", student.AM, name, surname, gender, year, grade);
                *size+=1;
                printf("Size=%d\n", *size);

            }
            else {
                printf("Student already exists");
            }

            printf("\nContinue Y/N: ");
            char ans;
            do {
                ans = getchar();
            }while(ans != 'Y' && ans != 'N');

            if(ans == 'N') break;
        }
        fclose(fp);
    }
}


char getCharacter() {
    char x;

    scanf(" %c", &x);

    return x;
}


void PrintStudent(int recNum) {
    FILE *fp;
    char studentDetails[40];
    int lines;

    fp = fopen("foitites.dat", "r");

    if(fp != NULL) {
        for(int i = 1; i <= recNum; i++) {
            fgets(studentDetails, 40, fp);
        }
        printf("%s", studentDetails);
    }

    fclose(fp);
}

void printStudentsWithGrade (float theGrade) {
    FILE *fp;
    int nscan;
    char termch;
    BinTreeElementType student;
    char name[20];
    char surname[20];
    char gender;
    int year;
    float grade;
    BinTreePointer indexRec;
    int size = 0;

    fp = fopen("foitites.dat", "r");

    if(fp != NULL) {
        while(TRUE) {
            nscan = fscanf(fp, "%d,%15[^,],%15[^,],%c,%d,%f,%c", &student.AM, name, surname, &gender, &year, &grade, &termch);
            if(nscan == EOF) break;

            if(grade >= theGrade) {
                printf("%d, %s, %s, %c, %d, %.1f\n", student.AM, name, surname, gender, year, grade, termch);
            }
        }
    }    

    fclose(fp);
}


//Given Functions

void CreateBST(BinTreePointer *Root)
{
    *Root = NULL;
}

boolean BSTEmpty(BinTreePointer Root)
{
    return (Root==NULL);
}

void RecBSTInsert(BinTreePointer *Root, BinTreeElementType Item)
{
    if (BSTEmpty(*Root)) {
        (*Root) = (BinTreePointer)malloc(sizeof (struct BinTreeNode));
        (*Root) ->Data = Item;
        (*Root) ->LChild = NULL;
        (*Root) ->RChild = NULL;
    }
    else
        if (Item.AM < (*Root) ->Data.AM)
            RecBSTInsert(&(*Root) ->LChild,Item);
        else if (Item.AM > (*Root) ->Data.AM)
            RecBSTInsert(&(*Root) ->RChild,Item);
        else
            printf("TO STOIXEIO EINAI HDH STO DDA\n");
}

void RecBSTSearch(BinTreePointer Root, BinTreeElementType KeyValue, boolean *Found, BinTreePointer *LocPtr)
{
    if (BSTEmpty(Root))
        *Found=FALSE;
    else
        if (KeyValue.AM < Root->Data.AM)
            RecBSTSearch(Root->LChild, KeyValue, &(*Found), &(*LocPtr));
        else
            if (KeyValue.AM > Root->Data.AM)
                RecBSTSearch(Root->RChild, KeyValue, &(*Found), &(*LocPtr));
            else
                {
                    *Found = TRUE;
                    *LocPtr=Root;
                }
}

void RecBSTDelete(BinTreePointer *Root, BinTreeElementType KeyValue)
{

   BinTreePointer TempPtr;

    if (BSTEmpty(*Root))
        printf("TO STOIXEIO DEN BRE8HKE STO DDA\n");
     else
          if (KeyValue.AM < (*Root)->Data.AM)
             RecBSTDelete(&((*Root)->LChild), KeyValue);
          else
            if (KeyValue.AM > (*Root)->Data.AM)
                  RecBSTDelete(&((*Root)->RChild), KeyValue);
            else
                if ((*Root)->LChild ==NULL)
                 {
                      TempPtr = *Root;
                      *Root = (*Root)->RChild;
                      free(TempPtr);
                 }
                else if ((*Root)->RChild == NULL)
                   {
                        TempPtr = *Root;
                        *Root = (*Root)->LChild;
                        free(TempPtr);
                   }
                   else
                   {
                        TempPtr = (*Root)->RChild;
                        while (TempPtr->LChild != NULL)
                              TempPtr = TempPtr->LChild;
                        (*Root)->Data = TempPtr->Data;
                        RecBSTDelete(&((*Root)->RChild), (*Root)->Data);
                   }
}

void RecBSTInorder(BinTreePointer Root)
{
    if (Root!=NULL) {
    //    printf("L");
        RecBSTInorder(Root->LChild);
        printf("(%d, %d), ",Root->Data.AM, Root->Data.line);
    //    printf("R");
        RecBSTInorder(Root->RChild);
    }
   // printf("U");
}

void RecBSTPreorder(BinTreePointer Root)
{
    if (Root!=NULL) {
        printf("(%d, %d), ",Root->Data.AM, Root->Data.line);
       // printf("L");
        RecBSTPreorder(Root->LChild);
      //  printf("R");
        RecBSTPreorder(Root->RChild);
    }
   // printf("U");
}

void RecBSTPostorder(BinTreePointer Root)
{
    if (Root!=NULL) {
      //  printf("L");
        RecBSTPostorder(Root->LChild);
     //   printf("R");
        RecBSTPostorder(Root->RChild);
        printf("(%d, %d), ",Root->Data.AM, Root->Data.line);
    }
   // printf("U");
}
