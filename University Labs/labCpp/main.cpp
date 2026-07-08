#include <iostream>

#include "zlab02.h"
#include "zlab03.h"
#include "zlab09.h"
#include "zlab10.h"
#include "organizm.h"
#include "ustawienia.h"
#include "generatorlosowy.h"
#include "sasiedztwo.h"
#include <fstream>
#include "kwadrat.h"

#include "nisza.h"
#include "osobniki.h"

using namespace std;

//static Nisza n1, n2, n3;
//
//static char sep = UstawieniaSymulacji::
//pobierzUstawienia().znakSeparator;
//
//void wyswietlNisze() {
//    cout << n1.jakiSymbol() << sep
//         << n2.jakiSymbol() << sep
//         << n3.jakiSymbol() << endl;
//}

//void drukujOrganizm(const Organizm &o) {
//    cout << "licznikZycia: "
//         << o.stanLicznikaZycia()
//         << " licznikPosilkow: "
//         << o.stanLicznikaPosilkow() << endl
//         << "limitPosilkow: "
//         << o.limitPosilkow
//         << " kosztPotomka: "
//         << o.kosztPotomka << endl
//         << "głodny: " << o.glodny()
//         << " pączkujący: "
//         << o.paczkujacy() << endl << endl;
//}
//
//void wyswietl(UstawieniaSymulacji &UST) {
//    cout << "Znak glon:" << UST.znakGlon
//         << " zycieMin=" << UST.glonZycieMin
//         << " zycieMax=" << UST.glonZycieMax << endl;
//}
//
//string nazwaRodzaju(RodzajMieszkanca rodzaj) {
//    switch (rodzaj) {
//        case GLON:
//            return "GLON";
//        case GRZYB:
//            return "GRZYB";
//        case BAKTERIA:
//            return "BAKTERIA";
//        case PUSTKA:
//            return "PUSTKA";
//        case SCIANA:
//            return "ŚCIANA";
//        case TRUP:
//            return "TRUP";
//        case NIEZNANE:
//            return "NIEZNANE";
//    }
//}

int main() {
    // Laboratorium 2
    // cout << "Laboratorium 02" << endl;

    // ZLab02 lab02;
    // lab02.zadanie_2_3();
    // lab02.zadanie_2_4();
    // lab02.zadanie_2_5();
    // lab02.zadanie_2_7();
    // lab02.zadanie_2_8();
    // lab02.zadanie_2_9();
    // lab02.zadanie_2_10(1, 100);
    // lab02.pobierzLiczbe();

    // lab02.menu(); // main operated menu

    // Laboratorium 3

    // Zadanie 2.1
    // Prostokat p1;
    // Prostokat p2("koc", 1.4, 2.2);
    // Prostokat p3("pułapka", -2, -3);

    // cout.precision(2);
    // cout << p1.doTekstu() << endl;
    // cout << p2.doTekstu() << endl;
    // cout << p3.doTekstu() << endl;

    // p3.zmienBoki(2, 3);
    // cout << endl << p3.doTekstu() << endl;

    // cout << endl << "Użycie metod obiektu:" << endl;
    // cout << "Nazwa: " << p2.jakaNazwa() << endl
    //      << "Poprawny: " << p2.czyPoprawny() << endl
    //      << "Obwód=:" << p2.podajObwod() << endl
    //      << "Pole=" << p2.podajPole() << endl;

    // Zadanie 2.3
    //// 1. Test kreacji obiektów
    //Organizm organizm1(8, 3, 2);
    //Organizm organizm2 = organizm1;
    //Organizm organizm3(organizm1);

    //cout << "Wynik testu kreacji obiektów:"
    //     << endl << endl;
    //cout << "Organizm1:" << endl;
    //drukujOrganizm(organizm1);
    //cout << "Organizm2" << endl;
    //drukujOrganizm(organizm1);
    //cout << "Organizm3" << endl;
    //drukujOrganizm(organizm2);

    //// 2. Test niezależności obiektów
    //organizm1.posilek();
    //organizm1.posilek();
    //organizm2.posilek();
    //organizm3.krokSymulacji();

    //cout << "Wynik testu niezależności obiektów:"
    //     << endl << endl;
    //cout << "Organizm1:" << endl;
    //drukujOrganizm(organizm1);
    //cout << "Organizm2" << endl;
    //drukujOrganizm(organizm2);
    //cout << "Organizm3" << endl;
    //drukujOrganizm(organizm3);

    //// 3. Test symulacji
    //Organizm organizm4(8, 3, 2);

    //cout << "Wynik testu symulacji:"
    //     << endl << endl;
    //cout << "Stan początkowy:" << endl;
    //drukujOrganizm(organizm4);

    //for (int i = 1; i < 11; i++) {

    //    organizm4.krokSymulacji();

    //    if (organizm4.paczkujacy()) {
    //        organizm4.potomek();
    //        cout << "---> Potomek" << endl;
    //    } else organizm4.posilek();

    //    cout << "Po wykonaniu kroku symulacji: "
    //         << i << endl;
    //    drukujOrganizm(organizm4);
    //}

//    // Laboratorium 4
//    cout << "Laboratorium 4" << endl;
//
//    // 1. Dostęp do obiektu klasy UstawienaSymulacji
//    UstawieniaSymulacji &UST1
//            = UstawieniaSymulacji::pobierzUstawienia();
//    UstawieniaSymulacji &UST2
//            = UstawieniaSymulacji::pobierzUstawienia();
//    UstawieniaSymulacji &UST3
//            = UstawieniaSymulacji::pobierzUstawienia();
//
//    cout << "Pobranie ustawien 3x" << endl;
//    cout << "UST1: ";
//    wyswietl(UST1);
//    cout << "UST2: ";
//    wyswietl(UST2);
//    cout << "UST3: ";
//    wyswietl(UST3);
//
//    cout << endl << "Zmiana wartości tylko 1x" << endl;
//    UST2.glonZycieMax = 100;
//    cout << "UST1: ";
//    wyswietl(UST1);
//    cout << "UST2: ";
//    wyswietl(UST2);
//    cout << "UST3: ";
//    wyswietl(UST3);
//
//    cout << endl << endl << endl;
//
//    // 2. Zadanie 2
//
//    cout << "Liczby losowe typu int:" << endl;
//    cout << " od 0 do 5: ";
//
//    for (int i = 0; i < 10; i++)
//        cout << GEN::losujOdZeraDo(5) << " ";
//    cout << endl << " od 0 do 3: ";
//    for (int i = 0; i < 10; i++)
//        cout << GEN::losujOdZeraDo(3) << " ";
//    cout << endl << " od 0 do 20: ";
//    for (int i = 0; i < 10; i++)
//        cout << GEN::losujOdZeraDo(20) << " ";
//    cout << endl << endl;
//
//    cout << "Liczby losowe typu long: " << endl;
//    cout << " od -2 do 2:";
//    for (int i = 0; i < 10; i++)
//        cout << GEN::losujPomiedzy(-2L, 2L) << " ";
//    cout << endl << endl
//         << "Liczby losowe typu unsigned short: " << endl;
//    cout << " od 2 do 6: ";
//    unsigned short min = 2, max = 6;
//
//    for (int i = 0; i < 10; i++)
//        cout << GEN::losujPomiedzy(max, min) << " ";
//    cout << endl << endl;

//    // Laboratorium 5
//
//    Sasiedztwo sasiedztwo;
//
//    sasiedztwo.okreslSasiada(P, GLON);
//    sasiedztwo.okreslSasiada(PG, GRZYB);
//    sasiedztwo.okreslSasiada(G, GRZYB);
//    sasiedztwo.okreslSasiada(LG, GLON);
//    sasiedztwo.okreslSasiada(L, BAKTERIA);
//    sasiedztwo.okreslSasiada(LD, BAKTERIA);
//    sasiedztwo.okreslSasiada(D, GLON);
//    sasiedztwo.okreslSasiada(PD, PUSTKA);
//
//    cout << "Przegląd sąsiedztwa:" << endl;
//
//    for (int i = 0; i < 8; i++) {
//        Polozenie p = static_cast<Polozenie>(i);
//        RodzajMieszkanca r = sasiedztwo.ktoJestSasiadem(p);
//        cout << "polozenie=" << p << " rodzaj="
//             << nazwaRodzaju(r) << endl;
//    }
//
//    cout << endl << "Policzenie sasiadów"
//         << "określonego rodzaju:" << endl
//         << " glony=" << sasiedztwo.ile(GLON) << endl
//         << " grzyby=" << sasiedztwo.ile(GRZYB) << endl
//         << " trupy=" << sasiedztwo.ile(TRUP) << endl;
//
//    cout << endl << "Wylosowanie sasiada:" << endl
//         << " glon -> "
//         << sasiedztwo.losujSasiada(GLON) << endl
//         << " pustka -> "
//         << sasiedztwo.losujSasiada(PUSTKA) << endl
//         << " trup -> "
//         << sasiedztwo.losujSasiada(TRUP) << endl;
//
//    long wiersz, kolumna;
//    cout << endl
//         << "Zmiana indeksów [5][7]"
//         << "wg polozenia:" << endl;
//
//    for (int i = 0; i < 8; i++) {
//        Polozenie p = static_cast<Polozenie>(i);
//
//        wiersz = 5;
//        kolumna = 7;
//
//        Sasiedztwo::zmienIdeksyWgPolozenia(p, wiersz, kolumna);
//        cout << " położenie: " << p << " ->[" << wiersz
//             << "][" << kolumna << "]" << endl;
//    }
//    cout << endl;

//    // Laboratorium 6

//    Kwadrat kwadrat("Kwadrek", 4);
//
//    Kwadrat &refDoKwadrat = kwadrat;
//
//    double r0 = refDoKwadrat.promienKolaWgPola();
//    double r1 = refDoKwadrat.promienOkreguWgObwodu();
//
//    cout << "ro=" << r0 << endl
//         << "r1=" << r1 << endl;

//    // Laboratorium 7
//    // A
//
//    cout << "Puste nisze: ";
//    wyswietlNisze();
//
//    cout << "Lokowanie mieszkańców: ";
//    n1.przyjmijLokatora(new Glon());
//    n3.przyjmijLokatora(new Grzyb());
//    wyswietlNisze();
//
//    cout << "Przesuwanie lokatorów: ";
//    n2 = n1;
//    wyswietlNisze();
//
//    cout << "Przesuwanie lokatorów:";
//    n3 = n2;
//    wyswietlNisze();
//
//    cout << endl;
//
//    // B
//    Nisza nisza;
//    nisza.przyjmijLokatora(new Bakteria());
//
//    cout << "Kto w niszy: "
//         << nisza.ktoTuMieszka() << endl;
//    cout << "Czy żywy: "
//         << nisza.lokatorZywy() << endl;
//
//    Sasiedztwo sasiedztwo;
//    sasiedztwo.okreslSasiada(P, GLON);
//    sasiedztwo.okreslSasiada(PG, GRZYB);
//    sasiedztwo.okreslSasiada(G, GRZYB);
//    sasiedztwo.okreslSasiada(LG, GLON);
//    sasiedztwo.okreslSasiada(L, BAKTERIA);
//    sasiedztwo.okreslSasiada(LD, BAKTERIA);
//    sasiedztwo.okreslSasiada(D, GLON);
//    sasiedztwo.okreslSasiada(PD, PUSTKA);
//
//    ZamiarMieszkanca zamiar = nisza.aktywujLokatora(sasiedztwo);
//
//    cout << "Akjca: " << zamiar.akcja << " gdzie: "
//         << zamiar.gdzie << endl;
//
//    cout << endl;

//    // Laboratorium 9
//
//    ZLab09 l;
//    l.skalar();
//    l.rozmiary();
//    l.referencja();
//    l.tablica1D();
//    l.tablica2D(5, 6);

//    // Laboratorium 10

//    ZLab10 zlab10;
//    zlab10.wektor();
//    zlab10.wektor_sortowanie();
//    zlab10.zbior();
//    zlab10.mapa();

//    Prostokat p("Prostokat",2,3);
//    Kwadrat k("Kwadrat",4);
//    cout << p << endl;
//    cout << k << endl;
//
//    cout << p << endl;
//    cin >> p;
//    cout << p << endl;
//
//    cout << p << endl;
//    p++;
//    cout << p << endl;
//
//    Prostokat p0("Prostokat",2,3);
//    cout << "!p0=" << !p0 << endl;
//    Prostokat p1("Prostokat",0,0);
//    cout << "!p1=" << !p1 << endl;

//    cout << "Przeciążanie operatora <" << endl;
//    Prostokat p1("p1", 2, 3);
//    cout << p1;
//    Prostokat p2("p2", 1, 2);
//    cout << p2;
//    cout << "czy p1 < p2?" << endl;
//    cout << (p1 < p2);
//
//    // Laboratorium 11
//
//    for (Indeks2D &I: GEN::indeksyLosowe(2, 4))
//        cout << "{" << I.wiersz << ", " << I.kolumna << "}\n";
//
//    Srodowisko ekoSystem(8, 12);
//    ekoSystem.lokuj(new Glon(), 0, 10);
//    ekoSystem.lokuj(new Glon(), 1, 10);
//    ekoSystem.lokuj(new Glon(), 1, 13);
//    ekoSystem.lokuj(new Glon(), 3, 10);
//    ekoSystem.lokuj(new Grzyb(), 1, 11);
//    ekoSystem.lokuj(new Grzyb(), 0, 0);
//    ekoSystem.lokuj(new Bakteria(), 3, 3);
//    ekoSystem.lokuj(new Bakteria(), 2, 6);
//
//    unsigned long i = 0;
//    do {
//        system("clear");
//        cout << "Krok symulacji: " << i << endl
//             << endl << ekoSystem.doTekstu() << endl;
//
//        cin.ignore(1);
//        ekoSystem.wykonajKrokSymulacji();
//        i++;
//    } while (i < 200 && !ekoSystem.martwy());
//    cout << endl;

    // Laboratorium 12

    Srodowisko ekoSystem = Srodowisko::czytajZPliku("start.txt");

    ofstream plikWynikowy("symulacja.txt");
    if (!plikWynikowy.is_open()) return 1;
    string stanSymulacji;

    unsigned long i = 0;
    do {
        system("clear");
        cout << "Krok symulacji: " << i << endl;
        plikWynikowy << "Krok symulacji: " << i << endl;
        stanSymulacji = ekoSystem.doTekstu();

        cout << endl << stanSymulacji << endl;
        plikWynikowy << stanSymulacji << endl;
        cin.ignore(1);
        ekoSystem++;
        i++;
    } while (i < 200 && !ekoSystem);
    cout << endl;
    plikWynikowy.close();

    return 0;
}
