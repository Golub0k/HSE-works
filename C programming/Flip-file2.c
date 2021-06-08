#define _CRT_SECURE_NO_WARNINGS
#include "stdlib.h"
#include "stdio.h"
#include "string.h"
void perever(FILE* in, FILE* out)
{
    char c;
    c = fgetc(in);
    if (c == EOF)
        return;
    perever(in, out);
    fputc(c, out);
}
int main()
{
    FILE* in;
    FILE* out;
    in = fopen("input.txt", "r");
    out = fopen("output.txt", "w");

    if ((in == 0) || (out == 0))
    {
        perror("Error");
        return 1;
    }

   

    perever(in, out);
    return 0;
}
