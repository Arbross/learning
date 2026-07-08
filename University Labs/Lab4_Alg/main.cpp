#include <iostream>
#include "student.h"
#include "studentBuilder.h"

using namespace std;

int main() {
    const int size = 14;
    Student* students = nullptr;

    StudentBuilder::wczytajZPliku(students);
    StudentBuilder::wyswietl(students, size);

    // StudentBuilder::sortowanieFlagiPolskiej(students, 0, size);
    StudentBuilder::sortowanieFlagiFrancuskiej(students, 0, size);

    StudentBuilder::wyswietl(students, size);

    delete [] students;
    return 0;
}
