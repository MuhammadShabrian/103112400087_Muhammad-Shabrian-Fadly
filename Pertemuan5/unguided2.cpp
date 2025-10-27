#include <iostream>
#include <string>

using namespace std;

struct Node {
    int data;
    Node* next;
};

void append(Node*& head, int value) {
    Node* newNode = new Node{value, nullptr};
    if (!head) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void displayList(Node* head) {
    Node* current = head;
    cout << "Linked List: ";
    while (current) {
        cout << current->data;
        if (current->next) {
            cout << " -> ";
        }
        current = current->next;
    }
    cout << " -> NULL" << endl;
}

Node* linearSearch(Node* head, int key) {
    Node* current = head;
    int node_ke = 1;
    
    cout << "\nProses Pencarian:" << endl;

    while (current != nullptr) {
        cout << "Memeriksa node " << node_ke++ << ": " << current->data;
        
        if (current->data == key) {
            cout << " (SAMA)" << endl;
            cout << "DITEMUKAN!" << endl;
            return current;
        } else {
            cout << " (tidak sama)" << endl;
        }
        current = current->next;
    }

    cout << "Tidak ada node lagi yang tersisa" << endl;
    return nullptr;
}

void runTugas2() {
    Node* head = nullptr;
    append(head, 10);
    append(head, 20);
    append(head, 30);
    append(head, 40);
    append(head, 50);

    cout << "LINEAR SEARCH PADA LINKED LIST" << endl;
    displayList(head);

    int key1 = 30;
    cout << "Mencari nilai: " << key1 << endl;
    Node* result1 = linearSearch(head, key1);

    cout << "\nHasil: Nilai " << key1;
    if (result1) {
        cout << " DITEMUKAN pada linked list!" << endl;
        cout << "Alamat node: " << result1 << endl;
        cout << "Data node: " << result1->data << endl;
        cout << "Node berikutnya: " << (result1->next ? to_string(result1->next->data) : "NULL") << endl;
    } else {
        cout << " TIDAK DITEMUKAN dalam linked list" << endl;
    }

    cout << "\n==============================\n" << endl;

    int key2 = 25;
    cout << "Mencari nilai: " << key2 << endl;
    Node* result2 = linearSearch(head, key2);

    cout << "\nHasil: Nilai " << key2;
    if (result2) {
        cout << " DITEMUKAN pada linked list" << endl;
        cout << "Alamat node: " << result2 << endl;
        cout << "Data node: " << result2->data << endl;
        cout << "Node berikutnya: " << (result2->next ? to_string(result2->next->data) : "NULL") << endl;
    } else {
        cout << " TIDAK DITEMUKAN dalam linked list" << endl;
    }
}

int main() {
     runTugas2();
     return 0;
 }