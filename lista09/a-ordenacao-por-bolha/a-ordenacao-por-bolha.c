#include <stdio.h>

typedef int Item;
#define Key(A) (A)
#define less(A, B) (Key(A) < Key(B))
#define greater(A, B) (Key(A) > Key(B))
#define exch(A, B) {Item t = A; A = B; B = t;}

void bubblesort(Item *v, int l, int r)
{
    for (int i = l; i < r; i++)
    {
        for (int j = l; j < r; j++)
        {
            if (greater(v[j], v[j + 1]))
                exch(v[j], v[j + 1]);
        }
    }
}

int main(void)
{
    Item v[1000];

    int i = 0;

    while (scanf("%d\n", &v[i++]) == 1);

    int r = i - 1;

    bubblesort(v, 0, r);

    for (int k = 0; k < r - 1; k++)
        printf("%d ", v[k]);

    printf("%d\n", v[r - 1]);

    return 0;
}
