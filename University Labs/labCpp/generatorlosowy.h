//
// Created by Victor Pavlovskyi on 13.03.2024.
//

#ifndef LABCPP_GENERATORLOSOWY_H
#define LABCPP_GENERATORLOSOWY_H

#include <iostream>
#include <random>

using namespace std;

class Indeks2D {
public:
    unsigned int wiersz, kolumna;

    Indeks2D(unsigned int _w = 0, unsigned int _k = 0)
            : wiersz(_w), kolumna(_k) {}
};

typedef std::vector<Indeks2D> WektorIndeksow2D;

class generatorlosowy {
private:
    static std::random_device device;

    generatorlosowy() {}

public:
    static unsigned short losujPomiedzy(unsigned short min, unsigned short max);
    static long losujPomiedzy(long min, long max);
    static int losujOdZeraDo(int max);
    static WektorIndeksow2D indeksyLosowe(unsigned int wiersze, unsigned int kolumny);
};

typedef generatorlosowy GEN;

#endif //LABCPP_GENERATORLOSOWY_H
