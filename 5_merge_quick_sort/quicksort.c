#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void quicksort(int *elementi, int inizio, int fine);
int partition(int *elementi, int inizio, int fine);
void swap(int *n1, int *n2);


int main()
{
    int elementi[] = {2, 1, 4, 3, 6, 8};
    
    quicksort(elementi, 0, 5);

    for (int i = 0; i <= 5; i++)
    {
        printf("%d ", elementi[i]);
    }
}

void quicksort(int *elementi, int inizio, int fine)
{
    int cardine;

    if (inizio < fine)
    {
        srand(time(0)),
        cardine = partition(elementi, inizio, fine);
        quicksort(elementi, inizio, cardine - 1);
        quicksort(elementi, cardine + 1, fine);
    }
}

int partition(int *elementi, int inizio, int fine)
{
    int cardine;
    int i_cardine;
    int i, j;

    i_cardine = inizio + (rand() % (fine - inizio));
    swap(elementi + i_cardine, elementi + fine);
    cardine = elementi[fine];

    i = 0;

    for (j = 0; j < fine; j++)
    {
        if (elementi[j] <= cardine)
        {
            swap(elementi + i, elementi + j);
            i++;
        }
    }
    swap(elementi + i, elementi + fine);
    return i;
}

void swap(int *n1, int *n2)
{
    int tmp;

    tmp = *n1;
    *n1 = *n2;
    *n2 = tmp;
}