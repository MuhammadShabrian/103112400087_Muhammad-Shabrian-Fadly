#include <iostream>
#include <string>
using namespace std;

struct Node {
    string namaMember;
    float beratBadan;
    string tierMember;
    Node *left, *right;
};

typedef Node* tree;

bool isEmpty(tree root) {
    return root == NULL;
}

void createTree(tree &root) {
    root = NULL;
}

Node* newNode(string nama, float berat, string tier) {
    Node* n = new Node;
    n->namaMember = nama;
    n->beratBadan = berat;
    n->tierMember = tier;
    n->left = n->right = NULL;
    return n;
}

void insertNode(tree &root, Node* node) {
    if (isEmpty(root)) {
        root = node;
    } else {
        if (node->beratBadan < root->beratBadan) {
            insertNode(root->left, node);
        } else if (node->beratBadan > root->beratBadan) {
            insertNode(root->right, node);
        }
    }
}

void inOrder(tree root) {
    if (!isEmpty(root)) {
        inOrder(root->left);
        cout << root->beratBadan << " ";
        inOrder(root->right);
    }
}

Node* mostLeft(tree root) {
    Node* curr = root;
    while (curr && curr->left != NULL) curr = curr->left;
    return curr;
}

Node* mostRight(tree root) {
    Node* curr = root;
    while (curr && curr->right != NULL) curr = curr->right;
    return curr;
}

Node* searchParent(tree root, float berat) {
    if (root == NULL || root->beratBadan == berat) return NULL;
    if ((root->left && root->left->beratBadan == berat) || (root->right && root->right->beratBadan == berat)) return root;
    if (berat < root->beratBadan) return searchParent(root->left, berat);
    return searchParent(root->right, berat);
}

Node* searchByBeratBadan(tree root, float berat) {
    if (root == NULL || root->beratBadan == berat) return root;
    if (berat < root->beratBadan) return searchByBeratBadan(root->left, berat);
    return searchByBeratBadan(root->right, berat);
}

int main() {
    tree myTree;
    createTree(myTree);

    insertNode(myTree, newNode("Rizkina Azizah", 60, "Basic"));
    insertNode(myTree, newNode("Hakan Ismail", 50, "Bronze"));
    insertNode(myTree, newNode("Olivia Saevali", 65, "Silver"));
    insertNode(myTree, newNode("Felix Pedrosa", 47, "Gold"));
    insertNode(myTree, newNode("Hanif Al Faiz", 70, "Basic"));
    insertNode(myTree, newNode("Mutiara Fauziah", 52, "Bronze"));
    insertNode(myTree, newNode("Davi Ilyas", 68, "Silver"));
    insertNode(myTree, newNode("Abdad Mubarok", 81, "Gold"));
    insertNode(myTree, newNode("Gamel Al Ghifari", 56, "Platinum"));

    cout << "=== Traversal InOrder ===" << endl;
    inOrder(myTree);
    cout << endl << endl;

    cout << "Node MostLeft: " << mostLeft(myTree)->beratBadan << endl;
    cout << "Node MostRight: " << mostRight(myTree)->beratBadan << endl << endl;

    float key = 70;
    Node* res = searchByBeratBadan(myTree, key);
    if (res) {
        cout << "Data ditemukan didalam BST!" << endl;
        cout << "Data Node Yang Dicari" << endl;
        cout << "Nama Member: " << res->namaMember << endl;
        cout << "Berat Badan: " << res->beratBadan << endl;
        cout << "Tier Member: " << res->tierMember << endl << endl;

        Node* p = searchParent(myTree, key);
        if (p) {
            cout << "Data Parent" << endl;
            cout << "Nama Member: " << p->namaMember << endl;
            cout << "Berat Badan: " << p->beratBadan << endl;
            cout << "Tier Member: " << p->tierMember << endl << endl;
            
            Node* sib = (p->left == res) ? p->right : p->left;
            if (!sib) cout << "Tidak Memiliki Sibling" << endl << endl;
        }

        if (res->left) {
            cout << "Data Child Kiri" << endl;
            cout << "Nama Member: " << res->left->namaMember << endl;
            cout << "Berat Badan: " << res->left->beratBadan << endl;
            cout << "Tier Member: " << res->left->tierMember << endl << endl;
        }
        if (res->right) {
            cout << "Data Child Kanan" << endl;
            cout << "Nama Member: " << res->right->namaMember << endl;
            cout << "Berat Badan: " << res->right->beratBadan << endl;
            cout << "Tier Member: " << res->right->tierMember << endl << endl;
        }
    }
    return 0;
}