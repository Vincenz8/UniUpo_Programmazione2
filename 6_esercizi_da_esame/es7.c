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
int del_mul_k(link* head, int k);
void list_print(link head);


int main()
{
    link head;
    int n;

    head = build_list(10);
    list_print(head);
    n = del_mul_k(&head, 2);
    list_print(head);
}

link new_node()
{
    return (link) malloc(sizeof(Nodo));
}

link build_list(int n)
{
    link head, tail, tmp;
    int k;

    tmp = NULL;
    head = new_node();
    k = 1;

    if (head != NULL)
    {
        head->data = k++;
        tail = head;

        for (int i = 0; i < n - 1; i++)
        {
            tmp = new_node();

            if (tmp != NULL)
            {
                tmp->data = k++;
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

int del_mul_k(link* head, int k)
{
    link tmp, tmp2;
    int i;
    int f_head;

    i = 0;
    f_head = 0;

    while ((*head) != NULL && !(f_head))
    {
        if(((*head)->data % k) == 0)
        {
            tmp = (*head);
            (*head) = (*head)->next;
            free(tmp);
            i++;
        }
        else
        {
            f_head = 1;
        }
    }

    tmp2 = (*head);

    if(tmp2 != NULL)
    {
        while (tmp2->next != NULL)
        {
            if ((tmp2->next->data % k) == 0)
            {
                tmp = tmp2->next;
                tmp2->next = tmp2->next->next;
                free(tmp);
                i++;
            }
            else
            {
                tmp2 = tmp2->next;
            }

        } 
    }
    
    return i;
}