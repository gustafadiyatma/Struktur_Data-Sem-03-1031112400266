#include <iostream>
#define Nil NULL
using namespace std;

typedef int infotype;
typedef struct elmlist *address;

struct elmlist {
    infotype info;
    address next;
    address prev;
};

struct List {
    address first;
    address last;
};

// Fungsi Dasar (createList, alokasi, insertFirst, insertLast, insertAfter)
void createList(List &L) {
    L.first = Nil;
    L.last = Nil;
}

address alokasi(infotype x) {
    address P = new elmlist;
    if (P != Nil) {
        P->info = x;
        P->next = Nil;
        P->prev = Nil;
    }
    return P;
}

void insertFirst(List &L, address P) {
    P->next = L.first;
    P->prev = Nil;
    if (L.first != Nil)
        L.first->prev = P;
    else
        L.last = P;
    L.first = P;
}

void insertLast(List &L, address P) {
    P->prev = L.last;
    P->next = Nil;
    if (L.last != Nil)
        L.last->next = P;
    else
        L.first = P;
    L.last = P;
}

void insertAfter(List &L, address P, address R) {
    if (R != Nil) {
        P->next = R->next;
        P->prev = R;
        if (R->next != Nil)
            R->next->prev = P;
        else
            L.last = P;
        R->next = P;
    }
}

// Fungsi Tambahan 1: insertBefore
/**
 * Menyisipkan elemen baru (P) sebelum elemen yang ditunjuk oleh Q.
 * @param L List
 * @param P address elemen baru yang akan disisipkan
 * @param Q address elemen yang menjadi acuan (elemen baru akan disisipkan SEBELUM Q)
 */
void insertBefore(List &L, address P, address Q) {
    if (Q == Nil || P == Nil) {
        // Handle case: Q is Nil (not found or list is empty) or P is Nil (allocation failed)
        return; 
    }
    
    // Kasus 1: Q adalah elemen pertama
    if (Q == L.first) {
        insertFirst(L, P);
        return;
    }

    // Kasus 2: Q berada di tengah atau di akhir
    address Prec = Q->prev; // Dapatkan elemen sebelum Q
    
    // Hubungkan P ke Prec dan Q
    P->next = Q;
    P->prev = Prec;
    
    // Hubungkan Prec dan Q ke P
    if (Prec != Nil) {
        Prec->next = P;
    }
    Q->prev = P;
    
    // Catatan: Jika Q == L.first, ini sudah ditangani di Kasus 1,
    // jadi tidak perlu khawatir L.first berubah di sini.
}

// Fungsi Utilitas 1: Mencari elemen berdasarkan info (untuk insertBefore)
address findElement(List L, infotype x) {
    address P = L.first;
    while (P != Nil) {
        if (P->info == x) {
            return P;
        }
        P = P->next;
    }
    return Nil; // Tidak ditemukan
}

// Fungsi Utilitas 2: Mencetak list dari Depan ke Belakang (Forward)
void printInfo(List L) {
    address P = L.first;
    while (P != Nil) {
        cout << P->info << " ";
        P = P->next;
    }
    cout << endl;
}

// Fungsi Tambahan 2: Mencetak list dari Belakang ke Depan (Reverse)
void printReverse(List L) {
    address P = L.last;
    while (P != Nil) {
        cout << P->info << " ";
        P = P->prev;
    }
    cout << endl;
}

// Fungsi Main
int main() {
    List L;
    createList(L);

    // Initial List Creation: 1 3 2
    address P1 = alokasi(1);
    insertFirst(L, P1); // List: 1

    address P2 = alokasi(2);
    insertLast(L, P2); // List: 1 2

    address P3 = alokasi(3);
    address R3 = findElement(L, 1);
    insertAfter(L, P3, R3); // List: 1 3 2 (Insert 3 after 1)

    cout << "🔵 TASK 1: INSERT OPERATIONS" << endl;
    cout << "---" << endl;
    cout << "**List awal:**" << endl;
    cout << "Forward: ";
    printInfo(L);
    cout << "Backward: ";
    printReverse(L);

    // 1. Insert 4 before 2 (Before Q=2, Info=4)
    address P4 = alokasi(4);
    address Q2 = findElement(L, 2);
    if (Q2 != Nil) {
        insertBefore(L, P4, Q2);
        cout << "**Berhasil insert 4 sebelum 2**" << endl; // Success message
    }

    // 2. Insert 5 before 1 (Before Q=1, Info=5)
    address P5 = alokasi(5);
    address Q1 = findElement(L, 1);
    if (Q1 != Nil) {
        insertBefore(L, P5, Q1);
        cout << "**Berhasil insert 5 sebelum 1**" << endl; // Success message
    }
    
    cout << "---" << endl;
    cout << "**List setelah insertBefore:**" << endl;
    cout << "Forward: ";
    printInfo(L);
    cout << "Backward: ";
    printReverse(L);

    return 0;
}