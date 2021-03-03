#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define megisto_plithos 1000

typedef enum {
    FALSE, TRUE
} boolean;

typedef boolean typos_synolou[megisto_plithos+1];
typedef int stoixeio_synolou;

void Dimiourgia(typos_synolou synolo);
boolean isFibonacci(stoixeio_synolou n, typos_synolou synolo);
void createFibonacciSet(stoixeio_synolou threshold, typos_synolou synolo);
void displayset(typos_synolou set);

main()
{
    typos_synolou Fibo;
    stoixeio_synolou max, n;

    do
    {
        printf("Please enter the max element (must be between [2..200)): ");
        scanf("%d", &max);
    }
    while (max < 2 || max > 1000);

    createFibonacciSet(max, Fibo);
    displayset(Fibo);

    do
    {
        printf("Enter number to check: ");
        scanf("%d", &n);
        if (n >= 0 && n <=1000){
            if (isFibonacci(n, Fibo))
                printf("Fibonacci!\n");
            else
                printf("Not Fibonacci...\n");
        }
    }while(n > 0);

    system("PAUSE");
}

void displayset(typos_synolou set)
{
	stoixeio_synolou i = 0;

	while(i <= megisto_plithos)
	{
		if((set[i]))
			printf("%d ", i);
		i++;
	}
	printf("\n");
}

void Dimiourgia(typos_synolou synolo)
{
    stoixeio_synolou i;

    for (i = 1; i <= megisto_plithos; i++)
        synolo[i] = FALSE;
}

void Eisagogi(stoixeio_synolou stoixeio, typos_synolou synolo)
{
    synolo[stoixeio] = TRUE;
}

boolean isFibonacci(stoixeio_synolou n, typos_synolou synolo)
{
    return synolo[n];
}

void createFibonacciSet(stoixeio_synolou threshold, typos_synolou synolo)
{
    stoixeio_synolou f1, f2, k;

    Dimiourgia(synolo);

    f1 = 0;
    f2 = 1;

    while (f1 <= threshold)
    {
        Eisagogi(f1,synolou);
        f1 += f2;
        f2 = f1 - f2;
    }
}
