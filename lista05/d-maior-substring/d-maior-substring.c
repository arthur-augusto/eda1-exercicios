#include <stdio.h>
#include <string.h>

char *pos_substring;

void maior_substring(char *string, char *substring)
{
    if (!strstr(string, substring)) return ;

    pos_substring = strstr(string, substring);

    maior_substring(pos_substring + 1, substring);
}

int main(void)
{
    char string[101];
    char substring[101];
    char *primeira_ocorrencia;

    int resultado = 0;

    scanf("%s\n%s", string, substring);
 
    primeira_ocorrencia = strstr(string, substring);

    if (primeira_ocorrencia)
    {
        resultado = strlen(substring);

        maior_substring(primeira_ocorrencia + 1, substring);
        
        if (pos_substring)
            resultado += (pos_substring - primeira_ocorrencia);
    }

    printf("%d\n", resultado);

    return 0;
}
