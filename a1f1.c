#include <math.h>
#include <stdio.h>
#define megisto_plithos 200

typedef enum {
    FALSE, TRUE
} boolean;

typedef boolean typos_synolou[megisto_plithos+1];
typedef int stoixeio_synolou;

void Dimiourgia(typos_synolou synolo);
void Eisagogi(stoixeio_synolou stoixeio, typos_synolou synolo);
boolean Melos(stoixeio_synolou stoixeio, typos_synolou synolo);

boolean isPrime(stoixeio_synolou n);
void createPrimeSet(typos_synolou s, stoixeio_synolou first, stoixeio_synolou last);

main()
{
    typos_synolou synolo;
    stoixeio_synolou first, last, n;

    do
    {
        printf("Enter first number (must be between [2...200)): ");
        scanf("%d", &first);
    }
    while (first < 2 || first >=200);

    do
    {
        printf("Enter last number (must be between [2...200]): ");
        scanf("%d", &last);
    }
    while (last < first || (last < 2 || last > 200));

    createPrimeSet(synolo, first, last);
    displaySet(synolo,first, last);

    system("PAUSE");
}

boolean isPrime(stoixeio_synolou n){
    stoixeio_synolou i, limit;

    if (n == 2){
        return TRUE;
    }
    else if (n%2 == 0){
        return FALSE;
    }

    //Number n is prime if it doesn't have a divisor till sqrt(n)
    limit = sqrt(n);
    for (i = 2; i < limit+1; i++)
    {
        if (n != i && n%i == 0)
            return FALSE;
    }
    return TRUE;
}

void createPrimeSet(typos_synolou s, stoixeio_synolou first, stoixeio_synolou last){
    stoixeio_synolou i;

    Dimiourgia(s);

    for (i = first; i < last+1; i++){
        if (isPrime(i))
            Eisagogi(i,s);
    }
}

void displaySet(typos_synolou set, stoixeio_synolou first, stoixeio_synolou last){
    stoixeio_synolou i;

    for (i = first; i < last+1; i++){
        if (Melos(i,set))
             printf("%d ", i);
    }
}

void Dimiourgia(typos_synolou synolo){
    stoixeio_synolou i;

    for (i = 0; i < megisto_plithos; i++)
        synolo[i] = FALSE;

}

void Eisagogi(stoixeio_synolou stoixeio, typos_synolou synolo)
{
    synolo[stoixeio] = TRUE;
}

boolean Melos(stoixeio_synolou stoixeio, typos_synolou synolo)
{
    return synolo[stoixeio];
}

