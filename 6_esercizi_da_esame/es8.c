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
float media(link head, int* n, int len_list, int i);


int main()
{
    link head;
    int n;

    head = build_list(10);
    list_print(head);
    printf("%.2f", media(head, &n, 10, 1));

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

float media(link head, int* n, int len_list, int i)
{
    if(head != NULL)
    {
        *n = head->data + media(head->next, n, len_list, i + 1);
        if (i == 1)
        {
            return *n / (float)len_list;
        }
        else
        {
            return *n;
        }
    }
    else
    {
        return 0;
    }

}