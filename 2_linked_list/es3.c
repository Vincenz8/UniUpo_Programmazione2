#include <stdlib.h>
#include <stdio.h>

typedef struct Nodo
{
    char c;
    struct Nodo* next;

}Nodo;

typedef struct Nodo* link;

link buildlist(char *stringa);
void list_print(link head);
int list_length(link head);
int count_vowels(link head);

int main(int argc, char** argv)
{
    if (argc == 2)
    {
        link head;

        head = buildlist(argv[1]);

        list_print(head);

        printf("I nodi sono: %d", list_length(head));

        printf("\nLe vocali sono: %d", count_vowels(head));
    }
}

link buildlist(char *stringa)
{
    link head, tail, temp;

    temp = NULL;
    head = NULL;

    if(stringa[0] != '\0')
    {
        head = (link) malloc(sizeof(Nodo));

        if(head != NULL)
        {
            tail = head;
            tail->next = temp;
            tail->c = *(stringa);
            stringa++;

            while(*(stringa) != '\0')
            {
                temp = (link) malloc(sizeof(Nodo));

                if (temp != NULL)
                {
                    tail->next = temp;
                    tail = temp;
                    tail->c = *stringa;
                }
                stringa++;
            }

            tail->next = NULL;
        }
    }
    return head;
}

void list_print(link head)
{
    while(head != NULL)
    {
        printf("%c -> ", head->c);
        head = head->next;
    }

    printf("\n");
}

int list_length(link head)
{
    int i;

    i = 0;

    while(head != NULL)
    {
        i++;
        head = head->next;
    }
    return i;
}

int count_vowels(link head)
{
    int i;
    int vocale;
    char vocali[] = "AEIOUaeiou";
    
    i = 0;
    vocale = 0;

    while (head != NULL)
    {
        for (int k = 0; vocali[k] != '\0' && !vocale; k++)
        {
            if(vocali[k] == head->c)
            {
                i++;
                vocale = 1;
            }
        }
        vocale = 0;
        head = head->next;
    }

    return i;
}

