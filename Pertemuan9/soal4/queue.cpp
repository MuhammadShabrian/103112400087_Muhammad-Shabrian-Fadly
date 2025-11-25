#include "queue.h"

const float BIAYA_PER_KG = 8250.0; 

void createQueue(QueuePaket &Q) {
    Q.front = -1;
    Q.rear = -1;
}

bool isQueueEmpty(QueuePaket Q) {
    return Q.front == -1;
}

bool isQueueFull(QueuePaket Q) {
    return Q.rear == MAX_PAKET - 1; 
}

void hitungBiaya(Paket &paket) {
    
    paket.BiayaPengiriman = BIAYA_PER_KG * paket.BeratBarang;
}

void enQueue(QueuePaket &Q, Paket paketBaru) {
    if (isQueueFull(Q)) {
        cout << "\n Gagal: Queue penuh! Tidak bisa enQueue data paket baru.\n";
    } else {
        if (isQueueEmpty(Q)) {
            Q.front = 0;
        }
        Q.rear++;
        hitungBiaya(paketBaru);
        Q.dataPaket[Q.rear] = paketBaru;
        cout << "\n Berhasil: Paket Resi " << paketBaru.KodeResi << " telah di-enQueue.\n";
    }
}

void deQueue(QueuePaket &Q, Paket &paketKeluar) {
    if (isQueueEmpty(Q)) {
        cout << "\n Gagal: Queue kosong! Tidak bisa deQueue data.\n";
        paketKeluar.KodeResi = "";
    } else {
        paketKeluar = Q.dataPaket[Q.front];
        cout << "\n Berhasil: Paket Resi " << paketKeluar.KodeResi << " telah di-deQueue.\n";

        if (Q.front == Q.rear) {
            Q.front = -1;
            Q.rear = -1;
        } else {
            Q.front++; 
        }
    }
}

void viewQueue(QueuePaket Q) {
    cout << "\n============== Data Paket di Queue ==============\n";
    if (isQueueEmpty(Q)) {
        cout << "Queue kosong.\n";
        cout << "===================================================\n";
        return;
    }
    
    cout << setw(5) << left << "No"
         << setw(12) << left << "Resi"
         << setw(15) << left << "Penerima"
         << setw(12) << left << "Tujuan"
         << setw(8) << left << "Berat"
         << setw(15) << left << "Biaya"
         << endl;
    cout << "------------------------------------------------------------------\n";

    int counter = 1;
    for (int i = Q.front; i <= Q.rear; i++) {
        Paket pkt = Q.dataPaket[i];
        cout << setw(5) << left << counter++
             << setw(12) << left << pkt.KodeResi
             << setw(15) << left << pkt.NamaPenerima
             << setw(12) << left << pkt.Tujuan
             << setw(8) << left << fixed << setprecision(1) << pkt.BeratBarang
             << "Rp" << setw(13) << left << fixed << setprecision(0) << pkt.BiayaPengiriman
             << endl;
    }
    cout << "===================================================\n";
}

float hitungTotalBiayaPengiriman(QueuePaket &Q) {
    float totalBiaya = 0.0;
    if (isQueueEmpty(Q)) {
        return 0.0;
    }
    
    for (int i = Q.front; i <= Q.rear; i++) {
    
        if (Q.dataPaket[i].BiayaPengiriman == 0) {
             hitungBiaya(Q.dataPaket[i]);
        }
        totalBiaya += Q.dataPaket[i].BiayaPengiriman;
    }

    return totalBiaya;
}