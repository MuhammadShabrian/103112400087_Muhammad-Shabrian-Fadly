# <h1 align="center">Laporan Praktikum Modul 10 - TREE </h1>
<p align="center">Muhammad Shabrian Fadly - 103112400087</p>

## Dasar Teori

Struktur tree adalah struktur yang mengandung aspek hirarki yang dibentuk melalui pengelompokkan elemen atau node dalam tingkatan tertentu. Terdapat macam-macam jenis tree beserta cabang ilmu lainnya yang berkaitan dengan jenis-jenis tree tersebut. Salah satunya adalah binary tree. Jenis tree tersebut identik dengan ciri parent yang pasti hanya memiliki dua anak. [21]

Struktur data tree menawarkan beberapa keunggulan penting, di antaranya:
<br>-Efisiensi pencarian dan penyisipan data, terutama pada jenis tree seperti Binary Search Tree (BST) yang memungkinkan pencarian dalam waktu logaritmik.
<br>-Representasi relasi hierarkis yang alami, seperti struktur organisasi, direktori file, dan klasifikasi data.
<br>-Fleksibilitas traversal, memungkinkan data diproses dalam berbagai urutan tergantung pada kebutuhan aplikasi.


Beberapa istilah penting dalam tree:

<br>-Root: Node utama paling atas dalam tree.
<br>-Parent & Child: Node yang memiliki koneksi ke node lain disebut induk (parent), sedangkan node yang berada di bawahnya dinamakan anak (child).
<br>-Leaf: Node yang tidak memiliki anak.
<br>-Edge: Garis penghubung antara dua node.
<br>-Path: Jalur dari satu node ke node lainnya melalui edge.
<br>-Height: Panjang maksimum dari root ke leaf terdalam.
<br>-Depth: Jarak dari root ke suatu node.
<br>-Subtree: Pohon kecil yang merupakan bagian dari tree utama.


## Guided 

### 1.Guided 1

```C++
//BST1.h
#ifndef BST1_H
#define BST1_H

#include <iostream>
using namespace std;

typedef int infotype;
typedef struct Node *address;

struct Node{
    infotype info;
    address left;
    address right;

};

bool isEmpty(address root);
void createTree(address &root);
address newNode(infotype x);
address insertNode (address root, infotype x);
void preOrder(address root);
void inOrder(address root);
void postOrder(address root);
int countNodes(address root);
int treeDepth(address root);

#endif

```

```C++
//BST1.cpp
#include "BST1.h"
#include <iostream>

using namespace std;

//isEmpty & createTree
bool isEmpty(address root) { //function untuk mengecek apakah BST kosong atau tidak
    if(root == NULL){
        return true;
    } else {
        return false;
    }
}

void createTree(address &root) { //function untuk membuat BST nya (root di-set sebagai NULL)
    root = NULL;
}


//alokasi & insert
address newNode(infotype x) { //function untuk memasukkan data (infotype) kedalam node
    address temp = new Node;
    temp->info = x;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

address insertNode(address root, infotype x) { //function untuk memasukkan node kedalam BST
    if (root == NULL) {
        return newNode(x);
    }

    if (x < root->info) {
        root->left = insertNode(root->left, x);
    } else if (x > root->info) {
        root->right = insertNode(root->right, x);
    }

    return root;
}


//Traversal
void preOrder(address root) { //function traversal tree secara pre-order (tengah - kiri - kanan atau root - child kiri - child kanan)
    if (root != NULL) {
        cout << root->info << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(address root) { //function traversal tree secara in-order (kiri - tengah - kanan atau child kiri - root - child kanan)
    if (root != NULL) {
        inOrder(root->left);
        cout << root->info << " ";
        inOrder(root->right);
    }
}

void postOrder(address root) { //function traversal tree secara post-order (kiri - kanan - tengah atau child kiri - child kanan - root)
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->info << " ";
    }
}


//Utilities
int countNodes(address root) { //function untuk menghitung size atau ukuran atau jumlah node yang ada didalam tree
    if (isEmpty(root) == true) {
        return 0;
    } else {
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
}

int treeDepth(address root) { //function untuk menghitung height atau kedalaman atau level tree
    if (isEmpty(root) == true) {
        return -1; //tree kosong jika depth = -1
    } else {
        int leftDepth = treeDepth(root->left);
        int rightDepth = treeDepth(root->right);
    
        return (leftDepth > rightDepth ? leftDepth : rightDepth) + 1;
    }
}


```
 
```C++
//main.cpp
#include <iostream>
#include "BST1.h"

using namespace std;

int main(){
    address root;
    createTree(root);

    cout << "Binary Search Tree Insert & Traversal" << endl;
    cout << endl;

    root = insertNode(root, 20); // Root awal
    insertNode(root, 10);
    insertNode(root, 35);
    insertNode(root, 5);
    insertNode(root, 18);
    insertNode(root, 40);

    cout << "Hasil InOrder Traversal : ";
    inOrder(root);
    cout << endl;

    cout << "Hasil PreOrder Traversal : ";
    preOrder(root);
    cout << endl;

    cout << "Hasil PostOrder Traversal : ";
    postOrder(root);
    cout << endl;

    cout << endl;
    cout << "Jumlah Node : " << countNodes(root) << endl;
    cout << "Kedalaman Tree : " << treeDepth(root) << endl;


    return 0;
}
```

Program guided 1 ini menunjukkan cara membangun Binary Search Tree dari awal, mulai dari pembuatan node, mekanisme penyisipan data, hingga proses traversal. Ketiga metode traversal (in-order, pre-order, dan post-order) membantu melihat susunan data dari sudut pandang yang berbeda. Program ini juga menghitung jumlah node dan kedalaman tree untuk mengetahui ukuran serta level terdalam dari struktur yang terbentuk.

### 2.Guided 2
```C++
//BST2.h
#ifndef BST1_H
#define BST1_H

#include <iostream>
using namespace std;

typedef int infotype;
typedef struct Node *address;

struct Node{
    infotype info;
    address left;
    address right;

};

bool isEmpty(address root);
void createTree(address &root);
address newNode(infotype x);
address insertNode (address root, infotype x);
void preOrder(address root);
void inOrder(address root);
void postOrder(address root);
int countNodes(address root);
int treeDepth(address root);
void searchByData(address root, infotype x);
address mostLeft(address root);
address mostRight(address root);
bool deleteNode(address &root, infotype x);
void deleteTree(address &root);

#endif
```
```C++
//BST2.cpp
#include "BST2.h"
#include <iostream>

using namespace std;

//FUNCTION & PROSEDUR SEBELUMNYA
//isEmpty & createTree
bool isEmpty(address root) { //function untuk mengecek apakah BST kosong atau tidak
    if(root == NULL){
        return true;
    } else {
        return false;
    }
}

void createTree(address &root) { //function untuk membuat BST nya (root di-set sebagai NULL)
    root = NULL;
}


//alokasi & insert
address newNode(infotype x) { //function untuk memasukkan data (infotype) kedalam node
    address temp = new Node;
    temp->info = x;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

address insertNode(address root, infotype x) { //function untuk memasukkan node kedalam BST
    if (root == NULL) {
        return newNode(x);
    }

    if (x < root->info) {
        root->left = insertNode(root->left, x);
    } else if (x > root->info) {
        root->right = insertNode(root->right, x);
    }

    return root;
}


//Traversal
void preOrder(address root) { //function traversal tree secara pre-order (tengah - kiri - kanan atau root - child kiri - child kanan)
    if (root != NULL) {
        cout << root->info << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(address root) { //function traversal tree secara in-order (kiri - tengah - kanan atau child kiri - root - child kanan)
    if (root != NULL) {
        inOrder(root->left);
        cout << root->info << " ";
        inOrder(root->right);
    }
}

void postOrder(address root) { //function traversal tree secara post-order (kiri - kanan - tengah atau child kiri - child kanan - root)
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->info << " ";
    }
}


//Utilities
int countNodes(address root) { //function untuk menghitung size atau ukuran atau jumlah node yang ada didalam tree
    if (isEmpty(root) == true) {
        return 0;
    } else {
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
}

int treeDepth(address root) { //function untuk menghitung height atau kedalaman atau level tree
    if (isEmpty(root) == true) {
        return -1; //tree kosong jika depth = -1
    } else {
        int leftDepth = treeDepth(root->left);
        int rightDepth = treeDepth(root->right);
    
        return (leftDepth > rightDepth ? leftDepth : rightDepth) + 1;
    }
}


//FUNCTION & PROSEDUR BARU
//searching
void searchByData(address root, infotype x) { //function untuk melakukan searching data tertentu
    if(isEmpty(root) == true){
        cout << "BST kosong!" << endl;
    } else {
        address nodeBantu = root;
        address parent = NULL;
        bool ketemu = false;
        while(nodeBantu != NULL){
            if(x < nodeBantu->info){
                parent = nodeBantu;
                nodeBantu = nodeBantu->left;
            } else if(x > nodeBantu->info){
                parent = nodeBantu;
                nodeBantu = nodeBantu->right;
            } else if(x == nodeBantu->info){
                ketemu = true;
                break;
            }
        }
        if(ketemu == false){
            cout << "Data tidak ditemukan" << endl;
        } else if(ketemu == true){
            cout << "Data ditemukan didalam BST!" << endl;
            cout << "Data Angka : " << nodeBantu->info << endl;

            //menampilkan parentnya & pengecekan sibling
            address sibling = NULL;
            if(parent != NULL){
                cout << "Parent : " << parent->info << endl;
                if(parent->left == nodeBantu){
                    sibling = parent->right;
                } else if(parent->right == nodeBantu){
                    sibling = parent->left;
                }
            } else {
                cout << "Parent : - (node root)"<< endl;
            }

            //menampilkan siblingnya
            if(sibling != NULL){
                cout << "Sibling : " << sibling->info << endl;
            } else {
                cout << "Sibling : - " << endl;
            }

            //menampilkan childnya
            if(nodeBantu->left != NULL){
                cout << "Child kiri : " << nodeBantu->left->info << endl;
            } else if(nodeBantu->left == NULL){
                cout << "Child kiri : -" << endl;
            }
            if(nodeBantu->right != NULL){
                cout << "Child kanan : " << nodeBantu->right->info << endl;
            } else if(nodeBantu->right == NULL){
                cout << "Child kanan : -" << endl;
            }
        }
    }
}


//mostleft & mostright
address mostLeft(address root) { //function untuk menampilkan mostleft atau node paling kiri (node dengan nilai terkecil) didalam BST
    while (root->left != NULL){
        root = root->left;
    }
    return root;
}

address mostRight(address root) { //function untuk menampilkan mostright atau node paling kanan (node dengan nilai terbesar) didalam BST
    while (root->right != NULL){
        root = root->right;
    }
    return root;
}


//delete
bool deleteNode(address &root, infotype x) { //function untuk menghapus node tertentu didalam BST (menghapus berdasarkan parameter infotype)
    if (root == NULL) {
        return false; //data tidak ditemukan di subtree ini
    } else {
        if (x < root->info) {
            return deleteNode(root->left, x);
        } else if (x > root->info) {
            return deleteNode(root->right, x);
        } else {
            //jika node yang mau dihapus ditemukan
            //Case 1 : node yang mau dihapus adalah leaf
            if (root->left == NULL && root->right == NULL) {
                address temp = root;
                root = NULL;
                delete temp;
            }
            //Case 2 : node yang mau dihapus hanya punya right child
            else if (root->left == NULL) {
                address temp = root;
                root = root->right;
                delete temp;
            }
            //Case 3 : node yang mau dihapus hanya punya left child
            else if (root->right == NULL) {
                address temp = root;
                root = root->left;
                delete temp;
            }
            // Case 4 : jika node yang mau dihapus punya dua child, maka ambil mostleft dari subtree kanan untuk menggantikan node yang mau dihapus
            else {
                //mostleft dari subtree kanan = node successor (node penerus)
                address successor = mostLeft(root->right);
                //salin data successor ke node saat ini
                root->info = successor->info;
                //hapus successor pada subtree kanan
                return deleteNode(root->right, successor->info);
            }
            return true; //berhasil dihapus
        }
    }
}

void deleteTree(address &root) { //prosedur untuk menghapus BST (menghapus seluruh node BST)
    if(root == NULL){
        return;
    } else {
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
        root = NULL;
    }
}
```
```C++
//main.cpp
#include <iostream>
#include "BST2.h"

using namespace std;

int main(){
    address root;
    createTree(root);

    cout << "=== Binary Search Tree ==" << endl;
    cout << endl;

    root = insertNode(root, 30); // Root awal
    insertNode(root, 15);
    insertNode(root, 35);
    insertNode(root, 11);
    insertNode(root, 17);
    insertNode(root, 20);
    insertNode(root, 38);
    insertNode(root, 16);
    insertNode(root, 22);
    insertNode(root, 33);
    insertNode(root, 18);

    cout << "Hasil InOrder Traversal : ";
    inOrder(root);
    cout << endl;

    cout << endl;
    cout << "Jumlah Node : " << countNodes(root) << endl;
    cout << "Kedalaman Tree : " << treeDepth(root) << endl;

    cout << endl;
    searchByData(root, 17);
    
    cout << endl;
    cout << "Node mostleft : " << mostLeft(root)->info << endl;
    cout << "Node mostright : " << mostRight(root)->info << endl;

    cout << endl;
    infotype angkaHapus;
    cout << "Masukkan angka yang ingin dihapus: ";
    cin >> angkaHapus;
    //misal angka yang dihapus adalah angka 17
    if(deleteNode(root, angkaHapus)){
        cout << "Data " << angkaHapus << " berhasil dihapus!" << endl;
    } else {
        cout << "Data " << angkaHapus << " tidak ditemukan!" << endl;
    }
    cout << endl;

    searchByData(root, 17);
    cout << endl;
    searchByData(root, 18);

    cout << endl;
    cout << "Hasil InOrder Traversal : ";
    inOrder(root);
    cout << endl;

    cout << endl;
    deleteTree(root);
    cout << "Seluruh tree berhasil dihapus!" << endl;

    cout << endl;
    if(isEmpty(root) == true){
        cout << "BST kosong!" << endl;
    } else {
        cout << "Hasil InOrder Traversal : ";
        inOrder(root);
    }

    return 0;
}
```
Program guided 2 ini merupakan pengembangan dari Guided 1. Selain proses insert dan traversal, program ini sudah mendukung pencarian data lengkap dengan informasi parent, sibling, dan child. Program juga dapat menampilkan nilai paling kecil (most-left), nilai paling besar (most-right), menghapus node tertentu, dan menghapus seluruh tree sekaligus.

## Unguided 

### 1. Buatlah ADT Binary Search Tree menggunakan Linked list sebagai berikut di dalam file “bstree.h”: Buatlah implementasi ADT Binary Search Tree pada file “bstree.cpp” dan cobalah hasil implementasi ADT pada file “main.cpp”
```C++
//bstree.h
#ifndef BSTREE_H
#define BSTREE_H

#include <iostream>
using namespace std;

#define Nil NULL

typedef int infotype;

struct Node {
    infotype info;
    Node *left;
    Node *right;
};

typedef Node* address;

address alokasi(infotype x);
void insertNode(address &root, infotype x);
address findNode(address root, infotype x);
void InOrder(address root);

#endif

```

```C++
//bstree.cpp
#include "bstree.h"

address alokasi(infotype x){
    address P = new Node;
    P->info = x;
    P->left = Nil;
    P->right = Nil;
    return P;
}

void insertNode(address &root, infotype x){
    if(root == Nil){
        root = alokasi(x);
    } else if(x < root->info){
        insertNode(root->left, x);
    } else if(x > root->info){
        insertNode(root->right, x);
    }
}

address findNode(address root, infotype x){
    if(root == Nil) return Nil;
    if(root->info == x) return root;
    else if(x < root->info) return findNode(root->left, x);
    else return findNode(root->right, x);
}

void InOrder(address root){
    if(root != Nil){
        InOrder(root->left);
        cout << root->info << " ";
        InOrder(root->right);
    }
}

```

```C++
//main.cpp
#include <iostream>
#include "bstree.h"

using namespace std;

int main(){
    cout << "Hello World\n";
    address root = Nil;

    insertNode(root,1);
    insertNode(root,2);
    insertNode(root,6);
    insertNode(root,4);
    insertNode(root,5);
    insertNode(root,3);
    insertNode(root,6);
    insertNode(root,7);

    InOrder(root);

    return 0;
}

```



### Output Unguided 1 :
![Output Unguided1](https://github.com/MuhammadShabrian/103112400087_Muhammad-Shabrian-Fadly/blob/main/Pertemuan10/Output%20Unguided1.png)

Program Unguided 1 ini memasukkan beberapa nilai ke dalam BST lalu menampilkannya menggunakan traversal in-order. Hasil output menunjukkan bahwa struktur tree berhasil mengurutkan data secara otomatis sesuai aturan BST.


### 2.Buatlah fungsi untuk menghitung jumlah node dengan fungsi berikut. fungsi hitungJumlahNode( root:address ) : integer fungsi mengembalikan integer banyak node yang ada di dalam BST*/ fungsi hitungTotalInfo( root:address, start:integer ) : integer fungsi mengembalikan jumlah (total) info dari node-node yang ada di dalam BST*/ fungsi hitungKedalaman( root:address, start:integer ) : integer Output fungsi rekursif mengembalikan integer kedalaman maksimal dari binary tree */


```C++
//bstree.h
#ifndef BSTREE_H
#define BSTREE_H

#include <iostream>
using namespace std;

#define Nil NULL

typedef int infotype;

struct Node {
    infotype info;
    Node *left;
    Node *right;
};

typedef Node* address;

address alokasi(infotype x);
void insertNode(address &root, infotype x);
address findNode(address root, infotype x);
void InOrder(address root);
int hitungNode(address root);
int hitungTotal(address root);
int hitungKedalaman(address root, int level);


#endif

```

```C++
//bstree.cpp
#include "bstree.h"

address alokasi(infotype x){
    address P = new Node;
    P->info = x;
    P->left = Nil;
    P->right = Nil;
    return P;
}

void insertNode(address &root, infotype x){
    if(root == Nil){
        root = alokasi(x);
    } else if(x < root->info){
        insertNode(root->left, x);
    } else if(x > root->info){
        insertNode(root->right, x);
    }
}

address findNode(address root, infotype x){
    if(root == Nil) return Nil;
    if(root->info == x) return root;
    else if(x < root->info) return findNode(root->left, x);
    else return findNode(root->right, x);
}

void InOrder(address root){
    if(root != Nil){
        InOrder(root->left);
        cout << root->info << " ";
        InOrder(root->right);
    }
}

int hitungNode(address root){
    if(root == Nil) return 0;
    return 1 + hitungNode(root->left) + hitungNode(root->right);
}

int hitungTotal(address root){
    if(root == Nil) return 0;
    return root->info + hitungTotal(root->left) + hitungTotal(root->right);
}

int hitungKedalaman(address root, int level){
    if(root == Nil) return level;
    int L = hitungKedalaman(root->left, level + 1);
    int R = hitungKedalaman(root->right, level + 1);
    return (L > R ? L : R);
}

```
```C++
//main.cpp
#include <iostream>
#include "bstree.h"

using namespace std;

int main(){
    cout << "Hello World" << endl;
    address root = Nil;

    insertNode(root,1);
    insertNode(root,2);
    insertNode(root,6);
    insertNode(root,4);
    insertNode(root,5);
    insertNode(root,3);
    insertNode(root,6);
    insertNode(root,7);

    InOrder(root);
    cout << "\n";

    cout << "kedalaman : " << hitungKedalaman(root,0) << endl;
    cout << "jumlah Node : " << hitungNode(root) << endl;
    cout << "total : " << hitungTotal(root) << endl;

    return 0;
}

```

### Output Unguided 2 :
![Output Unguided2](https://github.com/MuhammadShabrian/103112400087_Muhammad-Shabrian-Fadly/blob/main/Pertemuan10/Output%20Unguided2.png)

Program Unguided 2 Program ini menambahkan tiga fungsi analisis: menghitung jumlah node, menghitung total nilai info, dan mencari kedalaman tree. Hasilnya menggambarkan karakter dasar dari tree yang terbentuk, baik dari sisi ukuran data, nilai keseluruhan, maupun level terdalam.

### 3. Print tree secara pre-order dan post-order.
```C++
//bstree.h
#ifndef BSTREE_H
#define BSTREE_H

#include <iostream>
using namespace std;

#define Nil NULL

typedef int infotype;

struct Node {
    infotype info;
    Node *left;
    Node *right;
};

typedef Node* address;

address alokasi(infotype x);
void insertNode(address &root, infotype x);
address findNode(address root, infotype x);
void InOrder(address root);
int hitungNode(address root);
int hitungTotal(address root);
int hitungKedalaman(address root, int level);
void PreOrder(address root);
void PostOrder(address root);

#endif

```

```C++
//bstree.cpp
#include "bstree.h"

address alokasi(infotype x){
    address P = new Node;
    P->info = x;
    P->left = Nil;
    P->right = Nil;
    return P;
}

void insertNode(address &root, infotype x){
    if(root == Nil){
        root = alokasi(x);
    } else if(x < root->info){
        insertNode(root->left, x);
    } else if(x > root->info){
        insertNode(root->right, x);
    }
}

address findNode(address root, infotype x){
    if(root == Nil) return Nil;
    if(root->info == x) return root;
    else if(x < root->info) return findNode(root->left, x);
    else return findNode(root->right, x);
}

void InOrder(address root){
    if(root != Nil){
        InOrder(root->left);
        cout << root->info << " ";
        InOrder(root->right);
    }
}
int hitungNode(address root){
    if(root == Nil) return 0;
    return 1 + hitungNode(root->left) + hitungNode(root->right);
}

int hitungTotal(address root){
    if(root == Nil) return 0;
    return root->info + hitungTotal(root->left) + hitungTotal(root->right);
}

int hitungKedalaman(address root, int level){
    if(root == Nil) return level - 1;
    int L = hitungKedalaman(root->left, level + 1);
    int R = hitungKedalaman(root->right, level + 1);
    return (L > R ? L : R);
}

void PreOrder(address root){
    if(root != Nil){
        cout << root->info << " ";
        PreOrder(root->left);
        PreOrder(root->right);
    }
}

void PostOrder(address root){
    if(root != Nil){
        PostOrder(root->left);
        PostOrder(root->right);
        cout << root->info << " ";
    }
}

```
```C++
//main.cpp
#include <iostream>
#include "bstree.h"

using namespace std;

int main(){
    address root = Nil;

    insertNode(root,1);
    insertNode(root,2);
    insertNode(root,6);
    insertNode(root,4);
    insertNode(root,5);
    insertNode(root,3);
    insertNode(root,6);
    insertNode(root,7);

    cout << "PreOrder : ";
    PreOrder(root);

    cout << "\nPostOrder: ";
    PostOrder(root);

    return 0;
}

```

### Output Unguided 3 :

![Output Unguided3](https://github.com/MuhammadShabrian/103112400087_Muhammad-Shabrian-Fadly/blob/main/Pertemuan10/Output%20Unguided3.png)

Program Unguided 3 ini menampilkan data menggunakan preorder dan postorder. Kedua traversal tersebut memperlihatkan susunan tree dari arah yang berbeda, sehingga memudahkan memahami bentuk tree secara lebih menyeluruh.

## Kesimpulan
Dari praktikum ini, memberi gambaran jelas tentang bagaimana Binary Search Tree bekerja mulai dari struktur, cara menyimpan data, hingga penelusuran dan penghapusan. Pemakaian fungsi rekursif membuat proses traversal dan perhitungan menjadi lebih ringkas dan mudah dipahami. Setiap program menunjukkan bahwa BST mampu mengelola data secara terurut, efisien, dan tetap fleksibel saat dilakukan pencarian maupun perubahan data. Dengan memahami operasi dasar dan tambahan pada tree, pengelolaan data yang berbentuk hierarki menjadi lebih terstruktur dan mudah diolah.

## Referensi
[1] Djayusman, D., Suhartini, I., Gunawan, F. N., Alhakim, N. T., & Gunawan, T. A. (2021). Implementasi struktur data tree pada game Snake dengan C. Jurnal DIGIT, 11(1), 20–27. https://jurnaldigit.org/index.php/DIGIT/article/download/176/135 
<br>[2] Telkom University. (n.d.). Tree data structure. https://bse.telkomuniversity.ac.id/tree-data-structure/