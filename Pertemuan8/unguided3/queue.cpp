#include <iostream>
#include "queue.h"
using namespace std;

void createQueue(Queue &Q){
    Q.head = 0;
    Q.tail = -1;
}

bool isEmptyQueue(const Queue &Q){
    return (Q.tail == -1);
}

bool isFullQueue(const Queue &Q){
    if (isEmptyQueue(Q)) return false;
    return ((Q.tail + 1) % MAXQ) == Q.head;
}

void enqueue(Queue &Q, infotype x){
    if (isFullQueue(Q)){
        cout << "Queue penuh" << endl;
        return;
    }

    if (isEmptyQueue(Q)){
        Q.head = Q.tail = 0;
        Q.info[Q.tail] = x;
        return;
    }

    Q.tail = (Q.tail + 1) % MAXQ;
    Q.info[Q.tail] = x;
}

infotype dequeue(Queue &Q){
    if (isEmptyQueue(Q)){
        cout << "Queue kosong" << endl;
        return -1;
    }

    infotype x = Q.info[Q.head];

    if (Q.head == Q.tail){
        Q.head = 0;
        Q.tail = -1;
    } else {
        Q.head = (Q.head + 1) % MAXQ;
    }

    return x;
}

void printInfo(const Queue &Q){
    cout << Q.head << " - " << Q.tail << "\t| ";

    if (!isEmptyQueue(Q)){
        int i = Q.head;
        while (true){
            cout << Q.info[i] << " ";
            if (i == Q.tail) break;
            i = (i + 1) % MAXQ;
        }
    }

    cout << endl;
}
