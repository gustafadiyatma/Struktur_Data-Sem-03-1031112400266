#include <iostream>
using namespace std;

struct charML {
   string nama;
   charML *next;
}*head, *tail, *curr;

void cariNama(string dicari) {
    charML *leter = head;
    charML *after = nullptr;

    if (leter == nullptr) {
        cout << "List kosong.\n";
        return;
    }

    do {
        after = leter;
        leter = leter->next;
    } while (after != nullptr && after->nama != dicari);

    if (after != nullptr && after->nama == dicari) {
        cout << "Karakter ditemukan: " << after->nama << "\n";
    } else {
        cout << "Karakter '" << dicari << "' tidak ditemukan.\n";
    }
}

int main(){
    curr = new charML;
    curr->nama = "baxia";
    head = curr;
    tail = curr;
    
    curr = new charML;
    curr->nama = "alucrot";
    tail->next = curr;
    tail = curr; 

    curr = new charML;
    curr->nama = "hanzo sumedang";
    tail->next = curr;
    tail = curr;

    curr = new charML;
    curr->nama = "yve tasimalaya";
    tail->next = curr;
    tail = curr;

    curr = new charML;
    curr->nama = "Layla";
    tail->next = curr;
    tail = curr;

    curr = new charML;
    curr->nama = "cleret gombel";
    tail->next = curr;
    tail = curr;
    tail->next = NULL;

    curr = head;
    while(curr != NULL){    
        cout << curr->nama << "\n";
        curr = curr->next;
    }  
    
    cout << "\nHasil pencarian:\n";
    cariNama("cleret gombel");
    cariNama("Layla");

    return 0;
}
