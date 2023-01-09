#include <stdio.h>

unsigned int f91(unsigned int numero)
{
    if (numero >= 101) return numero - 10;
    
    else if (numero <= 100) return f91(f91(numero + 11));
}
int main(void)
{
    unsigned int numero;

    while (scanf("%d\n", &numero) == 1)
    {
        if (numero == 0) break;
        
        printf("f91(%d) = %d\n", numero, f91(numero));
    }

    return 0;
}
