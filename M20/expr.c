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

    int i, expr = 0;
    int begin = 0;
    int sign = 1; // Possible values: -1 & 1

    if (str[0] != 'I')
    {
        begin++;
        sign = -1;
    }

    int temp = 0;
    for (i = begin; i < strlen(str); i++)
    {
        if (str[i] == 'I')
        {
            temp++;
        }
        else
        {
            expr = expr + sign * temp;
            //printf("%d ", expr);
            temp = 0;

            if (str[i] == '+')
            {   
                sign = 1;
            }
            else
            {
                sign = -1;
            }            
        }        
    }

    expr = expr + sign * temp; // Last iteration is always 'I'.

    fprintf(fOut, "%d", expr);

    fclose(fIn);
    fclose(fOut);

    return 0;
}