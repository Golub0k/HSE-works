#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#define SIZE 10000

int summ(char chislo[], int sum, char znak)
{
    int lenC = strlen(chislo);
    int step = 1;
    for (int i = 1; i < lenC; ++i) { step *= 10; }
    for (int i = 0; i <lenC; ++i)
    {
        if (znak == '+') { sum += ((int)chislo[i]-48) * step; }
        else { sum -= ((int)chislo[i]-48) * step; }
        step = step / 10;
        chislo[i] = 0;
    }
    return sum;
}

int main()
{
    char str[SIZE] = { 0 };
    char chislo[SIZE] = { 0 };
    fgets(str, SIZE, stdin);
    int len = strlen(str) - 1, k = 0, sum = 0;
    str[len] = '\0';
    char znak = '+';
    for (int i = 0; i < len+1; ++i)
    {
        if (isdigit(str[i])) { chislo[k] = str[i]; k += 1; }
        else { sum= summ(chislo, sum, znak); k = 0; znak = str[i]; }
    }
    printf("%i", sum);
}
