#include "studentBuilder.h"

void StudentBuilder::wczytaj(Student *&array, int size) {
    for (int i = 0; i < size; ++i) {
        cout << "-----------------------------------" << endl;
        cout << "Enter student " << i + 1 << " first name: "; cin >> array[i].firstName;
        cout << "Enter student " << i + 1 << " last name: "; cin >> array[i].lastName;
        cout << "Enter student " << i + 1 << " mark: "; cin >> array[i].mark;
        cout << "-----------------------------------" << endl << endl;
    }
}

void StudentBuilder::usunTablice(Student *&array) {
    delete [] array;
}

void StudentBuilder::wyswietl(Student *array, int size) {
    for (int i = 0; i < size; ++i) {
        cout << "--------------Student " << i + 1 << "--------------" << endl;
        cout << "First name is " << array[i].firstName << endl;
        cout << "Last name is " << array[i].lastName << endl;
        cout << "Mark is " << array[i].mark << endl;
        cout << "-------------------------------------" << endl << endl;
    }
}

void StudentBuilder::wczytajZPliku(Student *&array) {
    string sciezka, linia, pomoc;
    int liczbaStudentow;
    ifstream plik;
    char sredniki;

    // Plik powinien znajdować się w cmake-build-debug
    sciezka = "studenci.csv";

    plik.open(sciezka);
    plik >> liczbaStudentow;

    // Alokowanie pamięci w tab o dlugosci liczbaStudentow
    array = new Student[liczbaStudentow];

    for (int i = 0; i < 2; i++)
        plik >> sredniki;

    for (int i = 0; i < liczbaStudentow; i++) {
        plik >> linia;

        stringstream ss(linia);
        getline(ss, array[i].firstName, ';');
        getline(ss, array[i].lastName, ';');
        getline(ss, pomoc);
        array[i].mark = atoi(pomoc.c_str());
    }
    plik.close();
}

int StudentBuilder::partition(Student*& array, int left, int right, Student pivot, SortType type)
{
    while (left <= right)
    {
        if (type == ASCENDING) {
            while (array[left].mark < pivot.mark)
                left++;
            while (array[right].mark > pivot.mark)
                right--;
        } else { // SortType::DESCENDING
            while (array[left].mark > pivot.mark)
                left++;
            while (array[right].mark < pivot.mark)
                right--;
        }

        if (left <= right)
        {
            swap(array[left], array[right]);
            left += 1;
            right -= 1;
        }
    }

    return left;
}

void StudentBuilder::sortowanieQuickSort(Student*& array, int startIndex, int endIndex, SortType type)
{
    if (startIndex < endIndex)
    {
        int pivotIndex = (startIndex + endIndex) / 2;
        Student pivot = array[pivotIndex];

        int index = partition(array, startIndex, endIndex, pivot, type);
        sortowanieQuickSort(array, startIndex, index - 1, type);
        sortowanieQuickSort(array, index, endIndex, type);
    }
}

void StudentBuilder::sortowanieFlagiPolskiej(Student*& array, int startIndex, int endIndex) {
    int j = endIndex - 1;
    for (int i = startIndex; i < j;) {
        if (array[i].mark <= 10) {
            ++i;
        }

        if (array[j].mark > 10) {
            --j;
        }

        if (i < j) {
            swap(array[i], array[j]);
        }
    }
}

void StudentBuilder::sortowanieFlagiFrancuskiej(Student*& array, int startIndex, int endIndex) {
    int l = startIndex;
    int m = startIndex;
    int p = endIndex - 1;

    Student pivot = array[startIndex];

    while (m <= p) {
        if (array[m].mark % 3 == 0) {
            swap(array[l], array[m]);
            ++l;
            ++m;
        } else if (array[m].mark % 3 == 1) {
            ++m;
        } else if (array[m].mark % 3 == 2) {
            swap(array[m], array[p]);
            --p;
        }
    }
}
