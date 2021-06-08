#define _CRT_SECURE_NO_WARNINGS
#include <ctype.h>
#include "stdlib.h"
#include "stdio.h"
#include "string.h"
int main()
{
    FILE* file;
    FILE* output = fopen("output.txt", "wt");
    int c = 0;
    char sym;
    file = fopen("input.txt", "r");
    fscanf(file, "%c", &sym);
    while (!feof(file))
    {
        if (isdigit(sym))
        {
            putchar(sym);
            c++;
        }
        fscanf(file, "%c", &sym);
    }

    fclose(file);
    fprintf(output, "%i", c);
    return 0;
}
