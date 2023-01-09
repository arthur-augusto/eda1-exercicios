#include <stdio.h>

void troca(char *string)
{
    if (string[0] == '\0') return ;

    if (string[0] == 'x') printf("y");

    else printf("%c", string[0]);

    troca(&string[1]);
}

int main(void)
{
    char entrada[81];

    scanf("%s", entrada);

    troca(entrada);

    printf("\n");

    return 0;
}
