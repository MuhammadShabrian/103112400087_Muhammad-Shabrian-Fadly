# <h1 align="center">Laporan Praktikum Modul 14 - GRAPH </h1>
<p align="center">Muhammad Shabrian Fadly - 103112400087</p>

## Dasar Teori
Teori graf adalah cabang matematika yang mempelajari hubungan antar objek menggunakan struktur yang disebut graf, yang terdiri dari simpul (node/vertex) dan sisi (edge) yang menghubungkan simpul-simpul tersebut. Tujuannya untuk memvisualisasikan hubungan dalam bentuk yang mudah dipahami.
Fungsi utamanya adalah memvisualisasikan objek-objek agar dapat dipahami dengan lebih mudah. Dalam kehidupan sehari-hari, penerapangraf  dapat  ditemui dalam berbagai bentuk, seperti bagan struktur organisasi, diagram alir, visualisasi peta, skema jaringan listrik, dan berbagai representasi visual lainnya.[673]

Jenis-jenis Graf

Graf G didefinisikan sebagai pasangan himpunan (V,E), ditulis dengan notasi G=(V,E), yang dalam hal ini V adalah himpunan tidak kosong dari simpul-simpul dan E adalah himpunan sisi yang menghubungkan sepasang simpul (Munir, R. 2005).

1. Berdasarkan ada tidaknya loop atau sisi ganda pada suatu graf
Dalam teori ini, simpul mewakili entitas atau objek, sedangkan sisi adalah hubungan antara simpul-simpul tersebut. Misalnya, dalam jaringan sosial, simpul dapat mewakili pengguna, dan sisi menggambarkan hubungan pertemanan di antara mereka.

-Graf sederhana (simple graph): Graf yang tidak mengandung loop maupun sisi ganda.
-Graf tak-sederhana (unsimple-graph): Graf yang mengandung loop maupun sisi ganda.

2. Berdasarkan orientasi arah pada sisi
Graf Berarah dan Tidak Berarah: Graf yang berisi sisi dengan arah disebut “graf berarah,” sedangkan graf yang tidak memiliki arah pada sisinya disebut “graf tidak berarah.” Misalnya, peta jalan kota adalah contoh graf berarah karena jalan-jalan memiliki arah, sementara jaringan telepon adalah contoh graf tidak berarah karena panggilan bisa berjalan dalam dua arah.

-Graf tak berarah (undirected graph): Graf yang sisinya tidak mempunyai orientasi arah.
-Graf berarah (directed graph/digraph): Graf yang setiap sisinya diberikan orientasi arah.

3. Graf Berbobot
Beberapa graf memiliki bobot pada setiap sisi, yang menggambarkan nilai atau jarak. Misalnya, dalam peta jalan kota, bobot bisa merepresentasikan jarak antara persimpulan.

## Guided 

### 1.Guided 1

```C++
//graph.h
#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
using namespace std;

typedef char infoGraph;
typedef struct ElmNode* adrNode;
typedef struct ElmEdge* adrEdge;

struct ElmEdge {
    adrNode node;
    adrEdge next;
};

struct ElmNode {
    infoGraph info;
    bool visited;
    adrEdge firstEdge;
    adrNode nextNode;
};

struct elmGraph {
    adrNode first;
};

typedef struct elmGraph *Graph;

//Prototype
void createGraph(Graph &G);
adrNode allocateNode(infoGraph x);
void insertNode(Graph &G, infoGraph x);
void connectNode(Graph &G, infoGraph start, infoGraph end);
void printGraph(Graph G);

#endif

```

```C++
//graph_init.cpp
#include "graph.h"

void createGraph(Graph &G) {
    G->first = NULL;
}

adrNode allocateNode(infoGraph x) {
    adrNode P = new ElmNode;
    P->info = x;
    P->visited = false;
    P->firstEdge = NULL;
    P->nextNode = NULL;
    return P;
}

void insertNode(Graph &G, infoGraph x) {
    adrNode P = allocateNode(x);
    if (G->first == NULL) {
        G->first = P;
    } else {
        adrNode Q = G->first;
        while (Q->nextNode != NULL) {
            Q = Q->nextNode;
        }
        Q->nextNode = P;
    }
}

```
```C++
//graph_edge.cpp
#include "graph.h"

adrNode findNode(Graph G, infoGraph x) {
    adrNode p = G->first;
    while (p != NULL) {
        if (p->info == x) return p;
        p = p->nextNode;
    }
    return NULL;
}

void connectNode(Graph &G, infoGraph start, infoGraph end) {
    adrNode pStart = findNode(G, start);
    adrNode pEnd = findNode(G, end);

    if (pStart != NULL && pEnd != NULL) {
        adrEdge newEdge = new ElmEdge;
        newEdge->node = pEnd;
        newEdge->next = pStart->firstEdge;
        //Insert First di list Edge
        pStart->firstEdge = newEdge;
    }
}

```
```C++
//graph_print.cpp
#include "graph.h"

void printGraph(Graph G) {
    adrNode p = G->first;
    while (p != NULL) {
        cout << "Node " << p->info << " terhubung ke: ";
        adrEdge e = p->firstEdge;
        while (e != NULL) {
            cout << e->node->info << " ";
            e = e->next;
        }
        cout << endl;
        p = p->nextNode;
    }
}

```
```C++
//main.cpp
#include "graph.h"
#include <iostream>

using namespace std;

int main() {
    // 1. Create Graph
    Graph G = new elmGraph;
    createGraph(G);

    // 2. Insert Nodes
    insertNode(G, 'A');
    insertNode(G, 'B');
    insertNode(G, 'C');
    insertNode(G, 'D');

    // 3. Connect Nodes (Edges)
    connectNode(G, 'A', 'B');
    connectNode(G, 'A', 'C');
    connectNode(G, 'B', 'D');
    connectNode(G, 'C', 'D');

    // 4. Print Graph Structure
    cout << "Isi Graph:" << endl;
    printGraph(G);

    return 0;
}

```

Program guided 1 ini mengimplementasikan graf berarah menggunakan struktur data linked list, di mana setiap simpul memiliki daftar sisi yang menunjukkan arah keterhubungan ke simpul lain. Program menyediakan fungsi untuk membuat graf kosong, menambahkan simpul, menghubungkan simpul secara berarah, serta menampilkan struktur graf dalam bentuk daftar keterhubungan. Implementasi ini bertujuan untuk memperkenalkan konsep dasar graf berarah dan cara merepresentasikan hubungan satu arah antar simpul secara sederhana.


## Unguided 

### 1. Buatlah ADT Graph tidak berarah file “graph.h”: Buatlah implementasi ADT Graph pada file “graph.cpp” dan cobalah hasil implementasi ADT pada file “main.cpp”.

```C++
//graph.h
#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
using namespace std;

typedef char infoGraph;
typedef struct ElmNode *adrNode;
typedef struct ElmEdge *adrEdge;

struct ElmEdge {
    adrNode Node;
    adrEdge Next;
};

struct ElmNode {
    infoGraph info;
    int visited;
    adrEdge firstEdge;
    adrNode Next;
};

struct Graph {
    adrNode first;
};

void CreateGraph(Graph &G);
adrNode AllocateNode(infoGraph X);
adrEdge AllocateEdge(adrNode N);
void InsertNode(Graph &G, infoGraph X);
void ConnectNode(adrNode N1, adrNode N2);
adrNode FindNode(Graph G, infoGraph X);
void PrintInfoGraph(Graph G);

#endif

```C++
//graph.cpp
#include "graph.h"

void CreateGraph(Graph &G) {
    G.first = NULL;
}

adrNode AllocateNode(infoGraph X) {
    adrNode P = new ElmNode;
    P->info = X;
    P->visited = 0;
    P->firstEdge = NULL;
    P->Next = NULL;
    return P;
}

adrEdge AllocateEdge(adrNode N) {
    adrEdge E = new ElmEdge;
    E->Node = N;
    E->Next = NULL;
    return E;
}

void InsertNode(Graph &G, infoGraph X) {
    adrNode P = AllocateNode(X);
    if (G.first == NULL) {
        G.first = P;
    } else {
        adrNode Q = G.first;
        while (Q->Next != NULL)
            Q = Q->Next;
        Q->Next = P;
    }
}

adrNode FindNode(Graph G, infoGraph X) {
    adrNode P = G.first;
    while (P != NULL) {
        if (P->info == X)
            return P;
        P = P->Next;
    }
    return NULL;
}

void ConnectNode(adrNode N1, adrNode N2) {
    adrEdge E1 = AllocateEdge(N2);
    E1->Next = N1->firstEdge;
    N1->firstEdge = E1;

    adrEdge E2 = AllocateEdge(N1);
    E2->Next = N2->firstEdge;
    N2->firstEdge = E2;
}

void PrintInfoGraph(Graph G) {
    adrNode P = G.first;
    while (P != NULL) {
        cout << P->info << " -> ";
        adrEdge E = P->firstEdge;
        while (E != NULL) {
            cout << E->Node->info << " ";
            E = E->Next;
        }
        cout << endl;
        P = P->Next;
    }
}

```

```C++
//main.cpp
#include "graph.h"

int main() {
    Graph G;
    CreateGraph(G);

    InsertNode(G,'A');
    InsertNode(G,'B');
    InsertNode(G,'C');
    InsertNode(G,'D');
    InsertNode(G,'E');
    InsertNode(G,'F');
    InsertNode(G,'G');
    InsertNode(G,'H');

    adrNode A = FindNode(G,'A');
    adrNode B = FindNode(G,'B');
    adrNode C = FindNode(G,'C');
    adrNode D = FindNode(G,'D');
    adrNode E = FindNode(G,'E');
    adrNode F = FindNode(G,'F');
    adrNode Gg = FindNode(G,'G');
    adrNode H = FindNode(G,'H');


    ConnectNode(A,B);
    ConnectNode(A,C);
    ConnectNode(B,D);
    ConnectNode(B,E);
    ConnectNode(D,H);
    ConnectNode(C,F);
    ConnectNode(C,Gg);

    cout << "Representasi Graph :" << endl;
    PrintInfoGraph(G);

    return 0;
}


```

### Output Unguided 1 :
![Output Unguided1](https://github.com/MuhammadShabrian/103112400087_Muhammad-Shabrian-Fadly/blob/main/Pertemuan12/Output%20Unguided1.png)

Program Unguided 1 ini mengimplementasikan Abstract Data Type (ADT) graf tidak berarah, di mana setiap sisi yang dibuat akan menghubungkan dua simpul secara dua arah. Struktur graf dibangun menggunakan simpul dan sisi berbasis linked list, dengan fitur pembuatan graf, penambahan simpul, pencarian simpul, penghubungan antar simpul, serta penampilan graf dalam bentuk adjacency list. Program ini menunjukkan bagaimana hubungan timbal balik antar simpul dapat direpresentasikan dan dikelola secara sistematis.


### 2. Buatlah prosedur untuk menampilkanhasil penelusuran DFS. prosedur PrintDFS (Graph G, adrNode N);

```C++
//graph.h
#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
using namespace std;

typedef char infoGraph;
typedef struct ElmNode *adrNode;
typedef struct ElmEdge *adrEdge;

struct ElmEdge {
    adrNode Node;
    adrEdge Next;
};

struct ElmNode {
    infoGraph info;
    int visited;
    adrEdge firstEdge;
    adrNode Next;
};

struct Graph {
    adrNode first;
};

void CreateGraph(Graph &G);
adrNode AllocateNode(infoGraph X);
adrEdge AllocateEdge(adrNode N);
void InsertNode(Graph &G, infoGraph X);
void ConnectNode(adrNode N1, adrNode N2);
adrNode FindNode(Graph G, infoGraph X);
void PrintInfoGraph(Graph G);
void PrintDFS(Graph G, adrNode N);

#endif

```

```C++
//graph.cpp
#include "graph.h"

void CreateGraph(Graph &G) {
    G.first = NULL;
}

adrNode AllocateNode(infoGraph X) {
    adrNode P = new ElmNode;
    P->info = X;
    P->visited = 0;
    P->firstEdge = NULL;
    P->Next = NULL;
    return P;
}

adrEdge AllocateEdge(adrNode N) {
    adrEdge E = new ElmEdge;
    E->Node = N;
    E->Next = NULL;
    return E;
}

void InsertNode(Graph &G, infoGraph X) {
    adrNode P = AllocateNode(X);
    if (G.first == NULL) {
        G.first = P;
    } else {
        adrNode Q = G.first;
        while (Q->Next != NULL)
            Q = Q->Next;
        Q->Next = P;
    }
}

adrNode FindNode(Graph G, infoGraph X) {
    adrNode P = G.first;
    while (P != NULL) {
        if (P->info == X)
            return P;
        P = P->Next;
    }
    return NULL;
}

void ConnectNode(adrNode N1, adrNode N2) {
    adrEdge E1 = AllocateEdge(N2);
    E1->Next = N1->firstEdge;
    N1->firstEdge = E1;

    adrEdge E2 = AllocateEdge(N1);
    E2->Next = N2->firstEdge;
    N2->firstEdge = E2;
}

void PrintInfoGraph(Graph G) {
    adrNode P = G.first;
    while (P != NULL) {
        cout << P->info << " -> ";
        adrEdge E = P->firstEdge;
        while (E != NULL) {
            cout << E->Node->info << " ";
            E = E->Next;
        }
        cout << endl;
        P = P->Next;
    }
}

void PrintDFS(Graph G, adrNode N) {
    if (N == NULL || N->visited == 1)
        return;

    cout << N->info << " ";
    N->visited = 1;

    adrEdge E = N->firstEdge;
    while (E != NULL) {
        PrintDFS(G, E->Node);
        E = E->Next;
    }
}

```
```C++
//main.cpp
#include "graph.h"

int main() {
    Graph G;
    CreateGraph(G);

    InsertNode(G,'A');
    InsertNode(G,'B');
    InsertNode(G,'C');
    InsertNode(G,'D');
    InsertNode(G,'E');
    InsertNode(G,'F');
    InsertNode(G,'G');
    InsertNode(G,'H');

    adrNode A = FindNode(G,'A');
    adrNode B = FindNode(G,'B');
    adrNode C = FindNode(G,'C');
    adrNode D = FindNode(G,'D');
    adrNode E = FindNode(G,'E');
    adrNode F = FindNode(G,'F');
    adrNode Gg = FindNode(G,'G');
    adrNode H = FindNode(G,'H');

    ConnectNode(A,B);
    ConnectNode(A,C);
    ConnectNode(B,D);
    ConnectNode(B,E);
    ConnectNode(D,H);
    ConnectNode(C,F);
    ConnectNode(C,Gg);

    adrNode P = G.first;
    while (P != NULL) {
        P->visited = 0;
        P = P->Next;
    }

    cout << "DFS : ";
    PrintDFS(G, A);
    cout << endl;

    return 0;
}

```

### Output Unguided 2 :
![Output Unguided2](https://github.com/MuhammadShabrian/103112400087_Muhammad-Shabrian-Fadly/blob/main/Pertemuan12/Output%20Unguided2.png)

Program Unguided 2 ini mengembangkan graf tidak berarah dengan menambahkan prosedur penelusuran Depth First Search (DFS). Penelusuran dilakukan secara rekursif dengan mengunjungi simpul secara mendalam hingga seluruh simpul yang terhubung telah dikunjungi. Setiap simpul diberi penanda untuk mencegah kunjungan berulang. Program ini digunakan untuk memahami mekanisme penelusuran graf yang berfokus pada eksplorasi jalur secara mendalam. 

### 3. Buatlah prosedur untuk menampilkanhasil penelusuran DFS. prosedur PrintBFS (Graph G, adrNode N);
```C++
//graph.h
#ifndef GRAPH_H
#define GRAPH_H

#include <queue>
#include <iostream>
using namespace std;

typedef char infoGraph;
typedef struct ElmNode *adrNode;
typedef struct ElmEdge *adrEdge;

struct ElmEdge {
    adrNode Node;
    adrEdge Next;
};

struct ElmNode {
    infoGraph info;
    int visited;
    adrEdge firstEdge;
    adrNode Next;
};

struct Graph {
    adrNode first;
};

void CreateGraph(Graph &G);
adrNode AllocateNode(infoGraph X);
adrEdge AllocateEdge(adrNode N);
void InsertNode(Graph &G, infoGraph X);
void ConnectNode(adrNode N1, adrNode N2);
adrNode FindNode(Graph G, infoGraph X);
void PrintInfoGraph(Graph G);
void PrintBFS(Graph G, adrNode N);

#endif

```

```C++
//graph.cpp
#include "graph.h"
#include <queue>

void CreateGraph(Graph &G) {
    G.first = NULL;
}

adrNode AllocateNode(infoGraph X) {
    adrNode P = new ElmNode;
    P->info = X;
    P->visited = 0;
    P->firstEdge = NULL;
    P->Next = NULL;
    return P;
}

adrEdge AllocateEdge(adrNode N) {
    adrEdge E = new ElmEdge;
    E->Node = N;
    E->Next = NULL;
    return E;
}

void InsertNode(Graph &G, infoGraph X) {
    adrNode P = AllocateNode(X);
    if (G.first == NULL) {
        G.first = P;
    } else {
        adrNode Q = G.first;
        while (Q->Next != NULL)
            Q = Q->Next;
        Q->Next = P;
    }
}

adrNode FindNode(Graph G, infoGraph X) {
    adrNode P = G.first;
    while (P != NULL) {
        if (P->info == X)
            return P;
        P = P->Next;
    }
    return NULL;
}

void ConnectNode(adrNode N1, adrNode N2) {
    adrEdge E1 = AllocateEdge(N2);
    E1->Next = N1->firstEdge;
    N1->firstEdge = E1;

    adrEdge E2 = AllocateEdge(N1);
    E2->Next = N2->firstEdge;
    N2->firstEdge = E2;
}

void PrintInfoGraph(Graph G) {
    adrNode P = G.first;
    while (P != NULL) {
        cout << P->info << " -> ";
        adrEdge E = P->firstEdge;
        while (E != NULL) {
            cout << E->Node->info << " ";
            E = E->Next;
        }
        cout << endl;
        P = P->Next;
    }
}

void PrintBFS(Graph G, adrNode N) {
    queue<adrNode> Q;
    Q.push(N);

    while (!Q.empty()) {
        adrNode P = Q.front();
        Q.pop();

        if (P->visited == 0) {
            cout << P->info << " ";
            P->visited = 1;

            adrEdge E = P->firstEdge;
            while (E != NULL) {
                if (E->Node->visited == 0)
                    Q.push(E->Node);
                E = E->Next;
            }
        }
    }
}

```C++
//main.cpp
#include "graph.h"

int main() {
    Graph G;
    CreateGraph(G);

    InsertNode(G,'A');
    InsertNode(G,'B');
    InsertNode(G,'C');
    InsertNode(G,'D');
    InsertNode(G,'E');
    InsertNode(G,'F');
    InsertNode(G,'G');
    InsertNode(G,'H');

    adrNode A = FindNode(G,'A');
    adrNode B = FindNode(G,'B');
    adrNode C = FindNode(G,'C');
    adrNode D = FindNode(G,'D');
    adrNode E = FindNode(G,'E');
    adrNode F = FindNode(G,'F');
    adrNode Gg = FindNode(G,'G');
    adrNode H = FindNode(G,'H');

    ConnectNode(A,B);
    ConnectNode(A,C);
    ConnectNode(B,D);
    ConnectNode(B,E);
    ConnectNode(C,F);
    ConnectNode(C,Gg);
    ConnectNode(D,H);

    adrNode P = G.first;
    while (P != NULL) {
        P->visited = 0;
        P = P->Next;
    }

    cout << "BFS : ";
    PrintBFS(G, A);
    cout << endl;

    return 0;
}

```

### Output Unguided 3 :

![Output Unguided3](https://github.com/MuhammadShabrian/103112400087_Muhammad-Shabrian-Fadly/blob/main/Pertemuan12/Output%20Unguided3.png)

Program Unguided 3 ini mengimplementasikan penelusuran Breadth First Search (BFS) pada graf tidak berarah menggunakan struktur data queue. Penelusuran dilakukan dengan mengunjungi simpul berdasarkan tingkat keterhubungan, dimulai dari simpul awal dan dilanjutkan ke simpul-simpul tetangga secara berurutan. Penanda kunjungan digunakan untuk memastikan setiap simpul hanya diproses satu kali. Program ini memperlihatkan cara kerja penelusuran graf secara melebar dan perbedaannya dengan DFS.

## Kesimpulan
Dari praktikum ini, Graf dapat direpresentasikan menggunakan struktur data linked list untuk menyimpan simpul dan sisi. Perbedaan antara graf berarah dan tidak berarah terlihat dari cara hubungan antar simpul dibentuk. Penerapan algoritma DFS dan BFS menunjukkan perbedaan metode penelusuran, yaitu penelusuran secara mendalam dan penelusuran secara melebar. Secara keseluruhan, praktikum ini memberikan gambaran yang jelas mengenai struktur graf dan cara penelusurannya dalam bentuk implementasi program.

## Referensi
[1] Andriani, A., Damanik, N. G., Damanik, T., Kembaren, S. N. B., Hutagalung, C. F., Harahap, D. M., Manik, S. G., Silitonga, N. S. S., & Haris, D. (2025). Studi literatur: Pembelajaran teori graph sebagai alat untuk meningkatkan keterampilan berpikir kritis siswa. Kognitif: Jurnal Riset HOTS Pendidikan Matematika, 5(2), 670–680. https://doi.org/10.51574/kognitif.v5i2.2381

<br>[2]Telkom University Surabaya. (n.d.). Teori graf: Sejarah, manfaat, dan aplikasinya. Diakses dari https://surabaya.telkomuniversity.ac.id/teori-graf-sejarah-manfaat-dan-aplikasinya/
