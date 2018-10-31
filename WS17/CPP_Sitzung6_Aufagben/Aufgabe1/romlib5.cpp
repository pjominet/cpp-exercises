#include <iostream>

using namespace std;

#include "rom5.h"

void ClRomZahl::zuArabien() {
    char roemischeZiffern[8] = "ivxlcdm";
    int ziffernWert[7] = {1, 5, 10, 50, 100, 500, 1000};
    int hilfe[10], stellen = 0;
    int j;

    if (roemisch[0] == '0') return;

    stellen = 0;
    for (j; roemisch[stellen] != '\0'; stellen++) {
        for (j = 0; j < 7; j++)
            if (roemisch[stellen] == roemischeZiffern[j]) {
                hilfe[stellen] = ziffernWert[j];
                break;
            }
        if (j == 7) return;
    }

    for (j = 1; j < stellen; j++)
        if (hilfe[j] > hilfe[j - 1]) {
            hilfe[j] -= hilfe[j - 1];
            hilfe[j - 1] = 0;
        }

    arabisch = 0;
    for (j = 0; j < stellen; j++) arabisch += hilfe[j];
}

void ClRomZahl::zuRom() {
    char roemischeZiffern[8] = "mdclxvi";
    int ziffernWert[7] = {1000, 500, 100, 50, 10, 5, 1};
    int stelle = 0, hilfe;

    hilfe = arabisch;
    for (int i = 0; i < 7; i++) {
        while (hilfe >= ziffernWert[i]) {
            roemisch[stelle] = roemischeZiffern[i];
            hilfe -= ziffernWert[i];
            stelle++;
        }
    }
    roemisch[stelle] = '\0';
}
