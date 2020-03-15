#include <stdio.h>
#include <string.h>

int main()
{
    FILE *fIn;
    FILE *fOut;

    fIn = fopen("expr.in", "r");
    fOut = fopen("expr.out", "w");

    char str[1000];
    fscanf(fIn, "%s", str);

    //printf("%s %d", str, strlen(str));

    int i, nr;
    for (i = 0; i < strlen(str); i++)
    {

    }

    fclose(fIn);
    fclose(fOut);

    return 0;
}