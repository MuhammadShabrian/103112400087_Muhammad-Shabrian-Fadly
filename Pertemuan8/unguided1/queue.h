#ifndef QUEUE_H
#define QUEUE_H

const int MAXQ = 5;
typedef int infotype;

struct Queue {
    infotype info[MAXQ];
    int head;
    int tail;
};

void createQueue(Queue &Q);
bool isEmptyQueue(const Queue &Q);
bool isFullQueue(const Queue &Q);
void enqueue(Queue &Q, infotype x);
infotype dequeue(Queue &Q);
void printInfo(const Queue &Q);

#endif
