#include <iostream>
#define Nil NULL // Penggunaan NULL di C++ dapat diganti dengan nullptr, tapi Nil tetap fungsional.
using namespace std;

// --- STRUKTUR DATA ---
typedef int infotype;
typedef struct elmlist *address;

struct elmlist {
    infotype info;
    address next = Nil; // Inisialisasi default
    address prev = Nil; // Inisialisasi default
};

struct List {
    address first = Nil; // Inisialisasi default
    address last = Nil;  // Inisialisasi default
};

// --- FUNGSI DASAR ---

address alokasi(infotype x) {
    // Alokasi dipindahkan ke atas agar bisa digunakan oleh fungsi insert
    address P = new elmlist;
    if (P) P->info = x; // Hanya set info, next/prev sudah Nil dari struct
    return P;
}

void printInfo(List L) {
    // Dipindahkan ke atas untuk urutan yang lebih baik
    address P = L.first;
    while (P) { // Mengganti P != Nil menjadi P
        cout << P->info << " ";
        P = P->next;
    }
    cout << endl;
}

void insertFirst(List &L, address P) {
    if (!P) return; // Cek alokasi
    P->next = L.first;
    P->prev = Nil;
    if (L.first) L.first->prev = P; else L.last = P;
    L.first = P;
}

void insertLast(List &L, address P) {
    if (!P) return; // Cek alokasi
    P->prev = L.last;
    P->next = Nil;
    if (L.last) L.last->next = P; else L.first = P;
    L.last = P;
}

void insertAfter(List &L, address P, address R) {
    if (!P || !R) return; // Cek P dan R
    P->next = R->next;
    P->prev = R;
    
    if (R->next)
        R->next->prev = P;
    else
        L.last = P; // P menjadi elemen terakhir
    
    R->next = P;
}

// --- MAIN PROGRAM ---
int main() {
    List L;
    // L.first = Nil; L.last = Nil; tidak diperlukan karena sudah ada inisialisasi default di struct

    // List awal: [1]
    address P1 = alokasi(1);
    insertFirst(L, P1);

    // List setelah insertLast: [1 2]
    address P2 = alokasi(2);
    insertLast(L, P2);

    // List setelah insertAfter (3 setelah 1): [1 3 2]
    address P3 = alokasi(3);
    insertAfter(L, P3, P1);

    cout << "Isi list: ";
    printInfo(L);

    return 0;
}