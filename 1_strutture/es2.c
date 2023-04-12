#include <stdio.h>
#include <stdlib.h>

#define MAX 20

typedef struct
{
    char nome[MAX];
    char cognome[MAX];
    int eta;
} Persona;

int main()
{
    Persona p[2];

    printf("INSERIMENTO DATI PERSONE\n\n");

    for(int i = 0; i < 2; i++)
    {
        printf("Persona %d\n{\n", i+1);
        printf("\tNome: ");
        scanf("%s", p[i].nome);

        printf("\tCognome: ");
        scanf("%s", p[i].cognome);

        printf("\tEta': ");
        scanf("%d", &p[i].eta);
        printf("}\n");
    }

    printf("La persona piu' vecchia e' ");

    if (p[0].eta > p[1].eta)
    {
        printf("%s", p[0].nome);
    }
    else
    {
        printf("%s", p[1].nome);
    }
    
    return EXIT_SUCCESS;
}