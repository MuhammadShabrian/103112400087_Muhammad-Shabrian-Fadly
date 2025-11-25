#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *prev, *next;
};

Node *head = NULL, *tail = NULL;

void insertEnd(int value) {
    Node* baru = new Node();
    baru->data = value;
    baru->next = NULL;
    baru->prev = tail;

    if (head == NULL) {       
        head = tail = baru;
    } else {
        tail->next = baru;
        tail = baru;
    }
}

void deleteLast() {
    if (head == NULL) {
        cout << "List kosong!\n";
        return;
    }
    if (head == tail) {       
        delete head;
        head = tail = NULL;
        return;
    }

    Node* hapus = tail;
    tail = tail->prev;
    tail->next = NULL;
    delete hapus;
}

void viewForward() {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void reverseList() {
    Node* curr = head;
    Node* temp = NULL;

    while (curr != NULL) {
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;

        curr = curr->prev;      }

    if (temp != NULL) {
        head = temp->prev;
    }
}

int main() {
    int menu, nilai;

    do {
        cout << "Menu: 1 insert (end), 2 delete (last), 3 view (depan), 4 reverse & view (depan), 0 exit\n";
        cin >> menu;

        switch (menu) {
            case 1:
                cout << "Masukkan nilai: ";
                cin >> nilai;
                insertEnd(nilai);
                break;

            case 2:
                deleteLast();
                break;

            case 3:
                viewForward();
                break;

            case 4:
                reverseList();
                viewForward();
                break;

            case 0:
                cout << "Keluar...\n";
                break;

            default:
                cout << "Menu tidak valid!\n";
        }

    } while (menu != 0);

    return 0;
}