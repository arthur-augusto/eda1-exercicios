#include <stdio.h>

void ao_contrario(char *string)
{
    if (string[0] == '\0') return ;

    ao_contrario(&string[1]);

    printf("%c", string[0]);
}

int main(void)
{
    char entrada[501];

    scanf("%s", entrada);

    ao_contrario(entrada);

    printf("\n");

    return 0;
}
