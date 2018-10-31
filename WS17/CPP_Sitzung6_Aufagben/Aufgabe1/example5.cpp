#include <iostream>

using namespace std;

#include "rom5.h"

int main() {
    ClRomZahl zahl1, zahl2, ergebnis;

    cout << "Bitte geben Sie eine erste Zahl ein:";
    zahl1.hole();
    cout << "Bitte geben Sie eine zweite Zahl ein:";
    zahl2.hole();

    ergebnis.addiere(zahl1, zahl2);
    cout << zahl1.druckbar() << " + " << zahl2.druckbar() << " = " << ergebnis.druckbar() << endl;

    ergebnis.subtrahiere(zahl1, zahl2);
    cout << zahl1.druckbar() << " - " << zahl2.druckbar() << " = " << ergebnis.druckbar() << endl;

    if (zahl2 != 0) {
        ergebnis.dividiere(zahl1, zahl2);
        cout << zahl1.druckbar() << " / " << zahl2.druckbar() << " = " << ergebnis.druckbar() << endl;
    } else if (zahl1 != 0){
        ergebnis.dividiere(zahl2, zahl1);
        cout << zahl2.druckbar() << " / " << zahl1.druckbar() << " = " << ergebnis.druckbar() << endl;
    } else cout << "Du möchtest du 0 teilen, bist du wahnsinnig?!?" << endl;

    ergebnis.multipliziere(zahl1, zahl2);
    cout << zahl1.druckbar() << " * " << zahl2.druckbar() << " = " << ergebnis.druckbar() << endl;
}
