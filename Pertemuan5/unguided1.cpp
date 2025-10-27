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

Node* binarySearch(Node* head, int key) {
    int size = 0;
    for (Node* current = head; current; current = current->next) {
        size++;
    }

    Node* start = head;
    int current_size = size;
    int iteration = 1;
    int offset = 0; 

    cout << "\nProses Pencarian:" << endl;

    while (current_size > 0) {
        int mid_offset = current_size / 2;
        int mid_index = offset + mid_offset;
        
        Node* midNode = start;
        for (int i = 0; i < mid_offset; i++) {
            midNode = midNode->next;
        }

        cout << "Iterasi " << iteration++ << ": Mid = " << midNode->data 
             << " (indeks " << mid_index << ", alamat: " << midNode << ")";

        if (midNode->data == key) {
            cout << " DITEMUKAN!" << endl;
            return midNode;
        } else if (midNode->data < key) {
            start = midNode->next;
            offset = mid_index + 1;
            current_size = current_size - mid_offset - 1;
            cout << " -> Cari di bagian kanan" << endl;
        } else {
            current_size = mid_offset; 
            cout << " -> Cari di bagian kiri" << endl;
        }
    }

    cout << "Tidak ada elemen tersisa" << endl;
    return nullptr;
}


void runTugas1() {
    Node* head = nullptr;
    append(head, 10);
    append(head, 20);
    append(head, 30);
    append(head, 40);
    append(head, 50);
    append(head, 60); 

    cout << "BINARY SEARCH PADA LINKED LIST" << endl;
    displayList(head);

    int key1 = 40;
    cout << "Mencari nilai: " << key1 << endl;
    Node* result1 = binarySearch(head, key1);

    cout << "\nHasil: Nilai " << key1;
    if (result1) {
        cout << " DITEMUKAN pada linked list" << endl;
        cout << "Alamat node: " << result1 << endl;
        cout << "Data node: " << result1->data << endl;
        cout << "Node berikutnya: " << (result1->next ? to_string(result1->next->data) : "NULL") << endl;
    } else {
        cout << " TIDAK DITEMUKAN dalam linked list" << endl;
    }

    cout << "\n==============================\n" << endl;

    int key2 = 25;
    cout << "Mencari nilai: " << key2 << endl;
    Node* result2 = binarySearch(head, key2);

    cout << "\nHasil: Nilai " << key2;
    if (result2) {
        cout << " DITEMUKAN pada linked list!" << endl;
        cout << "Alamat node: " << result2 << endl;
        cout << "Data node: " << result2->data << endl;
        cout << "Node berikutnya: " << (result2->next ? to_string(result2->next->data) : "NULL") << endl;
    } else {
        cout << " TIDAK DITEMUKAN dalam linked list!" << endl;
    }
}

int main() {
    runTugas1();
    return 0;
}