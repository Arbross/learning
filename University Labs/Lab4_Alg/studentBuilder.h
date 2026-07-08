#ifndef LAB3_ALG_STUDENTBUILDER_H
#define LAB3_ALG_STUDENTBUILDER_H

#include <fstream>
#include "student.h"

enum SortType {
    ASCENDING = 0,
    DESCENDING = 1,
};

class StudentBuilder {
public:
    static void wczytaj(Student*& array, int size);
    static void wczytajZPliku(Student*& array);
    static void usunTablice(Student*& array);
    static void wyswietl(Student* array, int size);
    static void sortowanieQuickSort(Student*& array, int startIndex, int endIndex, SortType type = DESCENDING);
    static void sortowanieFlagiPolskiej(Student*& array, int startIndex, int endIndex);
    static void sortowanieFlagiFrancuskiej(Student*& array, int startIndex, int endIndex);
private:
    static int partition(Student*& array, int startIndex, int endIndex, Student pivot, SortType type);
};

#endif
