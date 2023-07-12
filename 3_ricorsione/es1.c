#include <stdlib.h>
#include <stdio.h>

int prodotto(int n1, int n2);


int main()
{
    printf("Prodotto: %d", prodotto(5, 3));
}

int prodotto(int n1, int n2)
{
    if (n2 == 1)
    {
        return n1;
    }
    else if (n2 == 0)
    {
        return 0;
    }
    else
    {
        return n1 + prodotto(n1, (n2 - 1));
    }
}
