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
