#include <stdio.h>

int _length(char x[])
{
    int len = 0;
    int i = 0;
    for (i = 0; i < 18; i++)
        if (x[i] <= 57 && x[i] >= 48)
            len++;
        else
            return len;        
}

int _pwr(int x, int y)
{
    int r = 1;

    int i = 0;
    for (i = 0; i < y; i++)
        r = r * x;

    return r;
}

void _sort(int n, long x[])
{
    int i = 0, j = 0;

    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - 1 - i; j++)
        {
            if (x[j] < x[j+1])
            {
                x[j] = x[j] + x[j+1];
                x[j+1] = x[j] - x[j+1];
                x[j] = x[j] - x[j+1];
            }
        }
    }
}

void _sortAdv(int n, long x[], int y[])
{
    int i = 0, j = 0;

    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - 1 - i; j++)
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

int _digits(long x)
{
    int r = 0;
    do
    {
        x = x / 10;
        r++;
    } while (x != 0);
     
    return r;
}

int main()
{
    FILE *input, *output;

    input  = fopen("peste.in", "r");
    output = fopen("peste.out", "w");

    if (input == NULL || output == NULL)
    {
        printf("FILE Error!");
        return 1;
    }

    int N;
    fscanf(input, "%d", &N);

    char number[18];
    long arr[N];
    int i = 0, l = 0;
    while (fgetc(input) != EOF)
    {
        int length = 0;
        fscanf(input, "%s", &number);

        length = _length(number);

        int j = 0;
        long max = -1;
        for (i = 0; i < length - 1; i++)
        {
            long temp = 0;
            int k = 1;
            for (j = 0; j < length; j++)
            {
                if (j != i && j != i + 1)
                {
                    long pwr = _pwr(10, length-2-k);
                    temp = temp + (number[j] - 48) * pwr;
                    k++;
                }
            }
            if (max <= temp)
                max = temp;
        }
            
        arr[l] = max;
        l++;
    }

    _sort(N, arr);

    int k[N];
    for (i = 0; i < N; i++)
        k[i] = 0;

    for (i = 0; i < N; i++)
        while (arr[i] < _pwr(10, _digits(arr[0]) - 1))
        {
            k[i]++;
            arr[i] = arr[i] * 10;
        }
    
    _sortAdv(N, arr, k);

    for (i = 0; i < N; i++)
        while (k[i] > 0)
        {
            k[i]--;
            arr[i] = arr[i] / 10;
        }

    for (i = 0; i < N; i++)
        fprintf(output, "%d", arr[i]); 

    fclose(input);
    fclose(output);
    return 0;
}