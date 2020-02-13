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

int maximum(int x[], int n)
{
    int i = 0;
    int max = 0;

    for (i = 0; i < n; i++)
    {
        if (max <= x[i])
        {
            max = x[i];
        }
    }

    return max;
}

int search(int x[], int n, int y)
{
    int i = 0;

    for (i = 0; i < n; i++)
    {
        if (x[i] == y) return 1;
    }

    return 0;
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

    fIn = fopen("date10.in", "r");
    fOut = fopen("date.out", "w");

    int n;
    fscanf(fIn, "%d", &n);

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

    int st = 0;
    for (i = 0; i < n; i++)
    {
        st = st + vO[i];
    } 

    sort(o, v, n);

    int t = 0; // time
    int tempO[n];
    int tempV[n];
    int k = 0; // counter for temp[]
    int j = 0;

    int s = 0; 
    int pmin = 0;

    i = 0;
    while (i <= maximum(o, n))
    {
        if (search(o, n, i) == 1) 
        {
            if (t != 0)
            {
                tempO[k] = o[j];
                tempV[k] = v[j];
                s = s + tempV[k];
                k++;
                t--;
            }
            else
            {
                pmin = pmin + v[j];
            }

            j++;

            while ((o[j-1] == o[j]) && (t != 0))
            {
                tempO[k] = o[j];
                tempV[k] = v[j];
                s = s + tempV[k];
                k++;
                t--;
                j++;
            }  

            while ((o[j-1] == o[j]) && (t == 0))
            {
                int min, pos;
                minimum(tempV, k, &min, &pos);

                if (min < v[j]) 
                {                    
                    tempO[pos] = o[j];
                    pmin = pmin - tempV[pos];
                    s = s - tempV[pos];
                    tempV[pos] = v[j];                    
                    pmin = pmin + tempV[pos];
                    s = s + tempV[pos];
                }

                j++;
            }            
        }

        i++;
        t++;
    }

    int result[k];
    for (i = 0; i < k; i++)
    {
        result[i] = findIndex(oO, vO, tempO[i], tempV[i], n) + 1;
        oO[result[i] - 1] = 0;
        vO[result[i] - 1] = 0;
    }

    pmin = st - s;
    fprintf(fOut, "%d %d\n", s, pmin);
    for (i = 0; i < k; i++)
    {
        fprintf(fOut, "%d\n", result[i]);
    }

    fclose(fIn);
    fclose(fOut);

    return 0;
}