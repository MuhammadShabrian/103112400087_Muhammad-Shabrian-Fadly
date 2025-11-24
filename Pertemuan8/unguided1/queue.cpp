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
    return Q.tail == MAXQ - 1;
}

void enqueue(Queue &Q, infotype x){
    if (isFullQueue(Q)){
        cout << "Queue penuh" << endl;
        return;
    }
    Q.tail++;
    Q.info[Q.tail] = x;
}

infotype dequeue(Queue &Q){
    if (isEmptyQueue(Q)){
        cout << "Queue kosong" << endl;
        return -1;
    }

    infotype x = Q.info[0];

    // geser
    for (int i = 0; i < Q.tail; i++){
        Q.info[i] = Q.info[i+1];
    }

    Q.tail--;
    return x;
}

void printInfo(const Queue &Q){
    cout << Q.head << " - " << Q.tail << "\t| ";

    if (!isEmptyQueue(Q)){
        for (int i = 0; i <= Q.tail; i++){
            cout << Q.info[i] << " ";
        }
    }

    cout << endl;
}
