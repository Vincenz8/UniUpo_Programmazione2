#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo
{
    int data;
    struct Nodo* next;
}Node;

typedef Node* link;

/*new_node: alloca un nuovo nodo in memoria dinamica*/
link new_node()
{
    return (link) malloc(sizeof(Node));
}

/*build_list: alloca una linked list in memoria dinamica*/
link build_list(int n)
{
    link head, temp, tail;

    temp = NULL;

    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            head = new_node();

            if(head != NULL)
            {   
                tail = head;
                head->data = i;
                head->next = temp;
            }
            else
            {
                printf("Impossibile creare Il nodo!");
            }
        }
        else
        {
            temp = new_node();

            if(temp != NULL)
            {
                tail->next = temp;
                tail = temp;
                tail->data = i;
                tail->next = NULL;
            }
        }
    }
    
    return head;
}

/*view_list: visualizza una linked list*/
void view_list(link head)
{
    int i = 1;

    while(head != NULL)
    {
        printf("n%d: %d->", i, head->data);
        head = head->next;
        i++;
    }
}

int main()
{
    link testa = new_node();
    link testa2 = build_list(3);

    testa->data = 7;
    testa->next = NULL;

    view_list(testa2);

    return 0;
}