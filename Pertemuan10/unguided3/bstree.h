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
