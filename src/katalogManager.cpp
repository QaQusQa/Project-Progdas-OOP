#include "katalogManager.h"
#include <iostream>
#include <iomanip>

using namespace std;

KatalogManager* KatalogManager::instance = nullptr;

KatalogManager::KatalogManager() {
    inisialisasiData();
}

KatalogManager* KatalogManager::getInstance() {
    if (instance == nullptr) {
        instance = new KatalogManager();
    }
    return instance;
}

void KatalogManager::inisialisasiData() {
    katalog.inisialisasiProdukDummy();
    cout << "Katalog berhasil diinisialisasi dengan " << katalog.jumlahProduk() << " produk!\n";
}

void KatalogManager::tampilkanSemuaProduk() {
    katalog.tampilkanSemuaProduk();
}

void KatalogManager::tampilkanProdukByKategori(int kategori) {
    string namaKategori;
    switch(kategori) {
        case 1: namaKategori = "Elektronik"; break;
        case 2: namaKategori = "Kebutuhan Pokok"; break;
        case 3: namaKategori = "Fashion"; break;
        default: 
            cout << "Kategori tidak valid!\n";
            return;
    }
    
    katalog.tampilkanProdukKategori(namaKategori);
}

void KatalogManager::cariDanTampilkanProduk(const string& keyword) {
    vector<Produk*> hasil = katalog.cariProduk(keyword);
    
    cout << "\n=== HASIL PENCARIAN: '" << keyword << "' ===\n";
    if (hasil.empty()) {
        cout << "Tidak ditemukan produk dengan kata kunci '" << keyword << "'\n";
    } else {
        for (size_t i = 0; i < hasil.size(); i++) {
            cout << "[" << i + 1 << "] " << hasil[i]->getNama() 
                 << " - " << hasil[i]->getKategori() 
                 << " - Rp " << fixed << setprecision(0) << hasil[i]->getHarga()
                 << " (Stok: " << hasil[i]->getStok() << ")\n";
        }
        
        // Tanya apakah ingin lihat detail
        cout << "\nIngin lihat detail produk? (y/n): ";
        char pilihan;
        cin >> pilihan;
        if (pilihan == 'y' || pilihan == 'Y') {
            int nomor;
            cout << "Masukkan nomor produk: ";
            cin >> nomor;
            if (nomor > 0 && nomor <= (int)hasil.size()) {
                hasil[nomor-1]->tampilkanDetail();
            }
        }
    }
}

void KatalogManager::tampilkanDetailProduk(int index) {
    Produk* produk = katalog.getProdukByIndex(index);
    if (produk) {
        produk->tampilkanDetail();
    } else {
        cout << "Produk tidak ditemukan!\n";
    }
}

Produk* KatalogManager::getProdukByIndex(int index) {
    return katalog.getProdukByIndex(index);
}

vector<Produk*> KatalogManager::cariProduk(const string& keyword) {
    return katalog.cariProduk(keyword);
}

int KatalogManager::getJumlahProduk() {
    return katalog.jumlahProduk();
}