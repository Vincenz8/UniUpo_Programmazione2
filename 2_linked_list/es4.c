#include <stdlib.h>
#include <stdio.h>
#include <time.h>

typedef struct Nodo
{
    int data;
    struct Nodo* next;

} Nodo;

typedef struct Nodo* link;

link new_node();
link buildlist(int n);
void list_print(link head);
void pari_dispari(link head, link* pari, link* dispari);

int main(int argc, char** argv)
{
    link principale, pari, dispari;

    if (argc == 2)
    {
        principale = buildlist(atoi(argv[1]));
        pari = dispari = NULL;

        list_print(principale);

        pari_dispari(principale, &pari, &dispari);


        printf("lista n pari:\n");
        list_print(pari);

        printf("lista n dispari:\n");
        list_print(dispari);
    }
    else
    {
        printf("argomenti linea di comando errati!");
    }
}

link new_node()
{
    return (link) malloc(sizeof(Nodo));
}

link buildlist(int n)
{
    link head, tail, temp;

    srand(time(0));
    head = new_node();
    temp = NULL;

    if(head != NULL)
    {
        head->data = rand() % 51;
        tail = head;

        for (int i = 1; i < n; i++)
        {
            temp = new_node();
            if(temp != NULL)
            {
                tail->next = temp;
                tail = temp;
                tail->data = rand() % 51;
            }
        }

        tail->next = NULL;
    }

    return head;
}

void list_print(link head)
{
    while(head != NULL)
    {
        printf("%d -> ", head->data);
        head = head->next;
    }

    printf("\n");
}

void pari_dispari(link head, link* pari, link* dispari)
{
    link temp, aus_pari, aus_dispari;

    int primo_pari, primo_dispari;

    primo_pari = primo_dispari = 1;

    while(head != NULL)
    {
        temp = new_node();
        if (temp != NULL)
        {
            temp->data = head->data;

            if((head->data % 2) == 0)
            {
                if(primo_pari)
                {
                    *(pari) = temp;
                    aus_pari = *(pari);
                    primo_pari = 0;
                }
                aus_pari->next = temp;
                aus_pari = temp;
            }
            else
            {
                if(primo_dispari)
                {
                    *(dispari) = temp;
                    aus_dispari = *(dispari);
                    primo_dispari = 0;
                }    
                aus_dispari->next = temp;
                aus_dispari = temp;            
            }
        }

        head = head->next;
    }
    aus_pari->next = NULL;
    aus_dispari->next = NULL;
}