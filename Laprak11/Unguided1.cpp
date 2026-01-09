#include "multilist.h"
#include <iostream>
using namespace std;

int main() {
    list_induk L;
    createList(L);

    address_induk P1, P2;
    address_anak PDel;

    P1 = alokasi(1);
    insertLastInduk(L, P1);

    P2 = alokasi(2);
    insertLastInduk(L, P2);

    address_anak A1 = alokasiAnak(10);
    address_anak A2 = alokasiAnak(11);
    insertLastAnak(P1->anak, A1);
    insertLastAnak(P1->anak, A2);

    address_anak A3 = alokasiAnak(20);
    address_anak A4 = alokasiAnak(19);
    insertLastAnak(P2->anak, A3);
    insertFirstAnak(P2->anak, A4);

    printInfo(L);

    cout << "Menghapus anak terakhir dari Induk 1..." << endl;
    deleteLastAnak(P1->anak, PDel);

    printInfo(L);

    return 0;
}
