#include <stdio.h>

void sort(int x[], int y[], int n)
{
    int i, j;

    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
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

            if ((x[j] == x[j+1]) && (y[j] < y[j+1]))
            {
                y[j] = y[j] + y[j+1];
                y[j+1] = y[j] - y[j+1];
                y[j] = y[j] - y[j+1];
            }
        }
    }
}

void minimum(int x[], int n, int* min, int* y)
{
    int i = 0;
    *min = x[i];
    //printf("%d", *min < 700);
    *y = i;

    for (i = 1; i < n; i++)
    {
        if (*min > x[i])
        {
            *min = x[i];
            *y = i;
        }
    }
}

int findIndex(int o[], int v[], int x, int y, int n)
{
    int i = 0;

    for (i = 0; i < n; i++)
    {
        if ((o[i] == x) && (v[i] == y)) return i;
    }
}

int main()
{
    FILE *fIn;
    FILE *fOut;

    fIn = fopen("date3.in", "r");
    fOut = fopen("date.out", "w");

    int n;
    fscanf(fIn, "%d", &n);
    //printf("%d", n);

    int i;
    int o[n], v[n];
    for (i = 0; i < n; i++)
    {
        fscanf(fIn, "%d %d", &o[i], &v[i]);
    }

    int oO[n], vO[n]; // Originals;
    for (i = 0; i < n; i++)
    {
        oO[i] = o[i];
        vO[i] = v[i];
    } 

    sort(o, v, n);

    for (i = 0; i < n; i++)
    {
        printf("%d %d\n", o[i], v[i]);
    }    

    int t = 1; // time
    int tempO[n];
    int tempV[n];
    int k = 0; // counter for temp[]
    int flag = 0;

    int s = 0; 
    int pmin = 0;

    i = 0;
    while (i < n)
    {
        printf("%d %d\n", o[i], t);
        if (t != 0)
        {
            tempO[k] = o[i];
            tempV[k] = v[i];
            s = s + tempV[k];
            k++;
            flag++;
            t--;
        }
        else
        {
            pmin = pmin + v[i];
        }
        
        int min, j;
        minimum(tempV, k, &min, &j);
        //printf("%d %d", t, o[i-1] == o[i]);
        //printf("%d %d %d\n\n", min, j, k);
        if ((v[i] > min) && (flag == 0))
        {
            tempO[j] = o[i];
            pmin = pmin + tempV[j];
            s = s - tempV[j];
            tempV[j] = v[i];
            pmin = pmin - tempV[j];
            s = s + tempV[j];
        } 

        if (o[i] != o[i+1])
            t++;

        flag = 0;
        i++;      
    }

    int result[k];
    for (i = 0; i < k; i++)
    {
        //printf("%d %d %d\n", i, tempO[i], tempV[i]);
        result[i] = findIndex(oO, vO, tempO[i], tempV[i], n) + 1;
    }

    fprintf(fOut, "%d %d\n", s, pmin);
    for (i = 0; i < k; i++)
    {
        fprintf(fOut, "%d %d %d\n", result[i], tempO[i], tempV[i]);
    }

    fclose(fIn);
    fclose(fOut);

    return 0;
}