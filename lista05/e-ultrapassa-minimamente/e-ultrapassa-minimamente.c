#include <stdio.h>

int limite;
int montante = 0;

void ultrapassa_minimamente(int *entrada, int anterior)
{
    if (entrada[0] == 0) return ;

    montante += entrada[0];
    
    if (montante > limite)
    {
        anterior = entrada[0];

        montante = 0;
    }

    ultrapassa_minimamente(&entrada[1], anterior);

    if (anterior == entrada[0]) printf("%d\n", anterior);
}

int main(void)
{
    int vetor[100];
    int i = 0;
    int entrada;

    while (scanf("%d\n", &entrada) == 1)
    {
        vetor[i++] = entrada; 
        if (entrada == 0) break;
    }

    scanf("%d", &limite);

    ultrapassa_minimamente(vetor, vetor[i + 1]);

    return 0;
}
