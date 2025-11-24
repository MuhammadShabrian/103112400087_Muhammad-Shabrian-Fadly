#include <iostream>
#include "queue.h"
using namespace std;

void createQueue(Queue &Q){
    Q.head = 0;
    Q.tail = -1;
}

bool isEmptyQueue(const Queue &Q){
    return Q.tail == -1;
}

bool isFullQueue(const Queue &Q){
    return (Q.head == 0 && Q.tail == MAXQ-1);
}

void shiftLeft(Queue &Q){
    int j = 0;
    for (int i = Q.head; i <= Q.tail; i++){
        Q.info[j++] = Q.info[i];
    }
    Q.head = 0;
    Q.tail = j - 1;
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

    if (Q.tail == MAXQ - 1 && Q.head > 0){
        shiftLeft(Q);
    }

    Q.tail++;
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
        Q.head++;
    }
    return x;
}

void printInfo(const Queue &Q){
    cout << Q.head << " - " << Q.tail << "\t| ";

    if (!isEmptyQueue(Q)){
        for (int i = Q.head; i <= Q.tail; i++){
            cout << Q.info[i] << " ";
        }
    }

    cout << endl;
}
