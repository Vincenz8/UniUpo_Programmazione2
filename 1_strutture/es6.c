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
    FILE *fb;

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

    fb = fopen("files/es5_f.bin", "ab");
    
    fwrite(&imp, sizeof(Impiegato), 1, fb);
    fclose(fb);

    return EXIT_SUCCESS;
}