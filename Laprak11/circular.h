#ifndef CIRCULAR_H_INCLUDED
#define CIRCULAR_H_INCLUDED

#include <string>
using namespace std;

#define Nil NULL

struct mahasiswa {
    string nama;
    string nim;
    char jenis_kelamin;
    float ipk;
};

typedef mahasiswa infotype;

struct elemen;
typedef elemen* address;

struct elemen {
    infotype info;
    address next;
};

struct list {
    address first;
};

void createList(list &L);
address alokasi(infotype x);
void insertFirst(list &L, address P);
void insertLast(list &L, address P);
void printInfo(list L);

#endif
