//
// Created by Victor Pavlovskyi on 13.03.2024.
//

#include "zapas_wody.h"


const void ZapasWody::wyswietl() {
    cout << "Mam teraz " << ZapasWody::lacznaObjetosc() << " litrów wody" << endl
         << "Dużych butelek: " << duzaButelka << endl
         << "Średnich butelek: " << sredniaButelka << endl
         << "Małych butelek: " << malaButelka << endl;
}

const void ZapasWody::dodajDuza(int ilosc) {
    if (ilosc < 0)
    {
        return;
    }

    duzaButelka += ilosc;
}

const void ZapasWody::dodajSrednia(int ilosc) {
    if (ilosc < 0)
    {
        return;
    }

    sredniaButelka += ilosc;
}

const void ZapasWody::dodajMala(int ilosc) {
    if (ilosc < 0)
    {
        return;
    }

    malaButelka += ilosc;
}

const int ZapasWody::ileDuzychButelek() {
    return duzaButelka;
}

const int ZapasWody::ileSrednichButelek() {
    return sredniaButelka;
}

const int ZapasWody::ileMalychButelek() {
    return malaButelka;
}

const float ZapasWody::lacznaObjetosc() {
    float objetosc = 0;

    if (duzaButelka * oIleZmieniacButelke <= pojemnoscButelkiDuzej)
    {
        objetosc += duzaButelka * oIleZmieniacButelke;
    }

    if (sredniaButelka * oIleZmieniacButelke <= pojemnoscButelkiSredniej)
    {
        objetosc += sredniaButelka * oIleZmieniacButelke;
    }

    if (malaButelka * oIleZmieniacButelke <= pojemnoscButelkiMalej)
    {
        objetosc += malaButelka * oIleZmieniacButelke;
    }

    return objetosc;
}

ZapasWody::ZapasWody(float oIleZmieniacButelke) {
    this->oIleZmieniacButelke = oIleZmieniacButelke;

    duzaButelka = 0;
    sredniaButelka = 0;
    malaButelka = 0;
}
