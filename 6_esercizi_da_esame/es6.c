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
void list_print(link head);
int somma_max(link head1, link head2, int* s1, int* s2);

int main()
{
    link head1, head2;
    int s1, s2;

    head1 = build_list(3);
    head2 = build_list(2);
    s1 = s2 = 0;

    list_print(head1);
    list_print(head2);

    printf("%d", somma_max(head1, head2, &s1, &s2));
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
                tmp->data = k;
                tail->next = tmp;
                tail = tmp;
            }
            k++;    
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

int somma_max(link head1, link head2, int* s1, int* s2)
{
    if(head1 != NULL && head2 != NULL)
    {
        *s1 += head1->data;
        *s2 += head2->data;
        return somma_max(head1->next, head2->next, s1, s2);
    }
    else if (head1 != NULL && head2 == NULL)
    {
        *s1 += head1->data;
        return somma_max(head1->next, head2, s1, s2);
    }
    else if (head1 == NULL && head2 != NULL)
    {
        *s2 += head2->data;
        return somma_max(head1, head2->next, s1, s2);
    }
    else
    {
        return (*s1 > *s2) ? *s1 : *s2;
    }
}