#include <stdio.h>

int main(void)
{
    unsigned short int diametro_bola, altura, largura, profundidade;

    scanf("%hd\n", &diametro_bola);
    scanf("%hd %hd %hd", &altura, &largura, &profundidade);

    if (diametro_bola <= altura && diametro_bola <= largura && diametro_bola <= profundidade)
        printf("S\n");
    else
        printf("N\n");

    return 0;
}
