## 1. Nama, NIM, Kelas
- **Nama**: Gustaf Adiyatma Al fito 
- **NIM**: 103112400266
- **Kelas**: IF - 12 - 05

## 2. Motivasi Belajar Struktur Data
Supaya Saya bisa Struktur Data

## 3. Dasar Teori
Graph merupakan salah satu struktur data non-linier yang digunakan untuk merepresentasikan hubungan antar objek, di mana graph terdiri dari sekumpulan simpul (vertex/node) dan sisi (edge) yang menghubungkan antar simpul tersebut. Graph dapat bersifat berarah maupun tidak berarah; pada graph tidak berarah, hubungan antar simpul bersifat dua arah. Salah satu teknik penelusuran graph adalah Breadth First Search (BFS), yaitu algoritma traversal yang bekerja dengan cara mengunjungi simpul awal terlebih dahulu, kemudian seluruh simpul yang bertetangga langsung pada level yang sama sebelum melanjutkan ke level berikutnya. BFS umumnya diimplementasikan menggunakan struktur data queue (antrian) untuk menyimpan simpul yang akan dikunjungi berikutnya, sehingga urutan penelusuran berlangsung secara melebar. Algoritma BFS banyak digunakan dalam pencarian jalur terpendek, analisis jaringan, dan penelusuran struktur graph secara sistematis.

## 4. Guided
### 4.1 graph_edge.cpp

**-Code Program-**

```cpp
#include "graph.h"

adrNode findNode(Graph G, infoGraph X) {
    adrNode P = G.first;
    while (P != NULL) {
        if (P->info == X) return P;
        P = P->next;
    }
    return NULL;
}

void connectNode(Graph &G, infoGraph start, infoGraph end) {
    adrNode pStart = findNode(G, start);
    adrNode pEnd = findNode(G, end);

    if (pStart != NULL && pEnd != NULL) {
        adrEdge newEdge = new ElmEdge;
        newEdge->node = pEnd;
        newEdge->next = pStart->firstEdge; // Insert First di list Edge
        pStart->firstEdge = newEdge;
    }
} 
```

**-Penjelasan Umum-**
ungsi findNode digunakan untuk mencari simpul (node) dalam graf G berdasarkan nilai informasi X dengan menelusuri linked list node dari G.first hingga ditemukan node yang cocok atau mencapai akhir list. Jika ditemukan, fungsi mengembalikan alamat node tersebut, jika tidak maka mengembalikan NULL. Sementara itu, fungsi connectNode berfungsi untuk menghubungkan dua node dalam graf, yaitu dari node start ke node end. Fungsi ini terlebih dahulu mencari alamat kedua node menggunakan findNode. Jika keduanya ada, maka dibuat sebuah edge baru (ElmEdge) yang menunjuk ke node tujuan (pEnd), lalu edge tersebut dimasukkan ke awal daftar edge milik node awal (pStart) menggunakan teknik insert first, sehingga hubungan antar node berhasil dibentuk dalam struktur graf.

### 4.2 graph_init.cpp

**-Code Program-**
```cpp
#include "graph.h"

void createGraph(Graph &G) {
    G.first = NULL;
}

adrNode allocateNode(infoGraph X) {
    adrNode P = new ElmNode;
    P->info = X;
    P->visited = false;
    P->firstEdge = NULL;
    P->next = NULL;
    return P;
}

void insertNode(Graph &G, infoGraph X) {
    adrNode P = allocateNode(X);
    if (G.first == NULL) {
        G.first = P;
    } else {
        adrNode Q = G.first;
        while (Q->next != NULL) {
            Q = Q->next;
        }
        Q->next = P;
    }
}
```
**-Penjelasan Umum-**
membuat dan menambahkan node pada struktur graf yang direpresentasikan menggunakan linked list. Fungsi createGraph berperan untuk menginisialisasi graf dengan mengatur pointer first menjadi NULL, yang menandakan bahwa graf masih kosong. Fungsi allocateNode bertugas mengalokasikan memori untuk node baru, mengisi nilai informasi node (info) dengan data X, mengatur status visited menjadi false, serta menginisialisasi pointer firstEdge dan next ke NULL. Selanjutnya, fungsi insertNode digunakan untuk memasukkan node baru ke dalam graf; jika graf masih kosong, node langsung dijadikan sebagai node pertama, sedangkan jika graf sudah berisi node, maka penambahan dilakukan di akhir linked list node dengan menelusuri node terakhir terlebih dahulu.

### 4.3 graph_print.cpp
**-Code Program-**
```cpp
void printGraph(Graph G) {
    adrNode P = G.first;
    while (P != NULL) {
        cout << "Node " << P->info << " terhubung ke: ";
        adrEdge E = P->firstEdge;
        while (E != NULL) {
            cout << E->node->info << " ";
            E = E->next;
        }
        cout << endl;
        P = P->next;
    }
}
```

**-Penjelasan Umum-**
fungsi printGraph digunakan untuk menampilkan struktur graf dalam bentuk adjacency list. Proses dimulai dengan menelusuri seluruh node pada graf dari pointer G.first. Untuk setiap node P, fungsi mencetak informasi node tersebut, lalu menelusuri daftar edge yang terhubung melalui pointer firstEdge. Setiap edge akan menampilkan informasi node tujuan (E->node->info) yang menandakan adanya hubungan dari node saat ini ke node lain. Setelah seluruh edge dari satu node ditampilkan, fungsi berpindah ke node berikutnya hingga semua node dalam graf dicetak, sehingga hubungan antar node dapat dilihat secara jelas.f

### 4.4 main.cpp

**-Code Program-**
```cpp
#include "graph.h"
#include <iostream>

using namespace std;

int main() {
    Graph G;
    createGraph(G);

    
    insertNode(G, 'A');
    insertNode(G, 'B');
    insertNode(G, 'C');
    insertNode(G, 'D');


    connectNode(G, 'A', 'B'); // A ke B
    connectNode(G, 'A', 'C'); // A ke C
    connectNode(G, 'B', 'D'); // B ke D
    connectNode(G, 'C', 'D'); // C ke D

    cout << "Isi Graph:" << endl;
    printGraph(G);

    return 0;
}
```

**Penjelasan Umum**
berfungsi sebagai program utama untuk menguji implementasi graf. Program dimulai dengan membuat sebuah variabel graf G dan menginisialisasinya menggunakan fungsi createGraph. Selanjutnya, beberapa node dimasukkan ke dalam graf dengan nilai 'A', 'B', 'C', dan 'D'. Setelah semua node dibuat, fungsi connectNode digunakan untuk membentuk hubungan antar node, yaitu dari A ke B, A ke C, B ke D, dan C ke D, yang menunjukkan graf berarah. Terakhir, program mencetak isi graf menggunakan fungsi printGraph, sehingga hubungan antar node dapat dilihat dalam bentuk adjacency list sebelum program diakhiri.

## 5. Unguided
### 5.1 Unguided 1

**-Code Program-**
```cpp
#include "graph.h"
#include <iostream>
using namespace std;

int main() {
    Graph G;
    createGraph(G);

    char nodes[] = {'A','B','C','D','E','F','G','H'};
    for (char n : nodes) {
        insertNode(G, n);
    }

    connectNode(G, 'A', 'B');
    connectNode(G, 'A', 'C');

    connectNode(G, 'B', 'D');
    connectNode(G, 'B', 'E');

    connectNode(G, 'C', 'F');
    connectNode(G, 'C', 'G');

    connectNode(G, 'D', 'H');
    connectNode(G, 'E', 'H');
    connectNode(G, 'F', 'H');
    connectNode(G, 'G', 'H');

    cout << "=== UNGUIDED 1: Graph Tidak Berarah ===" << endl;
    printGraph(G);

    return 0;
}

```

**-Penjelasan Umum-**
Program ini digunakan untuk membangun dan menampilkan graph tidak berarah menggunakan struktur data graph yang didefinisikan pada graph.h. Pertama, graph diinisialisasi dengan createGraph, kemudian delapan node berlabel A sampai H dimasukkan ke dalam graph. Setelah itu, node-node tersebut dihubungkan satu sama lain menggunakan fungsi connectNode sesuai dengan relasi yang telah ditentukan, di mana setiap koneksi bersifat dua arah karena graph tidak berarah. Hubungan antar node membentuk struktur bertingkat yang berakhir pada node H sebagai simpul tujuan. Terakhir, fungsi printGraph digunakan untuk menampilkan seluruh node beserta hubungan antar node ke layar, sehingga pengguna dapat melihat representasi graph yang telah dibangun tanpa mengubah hasil output meskipun kode telah dimodifikasi.

**-Output-**
![](output/output6.png)


### 5.2 Unguided 2
**-Code Program-**
```cpp
#include "graph.h"
#include <iostream>
using namespace std;

int main() {
    Graph G;
    createGraph(G);

    
    char nodes[] = {'A','B','C','D','E','F','G','H'};
    for (char n : nodes) {
        insertNode(G, n);
    }

   
    connectNode(G, 'A', 'B');
    connectNode(G, 'A', 'C');

    connectNode(G, 'B', 'D');
    connectNode(G, 'B', 'E');

    connectNode(G, 'C', 'F');
    connectNode(G, 'C', 'G');

    connectNode(G, 'D', 'H');
    connectNode(G, 'E', 'H');
    connectNode(G, 'F', 'H');
    connectNode(G, 'G', 'H');

    cout << "=== UNGUIDED 2: DFS (Mulai dari A) ===" << endl;

    adrNode startNode = findNode(G, 'A');
    printDFS(G, startNode);
    cout << endl;

    return 0;
}

```

**-Penjelasan Umum-**
Program ini membangun sebuah graph tidak berarah yang terdiri dari delapan node berlabel A sampai H, kemudian menampilkan hasil traversal Depth First Search (DFS) yang dimulai dari node A. Setelah graph diinisialisasi menggunakan createGraph, seluruh node dimasukkan dan dihubungkan sesuai struktur yang telah ditentukan sehingga membentuk relasi bertingkat menuju node H. Selanjutnya, program mencari alamat node A dengan fungsi findNode sebagai titik awal traversal, lalu memanggil fungsi printDFS untuk menelusuri graph secara mendalam, yaitu mengunjungi satu cabang sampai ke node terdalam sebelum berpindah ke cabang lain. Karena struktur graph dan titik awal traversal tidak diubah, hasil output DFS yang ditampilkan tetap sama meskipun kode telah dimodifikasi.




### 5.3 Unguided 3
**-Code Program-**
```cpp
#include "graph.h"
#include <iostream>
using namespace std;

int main() {
    Graph G;
    createGraph(G);

    char nodes[] = {'A','B','C','D','E','F','G','H'};
    for (char n : nodes) {
        insertNode(G, n);
    }

    connectNode(G, 'A', 'B');
    connectNode(G, 'A', 'C');

    connectNode(G, 'B', 'D');
    connectNode(G, 'B', 'E');

    connectNode(G, 'C', 'F');
    connectNode(G, 'C', 'G');

    connectNode(G, 'D', 'H');
    connectNode(G, 'E', 'H');
    connectNode(G, 'F', 'H');
    connectNode(G, 'G', 'H');

    cout << "=== UNGUIDED 3: BFS (Mulai dari A) ===" << endl;

    adrNode startNode = findNode(G, 'A');
    printBFS(G, startNode);
    cout << endl;

    return 0;
}

```

**-Penjelasan Umum-**
Program ini membangun sebuah graph tidak berarah yang terdiri dari delapan node berlabel A sampai H, kemudian melakukan traversal Breadth First Search (BFS) dengan titik awal pada node A. Setelah graph diinisialisasi menggunakan createGraph, seluruh node dimasukkan melalui fungsi insertNode dan dihubungkan satu sama lain menggunakan connectNode sesuai struktur yang telah ditentukan. Selanjutnya, program mencari alamat node A sebagai simpul awal menggunakan findNode, lalu fungsi printBFS digunakan untuk menelusuri graph secara melebar, yaitu mengunjungi semua node yang bertetangga langsung terlebih dahulu sebelum berpindah ke level berikutnya. Hasil traversal BFS kemudian ditampilkan ke layar sesuai urutan kunjungan tanpa mengubah struktur graph yang telah dibentuk.

## 6. Kesimpulan
Berdasarkan implementasi dan pengujian program, dapat disimpulkan bahwa struktur data graph dapat digunakan secara efektif untuk merepresentasikan hubungan antar simpul melalui node dan edge. Penerapan algoritma Breadth First Search (BFS) memungkinkan penelusuran graph dilakukan secara melebar dimulai dari simpul awal, sehingga seluruh simpul dapat dikunjungi berdasarkan tingkat kedekatannya. Program berhasil membangun graph tidak berarah sesuai dengan struktur yang ditentukan dan menampilkan urutan traversal BFS dengan benar, sehingga menunjukkan bahwa konsep graph dan algoritma BFS telah diterapkan dengan tepat sesuai landasan teori yang digunakan.

## 7. Referensi
1. https://www.programiz.com/cpp-programming/online-compiler/
2. https://www.onlinegdb.com/online_c++_compiler