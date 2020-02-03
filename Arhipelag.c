#include <stdio.h>

int main()
{
    FILE *input  = fopen("arhi.in", "r");
    FILE *output = fopen("arhi.out", "w");

    if (input == NULL || output == NULL)
    {
        printf("FILE Error!");
        return 1;
    }

    int N, M;
    fscanf(input, "%d %d", &N, &M);
    printf("%d %d\n", N, M);

    int arr[N][M];
    int i = 0, j = 0;

    for (i = 0; i < N; i++)
    {
        for (j = 0; j < M; j++)
        {
            fscanf(input, " %d", &arr[i][j]);
        }
    }

    // 0 - apa, 1 - pamant

    for (i = 0; i < N; i++)
    {
        for (j = 0; j < M; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}