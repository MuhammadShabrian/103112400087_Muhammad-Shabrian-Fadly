#include <iostream>
using namespace std;

struct Edge;
struct Node {
    char info;
    bool isLockdown;
    bool visited;
    Node* nextNode;
    Edge* firstEdge;
};

struct Edge {
    Node* dest;
    Edge* nextEdge;
};

Node* findNode(Node* first, char x) {
    Node* p = first;
    while (p && p->info != x) p = p->nextNode;
    return p;
}

void addNode(Node* &first, char x) {
    Node* n = new Node{x, false, false, NULL, NULL};
    if (!first) first = n;
    else {
        Node* p = first;
        while (p->nextNode) p = p->nextNode;
        p->nextNode = n;
    }
}

void addEdge(Node* first, char src, char dest) {
    Node* s = findNode(first, src);
    Node* d = findNode(first, dest);
    Edge* e = new Edge{d, s->firstEdge};
    s->firstEdge = e;
}

void DFS(Node* n) {
    n->visited = true;
    Edge* e = n->firstEdge;
    while (e) {
        if (!e->dest->visited && !e->dest->isLockdown) DFS(e->dest);
        e = e->nextEdge;
    }
}

int main() {
    Node* graph = NULL;
    char names[] = {'A', 'B', 'C', 'D', 'E'};
    for (char c : names) addNode(graph, c);

    addEdge(graph, 'A', 'B'); addEdge(graph, 'B', 'A');
    addEdge(graph, 'B', 'C'); addEdge(graph, 'C', 'B');
    addEdge(graph, 'B', 'E'); addEdge(graph, 'E', 'B');
    addEdge(graph, 'C', 'D'); addEdge(graph, 'D', 'C');

    cout << "Membangun Jaringan Distribusi Vaksin" << endl;
    Node* p = graph;
    while (p) {
        cout << "Node " << p->info << " terhubung ke: ";
        Edge* e = p->firstEdge;
        while (e) { cout << e->dest->info; e = e->nextEdge; }
        cout << endl; p = p->nextNode;
    }

    cout << "\nAnalisis Kota Kritis (Single Point of Failure)" << endl;
    p = graph;
    while (p) {
        p->isLockdown = true;
        Node* start = (p == graph) ? graph->nextNode : graph;
        
        Node* temp = graph;
        while (temp) { temp->visited = false; temp = temp->nextNode; }
        
        DFS(start);

        bool disconnected = false;
        temp = graph;
        while (temp) {
            if (temp != p && !temp->visited) { disconnected = true; break; }
            temp = temp->nextNode;
        }

        if (disconnected) {
            cout << "[PERINGATAN] Kota " << p->info << " adalah KOTA KRITIS!" << endl;
            cout << "-> Jika " << p->info << " lockdown, distribusi terputus." << endl;
        } else {
            cout << "Kota " << p->info << " aman (redundansi oke)." << endl;
        }
        p->isLockdown = false;
        p = p->nextNode;
    }
    return 0;
}