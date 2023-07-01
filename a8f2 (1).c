#include <stdio.h>

#define StackLimit 50

typedef char StackElementType;

typedef struct  {
    int Top;
    StackElementType Element[StackLimit];
} StackType;

typedef enum {
    FALSE, TRUE
} boolean;

void CreateStack(StackType *Stack);
boolean EmptyStack(StackType Stack);
boolean FullStack(StackType Stack);
void Push(StackType *Stack, StackElementType Item);
void Pop(StackType *Stack, StackElementType *Item);


 int main() {

    boolean valid, flag;
    StackType Stack;
    StackElementType x,item;

    CreateStack(&Stack);
    valid=TRUE;
    flag=FALSE;

    printf("Enter string:\n");
    scanf("%c", &x); fflush(stdin);

    if (x=='#') return 0;

    while(x!='#' && valid){

        if (!flag){
            if (x=='C') flag=TRUE;
            else Push(&Stack, x);
            scanf("%c", &x); fflush(stdin);

        }
        else {
            if (!EmptyStack(Stack)){
                Pop(&Stack, &item);
                if (item!=x) valid=FALSE;
                else {scanf(" %c", &x); fflush(stdin);}
            }
        }
    }


    if (valid && EmptyStack(Stack)) printf("TRUE");
    else printf("FALSE");

    return 0;
 }


void CreateStack(StackType *Stack)
/* LEITOYRGIA: DHMIOYRGEI MIA KENH STOIBA.
   EPISTREFEI: MIA KENH STOIBA *)
*/
{
    Stack -> Top = -1;
   // (*Stack).Top = -1;
}

boolean EmptyStack(StackType Stack)
/* DEXETAI:    MIA STOIBA Stack.
   LEITOYRGIA: ELEGXEI AN H STOIBA Stack EINAI KENH.
   EPISTREFEI: TRUE AN H Stack EINAI KENH, FALSE DIAFORETIKA. */
{
    return (Stack.Top == -1);
}

boolean FullStack(StackType Stack)
/* DEXETAI:    MIA STOIBA Stack.
   LEITOYRGIA: ELEGXEI AN H STOIBA Stack EINAI GEMATH.
   EPISTREFEI: TRUE AN H STOIBA Stack EINAI GEMATH, FALSE DIAFORETIKA. */
{
    return (Stack.Top == (StackLimit - 1));
}

void Push(StackType *Stack, StackElementType Item)
/* DEXETAI:    MIA STOIBA Stack KAI TO STOIXEIO Item.
   LEITOYRGIA: EISAGEI STH KORYFH THS STOIBAS Stack, AN DEN EINAI GEMATH,
               TO STOIXEIO Item.
   EPISTREFEI: THN TROPOPOIHMENH STOIBA Stack.
   EJODOS:     MHNYMA GEMATHS STOIBAS, AN H STOIBA EINAI GEMATH. */
{
    if (!FullStack(*Stack)) {
        Stack -> Top++;
        Stack -> Element[Stack -> Top] = Item;
    } else
        printf("Full Stack...");
}

void Pop(StackType *Stack, StackElementType *Item)
/* DEXETAI:    MIA STOIBA Stack.
   LEITOYRGIA: AFAIREI APO TH KORYFH THS STOIBAS Stack, AN DEN EINAI KENH,
               TO STOIXEIO Item.
   EPISTREFEI: TO STOIXEIO Item KAI THN TROPOPOIHMENH STOIBA Stack
   EJODOS:     MHNYMA KENHS STOIBAS, AN H STOIBA EINAI KENH. */
{
    if (!EmptyStack(*Stack)) {
        *Item = Stack -> Element[Stack -> Top];
        Stack -> Top--;
    } else
        printf("Empty Stack...");

}

