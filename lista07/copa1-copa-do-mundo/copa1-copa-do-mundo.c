#include <stdio.h>

int main(void)
{
    int m, n;
    
    char resultados[15];
    
    int jogos_posteriores;

    for (int i = 0; i < 15; i++)
    {
        scanf("%d %d\n", &m, &n);
        
        jogos_posteriores = (i - 8) * 2;

        if (i < 8)
        {
            if (m > n) resultados[i] = (65 + (2 * i)); 

            else resultados[i] = (66 + (2 * i));
        }
        else if (i < 12)
        {
            if (m > n) resultados[i] = resultados[jogos_posteriores];
            
            else resultados[i] = resultados[jogos_posteriores + 1];
        }
        else if (i < 14)
        {
            if (m > n) resultados[i] = resultados[jogos_posteriores];
            
            else resultados[i] = resultados[jogos_posteriores + 1];
        }
        else if (i == 14)
        {
            if (m > n) resultados[i] = resultados[jogos_posteriores];

            else resultados[i] = resultados[jogos_posteriores + 1];
        }
    }

    printf("%c\n", resultados[14]);

    return 0;
}
