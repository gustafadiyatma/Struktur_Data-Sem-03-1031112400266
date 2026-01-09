#include <iostream>
using namespace std;
#define Nil NULL

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

// --- Fungsi Dasar ---
address alokasi(infotype x) {
    address P = new elmlist;
    P -> info = x; P -> next = Nil; P -> prev = Nil; return P;
}

void dealokasi(address &P) { delete P; P = Nil; }

void insertFirst(List &L, address P) {
    P -> next = L.first; P -> prev = Nil;
    if (L.first != Nil) L.first -> prev = P; else L.last = P;
    L.first = P;
}

void printInfo(List L) {
    address P = L.first; while (P != Nil) { cout << P -> info << " "; P = P -> next; } cout << endl;
}

void deleteFirst(List &L, address &P) {
    if (L.first == Nil) return;
    
    P = L.first; L.first = L.first -> next;
    
    if (L.first != Nil) L.first -> prev = Nil; else L.last = Nil;
    
    P -> next = Nil; P -> prev = Nil;
}

void deleteLast(List &L, address &P) {
    if (L.first == Nil) return;

    P = L.last; L.last = L.last -> prev;
    
    if (L.last != Nil) L.last -> next = Nil; else L.first = Nil;
    
    P -> prev = Nil; P -> next = Nil;
}

void deleteAfter(List &L, address &P, address R) {
    if (R == Nil || R->next == Nil) return; // R is Nil or R is last element
    
    P = R -> next; 
    R -> next = P -> next;
    
    if (P -> next != Nil) P -> next -> prev = R; else L.last = R;
    
    P -> prev = Nil; P -> next = Nil;
}

// --- Fungsi Tambahan 1: deleteByValue ---
/**
 * Menghapus elemen PERTAMA yang memiliki info = x.
 * @param L List
 * @param x Nilai (info) elemen yang akan dihapus.
 * @return true jika penghapusan berhasil, false jika nilai tidak ditemukan.
 */
bool deleteByValue(List &L, infotype x) {
    address P = L.first;
    address P_del = Nil;
    
    // Cari elemen dengan info = x
    while (P != Nil) {
        if (P->info == x) {
            P_del = P;
            break;
        }
        P = P->next;
    }
    
    // Jika elemen tidak ditemukan
    if (P_del == Nil) {
        return false;
    }
    
    // Kasus 1: Elemen yang dihapus adalah yang pertama (L.first)
    if (P_del == L.first) {
        deleteFirst(L, P_del);
    } 
    // Kasus 2: Elemen yang dihapus adalah yang terakhir (L.last)
    else if (P_del == L.last) {
        deleteLast(L, P_del);
    }
    // Kasus 3: Elemen yang dihapus berada di tengah
    else {
        address Prec = P_del->prev;
        address Succ = P_del->next;
        
        // Hubungkan Prec ke Succ
        if (Prec != Nil) Prec->next = Succ;
        // Hubungkan Succ ke Prec
        if (Succ != Nil) Succ->prev = Prec;
        
        // Bersihkan pointer P_del
        P_del->next = Nil;
        P_del->prev = Nil;
    }

    // Lakukan dealokasi
    dealokasi(P_del);
    return true;
}

// --- Fungsi Tambahan 2: deleteAll ---
/**
 * Menghapus SEMUA elemen dalam list.
 * @param L List
 * @return Jumlah elemen yang berhasil dihapus.
 */
int deleteAll(List &L) {
    int count = 0;
    address P_del;
    
    while (L.first != Nil) {
        deleteFirst(L, P_del); // Hapus elemen pertama
        dealokasi(P_del);      // Dealokasi elemen yang dihapus
        count++;
    }
    
    // Pastikan list benar-benar kosong
    L.first = Nil;
    L.last = Nil;
    
    return count;
}


// --- Main Program ---
int main() {
    List L; 
    L.first = Nil; 
    L.last = Nil;
    
    // Inisialisasi list awal: 2 3 2 1
    insertFirst(L, alokasi(1)); 
    insertFirst(L, alokasi(2)); 
    insertFirst(L, alokasi(3));
    insertFirst(L, alokasi(2)); 

    cout << "🔵 TASK 1: DELETE OPERATIONS" << endl;
    cout << "---" << endl;
    
    cout << "**List awal:** ";
    printInfo(L);
    
    // 1. Panggil deleteByValue(2)
    infotype val_del1 = 2;
    if (deleteByValue(L, val_del1)) {
        cout << "**Nilai " << val_del1 << " berhasil dihapus**" << endl;
    } else {
        cout << "**Nilai " << val_del1 << " tidak ditemukan**" << endl;
    }
    
    cout << "**Setelah deleteByValue(" << val_del1 << "):** ";
    printInfo(L);
    
    // 2. Panggil deleteByValue(5)
    infotype val_del2 = 5;
    if (deleteByValue(L, val_del2)) {
        cout << "**Nilai " << val_del2 << " berhasil dihapus**" << endl;
    } else {
        cout << "**Nilai " << val_del2 << " tidak ditemukan**" << endl;
    }
    
    cout << "**List tetap:** ";
    printInfo(L);
    
    // 3. Tambahkan data baru (5 4 3 2 1) untuk pengujian deleteAll
    insertFirst(L, alokasi(4)); 
    insertFirst(L, alokasi(5)); 
    
    cout << "**List setelah tambah data:** ";
    printInfo(L);
    
    // 4. Panggil deleteAll
    int deleted_count = deleteAll(L);
    
    cout << "**Semua elemen (" << deleted_count << ") berhasil dihapus**" << endl;
    
    // Verifikasi list kosong
    // cout << "List akhir (seharusnya kosong): ";
    // printInfo(L);

    return 0;
}