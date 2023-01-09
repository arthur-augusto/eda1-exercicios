#include <stdio.h>
#include <stdlib.h>

typedef int Item;
#define Key(A) (A)
#define less(A, B) Key(A) < Key(B)

void print_vetor(Item *vetor, int l, int r)
{
    for (int i = l; i < r ; i++)
        printf("%d ", vetor[i]);

    printf("%d\n", vetor[r]);
}

void merge(Item *vetor, int l, int m, int r)
{
    Item *aux = malloc(sizeof(Item) * (r - l + 1));

    int i = l, j = m + 1, k = 0;

    while (i <= m && j <= r)
    {
        if (less(vetor[j], vetor[i]))
            aux[k++] = vetor[j++];
        else
            aux[k++] = vetor[i++];
    }

    while (i <= m)
        aux[k++] = vetor[i++];

    while (j <= r)
        aux[k++] = vetor[j++];

    k = 0;

    for (int n = l; n <= r; n++)
        vetor[n] = aux[k++];

    free(aux);
}

void mergesort(Item *vetor, int l, int r)
{
    if (l >= r) return ;

    int m = l + (r - l) / 2;

    mergesort(vetor, l, m);
    mergesort(vetor, m + 1, r);
    merge(vetor, l, m, r);
}

int main(void)
{
    unsigned int tamanho_vetor;

    scanf("%u\n", &tamanho_vetor);

    Item *vetor = malloc(sizeof(Item) * tamanho_vetor);

    for (int i = 0; i < tamanho_vetor; i++)
        scanf("%d\n", &vetor[i]);

    mergesort(vetor, 0, tamanho_vetor - 1);

    print_vetor(vetor, 0, tamanho_vetor - 1);

    free(vetor);

    return 0;
}
