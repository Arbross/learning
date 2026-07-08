//
// Created by Victor Pavlovskyi on 06.03.2024.
//

#include <iostream>
#include "zlab03.h"

using namespace std;

bool Prostokat::czyPoprawny(double bok1, double bok2) {
    return bok1 > 0 && bok2 > 0;
}

void Prostokat::obliczObwod() {
    obwod = 2 * (bok1 + bok2);
}

void Prostokat::obliczPole() {
    pole = bok1 * bok2;
}

Prostokat::Prostokat(string n, double a, double b)
        : nazwa(n) {
    poprawny = czyPoprawny(a, b);

    if (poprawny) {
        bok1 = a;
        bok2 = b;
        obliczPole();
        obliczObwod();
    } else {
        bok1 = bok2 = pole = obwod = 0;
    }
}

Prostokat::~Prostokat() {
    cout << "Prostokąt: " << nazwa
         << " znika." << endl;
}

bool Prostokat::czyPoprawny() {
    return poprawny;
}

const std::string &Prostokat::jakaNazwa() {
    return nazwa;
}

double Prostokat::podajPole() const {
    return pole;
}

double Prostokat::podajObwod() const {
    return obwod;
}

bool Prostokat::zmienBoki(double a, double b) {
    if (czyPoprawny(a, b)) {
        poprawny = true;
        bok1 = a;
        bok2 = b;
        obliczPole();
        obliczObwod();
        return true;
    }
    return false;
}

string Prostokat::doTekstu() {
    string napis = "";

    napis = "Prostokąt o nazwie: " + nazwa
            + " bok1=" + to_string(bok1)
            + " bok2=" + to_string(bok2);

    if (poprawny)
        napis += " obwód=" + to_string(obwod)
                 + " pole=" + to_string(pole);
    else napis += " !Figura niepoprawna.";

    return napis;
}

Prostokat& Prostokat::operator++(int) {
    this->bok1 *= 2;
    this->bok2 *= 2;
    this->obliczPole();
    this->obliczObwod();
    return *this;
}
ostream& operator <<(ostream& strumien, Prostokat& prostokat) {
    strumien << prostokat.doTekstu();
    return strumien;
}

istream& operator >>(istream& strumien, Prostokat& prostokat) {
    double a, b;
    strumien >> a >> b;
    prostokat.zmienBoki(a,b);
    return strumien;
}

bool Prostokat::operator<(const Prostokat &p) const {
    return this->podajPole() < p.podajPole();
}
