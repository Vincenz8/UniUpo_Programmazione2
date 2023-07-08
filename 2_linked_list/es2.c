#include <stdlib.h>
#include <stdio.h>

typedef struct Nodo
{
    int data;
    struct Nodo* next;

}Nodo;

typedef struct Nodo* link;

link buildlist(char *f_name);
void list_print(link head);
int list_sum_even(link head);

int main(int argc, char** argv)
{
    if (argc == 2)
    {
        link head;

        head = buildlist(argv[1]);

        list_print(head);

        printf("Somma dei nodi in posizione pari: %d", list_sum_even(head));
    }
    else
    {
        printf("Numero di argomenti da linea di comando errati!");
        return 1;
    }
}

/*buildlist: genera una linked list da un file contenente numeri interi*/
link buildlist(char *f_name)
{
    FILE *f;
    link head, node, temp;
    int n_file;

    f = fopen(f_name, "r");
    head = NULL;

    if (f != NULL)
    {
        if(fscanf(f, "%d", &n_file)!= EOF)
        {
            temp = NULL;
            head = (link) malloc(sizeof(Nodo));

            if (head != NULL)
            {
                head->data = n_file;
                node = head;
                head->next = temp;
            
                while (fscanf(f, "%d", &n_file)!= EOF)
                {
                    temp = (link) malloc(sizeof(Nodo));

                    if (temp != NULL)
                    {
                        node->next = temp;
                        node = temp;
                        node->data = n_file;
                    }
                }

                node->next = NULL;
            }  
        }
    }
    else
    {
        printf("Errore nell'apertura del file");
    }

    return head;
}

/*list_print: visualizza una linked list*/
void list_print(link head)
{
    while (head != NULL)
    {
        printf("%d->", head->data);
        head = head->next;
    }

    printf("\n");
}

/*list_sum_even: restituisce la somma dei nodi in posizione pari*/
int list_sum_even(link head)
{
    int somma;
    int i;

    somma = 0;
    i = 0;

    while(head != NULL)
    {
        if ((i % 2) == 0)
        {
            somma += head->data;
        }

        head = head->next;
        i++;
    }

    return somma;
}

