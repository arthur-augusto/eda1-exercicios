#include<stdio.h>
#include<stdlib.h>

typedef unsigned long int Item;
#define Key(A) (A)
#define less(A, B) Key(A) < Key(B)

void print_vetor(Item *vetor, int l, int r)
{
    for (int i = l; i <= r; i++)
        printf("%lu ", vetor[i]);

    printf("\n");
}

Item* merge(Item *vetor1, int l1, int r1, Item *vetor2, int l2, int r2)
{
    Item *aux = malloc(sizeof(Item) * (r1 - l1 + 1 + r2 - l2 + 1));

    int i = l1;
    int j = l2;
    int k = 0;

    while (i <= r1 && j <= r2)
    {
        if (less(vetor2[j], vetor1[i]))
            aux[k++] = vetor2[j++];
        else
            aux[k++] = vetor1[i++];
    }

    while (i <= r1)
        aux[k++] = vetor1[i++];
    while (j <= r2)
        aux[k++] = vetor2[j++];

    return aux;
}

Item* merge4(Item *vetor1, int l1, int r1, Item *vetor2, int l2, int r2,
             Item *vetor3, int l3, int r3, Item *vetor4, int l4, int r4)
{
    Item *metade1 = merge(vetor1, l1, r1, vetor2, l2, r2);
    Item *metade2 = merge(vetor3, l3, r3, vetor4, l4, r4);

    return merge(metade1, 0, r1 + r2 + 1, metade2, 0, r3 + r4 + 1);
}

Item* merge8(Item *vetor1, int l1, int r1, Item *vetor2, int l2, int r2,
             Item *vetor3, int l3, int r3, Item *vetor4, int l4, int r4,
             Item *vetor5, int l5, int r5, Item *vetor6, int l6, int r6,
             Item *vetor7, int l7, int r7, Item *vetor8, int l8, int r8)

{
    Item *metade1 = merge4(vetor1, l1, r1, vetor2, l2, r2,
                           vetor3, l3, r3, vetor4, l4, r4);

    Item *metade2 = merge4(vetor5, l5, r5, vetor6, l6, r6,
                           vetor7, l7, r7, vetor8, l8, r8);

    return merge(metade1, 0, r1 + r2 + r3 + r4 + 3, metade2, 0, r5 + r6 + r7 + r8 + 3);

}

int main(void)
{
    unsigned long int tamanhos[8];

    Item *vetor = malloc(sizeof(Item) * 800000);
    
    unsigned long int k = 0;

    for (int i = 0; i < 8; i++)
    {
        scanf("%lu\n", &tamanhos[i]);

        for (int j = 0; j <= tamanhos[i]; j++)
            scanf("%lu\n", &vetor[k++]);
    }

    merge8(&vetor[0], 0, tamanhos[0] - 1, &vetor[tamanhos[0]], 0, tamanhos[1] - 1,
           &vetor[tamanhos[1]], 0, tamanhos[2] - 1, &vetor[tamanhos[2]], 0, tamanhos[3] - 1,
           &vetor[tamanhos[3]], 0, tamanhos[4] - 1, &vetor[tamanhos[4]], 0, tamanhos[5] - 1,
           &vetor[tamanhos[5]], 0, tamanhos[6] - 1, &vetor[tamanhos[6]], 0, tamanhos[7] - 1);
    
    print_vetor(vetor, 0, k);

    free(vetor);

    return 0;
}
