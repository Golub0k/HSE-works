#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define SIZE 100

typedef struct GAME
{
    char com1[100];
    char com2[100];
    int shet1;
    int shet2;
}GAME;

typedef struct SOPERNIC
{
    char com[100];
    int igri; //клдичество игр
    int doma;// количество игр на стадионе соперника
    int pobeda;
    int proigrish;
    int zab_gol;
    int prop_gol;
    int sopern[10];
}SOPERNIC;


void zapis(FILE* in, GAME m[100])
{
    char str[1000] = { 0 };
    int z = 0;
    while (!feof(in))
    {
        fgets(str, 1000, in);
        /*int len = strlen(str) - 1;
        str[len] = '\0';*/
        if (str[strlen(str)] == '\0' && (str[strlen(str) - 1] != '\n'))
        { break; };
        if (str[strlen(str) - 1] == '\n') { str[strlen(str) - 1] = '\0'; }
        else { str[strlen(str)] = '\0'; }
        char kom1[SIZE];
        int i = 0;
        while (str[i] != ' ') { kom1[i] = str[i]; i++; }
        kom1[i] = '\0';
        i += 3;
        char kom2[SIZE]; int k = 0;
        while (str[i] != ' ') { kom2[k] = str[i]; k += 1; i++; }
        kom2[k] = '\0';
        i += 1;
        int c1 = 0, c2 = 0;
        while (str[i] != ':') { c1 = c1 * 10 + ((int)str[i] - 48); i += 1; }
        i += 1;
        while (str[i] != '\0') { c2 = c2 * 10 + ((int)str[i] - 48); i += 1; }
        strcpy(m[z].com1, kom1);
        /*m[z].com1[strlen(kom1)] = '\n';*/
        strcpy(m[z].com2, kom2);
        /*m[z].com2[strlen(kom2)] = '\n';*/
        m[z].shet1 = c1;
        m[z].shet2 = c2;
        z += 1;
    }
}

int main()
{
    FILE* in;
    FILE* out;
    in = fopen("input.txt", "r");
    out = fopen("output.txt", "w");
    GAME vse_matchi[100];
    zapis(in, vse_matchi);
    SOPERNIC C[10];
    int j = 0;
    for (int i = 0; i < 10; i++) {
        for (int r = 0; r < 10; ++r) { C[i].sopern[r] = 0; };
    }
    while (vse_matchi[j].com1[0] >= 65)
    {
        int i = 0;
        int k1 = 0, k2 = 0;
        while (C[i].com[0] >=65)
        {
            
            if (C[i].com[0] == vse_matchi[j].com1[0] && C[i].com[2] == vse_matchi[j].com1[2])
            {
                C[i].igri += 1; C[i].doma += 1;

                if (vse_matchi[j].shet1 > vse_matchi[j].shet2) { C[i].pobeda += 1; }

                else { if (vse_matchi[j].shet1 < vse_matchi[j].shet2) { C[i].proigrish += 1; } }; C[i].zab_gol += vse_matchi[j].shet1; C[i].prop_gol += vse_matchi[j].shet2;
                int kom2=0;
                int w = 0;
                while (vse_matchi[j].com2[w] != '\0') {
                    kom2 += (int)vse_matchi[j].com2[w]; w++;
                }
                for (int d = 0; d< 10; ++d) {
                    if (C[i].sopern[d] == kom2) { break; };
                    if (C[i].sopern[d] == 0) { C[i].sopern[d] = kom2; break; }
                }
                k1 += 1;
            }

            /// 
            if (C[i].com[0] == vse_matchi[j].com2[0] && C[i].com[2] == vse_matchi[j].com2[2])
            {
                C[i].igri += 1;

                if (vse_matchi[j].shet1 < vse_matchi[j].shet2) { C[i].pobeda += 1; }

                else { if (vse_matchi[j].shet1 > vse_matchi[j].shet2) { C[i].proigrish += 1; } } C[i].zab_gol += vse_matchi[j].shet2; C[i].prop_gol += vse_matchi[j].shet1;
                int kom1=0;
                int w = 0;
                while (vse_matchi[j].com1[w] != '\0') {
                    kom1 += (int)vse_matchi[j].com1[w]; w++;
                }
                for (int d = 0; d < 10; ++d) {
                    if (C[i].sopern[d] == kom1) { break; };
                    if (C[i].sopern[d] == 0) { C[i].sopern[d] = kom1; break; }
                }
                k2 += 1;
            }
            i += 1;
        }

        if (C[i].com[0] < 65 && k1 == 0)
        {
            strcpy(C[i].com, vse_matchi[j].com1); C[i].igri = 1; C[i].doma = 1;

            if (vse_matchi[j].shet1 > vse_matchi[j].shet2) { C[i].pobeda = 1; C[i].proigrish = 0;
            }

            else {
                C[i].pobeda = 0; C[i].proigrish = 0;
                if (vse_matchi[j].shet1 < vse_matchi[j].shet2) { C[i].proigrish = 1; }
            } C[i].zab_gol = vse_matchi[j].shet1; C[i].prop_gol = vse_matchi[j].shet2;
            int kom2=0;
            int w = 0;
            while (vse_matchi[j].com2[w] != '\0') {
                kom2 += (int)vse_matchi[j].com2[w]; w++;
            }
            C[i].sopern[0] = kom2;
            i += 1;
        }
        if ((C[i].com[0] < 65) && k2 == 0)
        {
            strcpy(C[i].com, vse_matchi[j].com2); C[i].igri = 1;
            C[i].doma = 0;
            if (vse_matchi[j].shet1 < vse_matchi[j].shet2) { C[i].pobeda = 1; C[i].proigrish = 0;
            }

            else {
                C[i].pobeda = 0; C[i].proigrish = 0;
                if (vse_matchi[j].shet1 > vse_matchi[j].shet2) { C[i].proigrish = 1; }
            } C[i].zab_gol = vse_matchi[j].shet2; C[i].prop_gol = vse_matchi[j].shet1;
            int kom1=0;
            int w = 0;
            while (vse_matchi[j].com1[w] != '\0') {
                kom1 += (int)vse_matchi[j].com1[w]; w++;
            }
            C[i].sopern[0] = kom1;
        }
        j += 1;
    }
    int i = 0;
    while (C[i].com[0] >= 65)
    {
        fprintf(out, "%s %i %i %i %i %i %i ", C[i].com, C[i].igri, C[i].doma, C[i].pobeda, C[i].proigrish, C[i].zab_gol, C[i].prop_gol);
        /*fputs(C[i].com , out); fputs(" ", out); fpintf(C[i].igri, out);*/
        int e = 0;
        while (C[i].sopern[e] != 0)
        { e+=1; }
        fprintf(out, "%i\n", e);
        i++;
}
};
       
