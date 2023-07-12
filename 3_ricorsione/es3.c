#include <stdlib.h>
#include <stdio.h>

void divisori(int n, int div);


int main()
{
    divisori(10, 10);
}

void divisori(int n, int div)
{
    if (div != 0)
    {
        if ((n % div) == 0)
        {
            printf("%d -> ", div);
        }

        divisori(n, div - 1);
    }
    
}
