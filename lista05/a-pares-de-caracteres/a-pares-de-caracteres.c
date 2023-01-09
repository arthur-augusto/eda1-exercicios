#include <stdio.h>

unsigned char n_pares = 0;

void pares(char *string)
{
    if (string[2] == '\0') return ;

    if (string[0] == string[2]) n_pares++;

    pares(&string[1]);
}

int main(void)
{
    char entrada[201];

    scanf(" %200s", entrada);

    pares(entrada);

    printf("%hhd\n", n_pares);

    return 0;
}
