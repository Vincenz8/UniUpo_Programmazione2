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
void del_compreso(link* head, int n, int m);


int main()
{
    link head;

    head = build_list(10);
    list_print(head);
    del_compreso(&head, 2, 4);
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
        head->data = rand() %101;
        tail = head;

        for (int i = 0; i < n - 1; i++)
        {
            tmp = new_node();

            if (tmp != NULL)
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

void del_compreso(link* head, int n, int m)
{
    link tmp1, tmp2;
    int i;

    
    i = 1;
 

    if(n < m)
    {
        if (n == 1)
        {
            while ((*head) != NULL && i <= m)
            {
                tmp1 = (*head);
                (*head) = (*head)->next;
                free(tmp1);
                i++;
            }
        }
        else
        {
            tmp2 = (*head);

            while (tmp2 != NULL && i < (n - 1))
            {
                tmp2 = tmp2->next;
                i++;
            }
            if (tmp2 != NULL)
            {
                while (tmp2->next != NULL && i < m)
                {
                    tmp1 = tmp2->next;
                    tmp2->next = tmp2->next->next;
                    free(tmp1);
                    i++;
                }
            }
        }
    }
}