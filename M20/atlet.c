#include <stdio.h>

// ----- Sort. ----- //

void sort(int n, int x[], int y[])
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n - 1; j++)
        {
            if (x[j] < x[j+1])
            {
                x[j] = x[j] + x[j+1];
                x[j+1] = x[j] - x[j+1];
                x[j] = x[j] - x[j+1];

                y[j] = y[j] + y[j+1];
                y[j+1] = y[j] - y[j+1];
                y[j] = y[j] - y[j+1];
            }
        }
    }
}

// ----- ----- //

int checkHeight(int n, int m[], int s[], int x, int y) // x - ordinea, y - puterea ramasa
{
    int j, result = 1;
    //printf("    ");
    int k = x;

    for (j = k; j < n; j++)
    {
        int temp = 1;
        //printf(" %d %d %d", j, k, y);
        if (m[j] <= y)
        {
            temp = 1 + checkHeight(n, m, s, x+1, y - m[j]);
            x++;
        }
        
        k = j;

        if (temp > result)
            result = temp;
    }

    //printf(" result: %d", result);

    return result;
}

int main()
{
    FILE *fIn;
    FILE *fOut;
    fIn = fopen("atlet.in", "r");
    fOut = fopen("atlet.out", "w");

    int n;
    fscanf(fIn, "%d", &n);
    int i, m[n], s[n];
    for (i = 0; i < n; i++)
    {
        fscanf(fIn, "%d %d", &m[i], &s[i]);
    }

    sort(n, m, s);
    // for (i = 0; i < n; i++)
    // {
    //     printf("%d %d\n", m[i], s[i]);
    // }

    int result = 1;

    for (i = 0; i < n - 1; i++) // Nu are sens de verificat si ultimul acrobat.
    {
        //printf("\n\n");
        int temp = checkHeight(n, m, s, i+1, s[i]);
        if (temp > result)
            result = temp;
    }
    fprintf(fOut, "%d", result);

    fclose(fIn);
    fclose(fOut);
    return 0;
}