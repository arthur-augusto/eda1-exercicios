#include <stdio.h>
#include <string.h>

unsigned char soma = 0, grau_9 = 0;
char multiplo = -1;

char digitos_soma[1001];

void soma_digitos(char *numero)
{
    if (numero[0] == '\0') 
    {
        sprintf(digitos_soma, "%d", soma);
        return ;
    }

    soma += numero[0] - 48;

    soma_digitos(&numero[1]);
}

void grau_nove(char *numero)
{
    soma_digitos(digitos_soma);

    sprintf(digitos_soma, "%d", soma);
    
    grau_9++;

    if (soma == 9)
    {
        multiplo = 1;

        return ;
    }
    else
    {
        multiplo = 0;
    }

    grau_nove(digitos_soma);
}

int main(void)
{
    char digitos_num[1001];

    while (1)
    {
        scanf("%1000s", digitos_num);

        if (strcmp(digitos_num, "0") == 0) break;

        scanf("\n");

        strcpy(digitos_soma, digitos_num);

        soma = 0;

        grau_nove(digitos_soma);
            
        if (multiplo == 1) 
            printf("%s is a multiple of 9 and has 9-degree %hhd.\n", digitos_num, &grau_9);
        else if (multiplo == 0)
            printf("%s is not a multiple of 9.\n", digitos_num);
    }

    return 0;
}
