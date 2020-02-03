#include <stdio.h>
#include <string.h>

int check(char x[])
{
    int j;
    for (j = 0; j < strlen(x)/2; j++)
    {
        if (x[j] != x[strlen(x) - j - 1]) return 1;
    }

    return 0; // 0 - true 1 - false 
}

void inc(char x[], int y)
{
    //printf("%c ", x[y-1]);
    if (x[y - 1] < 57)
        x[y - 1] = x[y - 1] + 1;
    else
    {
        x[y - 1] = 48;
        inc(x, y - 1);
    }    
}

int main()
{
    FILE* fIn;
    FILE* fOut;
    fIn = fopen("pal.in", "r");
    fOut = fopen("pal.out", "w");

    int n;
    fscanf(fIn, "%d", &n);

    int i;
    char str[17];
    for (i = 0; i < n; i++)
    {
        fscanf(fIn, "%s", &str);
        //printf("%c %d\n", str[strlen(str) - 1], str[strlen(str) - 1] + 1);
        while (check(str) == 1)
        {
            inc(str, strlen(str));
        }
        printf("%s\n", str);
    }        

    fclose(fIn); 
    fclose(fOut);
    return 0;
}