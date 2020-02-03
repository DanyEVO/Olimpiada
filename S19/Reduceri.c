#include <stdio.h>

int binarySearch(int l, int h, int arr[], int x);

int main()
{
    FILE *input, *output;

    input  = fopen("pret.in", "r");
    output = fopen("pret.out", "w");

    if(input == NULL || output == NULL)
    {
        printf("FILE Error!");
        return 1;
    }

    int N;
    fscanf(input, "%d", &N);

    int array[N];
    int i = 0;
    while (getc(input) != EOF)
    {
        fscanf(input, "%d", &array[i]);
        i++;
    }

    int result[N / 2];
    int k = 0, comp, temp;
    
    for(i = 0; i < N - 1; i++)
    {   
        if (array[i] != 0)
        {
            comp = (array[i] * 100) / 75;
            temp = binarySearch(0, N - 1, array, comp);
            if (temp != -1)
            {
                result[k] = array[i];
                array[temp] = 0;
                k++; 
            }
        }
    }

    for(i = 0; i < N/2; i++)
    {
        fprintf(output, "%d\n", result[i]);
    }

    fclose(input);
    fclose(output);

    return 0;
}

int binarySearch(int l, int h, int arr[], int x)
{
    if(h >= l)
    {
        int m = l + (h - 1) / 2;
        if (arr[m] == x)
            return m;

        if (arr[m] > x)
            return binarySearch(l, m - 1, arr, x);
        
        return binarySearch(m + 1, h, arr, x);
    }
    return -1;
}