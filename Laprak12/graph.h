#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
using namespace std;

typedef char infotype;

struct edge;
struct node;

typedef node* adrNode;
typedef edge* adrEdge;

struct edge {
    adrNode dest;
    adrEdge next;
};

struct node {
    infotype info;
    adrEdge firstEdge;
    adrNode next;
};

struct Graph {
    adrNode firstNode;
};

// PROTOTYPE FUNGSI (WAJIB ADA)
void createGraph(Graph &G);
void insertNode(Graph &G, infotype x);
void connectNode(Graph &G, infotype x, infotype y);
adrNode findNode(Graph G, infotype x);
void printGraph(Graph G);
void printDFS(Graph G, adrNode start);
void printBFS(Graph G, adrNode start);

#endif
