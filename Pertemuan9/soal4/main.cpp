#include "queue.h"

void runSoalA4(QueuePaket &Q) {
    cout << "\n=============== 📝 Eksekusi Soal Nomor 4 Bagian A ==============\n";

    createQueue(Q);
    cout << "1) Queue kosong telah dibuat.\n";

    Paket pkt1 = {"123456", "Inazuma", "Hutao", 14.0};
    Paket pkt2 = {"234567", "Liyue", "Ayaka", 10.0};
    Paket pkt3 = {"345678", "Sumeru", "Bennett", 8.6};
    Paket pkt4 = {"456789", "Fontaine", "Furina", 16.0};
    Paket pkt5 = {"567890", "Mondstadt", "Heifer", 6.5};
    enQueue(Q, pkt1);
    enQueue(Q, pkt2);
    enQueue(Q, pkt3);
    enQueue(Q, pkt4);
    enQueue(Q, pkt5); 
    viewQueue(Q);

    Paket pktDeQ;
    deQueue(Q, pktDeQ);
    cout << "   -> Paket yang di-deQueue: Resi " << pktDeQ.KodeResi << ", Tujuan " << pktDeQ.Tujuan << endl;

    viewQueue(Q);
    
    cout << "\n============== Eksekusi Soal Nomor 4 Bagian A Selesai ==============\n";
}

void runSoalB4(QueuePaket &Q) {
    cout << "\n=============== Eksekusi Soal Nomor 4 Bagian B ==============\n";
    cout << "Melakukan pemanggilan fungsi hitungTotalBiayaPengiriman().\n";
    
    float total = hitungTotalBiayaPengiriman(Q);
    
    viewQueue(Q);
    cout << "\n Total Biaya Pengiriman Semua Paket (yang tersisa): Rp" 
         << fixed << setprecision(0) << total << endl;
    
    cout << "\n============== Eksekusi Soal Nomor 4 Bagian B Selesai ==============\n";
}

int main() {
    QueuePaket Q;
    
    runSoalA4(Q);
    runSoalB4(Q);

    return 0;
}