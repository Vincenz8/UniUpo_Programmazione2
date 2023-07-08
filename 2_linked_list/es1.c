#include <stdlib.h>
#include <stdio.h>
#include <time.h>

typedef struct Nodo
{
    int data;
    struct Nodo* next;

}Nodo;

typedef struct Nodo* link;

link buildlist(int n);
void list_print();
float list_mean(link head);
void to_file(link head, char * f_name);

int main(int argc, char** argv)
{
    if (argc == 2)
    {
        link head;

        head = buildlist(atoi(argv[1]));

        list_print(head);

        printf("Media nodi: %.2f", list_mean(head));

        to_file(head, "files/es1.txt");
    }
    else
    {
        printf("Numero di argomenti da linea di comando errati!\n");
        return 1;
    }
}

/*buildlist: genera una linked list con numeri casuali da 0 a 50*/
link buildlist(int n)
{
    link head, temp, node;

    temp = NULL;
    srand(time(0));

    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            head = (link) malloc(sizeof(Nodo));

            if(head != NULL)
            {
                node = head;
                head->next = temp;
                head->data = rand()%51;
            }

        }
        else
        {
            temp = (link) malloc(sizeof(Nodo));

            if (temp != NULL)
            {
                node->next = temp;
                node = temp;
                node->data = rand()%51;
                node->next = NULL;   
            }
        }
    }
    return head;
}

/*list_print: visualizza una linked list*/
void list_print(link head)
{
    while(head != NULL)
    {
        printf("%d->", head->data);
        head = head->next;
    }
    printf("\n");
}

/*list_mean: restituisce la media dei nodi*/
float list_mean(link head)
{
    float media;
    int i;

    i = 0;
    media = 0;

    while(head != NULL)
    {
        media += head->data;
        head = head->next;
        i++;
    }

    return (media / i);
}

/*to_file: salva su file la lista*/
void to_file(link head, char * f_name)
{
    FILE *f;

    f = fopen(f_name, "w");

    while(head != NULL)
    {
        fprintf(f, "%d\n", head->data);
        head = head->next;
    }
}