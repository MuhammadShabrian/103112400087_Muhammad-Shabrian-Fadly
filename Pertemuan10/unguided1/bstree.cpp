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
