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
    Item *vetor = malloc(sizeof(Item) * 100000);

    unsigned long int i = 0;

    while (scanf("%d\n", &vetor[i++]) == 1);

    mergesort(vetor, 0, i);

    print_vetor(vetor, 2, i);

    free(vetor);

    return 0;
}
