#include <stdio.h>
#include <string.h>

#define DIM 20
#define N_ALUNNI 10

typedef struct STUDENTE
{
    char cognome[DIM];
    char nome[DIM];
    int anno;
} 
Studente;

Studente crea_studente(char cognome[], char nome[], int anno);
void stampa_studente(Studente x);
void copia_studente(Studente* dest, Studente source);
void init_alunni(Studente alunni[]);
void stampa_alunni(Studente alunni[], int n_alunni);
void dividi_alunni(Studente alunni[], Studente minorenni[], Studente maggiorenni[], int* n_min, int* n_mag);

int main()
{
    Studente alunni[N_ALUNNI], minorenni[N_ALUNNI], maggiorenni[N_ALUNNI];
    int n_min, n_mag;

    init_alunni(alunni);

    alunni[3].anno = 2005;
    alunni[6].anno = 2010;
    alunni[1]. anno = 2007;

    stampa_alunni(alunni, N_ALUNNI);

    dividi_alunni(alunni, minorenni, maggiorenni, &n_min, &n_mag);

    printf("\n\nMINORENNI %d\n\n", n_min);
    stampa_alunni(minorenni, n_min);

    printf("\n\nMAGGIORENNI %d\n\n", n_mag);
    stampa_alunni(maggiorenni, n_mag);
}

/*crea_studente: inizializza uno studente*/
Studente crea_studente(char cognome[], char nome[], int anno)
{
    Studente temp;

    strcpy(temp.cognome, cognome);
    strcpy(temp.nome, nome);
    temp.anno = anno;

    return temp;
}

/*stampa_studente: visualizza a schermo le info di uno studente*/
void stampa_studente(Studente x)
{
    printf("%s\t%s\t%d", x.cognome, x.nome, x.anno);
}

/*copia_studente: copia uno studente*/
void copia_studente(Studente* dest, Studente source)
{
    strcpy(dest->cognome, source.cognome);
    strcpy(dest->nome, source.nome);
    dest->anno = source.anno;
}

/*init_alunni: inizializza un vettore di tipo Studente*/
void init_alunni(Studente alunni[])
{
    char temp_nome[] = "Carlo";
    char temp_cognome[] = "Parla";
    int temp_anno;

    temp_anno = 2001;

    for (int i = 0; i < N_ALUNNI; i++)
    {
        alunni[i] = crea_studente(temp_cognome, temp_nome, temp_anno);
        temp_cognome[4]++;
    }  
}

/*stampa_alunni: visualizza a schermo info degli alunni*/
void stampa_alunni(Studente alunni[], int n_alunni)
{
    printf("COGNOME\tNOME\tANNO\n\n");

    for (int i = 0; i < n_alunni; i++)
    {
        stampa_studente(alunni[i]);
        printf("\n");
    }  
}

/*dividi_alunni: suddivide un vettore di studenti in minorenni e maggiorenni*/
void dividi_alunni(Studente alunni[], Studente minorenni[], Studente maggiorenni[], int* n_min, int* n_mag)
{
    *n_min = 0;
    *n_mag = 0;

    for (int i = 0; i < N_ALUNNI; i++)
    {
        if (alunni[i].anno < 2004)
        {
            copia_studente(&maggiorenni[*n_mag], alunni[i]);
            (*n_mag)++;
        }
        else
        {
            copia_studente(&minorenni[*n_min], alunni[i]);
            (*n_min)++;
        }
    }
}