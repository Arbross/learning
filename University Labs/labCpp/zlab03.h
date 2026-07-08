//
// Created by Victor Pavlovskyi on 06.03.2024.
//

#ifndef LABCPP_ZLAB03_H
#define LABCPP_ZLAB03_H

#include <iostream>

using namespace std;

class Prostokat {
protected:
    string nazwa;
    double bok1, bok2;
    bool poprawny;
    double obwod, pole;

    bool czyPoprawny(double bok1, double bok2);
    void obliczObwod();
    void obliczPole();
public:
    Prostokat(string n = "?", double a = 1, double b = 2);
    ~Prostokat();

    Prostokat& operator++(int);
    bool operator!() {return czyPoprawny();}
    bool operator<(const Prostokat &p) const;

    bool czyPoprawny();
    const string &jakaNazwa();
    double podajPole() const;
    double podajObwod() const;
    bool zmienBoki(double a, double b);
    string doTekstu();
};

ostream& operator <<(ostream& strumien, Prostokat& prostokat);
istream& operator >>(istream& strumien, Prostokat& prostokat);

#endif //LABCPP_ZLAB03_H
