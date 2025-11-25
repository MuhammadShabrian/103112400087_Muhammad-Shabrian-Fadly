#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

const int MAX_PAKET = 10; 

struct Paket {
    string KodeResi;
    string Tujuan;
    string NamaPenerima;
    float BeratBarang;
    float BiayaPengiriman;
};

struct QueuePaket {
    Paket dataPaket[MAX_PAKET];
    int front;
    int rear;
};

void createQueue(QueuePaket &Q);
bool isQueueEmpty(QueuePaket Q);
bool isQueueFull(QueuePaket Q);
void hitungBiaya(Paket &paket);
void enQueue(QueuePaket &Q, Paket paketBaru);
void deQueue(QueuePaket &Q, Paket &paketKeluar);
void viewQueue(QueuePaket Q);
float hitungTotalBiayaPengiriman(QueuePaket &Q);

#endif