#include <stdio.h>

int main(void)
{
    int n_cobrancas;

    scanf("%d\n", &n_cobrancas);

    char cobrancas_a[n_cobrancas + 1];
    char cobrancas_b[n_cobrancas + 1];
    char cobrancas_todas[n_cobrancas * 2];

    int gols_a = 0;
    int gols_b = 0;

    int saida;

    scanf("%s\n%s", cobrancas_a, cobrancas_b);
    
    for (int i = 0; i < n_cobrancas * 2; i++)
    {
        if (cobrancas_a[i] == 'o') gols_a++;

        if (cobrancas_b[i] == 'o') gols_b++;

        if (gols_b + n_cobrancas - i - 1 <= gols_a)
        {
            saida = 2 * i + 2;

            printf("%d\n", saida);

            return 0;
        }
        else if (gols_a + n_cobrancas - i - 1 <= gols_b)
        {
            saida = 2 * i + 1;

            printf("%d\n", saida);

            return 0;
        }
    }

    if (gols_a == gols_b) printf("Empate\n");

    return 0;
}
