#include "zapas_wody.h"

using namespace std;

int main() {
    ZapasWody zapasWody(2.5);
    zapasWody.dodajDuza(2);
    zapasWody.dodajSrednia(1);
    zapasWody.dodajMala(3);

    zapasWody.wyswietl();

    ZapasWody::pojemnoscButelkiDuzej += 10;

    return 0;
}
