#include <stdlib.h>
#include <stdio.h>

int c_occ(char* stringa, char c);


int main()
{
    char stringa[] = "Nardella";
    printf("%d", c_occ(stringa, 'l'));
}


int c_occ(char* stringa, char c)
{
    int trovato = 0;

    if (*(stringa) == '\0')
    {
        return trovato;
    }
    else if (*(stringa) == c)
    {
        trovato = 1;
    }
    return trovato + c_occ(stringa + 1, c);
}