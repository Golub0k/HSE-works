#include "stdio.h"
#define _CRT_SECURE_NO_WARNINGS
#include "stdlib.h"
#define SIZE 1000
#include <string.h>


typedef struct STACKzn
{
    char value;
    struct STACKzn* pnext;
}STACKzn;

int prior(char zn)
{
    if (zn == '(')
        return 0;
    if (zn == '+' || zn == '-')
        return 1;
    if (zn == '*' || zn == '/')
        return 2;
}
STACKzn* PushZn(STACKzn* phead, char v)
{
    STACKzn* pnew = (STACKzn*)malloc(sizeof(STACKzn));
    pnew->pnext = phead;
    pnew->value = v;
    return pnew;
}

STACKzn* PopZn(STACKzn* phead)
{
    STACKzn* pnew = phead->pnext;
    free(phead);
    return pnew;
}

int IsEmptyZn(STACKzn* phead)
{
    if (phead)
        return 0;
    return 1;
}
///////////////////////////////////стек для чисел
typedef struct STACK
{
    char value;
    struct STACK* pnext;
}STACK;

STACK* Push(STACK* phead, char v)
{
    STACK* pnew = (STACK*)malloc(sizeof(STACK));
    pnew->pnext = phead;
    pnew->value = v;
    return pnew;
}

STACK* Pop(STACK* phead)
{
    STACK* pnew = phead->pnext;
    free(phead);
    return pnew;
}

int IsEmpty(STACK* phead)
{
    if (phead)
        return 0;
    return 1;
}


void printStack(const STACK* head, char polsk[]) {
    STACK* polskaya = 0; int i=0;
    while (head) {

        polskaya = Push(polskaya, head->value);

        head = head->pnext;
    }
    while (polskaya) { printf("%c", polskaya->value); polsk[i]= polskaya->value; i+=1; polskaya = polskaya->pnext; }
}
int rezultat(char polsk[])
{
     
    int rez[1000] = { 0 };//массив подсчета результата
    int i = 0;
    int i2 = 0;
     while (polsk[i]!='\0') 
    {
        if (polsk[i] == '+')
        {
            rez[i2-2] = rez[i2 - 2] + rez[i2 - 1];
            rez[i2-1]=0;
            i2-=1;
        }
        if (polsk[i] == '-')
        {
            rez[i2-2] = rez[i2 - 2] - rez[i2 - 1];
            rez[i2-1]=0;
            i2-=1;
        }
        if (polsk[i] == '*')
        {
            rez[i2-2] = rez[i2 - 2] * rez[i2 - 1];
            rez[i2-1]=0;
            i2-=1;
        }
        if (polsk[i] == '/')
        {
            rez[i2-2] = rez[i2 - 2] / rez[i2 - 1];
            rez[i2-1]=0;
            i2-=1;
        }
        
        if (polsk[i] >= '0' && polsk[i] <= '9')
        {
             rez[i2] = (int)polsk[i]-48; i+=1;
            while (polsk[i]>= '0' && polsk[i] <= '9') 
            { rez[i2] = rez[i2] * 10 + ((int)polsk[i]-48); i+=1;}
            i2+=1;
            if (polsk[i] == '+'||polsk[i] == '-'||polsk[i] == '/'||polsk[i] == '*')
            {i-=1;}
        }
        i+=1;
    }
    return  rez[0];
}
/////////////////////////////////////////
int main()
{
    printf("Expression:\n");
    char* str = (char*)malloc(sizeof(STACK));
    fgets(str, SIZE, stdin);
    int len = strlen(str);
    str[len] = '\0';
    printf("%s\n", str);
    STACK* tsifri = 0;  //стек с числами
    STACKzn* znaki = 0; //стек со знаками oper
    //char polskaya[100];
    char polsk[100] = {0};
    char vivod[100];
    STACK* tsifri2 = 0;
    for (int i = 0; i < len; i++)
    {
        if (str[i] >= '0' && str[i] <= '9')
        {

            if (str[i + 1] < '0' || str[i + 1] >'9') { tsifri = Push(tsifri, str[i]); tsifri = Push(tsifri, ' '); }
            else {
                while (str[i] >= '0' && str[i] <= '9')
                {
                    /* k = k * 10 + str[i];*/
                    tsifri = Push(tsifri, str[i]);
                    i += 1;
                }tsifri = Push(tsifri, ' ');
            }


        }
        if (str[i] == '(')
        {
            znaki = PushZn(znaki, '(');
            continue;
        }
        if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/')
        {
            if (IsEmptyZn(znaki) || prior(str[i]) > prior(znaki->value))
            {
                znaki = PushZn(znaki, str[i]);
                continue;
            }
            else
            {
                while (!IsEmptyZn(znaki) && prior(str[i]) <= prior(znaki->value))
                {
                    tsifri = Push(tsifri, znaki->value);
                    tsifri = Push(tsifri, ' ');
                    znaki = PopZn(znaki);
                }
                znaki = PushZn(znaki, str[i]);
                continue;
            }
        }
        if (str[i] == ')')
        {
            while (znaki->value != '(')
            {
                tsifri = Push(tsifri, znaki->value);
                tsifri = Push(tsifri, ' ');
                znaki = PopZn(znaki);
            }
            znaki = PopZn(znaki); // минус скобка
        }
    }

    while (!IsEmptyZn(znaki))
    {
        tsifri = Push(tsifri, znaki->value);
        tsifri = Push(tsifri, ' ');
        znaki = PopZn(znaki);
    }
    printf("Reverse Polish Notation:\n");
    printStack(tsifri, polsk);
    polsk[strlen(polsk)]='\0';

  printf("\nResult:\n%i", rezultat(polsk));
}
