#include "circular.h"
#include <iostream>

using namespace std;

void createList(list &L) {
    L.first = Nil;
}

address alokasi(infotype x) {
    address P = new elemen;
    P->info = x;
    P->next = Nil;
    return P;
}

void insertFirst(list &L, address P) {
    if (L.first == Nil) {
        L.first = P;
        P->next = P;
    } else {
        address Q = L.first;
        while (Q->next != L.first)
            Q = Q->next;

        P->next = L.first;
        Q->next = P;
        L.first = P;
    }
}

void insertLast(list &L, address P) {
    if (L.first == Nil) {
        insertFirst(L, P);
    } else {
        address Q = L.first;
        while (Q->next != L.first)
            Q = Q->next;

        Q->next = P;
        P->next = L.first;
    }
}

void printInfo(list L) {
    if (L.first == Nil) {
        cout << "List kosong" << endl;
        return;
    }

    address P = L.first;
    do {
        cout << P->info.nama << " | "
             << P->info.nim << " | "
             << P->info.jenis_kelamin << " | "
             << P->info.ipk << endl;
        P = P->next;
    } while (P != L.first);
}
