//
// Created by Victor Pavlovskyi on 13.03.2024.
//

#ifndef ZAPASWODY_ZAPAS_WODY_H
#define ZAPASWODY_ZAPAS_WODY_H

#include <iostream>

using namespace std;

class ZapasWody {
public:
    ZapasWody(float oIleZmieniacButelke);

    const void dodajDuza(int ilosc);
    const void dodajSrednia(int ilosc);
    const void dodajMala(int ilosc);
    const void wyswietl();

    const int ileDuzychButelek();
    const int ileSrednichButelek();
    const int ileMalychButelek();
private:
    int duzaButelka;
    int sredniaButelka;
    int malaButelka;

    const static int pojemnoscButelkiDuzej = 21;
    const static int pojemnoscButelkiSredniej = 11;
    const static int pojemnoscButelkiMalej = 0.5;

    const float lacznaObjetosc();

    float oIleZmieniacButelke;
};


#endif //ZAPASWODY_ZAPAS_WODY_H
