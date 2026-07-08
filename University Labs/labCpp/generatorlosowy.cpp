//
// Created by Victor Pavlovskyi on 13.03.2024.
//

#include "generatorlosowy.h"
#include <chrono>

random_device generatorlosowy::device;

unsigned short generatorlosowy::losujPomiedzy
        (unsigned short min, unsigned short max) {
    if (min > max) {
        unsigned short t = min;
        min = max;
        max = t;
    }

    std::uniform_int_distribution<unsigned short>
            dist(min, max);

    return dist(generatorlosowy::device);
}

long generatorlosowy::losujPomiedzy(long min, long max) {
    if (min > max) {
        long t = min;
        min = max;
        max = t;
    }

    std::uniform_int_distribution<long> dist(min, max);
    return dist(generatorlosowy::device);
}

int generatorlosowy::losujOdZeraDo(int max) {
    std::uniform_int_distribution<int> dist(0, max);
    return dist(generatorlosowy::device);
}

WektorIndeksow2D generatorlosowy::indeksyLosowe(unsigned int wiersze, unsigned int kolumny) {
    WektorIndeksow2D indeksy;

    for (unsigned int w = 0; w < wiersze; w++)
        for (unsigned int k = 0; k < kolumny; k++)
            indeksy.push_back(Indeks2D(w, k));

    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    default_random_engine e(seed);
    shuffle(indeksy.begin(), indeksy.end(), e);

    return indeksy;
}
