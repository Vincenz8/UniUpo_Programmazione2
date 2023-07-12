#include <stdlib.h>
#include <stdio.h>

typedef struct Nodo
{
    int data;
    struct Nodo* next;

}Nodo;

typedef struct Nodo* link;

link new_node();
link build_list(int n);
void list_print(link head);
link eccedenza(link head1, link head2);


int main()
{
    link lista1, lista2, lista3;

    lista1 = build_list(8);
    lista2 = build_list(3);

    list_print(lista1);
    list_print(lista2);

    lista3 = eccedenza(lista1, lista2);

    list_print(lista3);

}

link new_node()
{
    return (link) malloc(sizeof(Nodo));
}

link build_list(int n)
{
    link head, tail, tmp;

    head = new_node();

    if(head != NULL)
    {
        head->data = rand() % 101;
        tail = head;

        for (int i = 0; i < n - 1; i++)
        {
            tmp = new_node();

            if(tmp != NULL)
            {
                tmp->data = rand() % 101;
                tail->next = tmp;
                tail = tmp;
            }
        }

        tail->next = NULL;
    }
    return head;
}

void list_print(link head)
{
    while (head != NULL)
    {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("\n");
}

link eccedenza(link head1, link head2)
{
    link new_list, tail, tmp;

    new_list = NULL;

    while (head1 != NULL && head2 != NULL)
    {
        head1 = head1->next;
        head2 = head2->next;
    }

    if (head1 == NULL && head2 == NULL)
    {
        return NULL;
    }

    new_list = new_node();
    tail = new_list;
    
    if (head1 == NULL)
    {
        if (new_list != NULL)
        {
            new_list->data = head2->data;
            head2 = head2->next;
            while(head2 != NULL)
            {
                tmp = new_node();
                if(tmp != NULL)
                {
                    tmp->data = head2->data;
                    tail->next = tmp;
                    tail = tmp;
                }
                head2 = head2->next;
            }
        }
    }
    else
    {
        if (new_list != NULL)
        {
            new_list->data = head1->data;
            head1 = head1->next;
            while(head1 != NULL)
            {
                tmp = new_node();
                if(tmp != NULL)
                {
                    tmp->data = head1->data;
                    tail->next = tmp;
                    tail = tmp;
                }
                head1 = head1->next;
            }
        }        
    }
    tail->next = NULL;

    return new_list;
}