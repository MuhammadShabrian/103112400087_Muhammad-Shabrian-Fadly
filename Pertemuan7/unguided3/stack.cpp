#include <iostream>
#include "stack.h"
using namespace std;

bool isFull(Stack S) {
    return S.top == MAX_STACK - 1;
}

bool isEmpty(Stack S) {
    return S.top == -1;
}

void createStack(Stack &S) {
    S.top = -1;
}

void push(Stack &S, infotype x) {
    if (!isFull(S)) {
        S.top++;
        S.info[S.top] = x;
    }
}

infotype pop(Stack &S) {
    if (!isEmpty(S)) {
        int x = S.info[S.top];
        S.top--;
        return x;
    }
    return -1;
}

void printInfo(Stack S) {
    if (S.top == -1) {
        cout << "[Stack kosong]" << endl;
        return;
    }
    for (int i = 0; i <= S.top; i++) {
        cout << S.info[i];
    }
    cout << endl;
}



void balikStack(Stack &S) {
    Stack temp;
    createStack(temp);

    while (!isEmpty(S)) {
        push(temp, pop(S));
    }

    S = temp;
}

void getInputStream(Stack &S) {
    cout << "Masukkan karakter (ENTER untuk berhenti): ";
    char c;

    while (true) {
        c = cin.get();
        if (c == '\n') {
            break;
        }
        push(S, c);
    }
}
