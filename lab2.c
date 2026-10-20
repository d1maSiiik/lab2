#include <stdio.h>
#define N 10

void secondMax(int M[], int n, int *max, int *second)
{
    if (n == 0) {
        return;
    }

    if (M[n - 1] > *max) {
        *second = *max;
        *max = M[n - 1];
    }
    else if (M[n - 1] > *second && M[n - 1] != *max) {
        *second = M[n - 1];
    }

    secondMax(M, n - 1, max, second);
}

int main()
{
    int M[N];

    printf("Введите %i целых чисел:\n", N);

    for (int i = 0; i < N; i++) {
        if (scanf("%i", &M[i]) != 1) {
            printf("Ошибка: необходимо вводить целые числа\n");
            return 1;
        }
    }

    int max = M[0];
    int second = M[0];

    secondMax(M, N, &max, &second);

    printf("Второй максимальный элемент = %i\n", second);

    return 0;
}
