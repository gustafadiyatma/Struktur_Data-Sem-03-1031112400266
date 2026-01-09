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