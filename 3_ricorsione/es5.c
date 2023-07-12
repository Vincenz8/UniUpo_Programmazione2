#include <stdlib.h>
#include <stdio.h>

int potenza(int base, int exp);

int main()
{
    printf("%d", potenza(2, 3));
}

int potenza(int base, int exp)
{
    if (exp == 0)
    {
        return 1;
    }
    else if (exp == 1)
    {
        return base;
    }
    else
        return base * potenza(base, exp - 1);
    
}