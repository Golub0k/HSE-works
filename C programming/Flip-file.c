#define _CRT_SECURE_NO_WARNINGS
#include "stdlib.h"
#include "stdio.h"
#include "string.h"

void perever(FILE* input, FILE* output)
{
    char str[10000] = { 0 };
    while (!feof(input))
    {
        fgets(str, 1000, input); // чтобы ввести пословно, а не построчно - нужен fscanf(..);
        perever(input, output);
        fputs(str, output);
    }
}
int main(int argc, char* argv[])
{
    FILE* input = fopen("input.txt", "r");
    FILE* output = fopen("output.txt", "w");
    perever(input, output);
}
