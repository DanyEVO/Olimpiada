#include <stdio.h>

int len(int x)
{
    int y = 0;
    while(x > 0)
    {
        x = x / 10;
        y++;
    }

    return y;
}

int pwr(int x)
{
    int i;
    int y = 1;
    for(i = 0; i < x; i++)
    {
        y = y * 10;
    }

    return y;
}   

void sort(int x[], int n) //734 11 422 651
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

int main()
{
    FILE* fIn;
    FILE* fOut;
    fIn = fopen("joc10.in", "r");
    fOut = fopen("joc.out", "w");

    int n;
    fscanf(fIn, "%d", &n);

    int arr[n];
    int i;
    for(i = 0; i < n; i++)
    {
        fscanf(fIn, "%d", &arr[i]);
    }

    int temp[n];
    int t = 0;
    for(i = 0; i < n; i++)
    {
        //printf("%d\n", arr[i]);
        //printf("%d", len(arr[i]));
        //printf("%d\n", pwr(len(arr[i]) - 1));

        int t2, j;
        t2 = arr[i] % pwr(len(arr[i]) - 1);
        printf("%d ", t2);
        
        int t3 = 0;
        int t4 = len(t2);
        for(j = 0; j < t4; j++)
        {   
            t3 = t3 + t2 / pwr(len(t2) - 1);
            t2 = t2 % pwr(len(t2) - 1);
            //printf("%d %d\n", len(t2), t2 / pwr(len(t2) - 1));
        }

        //printf("%d\n\n", t3, arr[i] / pwr(len(arr[i]) - 1));

        if(arr[i] / pwr(len(arr[i]) - 1) == t3)
        {
            temp[t] = arr[i];
            t++;
        }
    }

    int res[t];
    for(i = 0; i < t; i++)
    {
        res[i] = temp[i];
        //printf("%d\n", res[i]);
    }

    //printf("\n");

    sort(res, t);

    for(i = 0; i < t; i++)
    {
        fprintf(fOut, "%d\n", res[i]);
    }

    fclose(fIn); 
    fclose(fOut);
}