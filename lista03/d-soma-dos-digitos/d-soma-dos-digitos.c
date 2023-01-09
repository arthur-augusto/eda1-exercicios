#include <stdio.h>

int soma = 0;

void soma_digitos(char *numero)
{
    if (numero[0] == '\0') return ;

    soma += numero[0] - 48;

    soma_digitos(&numero[1]);
}

int main(void)
{
    char numero[13];

    scanf("%s", numero);

    soma_digitos(numero);

    printf("%d\n", soma);

    return 0;
}
