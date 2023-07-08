#include <stdio.h>

void move(int n_dischi, char inizio, char supporto, char fine);

int main() 
{
    int n;

    printf("Inserire numero di dischi: ");
    scanf("%d", &n);
    
    // Torre A --> Torre C
    move(n,'A','B','C');

    return 0;
}

void move(int n_dischi, char inizio, char supporto, char fine)
{
    // passo base, se n == 1 direttamente A --> C
    if(n_dischi == 1) 
    {
        printf("disco %d: %c --> %c\n", n_dischi, inizio, fine);
    }
    else 
    {
        // A --> B con C da supporto
        move(n_dischi - 1 , inizio, fine, supporto);

        printf("disco %d: %c --> %c\n", n_dischi, inizio, fine);

        // B --> C con A da supporto
        move(n_dischi - 1 , supporto, inizio, fine);
    }
}