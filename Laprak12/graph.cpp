#include "graph.h"

void createGraph(Graph &G) {
    G.firstNode = NULL;
}

void insertNode(Graph &G, char x) {
    adrNode p = new node;
    p->info = x;
    p->firstEdge = NULL;
    p->next = G.firstNode;
    G.firstNode = p;
}

adrNode findNode(Graph G, char x) {
    adrNode p = G.firstNode;
    while (p != NULL) {
        if (p->info == x) return p;
        p = p->next;
    }
    return NULL;
}

/* connectNode, printGraph, DFS, BFS
   (isi sesuai modul kamu) */
