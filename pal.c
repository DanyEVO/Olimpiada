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

int pwr(long x)
{
    int i;
    int y = 1;
    for(i = 0; i < x; i++)
    {
        y = y * 10;
    }

    return y;
} 

int check(long x)
{
    int i, j;
    int t = 0;

    if (len(x) % 2 == 1)
        j = len(x)/2 + 1;
    else 
        j = len(x)/2;

    //printf("%d\n", j);
    for(i = 0; i < j; i++)
    {
        if(x / pwr(len(x) - 1) == x % 10) t++;
        else return -1;

        x = x % pwr(len(x) - 1);
        x = x / 10;

        //printf("%d ", t);
    }

    //printf("%d\n", t);

    if (t == j) return 0;
    return -1;
}

int main()
{
    FILE* fIn;
    FILE* fOut;
    fIn = fopen("pal6.in", "r");
    fOut = fopen("pal.out", "w");

    int n;
    fscanf(fIn, "%d", &n);

    long arr[n];
    int i, j;
    for(i = 0; i < n; i++)
    {
        fscanf(fIn, "%d", &arr[i]);
        //printf("%d\n", arr[i]);
    }  

    long r; 

    for(i = 0; i < n; i++)
    {
        r = arr[i];
        while (check(r) != 0)
        {
            r++;
            //printf("%d %d ", check(r), r);
        }
        
        fprintf(fOut, "%d\n", r);
    }  

    //printf("%d\n", check(64346));

    fclose(fIn); 
    fclose(fOut);
}