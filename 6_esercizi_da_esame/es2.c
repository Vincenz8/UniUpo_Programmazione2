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
void del_i_k(link* head, int i, int k, int list_len);


int main()
{
    link head;

    head = build_list(8);
    list_print(head);
    del_i_k(&head, 0, 7, 8);
    list_print(head);
}

link new_node()
{
    return (link) malloc(sizeof(Nodo));
}

link build_list(int n)
{
    link head, tail, tmp;

    tmp = NULL;

    head = new_node();

    if (head != NULL)
    {
        head->data = rand() % 100;
        tail = head;

        for (int i = 0; i < n - 1; i++)
        {
            tmp = new_node();

            if (tmp != NULL)
            {
                tmp->data = rand() % 100;
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

void del_i_k(link* head, int i, int k, int list_len)
{
    if(head != NULL)
    {
        if (k < list_len)
        {
            link tmp;

            if(i == k)
            {
                tmp = *head;
                *head = (*(head))->next;
                free(tmp);
            }
            else
            {
                link* next;
                next = &((*(head))->next);
                del_i_k(next, i + 1, k, list_len);
            }
        }
    }
}