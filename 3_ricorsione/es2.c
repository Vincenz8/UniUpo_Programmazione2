#include <stdlib.h>
#include <stdio.h>

int c_presente(char* stringa, char c);


int main()
{
    char stringa[] = "Nardella";

    printf("%d", c_presente(stringa, 'a'));
}

int c_presente(char* stringa, char c)
{

    if (*(stringa) == '\0')
    {
        return 0;
    }
    else if (*(stringa) == c)
    {
        
        return 1;
    }
    
    return c_presente(stringa + 1, c);

}
