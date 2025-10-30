## 1. Nama, NIM, Kelas
- **Nama**: Gustaf Adiyatma Al fito 
- **NIM**: 103112400266
- **Kelas**: IF - 12 - 05

## 2. Motivasi Belajar Struktur Data
Supaya Saya bisa Struktur Data

## 3. Dasar Teori
DLL adalah struktur data di mana setiap node tahu siapa tetangganya di depan (next) dan di belakang (prev), memungkinkan navigasi dua arah. Operasi penyisipan seperti insertBefore atau insertAfter wajib mengelola empat sambungan pointer secara hati-hati, sementara operasi penghapusan seperti deleteByValue harus memutus node dari list dan mengembalikan memorinya lewat dealokasi. Bagian advanced-nya, smartInsert menentukan posisi node baru berdasarkan empat aturan kondisi kompleks (termasuk genap/ganjil), dan conditionalDelete menghapus semua node yang memenuhi kriteria tersebut.
## 4. Guided
### 4.1 Guided 1

**-Code Program-**

```cpp
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

void printInfo(List L) {
    address P = L.first;
    while (P != Nil) {
        cout << P->info << " ";
        P = P->next;
    }
    cout << endl;
}

int main() {
    List L;
    createList(L);

    address P1 = alokasi(1);
    insertFirst(L, P1);

    address P2 = alokasi(2);
    insertLast(L, P2);

    address P3 = alokasi(3);
    insertAfter(L, P3, P1);

    cout << "Isi list: ";
    printInfo(L);

    return 0;
}

```

**-Penjelasan Umum-**
Program ini adalah implementasi dari Double Linked List (DLL) dalam bahasa C++.
Double Linked List adalah struktur data berantai dua arah, di mana setiap elemen (node) memiliki penunjuk ke elemen sebelumnya (prev) dan penunjuk ke elemen berikutnya (next).

**-Output-**
![](output/guided1.png)


### 4.2 Guided 2

**-Code Program-**
```cpp
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
    P = L.first; L.first = L.first -> next;
    if (L.first != Nil) L.first -> prev = Nil; else L.last = Nil;
    P -> next = Nil; P -> prev = Nil;
}

void deleteLast(List &L, address &P) {
    P = L.last; L.last = L.last -> prev;
    if (L.last != Nil) L.last -> next = Nil; else L.first = Nil;
    P -> prev = Nil; P -> next = Nil;
}

void deleteAfter(List &L, address &P, address R) {
    P = R -> next; R -> next = P -> next;
    if (P -> next != Nil) P -> next -> prev = R; else L.last = R;
    P -> prev = Nil; P -> next = Nil;
}

int main() {
    List L; L.first = Nil; L.last = Nil;
    insertFirst(L, alokasi(1)); insertFirst(L, alokasi(2)); insertFirst(L, alokasi(3));
    printInfo(L);
    address P; deleteFirst(L, P); dealokasi(P);
    deleteAfter(L, P, L.first); dealokasi(P);
    printInfo(L);
    return 0;
}
```
**-Penjelasan Umum-**
Program ini adalah implementasi struktur data Double Linked List (daftar berantai ganda) yang bisa menambah dan menghapus elemen di awal, akhir, atau setelah elemen tertentu dalam list.
Double Linked List memungkinkan kita bergerak maju dan mundur melalui data karena tiap node punya dua pointer

**-Output-**
![](output/guided2.png)


## 5. Unguided
### 5.1 Unguided 1

**-Code Program-**
```cpp
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
```

**-Penjelasan Umum-**
Fungsi insertBefore menyisipkan node baru (P) sebelum node acuan (Q), menangani kasus khusus jika Q adalah elemen pertama (L.first). Sementara itu, fungsi printReverse memanfaatkan pointer prev dalam Doubly Linked List dengan memulai traversal dari L.last dan bergerak mundur untuk mencetak urutan terbalik.
**-Output-**
![](output/unguided1.png)


### 5.2 Unguided 2
**-Code Program-**
```cpp
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
```

**-Penjelasan Umum-**
deleteByValue mencari kemunculan pertama nilai x; jika ditemukan, node tersebut dikeluarkan dari list dengan menghubungkan node sebelum dan sesudahnya, lalu di-dealokasi. Fungsi deleteAll menghapus semua elemen secara berurutan, berulang kali memanggil logika penghapusan elemen pertama (deleteFirst) dan melakukan dealokasi hingga list benar-benar kosong.

**-Output-**
![](output/unguided2.png)



### 5.3 Unguided 3
**-Code Program-**
```cpp
#include <iostream>
#define Nil NULL
using namespace std;

typedef int infotype;
typedef struct elmlist *address;
struct elmlist { infotype info; address next = Nil; address prev = Nil; };
struct List { address first = Nil; address last = Nil; };

// --- FUNGSI DASAR & UTILITAS MINIMAL ---

address alokasi(infotype x) { address P = new elmlist; P->info = x; return P; }
void dealokasi(address &P) { delete P; P = Nil; }

// Traversal
void printInfo(List L) { address P = L.first; while (P) { cout << P->info << " "; P = P->next; } cout << endl; }
void printReverse(List L) { address P = L.last; while (P) { cout << P->info << " "; P = P->prev; } cout << endl; }

// Penghapusan Umum (Memutus node P_del dari List L)
void deleteNode(List &L, address &P_del) {
    if (!P_del) return;
    address Prec = P_del->prev;
    address Succ = P_del->next;

    if (P_del == L.first) L.first = Succ;
    if (P_del == L.last) L.last = Prec;

    if (Prec) Prec->next = Succ;
    if (Succ) Succ->prev = Prec;
    
    dealokasi(P_del);
}

// Penyisipan (First & Last Digabungkan)
void insertNode(List &L, address P, address Q = Nil) {
    if (!Q || Q == L.first) { // Insert First
        P->next = L.first;
        if (L.first) L.first->prev = P; else L.last = P;
        L.first = P;
    } else { // Insert After Q (untuk kasus Last)
        P->next = Q->next; P->prev = Q;
        if (Q->next) Q->next->prev = P; else L.last = P;
        Q->next = P;
    }
}

// --- FUNGSI ADVANCED 1: smartInsert ---
void smartInsert(List &L, address P) {
    infotype x = P->info;
    if (!L.first || x < L.first->info) {
        insertNode(L, P);
        cout << "Smart Insert: " << (!L.first ? "List kosong, " : x < L.first->info ? to_string(x) + " < first, " : "List kosong, ") << "insert " << x << " di first" << endl;
    } else if (x % 2 == 0 || x > L.last->info) {
        insertNode(L, P, L.last); // Insert Last
        cout << "Smart Insert: " << x << (x % 2 == 0 ? " genap" : " > last") << ", insert di last" << endl;
    } else {
        address Q = L.first;
        while (Q->next && Q->next->info < x) Q = Q->next;
        insertNode(L, P, Q); // Insert After Q
        cout << "Smart Insert: " << x << " ganjil, insert di antara " << Q->info << " dan " << (Q->next ? to_string(Q->next->info) : "akhir") << endl;
    }
}

// --- FUNGSI ADVANCED 2: conditionalDelete ---
int conditionalDelete(List &L, bool is_odd) {
    int count = 0;
    address Curr = L.first, Next;

    while (Curr) {
        Next = Curr->next;
        bool cond = (is_odd && Curr->info % 2 != 0) || (!is_odd && Curr->info % 2 == 0);
        if (cond) {
            address P_del = Curr;
            address Prec = P_del->prev;
            address Succ = P_del->next;

            if (P_del == L.first) L.first = Succ;
            if (P_del == L.last) L.last = Prec;

            if (Prec) Prec->next = Succ;
            if (Succ) Succ->prev = Prec;
            
            dealokasi(P_del);
            count++;
        }
        Curr = Next;
    }
    return count;
}

// Fungsi deleteByValue (minimal)
bool deleteByValue(List &L, infotype x) {
    address P = L.first;
    while (P && P->info != x) P = P->next;
    if (!P) return false;
    deleteNode(L, P);
    return true;
}

// Fungsi deleteAll (minimal)
int deleteAll(List &L) {
    int count = 0;
    while (L.first) {
        address P_del = L.first;
        L.first = L.first->next;
        if (L.first) L.first->prev = Nil; else L.last = Nil;
        dealokasi(P_del); count++;
    }
    return count;
}


// --- Main Program ---
int main() {
    List L; 

    cout << "🔵 ADVANCED OPERATIONS" << endl << "---" << endl;
    
    // A. SMART INSERT DEMO
    cout << "SMART INSERT DEMO" << endl;
    smartInsert(L, alokasi(5)); smartInsert(L, alokasi(3)); smartInsert(L, alokasi(8)); 
    smartInsert(L, alokasi(6)); smartInsert(L, alokasi(4)); smartInsert(L, alokasi(7));

    cout << "---" << endl << "**Hasil Smart Insert:**" << endl;
    cout << "Forward: "; printInfo(L);
    cout << "Backward: "; printReverse(L);
    
    // B. CONDITIONAL DELETE DEMO
    cout << "---" << endl << "CONDITIONAL DELETE" << endl;
    cout << "Sebelum Conditional Delete: "; printInfo(L);
    cout << "Conditional Delete: 3 elemen ganjil dihapus" << endl;
    conditionalDelete(L, true);
    cout << "Setelah Conditional Delete: "; printInfo(L);
    
    // C. DELETE BY VALUE DEMO
    cout << "---" << endl << "DELETE BY VALUE DEMO" << endl;
    insertNode(L, alokasi(6)); // Tambahkan 6 lagi: [6 8 6 4]
    
    if (deleteByValue(L, 6)) cout << "Nilai 6 berhasil dihapus" << endl; else cout << "Nilai 6 tidak ditemukan" << endl;
    if (deleteByValue(L, 10)) cout << "Nilai 10 berhasil dihapus" << endl; else cout << "Nilai 10 tidak ditemukan" << endl;

    cout << "List akhir: "; printInfo(L);
    
    // D. DELETE ALL DEMO
    cout << "---" << endl << "DELETE ALL DEMO" << endl;
    cout << "Semua elemen (" << deleteAll(L) << ") berhasil dihapus" << endl;

    return 0;
}
```

**-Penjelasan Umum-**
smartInsert menyisipkan node baru berdasarkan empat kondisi kompleks: disisipkan di first jika list kosong atau nilainya terkecil; di last jika genap atau nilainya terbesar; dan disisipkan di tengah secara terurut jika ganjil. Sementara itu, conditionalDelete menghapus semua node yang memenuhi kondisi ganjil atau genap tertentu sambil mempertahankan struktur list.

**-Output-**
![](output/unguided3.png)

## 6. Kesimpulan
kesimpulannya saya dapat memahami sebagian awalan materi pemrograman mengggunakan bahasa c++ karena ini saya pertama kalinya mengenal bahasa c++

## 7. Referensi
1. https://www.programiz.com/cpp-programming/online-compiler/
2. https://www.onlinegdb.com/online_c++_compiler

