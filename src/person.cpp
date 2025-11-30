#include "person.h"
#include "katalogManager.h"
#include <iostream>
#include <limits>
#include <iomanip>

using namespace std;

// ========== PERSON IMPLEMENTATION ==========
Person::Person(const string& uname, const string& mail, const string& pwd)
    : username(uname), email(mail), password(pwd), loggedIn(false) {}

string Person::cariUsername() const {
    return username;
}

string Person::cariEmail() const {
    return email;
}

bool Person::sudahLoggedIn() const {
    return loggedIn;
}

bool Person::login(const string& inputPassword) {
    if (inputPassword == password) {
        loggedIn = true;
        cout << "Login berhasil! Selamat datang " << username << "!\n";
        return true;
    } else {
        cout << "Password salah!\n";
        return false;
    }
}

void Person::logout() {
    loggedIn = false;
    cout << "Logout berhasil. Sampai jumpa " << username << "!\n";
}

// ========== PEMBELI IMPLEMENTATION ==========
Pembeli::Pembeli(const string& uname, const string& mail, const string& pwd)
    : Person(uname, mail, pwd) {}

void Pembeli::cariProduk() {
    if (!sudahLoggedIn()) {
        cout << "Silakan login terlebih dahulu!\n";
        return;
    }
    
    KatalogManager* katalog = KatalogManager::getInstance();
    
    int pilihan;
    cout << "\n=== CARI PRODUK ===\n";
    cout << "1. Cari berdasarkan kategori\n";
    cout << "2. Cari dengan kata kunci\n";
    cout << "3. Lihat semua produk\n";
    cout << "Pilihan: ";
    cin >> pilihan;
    
    if (pilihan == 1) {
        int kategori;
        cout << "\n=== KATEGORI PRODUK ===\n";
        cout << "1. Elektronik\n";
        cout << "2. Kebutuhan Pokok\n";
        cout << "3. Fashion\n";
        cout << "Pilihan kategori: ";
        cin >> kategori;
        
        katalog->tampilkanProdukByKategori(kategori);
        
    } else if (pilihan == 2) {
        string keyword;
        cout << "Masukkan kata kunci: ";
        cin.ignore();
        getline(cin, keyword);
        katalog->cariDanTampilkanProduk(keyword);
        
    } else if (pilihan == 3) {
        katalog->tampilkanSemuaProduk();
    } else {
        cout << "Pilihan tidak valid!\n";
    }
}

void Pembeli::lihatDetailProduk() {
    if (!sudahLoggedIn()) {
        cout << "Silakan login terlebih dahulu!\n";
        return;
    }
    
    KatalogManager* katalog = KatalogManager::getInstance();
    
    cout << "\n=== LIHAT DETAIL PRODUK ===\n";
    katalog->tampilkanSemuaProduk();
    
    int pilihan;
    cout << "Pilih nomor produk: ";
    cin >> pilihan;
    
    if (pilihan < 1 || pilihan > katalog->getJumlahProduk()) {
        cout << "Nomor produk tidak valid!\n";
        return;
    }
    
    katalog->tampilkanDetailProduk(pilihan - 1);
}

void Pembeli::tambahKeKeranjang() {
    if (!sudahLoggedIn()) {
        cout << "Silakan login terlebih dahulu!\n";
        return;
    }
    
    KatalogManager* katalog = KatalogManager::getInstance();
    
    cout << "\n=== TAMBAH KE KERANJANG ===\n";
    katalog->tampilkanSemuaProduk();
    
    int pilihan;
    cout << "Pilih nomor produk: ";
    cin >> pilihan;
    
    if (pilihan < 1 || pilihan > katalog->getJumlahProduk()) {
        cout << "Nomor produk tidak valid!\n";
        return;
    }
    
    Produk* produk = katalog->getProdukByIndex(pilihan - 1);
    if (produk && produk->getStok() > 0) {
        keranjang.push_back(produk);
        cout << "Produk '" << produk->getNama() << "' berhasil ditambahkan ke keranjang!\n";
    } else {
        cout << "Produk tidak tersedia!\n";
    }
}

void Pembeli::lihatKeranjang() {
    if (!sudahLoggedIn()) {
        cout << "Silakan login terlebih dahulu!\n";
        return;
    }
    
    cout << "\n=== KERANJANG BELANJA ===\n";
    if (keranjang.empty()) {
        cout << "Keranjang kosong.\n";
    } else {
        double total = 0;
        for (size_t i = 0; i < keranjang.size(); i++) {
            cout << i+1 << ". " << keranjang[i]->getNama() 
                 << " - Rp " << fixed << setprecision(0) << keranjang[i]->getHarga() << "\n";
            total += keranjang[i]->getHarga();
        }
        cout << "Total: Rp " << fixed << setprecision(0) << total << "\n";
    }
}

void Pembeli::prosesCheckout() {
    if (!sudahLoggedIn()) {
        cout << "Silakan login terlebih dahulu!\n";
        return;
    }
    
    if (keranjang.empty()) {
        cout << "Keranjang kosong!\n";
        return;
    }
    
    cout << "\n=== PROSES CHECKOUT ===\n";
    double total = 0;
    for (size_t i = 0; i < keranjang.size(); i++) {
        cout << i+1 << ". " << keranjang[i]->getNama() 
             << " - Rp " << keranjang[i]->getHarga() << "\n";
        total += keranjang[i]->getHarga();
        keranjang[i]->kurangiStok(1);
    }
    
    cout << "Total: Rp " << fixed << setprecision(0) << total << "\n";
    cout << "Checkout berhasil!\n";
    
    // PERBAIKAN: Simpan nama produk ke riwayat
    for (size_t i = 0; i < keranjang.size(); i++) {
        riwayatPesanan.push_back(keranjang[i]->getNama());
    }
    keranjang.clear();
}

void Pembeli::lakukanPembayaran() {
    if (!sudahLoggedIn()) {
        cout << "Silakan login terlebih dahulu!\n";
        return;
    }
    
    cout << "\n=== PEMBAYARAN ===\n";
    cout << "Pembayaran berhasil!\n";
}

void Pembeli::lihatStatusPesanan() {
    if (!sudahLoggedIn()) {
        cout << "Silakan login terlebih dahulu!\n";
        return;
    }
    
    cout << "\n=== STATUS PESANAN ===\n";
    if (riwayatPesanan.empty()) {
        cout << "Belum ada pesanan.\n";
    } else {
        for (size_t i = 0; i < riwayatPesanan.size(); i++) {
            cout << i+1 << ". " << riwayatPesanan[i] << " - Status: Diproses\n";
        }
    }
}

void Pembeli::terimaBarang() {
    if (!sudahLoggedIn()) {
        cout << "Silakan login terlebih dahulu!\n";
        return;
    }
    cout << "Barang diterima. Terima kasih!\n";
}

void Pembeli::tampilkanInfo() const {
    cout << "\n=== INFO PEMBELI ===\n";
    cout << "Username: " << username << "\n";
    cout << "Email: " << email << "\n";
    cout << "Status: " << (loggedIn ? "Online" : "Offline") << "\n";
}

void Pembeli::tampilkanMenu() {
    int pilihan;
    do {
        cout << "\n=== MENU PEMBELI ===\n";
        cout << "1. Cari Produk\n";
        cout << "2. Lihat Detail Produk\n";
        cout << "3. Tambah ke Keranjang\n";
        cout << "4. Lihat Keranjang\n";
        cout << "5. Checkout\n";
        cout << "6. Bayar Pesanan\n";
        cout << "7. Lihat Status Pesanan\n";
        cout << "8. Terima Barang\n";
        cout << "9. Lihat Info Akun\n";
        cout << "0. Logout\n";
        cout << "Pilihan: ";
        cin >> pilihan;
        
        switch(pilihan) {
            case 1: cariProduk(); break;
            case 2: lihatDetailProduk(); break;
            case 3: tambahKeKeranjang(); break;
            case 4: lihatKeranjang(); break;
            case 5: prosesCheckout(); break;
            case 6: lakukanPembayaran(); break;
            case 7: lihatStatusPesanan(); break;
            case 8: terimaBarang(); break;
            case 9: tampilkanInfo(); break;
            case 0: logout(); break;
            default: cout << "Pilihan tidak valid!\n";
        }
    } while (pilihan != 0);
}

// ========== PENJUAL IMPLEMENTATION ==========
Penjual::Penjual(const string& uname, const string& mail, const string& pwd, const string& toko)
    : Person(uname, mail, pwd), namaToko(toko) {}

void Penjual::tambahProduk() {
    if (!sudahLoggedIn()) {
        cout << "Silakan login terlebih dahulu!\n";
        return;
    }
    cout << "Fitur tambah produk sedang dikembangkan...\n";
}

void Penjual::aturStokProduk() {
    if (!sudahLoggedIn()) {
        cout << "Silakan login terlebih dahulu!\n";
        return;
    }
    cout << "Fitur atur stok sedang dikembangkan...\n";
}

void Penjual::lihatKatalog() {
    if (!sudahLoggedIn()) {
        cout << "Silakan login terlebih dahulu!\n";
        return;
    }
    cout << "Fitur lihat katalog sedang dikembangkan...\n";
}

void Penjual::terimaPesanan() {
    if (!sudahLoggedIn()) {
        cout << "Silakan login terlebih dahulu!\n";
        return;
    }
    cout << "Fitur terima pesanan sedang dikembangkan...\n";
}

void Penjual::prosesPesanan() {
    if (!sudahLoggedIn()) {
        cout << "Silakan login terlebih dahulu!\n";
        return;
    }
    cout << "Fitur proses pesanan sedang dikembangkan...\n";
}

void Penjual::aturPengiriman() {
    if (!sudahLoggedIn()) {
        cout << "Silakan login terlebih dahulu!\n";
        return;
    }
    cout << "Fitur atur pengiriman sedang dikembangkan...\n";
}

void Penjual::lihatDaftarPesanan() {
    if (!sudahLoggedIn()) {
        cout << "Silakan login terlebih dahulu!\n";
        return;
    }
    cout << "Fitur lihat daftar pesanan sedang dikembangkan...\n";
}

void Penjual::konfirmasiPengiriman() {
    if (!sudahLoggedIn()) {
        cout << "Silakan login terlebih dahulu!\n";
        return;
    }
    cout << "Fitur konfirmasi pengiriman sedang dikembangkan...\n";
}

void Penjual::tampilkanInfo() const {
    cout << "\n=== INFO PENJUAL ===\n";
    cout << "Username: " << username << "\n";
    cout << "Email: " << email << "\n";
    cout << "Nama Toko: " << namaToko << "\n";
    cout << "Status: " << (loggedIn ? "Online" : "Offline") << "\n";
}

void Penjual::tampilkanMenu() {
    int pilihan;
    do {
        cout << "\n=== MENU PENJUAL ===\n";
        cout << "1. Tambah Produk\n";
        cout << "2. Atur Stok Produk\n";
        cout << "3. Lihat Katalog\n";
        cout << "4. Terima Pesanan\n";
        cout << "5. Proses Pesanan\n";
        cout << "6. Atur Pengiriman\n";
        cout << "7. Lihat Daftar Pesanan\n";
        cout << "8. Konfirmasi Pengiriman\n";
        cout << "9. Lihat Info Akun\n";
        cout << "0. Logout\n";
        cout << "Pilihan: ";
        cin >> pilihan;
        
        switch(pilihan) {
            case 1: tambahProduk(); break;
            case 2: aturStokProduk(); break;
            case 3: lihatKatalog(); break;
            case 4: terimaPesanan(); break;
            case 5: prosesPesanan(); break;
            case 6: aturPengiriman(); break;
            case 7: lihatDaftarPesanan(); break;
            case 8: konfirmasiPengiriman(); break;
            case 9: tampilkanInfo(); break;
            case 0: logout(); break;
            default: cout << "Pilihan tidak valid!\n";
        }
    } while (pilihan != 0);
}