#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo
{
    int data;
    struct Nodo* next;

} Nodo;

typedef struct Nodo* link;

link new_node();
link buildlist(int n);
void list_print(link head);
int sequenza(link head);

int main()
{
    link head;

    head = buildlist(10);
    list_print(head);
    printf("Sequenza maggiore: %d", sequenza(head));
}

link new_node()
{
    return (link) malloc(sizeof(Nodo));
}

link buildlist(int n)
{
    link head, tail, tmp;

    tmp = NULL;

    head = new_node();

    if (head != NULL)
    {
        tail = head;

        printf("Valore nodo: ");
        scanf("%d", &(head->data));

        tail->next = tmp;

        for (int i = 0; i < n - 1; i++)
        {
            tmp = new_node();

            if (tmp != NULL)
            {
                tail->next = tmp;
                tail = tmp;
                printf("Valore nodo: ");
                scanf("%d", &(tail->data));
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
    
}

int sequenza(link head)
{
    int i, k;

    i = k = 1;

    while(head != NULL)
    {
        if (head->next != NULL)
        {
            if (head->data == head->next->data)
            {
                i++;
                if (i > k)
                {
                    k++;
                }
            }
            else
            {
                i = 1;
            }
        }

        head = head->next;
    }
    return k;
}