#include "multilist.h"
#include <iostream>
using namespace std;

/* ===================== LIST INDUK ===================== */

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

void insertLastInduk(list_induk &L, address_induk P) {
    if (L.first == Nil) {
        insertFirstInduk(L, P);
    } else {
        P->prev = L.last;
        L.last->next = P;
        L.last = P;
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

void deleteAfterInduk(list_induk &L, address_induk Prec, address_induk &P) {
    if (Prec != Nil && Prec->next != Nil) {
        P = Prec->next;
        Prec->next = P->next;
        if (P->next != Nil) {
            P->next->prev = Prec;
        } else {
            L.last = Prec;
        }
        P->next = Nil;
        P->prev = Nil;
    }
}

address_induk findInduk(list_induk L, infotype x) {
    address_induk P = L.first;
    while (P != Nil) {
        if (P->info == x) {
            return P;
        }
        P = P->next;
    }
    return Nil;
}

/* ===================== LIST ANAK ===================== */

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

void insertAfterAnak(list_anak &LA, address_anak Prec, address_anak PA) {
    if (Prec != Nil) {
        PA->next = Prec->next;
        PA->prev = Prec;
        if (Prec->next != Nil) {
            Prec->next->prev = PA;
        } else {
            LA.last = PA;
        }
        Prec->next = PA;
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

void deleteAfterAnak(list_anak &LA, address_anak Prec, address_anak &PA) {
    if (Prec != Nil && Prec->next != Nil) {
        PA = Prec->next;
        Prec->next = PA->next;
        if (PA->next != Nil) {
            PA->next->prev = Prec;
        } else {
            LA.last = Prec;
        }
        PA->next = Nil;
        PA->prev = Nil;
    }
}

address_anak findAnak(list_anak LA, infotype x) {
    address_anak P = LA.first;
    while (P != Nil) {
        if (P->info == x) {
            return P;
        }
        P = P->next;
    }
    return Nil;
}

/* ===================== OUTPUT ===================== */

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
