#include <stdio.h>
#include <stdlib.h>

#define MAX 64

typedef struct {
    char nome[MAX];
    char cognome[MAX];
    unsigned int eta;
    char sesso;
    double salario;
} Impiegato;

int main()
{
    Impiegato imp;
    FILE *f;

    printf("INSERIMENTO DATI IMPIEGATO\n\n");
    printf("Nome: ");
    scanf("%s", imp.nome);
    printf("Cognome: ");
    scanf("%s", imp.cognome);
    printf("Eta': ");
    scanf("%d", &imp.eta);
    printf("Sesso: ");
    scanf(" %c", &imp.sesso);
    printf("Salario: ");
    scanf("%lf", &imp.salario);

    f = fopen("files/es5_f.tsv", "a");
    
    fprintf(f, "%s\t%s\t%d\t%c\t%lf\n", imp.nome, imp.cognome, imp.eta, imp.sesso, imp.salario);
    fclose(f);

    return EXIT_SUCCESS;
}