#include <stdio.h>

void sort(int x[], int y[], int n)
{
    int i = 0, j = 0;

    for (i = 0; i < n - 1; i++)
    {
        for (j = i; j < n; j++)
        {
            if (x[j] > x[j+1])
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

int main()
{
    FILE* fIn;
    FILE* fOut;
    fIn = fopen("date.in", "r");
    fOut = fopen("date.out", "w");

    int n;
    fscanf(fIn, "%d", &n);

    int O[n], V[n];
    int i, j;
    for(i = 0; i < n; i++)
    {
        fscanf(fIn, "%d %d", &O[i], &V[i]);
        //printf("%d %d\n", O[i], V[i]);
    } 

    sort(O, V, n);

    int t = 1, l;
    int s = 0, pmin = 0; 
    int temp[n];
    for(i = 0; i < n; i++)
    {
        int k = 0;
        s = 0; 
        pmin = 0; 
        for(j = 0; j < n; j++)
        {
            if((t != 0) && (O[j] != O[i]))
            {
                temp[k] = O[j];
                s = s + V[j];
                k++;
                t--;
            }
            else pmin = pmin + V[j];
            
            if(O[j] != O[j+1]) t++;  
        }

        for(l = 0; l < k; l++)
        {
            printf("%d\n", temp[l]);
        } 
        printf("%d %d\n", s, pmin); 
        printf("\n");
    }

    /*for(i = 0; i < k; i++)
    {
        printf("%d\n", temp[i]);
    }*/ 

    //printf("%d %d\n", s, pmin);

    fclose(fIn); 
    fclose(fOut);
}