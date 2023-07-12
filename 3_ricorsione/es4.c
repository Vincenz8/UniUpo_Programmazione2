#include <stdlib.h>
#include <stdio.h>

int i_max(int* numeri, int i_n1, int i_n2, int n_len);


int main()
{
    int numeri[] = {3, 2, 7, 4, 5};
    printf("%d", i_max(numeri, 0, 1, 5));
}

int i_max(int* numeri, int i_n1, int i_n2, int n_len)
{
    if(i_n2 < n_len)
    {
        if (numeri[i_n1] > numeri[i_n2])
        {
            i_n1 = i_max(numeri, i_n1, i_n2 + 1, n_len);
        }
        else
        {
            i_n1 = i_max(numeri, i_n2, i_n2 + 1, n_len);
        }
    }

    return i_n1;
}