#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define SIZE 10000

int Chislo(char chislo[])
{
    int lenC = strlen(chislo);
    int step = 1;
    int C = 0;
    for (int i = 1; i < lenC; ++i) { step *= 10; }
    for (int i = 0; i <lenC; ++i)
    {
        C += ((int)chislo[i]-48) * step;
        step = step / 10;
        chislo[i] = 0;
    }
    return C;
}
int main()
{
    char str[SIZE] = { 0 };
    char kom1[SIZE] = { 0 };
    char kom2[SIZE] = { 0 };
	fgets(str, SIZE, stdin);
    int len = strlen(str) - 1;
	str[len] = '\0';
	char chisl1[SIZE] = { 0 };
	int k = 0;
	int p = 0;
	int rez = 0;
	for (int i = 0; i < len; ++i)
	{
	    if(str[i]!=' ' && p==0){kom1[i]=str[i];}
	    if(str[i]==' '){p+=1; if(p==3){rez=i+1;}};
	    if(str[i]!=' ' && p==2){kom2[k]=str[i];k+=1;}
	}
	k=0;
    while (str[rez]!=':'){chisl1[k]=str[rez];k+=1;rez+=1;}
    int C1 = Chislo(chisl1);
    rez+=1;
    k=0;
    while (str[rez]!=' '){chisl1[k]=str[rez];k+=1;rez+=1;}
     rez+=2;
     k=0;
    int C2 = Chislo(chisl1);
    while (str[rez]!=':'){chisl1[k]=str[rez];k+=1;rez+=1;}
     rez+=1;
     k=0;
    int C3 = Chislo(chisl1);
    while (str[rez]!=')'){chisl1[k]=str[rez];k+=1;rez+=1;}
    int C4 = Chislo(chisl1);

    
    if (C1>C2 && C3>C4 && C1-C3>C2-C4) {printf("%s\n", kom1);}
    else if (C1<C2 && C3<C4 && C1-C3<C2-C4) {printf("%s\n", kom2);}
    else { if (C3>C4){printf("%s\n", kom1);} else if (C3<C4){printf("%s\n", kom2);}
           else if (C3==C4){printf("draw\n");};
           
           if (C1-C3>C2-C4){printf("%s\n", kom1);} else if (C1-C3<C2-C4){printf("%s\n", kom2);}
           else if (C1-C3==C2-C4){printf("draw\n");};
           
           if (C1>C2){printf("%s\n", kom1);} else if (C1<C2){printf("%s\n", kom2);}
           else if (C1==C2){printf("draw\n");}
           }
    
}
