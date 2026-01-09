## 1. Nama, NIM, Kelas
- **Nama**: Gustaf Adiyatma Al fito 
- **NIM**: 103112400266
- **Kelas**: IF - 12 - 05

## 2. Motivasi Belajar Struktur Data
Supaya Saya bisa Struktur Data

## 3. Dasar Teori
konsep circular single linked list, yaitu struktur data linier yang terdiri dari kumpulan node di mana setiap node memiliki dua bagian, yaitu data dan pointer ke node berikutnya, serta node terakhir menunjuk kembali ke node pertama sehingga membentuk suatu lingkaran. Berbeda dengan linked list biasa yang berakhir pada pointer NULL, circular linked list memungkinkan traversal dilakukan secara terus-menerus dari node mana pun. Operasi dasar yang dipelajari meliputi pembuatan list (createList), alokasi memori node (alokasi), pencarian elemen (findElm), serta penyisipan node di awal (insertFirst), di akhir (insertLast), dan setelah node tertentu (insertAfter). Struktur data ini banyak digunakan pada sistem antrian berulang, penjadwalan, dan aplikasi yang membutuhkan proses rotasi data secara kontinu.
## 4. Guided
### 4.1 Main.cpp

**-Code Program-**

```cpp
#include "multilist.h"
#include <iostream>
using namespace std;

int main() {
    list_induk L;
    createList(L);

    address_induk P1 = alokasi(1);
    insertLastInduk(L, P1);

    address_anak PA1 = alokasiAnak(10);
    insertLastAnak(P1->anak, PA1);

    address_induk P2 = alokasi(2);
    insertLastInduk(L, P2);

    address_anak PA2 = alokasiAnak(20);
    insertLastAnak(P2->anak, PA2);

    printInfo(L);
    return 0;
}
```

**-Penjelasan Umum-**
Program ini membuat sebuah multiple linked list yang terdiri dari list induk dan list anak. Pertama, list induk L diinisialisasi menggunakan createList. Kemudian dibuat dua node induk dengan nilai 1 dan 2, lalu masing-masing dimasukkan ke dalam list induk.
**-Output-**



### 4.2 multilist_anak.cpp

**-Code Program-**
```cpp
#include "multilist.h"

address_anak alokasiAnak(infotype x) {
    address_anak P = new elemen_anak;
    P->info = x;
    P->next = Nil;
    P->prev = Nil;
    return P;
}

void insertFirstAnak(list_anak &LA, address_anak PA) {
    if (LA.first == Nil) {
        LA.first = PA;
        LA.last = PA;
    } else {
        PA->next = LA.first;
        LA.first->prev = PA;
        LA.first = PA;
    }
}

void insertLastAnak(list_anak &LA, address_anak PA) {
    if (LA.first == Nil) {
        insertFirstAnak(LA, PA);
    } else {
        PA->prev = LA.last;
        LA.last->next = PA;
        LA.last = PA;
    }
}

void deleteFirstAnak(list_anak &LA, address_anak &PA) {
    if (LA.first != Nil) {
        PA = LA.first;
        if (LA.first == LA.last) {
            LA.first = Nil;
            LA.last = Nil;
        } else {
            LA.first = LA.first->next;
            LA.first->prev = Nil;
            PA->next = Nil;
        }
    }
}

void deleteLastAnak(list_anak &LA, address_anak &PA) {
    if (LA.first != Nil) {
        PA = LA.last;
        if (LA.first == LA.last) {
            LA.first = Nil;
            LA.last = Nil;
        } else {
            LA.last = LA.last->prev;
            LA.last->next = Nil;
            PA->prev = Nil;
        }
    }
}
```
**-Penjelasan Umum-**
Kode tersebut mengimplementasikan operasi dasar pada list anak dalam struktur multiple linked list yang menggunakan double linked list. Fungsi alokasiAnak digunakan untuk membuat node anak baru dengan menginisialisasi data serta pointer next dan prev. Fungsi insertFirstAnak dan insertLastAnak berfungsi untuk menambahkan node anak ke awal dan ke akhir list anak, baik saat list masih kosong maupun sudah berisi. Sementara itu, fungsi deleteFirstAnak dan deleteLastAnak digunakan untuk menghapus node anak pertama dan terakhir dengan tetap menjaga keterhubungan antar node serta kondisi list ketika hanya terdapat satu elemen.

### 4.3 multilist.cpp
**-Code Program-**
```cpp
#include "multilist.h"

void createList(list_induk &L) {
    L.first = Nil;
    L.last = Nil;
}

address_induk alokasi(infotype x) {
    address_induk P = new elemen_induk;
    P->info = x;
    P->next = Nil;
    P->prev = Nil;
    P->anak.first = Nil;
    P->anak.last = Nil;
    return P;
}

void insertLastInduk(list_induk &L, address_induk P) {
    if (L.first == Nil) {
        L.first = P;
        L.last = P;
    } else {
        P->prev = L.last;
        L.last->next = P;
        L.last = P;
    }
}

void insertFirstInduk(list_induk &L, address_induk P) {
    if (L.first == Nil) {
        L.first = P;
        L.last = P;
    } else {
        P->next = L.first;
        L.first->prev = P;
        L.first = P;
    }
}

void insertAfterInduk(list_induk &L, address_induk Prec, address_induk P) {
    if (Prec != Nil) {
        P->next = Prec->next;
        P->prev = Prec;
        if (Prec->next != Nil) {
            Prec->next->prev = P;
        } else {
            L.last = P;
        }
        Prec->next = P;
    }
}

void deleteFirstInduk(list_induk &L, address_induk &P) {
    if (L.first != Nil) {
        P = L.first;
        if (L.first == L.last) {
            L.first = Nil;
            L.last = Nil;
        } else {
            L.first = L.first->next;
            L.first->prev = Nil;
            P->next = Nil;
        }
    }
}

void deleteLastInduk(list_induk &L, address_induk &P) {
    if (L.first != Nil) {
        P = L.last;
        if (L.first == L.last) {
            L.first = Nil;
            L.last = Nil;
        } else {
            L.last = L.last->prev;
            L.last->next = Nil;
            P->prev = Nil;
        }
    }
}

address_induk findInduk(list_induk L, infotype x) {
    address_induk P = L.first;
    while (P != Nil) {
        if (P->info == x) return P;
        P = P->next;
    }
    return Nil;
}

void printInfo(list_induk L) {
    address_induk PI = L.first;
    cout << "=== DATA MULTILIST ===" << endl;
    while (PI != Nil) {
        cout << "Induk ID: " << PI->info << endl;
        address_anak PA = PI->anak.first;
        if (PA == Nil) {
            cout << "   (Tidak ada anak)" << endl;
        } else {
            while (PA != Nil) {
                cout << "   -> Anak ID: " << PA->info << endl;
                PA = PA->next;
            }
        }
        PI = PI->next;
    }
    cout << endl;
}
```

**-Penjelasan Umum-**
berfungsi untuk mengelola list induk pada struktur multiple linked list yang menggunakan double linked list. Fungsi createList digunakan untuk menginisialisasi list induk agar berada dalam kondisi kosong. Fungsi alokasi berperan membuat node induk baru, mengisi data induk, mengatur pointer next dan prev, serta menginisialisasi list anak agar masih kosong. Proses penambahan node induk dilakukan melalui fungsi insertFirstInduk, insertLastInduk, dan insertAfterInduk untuk menyisipkan data di awal, akhir, atau setelah node tertentu. Penghapusan node induk ditangani oleh deleteFirstInduk dan deleteLastInduk dengan tetap menjaga keterhubungan antar node. Fungsi findInduk digunakan untuk mencari node induk berdasarkan nilai tertentu, sedangkan printInfo menampilkan seluruh data induk beserta anak-anaknya dalam struktur multilinked list.\

### 4.4 multilist.h

**-Code Program-**
```cpp
#ifndef MULTILIST_H_INCLUDED
#define MULTILIST_H_INCLUDED
#include <iostream>
#define Nil NULL

using namespace std;

typedef int infotype;
typedef struct elemen_induk *address_induk;
typedef struct elemen_anak *address_anak;

struct elemen_anak {
    infotype info;
    address_anak next;
    address_anak prev;
};

struct list_anak {
    address_anak first;
    address_anak last;
};

struct elemen_induk {
    infotype info;
    list_anak anak;
    address_induk next;
    address_induk prev;
};

struct list_induk {
    address_induk first;
    address_induk last;
};

void createList(list_induk &L);
address_induk alokasi(infotype x);
void insertFirstInduk(list_induk &L, address_induk P);
void insertLastInduk(list_induk &L, address_induk P);
void insertAfterInduk(list_induk &L, address_induk Prec, address_induk P);
void deleteFirstInduk(list_induk &L, address_induk &P);
void deleteLastInduk(list_induk &L, address_induk &P);
void deleteAfterInduk(list_induk &L, address_induk Prec, address_induk &P);
address_induk findInduk(list_induk L, infotype x);

address_anak alokasiAnak(infotype x);
void insertFirstAnak(list_anak &LA, address_anak PA);
void insertLastAnak(list_anak &LA, address_anak PA);
void insertAfterAnak(list_anak &LA, address_anak Prec, address_anak PA);
void deleteFirstAnak(list_anak &LA, address_anak &PA);
void deleteLastAnak(list_anak &LA, address_anak &PA);
void deleteAfterAnak(list_anak &LA, address_anak Prec, address_anak &PA);
address_anak findAnak(list_anak LA, infotype x);

void printInfo(list_induk L);

#endif
```

**-Penjelasan Umum-**
Header file ini mendefinisikan struktur dan prototipe fungsi untuk membangun multiple linked list yang terdiri dari list induk dan list anak, keduanya menggunakan double linked list. Di dalamnya terdapat pendefinisian tipe data, pointer alamat, serta struktur node induk dan anak beserta list-nya. File ini juga mendeklarasikan fungsi-fungsi dasar untuk membuat list, mengalokasikan node, melakukan operasi penyisipan, penghapusan, pencarian data pada induk maupun anak, serta menampilkan seluruh isi multilinked list. Header ini berperan sebagai penghubung antara implementasi dan program utama agar pengelolaan data menjadi terstruktur dan modular.


## 5. Unguided
### 5.1 Unguided 1

**-Code Program-**
```cpp
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

```

**-Penjelasan Umum-**
Program tersebut merupakan contoh penerapan multiple linked list yang terdiri dari list induk dan list anak. Pada awal program, list induk diinisialisasi agar berada dalam kondisi kosong. Selanjutnya dibuat dua node induk dengan nilai 1 dan 2 yang dimasukkan ke dalam list induk. Masing-masing induk kemudian diberi beberapa node anak, di mana induk pertama memiliki anak bernilai 10 dan 11, sedangkan induk kedua memiliki anak bernilai 19 dan 20.

Setelah seluruh data dimasukkan, fungsi printInfo digunakan untuk menampilkan isi multilinked list, yaitu data induk beserta anak-anaknya. Program kemudian menghapus node anak terakhir dari induk pertama menggunakan fungsi deleteLastAnak, lalu menampilkan kembali isi list untuk memperlihatkan perubahan yang terjadi. Dengan demikian, program ini menunjukkan proses penambahan, penampilan, dan penghapusan data pada struktur multiple linked list.
**-Output-**
![](SS/unguided 1.png)


### 5.2 Unguided 2
**-Code Program-**
```cpp
#include "circular.h"
#include <iostream>

using namespace std;

void tambahAfter(List &L, string cariNIM, infotype data) {
    address p = findElm(L, cariNIM);
    if (p != NULL) {
        insertAfter(L, p, alokasi(data));
    }
}

int main() {
    List L;
    createList(L);

    cout << "coba insert first, last, dan after" << endl;

    insertFirst(L, alokasi({"Danu", "04", '1', 4.0}));
    insertFirst(L, alokasi({"Ali", "01", '1', 3.3}));
    insertLast(L,  alokasi({"Fahmi", "06", '1', 3.45}));

    tambahAfter(L, "01", {"Bobi", "02", '1', 3.71});
    tambahAfter(L, "02", {"Cindi", "03", 'p', 3.5});
    tambahAfter(L, "04", {"Eli", "05", 'p', 3.4});

    insertLast(L, alokasi({"Gita", "07", 'p', 3.75}));
    tambahAfter(L, "07", {"Hilmi", "08", '1', 3.3});

    printInfo(L);

    return 0;
}

```

**-Penjelasan Umum-**
Program ini bertujuan untuk menguji operasi pada circular single linked list dengan data mahasiswa yang berisi nama, NIM, golongan, dan IPK. List diinisialisasi kosong menggunakan createList, kemudian dilakukan penyisipan data menggunakan insertFirst, insertLast, dan insertAfter. Fungsi findElm digunakan untuk mencari node berdasarkan NIM agar data baru dapat disisipkan setelah node tertentu. Karena bersifat circular, node terakhir selalu menunjuk kembali ke node pertama sehingga tidak ada pointer NULL di akhir list. Seluruh data kemudian ditampilkan menggunakan printInfo, yang menelusuri list satu putaran penuh. Modifikasi kode yang dilakukan hanya berupa perapian (refactoring) tanpa mengubah urutan penyisipan maupun hasil output program.

**-Output-**
![](output/output6.png)


## 6. Kesimpulan
bahwa struktur data circular single linked list dapat diimplementasikan dengan baik untuk mengelola data yang saling terhubung secara melingkar tanpa adanya pointer NULL di akhir list. Melalui penerapan operasi insertFirst, insertLast, dan insertAfter, program mampu menyisipkan data pada berbagai posisi dengan tetap menjaga sifat circular. Penggunaan fungsi pencarian (findElm) membantu memastikan penyisipan data dilakukan pada node yang tepat. Secara keseluruhan, program ini menunjukkan bahwa pemahaman konsep pointer dan linked list sangat penting dalam pengolahan struktur data dinamis serta dapat diterapkan pada berbagai kasus yang membutuhkan pengolahan data secara berulang.

## 7. Referensi
1. https://www.programiz.com/cpp-programming/online-compiler/

2. https://www.onlinegdb.com/online_c++_compiler
