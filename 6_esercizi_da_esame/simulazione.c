#include <stdio.h>
#include <stdlib.h>


typedef struct Nodo
{
    int data;
    struct Nodo* next;
}Nodo;

typedef struct Nodo* link;

link new_node();
link build_list(int n);
void input_int(link head);
void list_print(link head);
void free_list(link* head);
int ordinata(link head);
void reverse(link* head);
int presenti(link head1, link head2);
void lista_alternata(link head1, link head2, link* head3);

int main()
{
    link head, head2;
    int n_len1 = 4;
    head = build_list(n_len1);
    input_int(head);
    list_print(head);

    printf("lista 1 ordinata: %d\n", ordinata(head));
    // reverse(&head);
    list_print(head);

    head2 = build_list(9);
    input_int(head2);
    list_print(head2);

    printf("presenti: %d", presenti(head, head2));
    
}

link new_node()
{
    return (link) malloc(sizeof(Nodo));
}

link build_list(int n)
{
    link head, tail, tmp;

    head = new_node();

    if (head != NULL)
    {
        tail = head;

        for (int i = 0; i < n - 1; i++)
        {
            tmp = new_node();

            if (tmp != NULL)
            {
                tail->next = tmp;
                tail = tmp;
            }
        }
        tail->next = NULL;
    }

    return head;
}

void input_int(link head)
{
    while (head != NULL)
    {
        printf("Inserisci nodo: ");
        scanf("%d", &(head->data));
        head = head->next;
    }
}

void list_print(link head)
{
    while (head != NULL)
    {
        printf("%d -> ", head->data);
        head = head->next;
    }
        printf("NULL\n");
}

/*
Complessita in tempo di O(n) dato che nel peggiore dei casi dovra' controllare tutta lista per sapere se e' ordinata.
Complessita in spazio di O(1) dato che vi e' un solo record d'attivazione in memoria;
*/
int ordinata(link head)
{
    int ordinata;
    ordinata = 1; // assumo ordinata

    while(head != NULL && ordinata)
    {
        if (head->next != NULL)
        {
            if(head->data > head->next->data)
            {
                ordinata = 0;
            }
        }
        head = head->next;
    }

    return ordinata;
}

/*
Complessita in tempo di O(n) dato che dovra' scandire tutta lista.
Complessita in spazio di O(1) dato che vi e' un solo record d'attivazione in memoria;
*/
void reverse(link* head)
{
    link tmp1, tmp2, tmp3;

    tmp1 = (*head);
    tmp2 = tmp3 = NULL;

    while (tmp1 != NULL)
    {
        tmp2 = tmp1->next;
        tmp1->next = tmp3;
        tmp3 = tmp1;
        tmp1 = tmp2;
    }

    (*head) = tmp3;
}

/*
Complessita in tempo di O(min(len_lista1, len_lista2)) dato che dovra' scandire tutta lista.
Complessita in spazio di O(min(len_lista1, len_lista2)) dato che il numero di record d'attivazioner dipende dalla lunghezza della lista piu' piccola.
*/
int presenti(link head1, link head2)
{
    if (head2 == NULL && head1 == NULL)
    {
        return 1;
    }
    else if (head2 == NULL && head1 != NULL)
    {
        return 0;
    }
    else if (head2 != NULL && head1 == NULL)
    {
        return 1;
    }
    else
    {
        if (head1->data == head2 -> data)
        {
            printf("%d    %d\n", head1->data, head2->data);
            return presenti(head1->next, head2->next);
        }
        else
        {
            printf("%d    %d\n", head1->data, head2->data);
            return presenti(head1, head2->next);
        }
    }
}

void lista_alternata(link head1, link head2, link* head3)
{
    int i = 0;
    link tmp;

    if (head1 == NULL && head2 == NULL)
    {
        (*head3)->next = NULL;
    }
    else if (head1 != NULL && head2 == NULL)
    {
        tmp = new_node();
        if (tmp != NULL)
        {
            tmp->data = head1->data;
            (*head3)->next = tmp;
        }
        lista_alternata(head1->next, head2, head3);
    }
    else if (head1 == NULL && head2 != NULL)
    {
        tmp = new_node();
        if (tmp != NULL)
        {
            tmp->data = head2->data;
            (*head3)->next = tmp;
        }
        lista_alternata(head1, head2->next, head3);        
    }
    else
    {
        tmp = new_node();

        if(tmp != NULL)
        {
            if((i % 2) == 0)
            {
                tmp->data == head1->data;
                (*head3)->next = tmp;
            }
        }
    }
    
    


}





