#include <iostream> 
#include <fstream> //untuk baca/tulis file data.txt
#include <vector> //untuk simpan kumpulan data barang
#include <algorithm> //untuk ubah string ke lowercase
#include <sstream> //untuk pisah data dari file berdasarkan '|'
#include <cctype> //untuk fungsi tolower untuk pencarian tidak case-sensitive
using namespace std;


struct Item {
    int id;
    string name;
    string type;      // "lost" atau "found"
    string location;
    string date;
    string status;    // "available", "claimed"
    string contact;
};

struct BSTNode {
    Item data;
    BSTNode* left;
    BSTNode* right;
    
    BSTNode(Item item) {
        data = item;
        left = right = nullptr;
    }
};

BSTNode* root = nullptr;
int nextId = 1;

// fungsi untuk membersihkan buffer input
void clearInput() {
    cin.clear();
    cin.ignore(1000, '\n');
}

// fungsi untuk memisahkan string berdasarkan delimiter
vector<string> split(string str, char delimiter) {
    vector<string> result;
    stringstream ss(str);
    string token;
    while (getline(ss, token, delimiter)) {
        result.push_back(token);
    }
    return result;
}

// fungsi untuk mengubah string menjadi lowercase
string toLower(string str) {
    string result = str;
    transform(result.begin(), result.end(), result.begin(), ::tolower);
    return result;
}

// fungsi untuk memasukkan item ke dalam BST berdasarkan nama barang
BSTNode* insertBST(BSTNode* node, Item item) {
    if (node == nullptr) {
        return new BSTNode(item);
    }
    
    // insert berdasarkan nama barang (ascending)
    if (item.name < node->data.name) {
        node->left = insertBST(node->left, item);
    } else {
        node->right = insertBST(node->right, item);
    }
    
    return node;
}

// fungsi untuk traversal inorder pada BST, bisa filter by type
void inorderTraversal(BSTNode* node, string type = "") {
    if (node == nullptr) return;
    
    inorderTraversal(node->left, type);
    
    // jika type kosong, tampilkan semua. jika tidak, filter by type
    if (type.empty() || node->data.type == type) {
        if (node->data.status == "available") {
            cout << "ID: " << node->data.id 
                 << " | Nama: " << node->data.name 
                 << " | Tipe: " << node->data.type
                 << " | Lokasi: " << node->data.location 
                 << " | Tanggal: " << node->data.date << endl;
        }
    }
    
    inorderTraversal(node->right, type);
}

// fungsi untuk mencari item berdasarkan ID di BST
BSTNode* searchBST(BSTNode* node, int id) {
    if (node == nullptr) return nullptr;
    if (node->data.id == id) return node;
    
    BSTNode* leftResult = searchBST(node->left, id);
    if (leftResult != nullptr) return leftResult;
    
    return searchBST(node->right, id);
}

// fungsi helper untuk menyimpan data dengan traversal inorder
void inorderSave(BSTNode* node, vector<Item>& sortedItems) {
    if (node == nullptr) return;
    inorderSave(node->left, sortedItems);
    sortedItems.push_back(node->data);
    inorderSave(node->right, sortedItems);
}

// fungsi helper untuk mengecek keberadaan barang berdasarkan tipe
void checkItems(BSTNode* node, string type, bool& found) {
    if (node == nullptr) return;
    checkItems(node->left, type, found);
    if (node->data.type == type && node->data.status == "available") {
        found = true;
    }
    checkItems(node->right, type, found);
}

// fungsi untuk auto-match barang dengan nama sama
void autoMatchTraversal(BSTNode* node, int currentId, string targetName, string targetType) {
    if (node == nullptr) return;
    
    autoMatchTraversal(node->left, currentId, targetName, targetType);
    
    if (node->data.id != currentId && 
        node->data.name == targetName &&
        node->data.type != targetType &&
        node->data.status == "available") {
        node->data.status = "claimed";
        cout << "Barang pasangan (ID: " << node->data.id 
             << ") juga diklaim otomatis.\n";
    }
    
    autoMatchTraversal(node->right, currentId, targetName, targetType);
}

// fungsi untuk traversal mencari barang berdasarkan keyword
void searchTraversal(BSTNode* node, string keyword) {
    if (node == nullptr) return;
    
    searchTraversal(node->left, keyword);
    
    string itemNameLower = toLower(node->data.name);
    string keywordLower = toLower(keyword);
    
    if (itemNameLower.find(keywordLower) != string::npos && node->data.status == "available") {
        cout << "ID: " << node->data.id 
             << " | Nama: " << node->data.name 
             << " | Tipe: " << node->data.type
             << " | Lokasi: " << node->data.location 
             << " | Status: " << node->data.status << endl;
    }
    
    searchTraversal(node->right, keyword);
}

// fungsi untuk traversal menghitung statistik
void statsTraversal(BSTNode* node, int& lost, int& found, int& available, int& claimed) {
    if (node == nullptr) return;
    
    statsTraversal(node->left, lost, found, available, claimed);
    
    if (node->data.type == "lost") lost++;
    if (node->data.type == "found") found++;
    if (node->data.status == "available") available++;
    if (node->data.status == "claimed") claimed++;
    
    statsTraversal(node->right, lost, found, available, claimed);
}

// fungsi untuk memuat data dari file ke BST
void loadData() {
    ifstream file("data.txt");
    if (!file) return;
    
    string line;
    while (getline(file, line)) {
        vector<string> tokens = split(line, '|');
        if (tokens.size() < 7) continue;
        
        Item item;
        item.id = stoi(tokens[0]);
        item.name = tokens[1];
        item.type = tokens[2];
        item.location = tokens[3];
        item.date = tokens[4];
        item.status = tokens[5];
        item.contact = tokens[6];
        
        root = insertBST(root, item);
        
        if (item.id >= nextId) nextId = item.id + 1;
    }
    file.close();
}

// fungsi untuk menyimpan data dari BST ke file
void saveData() {
    ofstream file("data.txt");
    vector<Item> sortedItems;
    
    //inorder traversal untuk mendapatkan data terurut
    inorderSave(root, sortedItems);
    
    for (auto &item : sortedItems) {
        file << item.id << "|" << item.name << "|" << item.type << "|"
             << item.location << "|" << item.date << "|" 
             << item.status << "|" << item.contact << "\n";
    }
    file.close();
}

// fungsi untuk melaporkan barang hilang atau ditemukan
void reportItem(bool isLost) {
    Item item;
    item.id = nextId++;
    item.type = isLost ? "lost" : "found";
    item.status = "available";
    
    cout << "\n=== LAPOR BARANG " << (isLost ? "HILANG" : "DITEMUKAN") << " ===\n";
    cout << "Nama Barang: ";
    clearInput();
    getline(cin, item.name);
    
    cout << "Lokasi: ";
    getline(cin, item.location);
    
    cout << "Tanggal (DD-MM): ";
    getline(cin, item.date);
    
    cout << "Kontak Anda: ";
    getline(cin, item.contact);
    
    // tambah ke BST
    root = insertBST(root, item);
    
    saveData();
    cout << "Laporan berhasil. ID: " << item.id << endl;
}

// fungsi untuk menampilkan barang berdasarkan tipe (lost/found)
void showItems(string type) {
    cout << "\n=== BARANG " << (type == "lost" ? "HILANG" : "DITEMUKAN") << " ===\n";
    inorderTraversal(root, type);
    
    // cek jika tidak ada barang dengan type tersebut
    bool found = false;
    checkItems(root, type, found);
    
    if (!found) {
        cout << "Tidak ada barang " << (type == "lost" ? "hilang" : "ditemukan") << ".\n";
    }
}

// fungsi untuk mengklaim barang berdasarkan ID
void claimItem() {
    int id;
    cout << "\n=== KLAIM BARANG ===\n";
    cout << "Masukkan ID barang: ";
    cin >> id;
    clearInput();
    
    // cari di BST
    BSTNode* foundNode = searchBST(root, id);
    
    if (foundNode != nullptr && foundNode->data.status == "available") {
        cout << "\nBarang ditemukan:\n";
        cout << "Nama: " << foundNode->data.name << endl;
        cout << "Tipe: " << foundNode->data.type << endl;
        cout << "Lokasi: " << foundNode->data.location << endl;
        cout << "Tanggal: " << foundNode->data.date << endl;
        cout << "Kontak: " << foundNode->data.contact << endl;
        
        cout << "\nKlaim barang ini? (y/n): ";
        char choice;
        cin >> choice;
        clearInput();
        
        if (choice == 'y' || choice == 'Y') {
            foundNode->data.status = "claimed";
            
            // fitur auto-match: cari pasangan dengan nama yang sama
            autoMatchTraversal(root, id, foundNode->data.name, foundNode->data.type);
            
            saveData();
            cout << "Klaim berhasil.\n";
        } else {
            cout << "Klaim dibatalkan.\n";
        }
    } else {
        cout << "Barang tidak ditemukan atau sudah diklaim.\n";
    }
}

// fungsi untuk menampilkan semua barang yang tersedia
void showAllItems() {
    cout << "\n=== SEMUA BARANG (TERURUT BERDASARKAN NAMA) ===\n";
    inorderTraversal(root);
}

// fungsi untuk mencari barang berdasarkan nama
void searchItem() {
    string keyword;
    cout << "\n=== CARI BARANG ===\n";
    cout << "Masukkan nama barang: ";
    clearInput();
    getline(cin, keyword);
    
    cout << "\nHasil Pencarian:\n";
    
    searchTraversal(root, keyword);
}

// fungsi untuk menu admin dengan password
void adminMenu() {
    string password;
    cout << "\nPassword Admin: ";
    clearInput();
    getline(cin, password);
    
    if (password != "admin123") {
        cout << "Password salah.\n";
        return;
    }
    
    int choice;
    do {
        cout << "\n=== ADMIN MENU ===\n";
        cout << "1. Lihat Semua Barang\n";
        cout << "2. Statistik\n";
        cout << "3. Cari Barang\n";
        cout << "4. Update Status Barang\n";
        cout << "0. Kembali\n";
        cout << "Pilih: ";
        cin >> choice;
        clearInput();
        
        switch(choice) {
            case 1: showAllItems(); break;
            case 2: {
                int lost = 0, found = 0, available = 0, claimed = 0;
                
                statsTraversal(root, lost, found, available, claimed);
                
                cout << "\n=== STATISTIK ===\n";
                cout << "Total Barang: " << (lost + found) << endl;
                cout << "Barang Hilang: " << lost << endl;
                cout << "Barang Ditemukan: " << found << endl;
                cout << "Barang Available: " << available << endl;
                cout << "Barang Claimed: " << claimed << endl;
                break;
            }
            case 3: searchItem(); break;
            case 4: {
                int id;
                string newStatus;
                cout << "ID Barang: ";
                cin >> id;
                clearInput();
                cout << "Status Baru (available/claimed): ";
                getline(cin, newStatus);
                
                BSTNode* node = searchBST(root, id);
                if (node != nullptr) {
                    node->data.status = newStatus;
                    saveData();
                    cout << "Status berhasil diubah.\n";
                } else {
                    cout << "Barang tidak ditemukan.\n";
                }
                break;
            }
        }
    } while (choice != 0);
}

// fungsi utama program
int main() {
    loadData();
    
    int choice;
    do {
        cout << "\n=== LOST & FOUND SYSTEM ===\n";
        cout << "1. Laporkan Barang Hilang\n";
        cout << "2. Laporkan Barang Ditemukan\n";
        cout << "3. Lihat Barang Hilang\n";
        cout << "4. Lihat Barang Ditemukan\n";
        cout << "5. Klaim Barang\n";
        cout << "6. Cari Barang\n";
        cout << "7. Admin Menu\n";
        cout << "0. Exit\n";
        cout << "Pilih: ";
        cin >> choice;
        
        switch(choice) {
            case 1: reportItem(true); break;
            case 2: reportItem(false); break;
            case 3: showItems("lost"); break;
            case 4: showItems("found"); break;
            case 5: claimItem(); break;
            case 6: searchItem(); break;
            case 7: adminMenu(); break;
            case 0: cout << "Terima kasih.\n"; break;
            default: cout << "Pilihan tidak valid.\n";
        }
    } while (choice != 0);
    
    return 0;
}