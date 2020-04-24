#include <stdio.h>

int pwr(int x, int y)
{
    int r = 1;

    int i;
    for (i = 0; i < y; i++)
    {
        r = r * x;
    }

    return r;
}

int nrLen(int n)
{
    int r = 0;
    do
    {
        n = n / 10;
        r++;
    } while (n != 0);    
    return r;
}

int rmChr(int n, int chrNr)
{
    int r;
    if (chrNr != 0)
    {
        r = n % pwr(10, chrNr);
        n = n / pwr(10, chrNr);
    }

    n = n / 10;

    if (chrNr != 0)
        r = n * pwr(10, chrNr) + r;
    else
        r = n;
    
    return r;
}

int main()
{
    FILE *fIn;
    FILE *fOut;
    fIn = fopen("date.in", "r");
    fOut = fopen("date.out", "w");

    int N, K;
    fscanf(fIn, "%d %d", &N, &K);
    //printf("%d %d %d", N, rmChr(N, 0), rmChr(N, 2));

    int result;
    int i, j;
    for (i = 0; i < K; i++)
    {
        result = rmChr(N, 0);
        for (j = 1; j < nrLen(N); j++)
        {
            if (rmChr(N, j) > result)
                result = rmChr(N, j);
        }
        N = result;
    }

    fprintf(fOut, "%d", result);

    fclose(fIn);
    fclose(fOut);
    return 0;
}