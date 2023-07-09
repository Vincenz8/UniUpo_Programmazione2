#include <stdlib.h>
#include <stdio.h>

void mergesort(int *elementi, int inizio, int fine);
void merge(int *elementi, int inizio, int meta, int fine);


int main()
{
    int v[] = {3, 1, 5, 7, 8, 2, 1, 0};

    mergesort(v, 0, 7);

    for(int i = 0; i < 8; i++)
    {
        printf("%d  ", v[i]);
    }
}

/*mergesort: ordinamento ricorsivo di una lista*/
void mergesort(int *elementi, int inizio, int fine)
{
    int n;

    if (inizio < fine)
    {
        n = (fine + inizio) / 2;

        mergesort(elementi, inizio, n);
        mergesort(elementi, n + 1, fine);
        merge(elementi, inizio, n, fine);
    }
}

void merge(int *elementi, int inizio, int meta, int fine)
{
    int i, j, k;
    int *temp;

    temp = (int *) malloc(sizeof(int) * (fine - inizio + 1));

    i = inizio;
    j = meta+1;
    k = 0;

    while (i <= meta && j <= fine) 
    {
        if (elementi[i]<elementi[j]) 
        {
            temp[k] = elementi[i++];
        } else 
        {
            temp[k] = elementi[j++];
        }
        k++;
    }

    while (i <= meta) 
    {
        temp[k++] = elementi[i++];
    }

    while (j <= fine) 
    {
        temp[k++] = elementi[j++];
    }

    for (k = inizio; k <= fine; k++)
    {
        elementi[k] = temp[k - inizio];
    }

    free(temp);
}