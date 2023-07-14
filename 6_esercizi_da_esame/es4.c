#include <stdlib.h>
#include <stdio.h>

typedef struct Nodo
{
    int data;
    struct Nodo* next;
} Nodo;

typedef struct Nodo* link;


link new_node();
link build_list(int n);
void list_print(link head);
void del_k_value(link* head, int k);


int main()
{
    int k;
    link head;
    head = build_list(6);

    list_print(head);

    printf("Inserire valore: ");
    scanf("%d", &k);
    del_k_value(&head, k);

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

void del_k_value(link* head, int k)
{
    link tmp;
    link* successivo;

    if ((*(head)) != NULL)
    {
        if ((*(head))->data == k)
        {
            tmp = *(head);
            *(head) = (*(head))->next;
            free(tmp);
        }
        else
        {
            successivo = &((*(head))->next);
            del_k_value(successivo, k);
        }
    }
}