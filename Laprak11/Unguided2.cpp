#include "circular.h"
#include <iostream>

using namespace std;

int main() {
    list L;
    createList(L);

    insertFirst(L, alokasi({"Ali", "01", 'L', 3.3}));
    insertLast(L,  alokasi({"Bobi", "02", 'L', 3.7}));
    insertLast(L,  alokasi({"Cindi", "03", 'P', 3.5}));
    insertFirst(L, alokasi({"Danu", "04", 'L', 4.0}));

    cout << "Data Mahasiswa:" << endl;
    printInfo(L);

    return 0;
}
