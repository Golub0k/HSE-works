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
    int pobeda;//количество выигранных у соперника игр
    int gol;//количество забитых сопернику голов
}SOPERNIC;

typedef struct COM_and_SOPERNIC
{
    char comanda[100];
    SOPERNIC S[10];
}COM_and_SOPERNIC;

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
    COM_and_SOPERNIC C[10] = { 0 };
    int i_m = 0, i_c = 0;
    while ((vse_matchi[i_m].com1[0]) >=65)
    {
        i_c = 0;
        int k1 = 0, k2 = 0; // счетчик вхождений
        /// ///////////////сравниваем с предыдущими записанными командами
        while (strlen(C[i_c].comanda) != 0)
        {
            if (vse_matchi[i_m].com1[0] == C[i_c].comanda[0] && vse_matchi[i_m].com1[2] == C[i_c].comanda[2])
            {
                int q = 0;
                while (strlen(C[i_c].S[q].com) != 0 && (C[i_c].S[q].com[0] != vse_matchi[i_m].com2[0] || C[i_c].S[q].com[3] != vse_matchi[i_m].com2[3])) { q += 1; }
                strcpy(C[i_c].S[q].com, vse_matchi[i_m].com2);
                C[i_c].S[q].igri += 1;
                C[i_c].S[q].doma += 0;
                if (vse_matchi[i_m].shet1 > vse_matchi[i_m].shet2) {
                    C[i_c].S[q].pobeda += 1;
                }
                else { C[i_c].S[q].pobeda += 0; }
                C[i_c].S[q].gol += vse_matchi[i_m].shet1;
                k1 += 1;
            }
            /// проверка второй команды
            if (vse_matchi[i_m].com2[0] == C[i_c].comanda[0] && vse_matchi[i_m].com2[2] == C[i_c].comanda[2])
            {
                int q = 0;
                while (strlen(C[i_c].S[q].com) != 0 && (C[i_c].S[q].com[0] != vse_matchi[i_m].com1[0] || C[i_c].S[q].com[2] != vse_matchi[i_m].com1[2])) { q += 1; }
                strcpy(C[i_c].S[q].com, vse_matchi[i_m].com1);
                C[i_c].S[q].igri += 1;
                C[i_c].S[q].doma += 1;
                if (vse_matchi[i_m].shet1 >= vse_matchi[i_m].shet2) {
                    C[i_c].S[q].pobeda += 0;
                }
                else { C[i_c].S[q].pobeda += 1; }
                C[i_c].S[q].gol += vse_matchi[i_m].shet2;
                k2 += 1;
            }
            i_c += 1;
        }
        ///  ///////////////////////////////////////////////////
        if (strlen(C[i_c].comanda) == 0 && (k1 == 0 || k2 == 0))
        {
            if (k1 == 0) {
                strcpy(C[i_c].comanda, vse_matchi[i_m].com1);
                //C[i_c].comanda[strlen(vse_matchi[i_m].com1)-1] = '\0';
                strcpy(C[i_c].S[0].com, vse_matchi[i_m].com2);
                C[i_c].S[0].igri = 1; // если уже играли с этой командой, добавляем количесвто игр
                C[i_c].S[0].doma = 0;
                if (vse_matchi[i_m].shet1 > vse_matchi[i_m].shet2) {
                    C[i_c].S[0].pobeda = 1;
                }
                else { C[i_c].S[0].pobeda = 0; }
                C[i_c].S[0].gol = vse_matchi[i_m].shet1;
                i_c += 1;
            }
            if (k2 == 0) {
                strcpy(C[i_c].comanda, vse_matchi[i_m].com2);
                C[i_c].comanda[strlen(vse_matchi[i_m].com2)] = '\0';
                strcpy(C[i_c].S[0].com, vse_matchi[i_m].com1);
                C[i_c].S[0].igri = 1; // если уже играли с этой командой, добавляем количесвто игр
                C[i_c].S[0].doma = 1;
                if (vse_matchi[i_m].shet1 >= vse_matchi[i_m].shet2) {
                    C[i_c].S[0].pobeda = 0;
                }
                else { C[i_c].S[0].pobeda = 1; }
                C[i_c].S[0].gol = vse_matchi[i_m].shet2;
            }
        }
        i_m += 1;
    }

    i_c = 0;
    while (C[i_c].comanda[0] >= 65 && C[i_c].comanda[0] <= 90)
    {
        int s = 0;
        fprintf(out,"%s\n", C[i_c].comanda);
        while (strlen(C[i_c].S[s].com) != 0) {
            fprintf(out,"%s %i %i %i %i\n", C[i_c].S[s].com, C[i_c].S[s].igri, C[i_c].S[s].doma, C[i_c].S[s].pobeda, C[i_c].S[s].gol);
            s += 1;
        }
        i_c += 1;
    }
}
