#include "person.h"
#include <iostream>
#include <limits>
#include <iomanip>

using namespace std;

vector<vector<string>> katalogGlobal;

void initializeKatalog() { // Katalog awal sebelum penjual menambahkan produknya
    if (katalogGlobal.empty()) {
        katalogGlobal.push_back({"Smartphone", "1000000", "10", "Elektronik"});
        katalogGlobal.push_back({"Laptop", "1500000", "5", "Elektronik"});
        katalogGlobal.push_back({"Kamera", "800000", "8", "Elektronik"});
        katalogGlobal.push_back({"Minyak Goreng", "15000", "30", "Kebutuhan Pokok"});
        katalogGlobal.push_back({"Gula", "12000", "20", "Kebutuhan Pokok"});
        katalogGlobal.push_back({"Beras", "75000", "15", "Kebutuhan Pokok"});
        katalogGlobal.push_back({"Sepatu", "200000", "5", "Fashion"});
        katalogGlobal.push_back({"Celana Jeans", "150000", "10", "Fashion"});
        katalogGlobal.push_back({"Jaket Kulit", "750000", "20", "Fashion"});
        
        cout << "[DEBUG] Data dummy berhasil diinisialisasi: " << katalogGlobal.size() << " produk\n"; // Kalo tidak error muncul, kalau error kita pusing
    }
}

//Katalog harus tampil
void tampilkanKatalog() {
    cout << "\n=== KATALOG PRODUK ===\n";
    for (size_t i = 0; i < katalogGlobal.size(); i++) {
        cout << "[" << i + 1 << "] " << katalogGlobal[i][0] 
             << " - Rp " << katalogGlobal[i][1] 
             << " (Stok: " << katalogGlobal[i][2] << ")" << endl;
    }
}

// === CERITANYA ORANG ===
Person::Person(const string& uname, const string& mail, const string& pwd)
    : username(uname), email(mail), password(pwd), loggedIn(false), 
      katalogProduk(katalogGlobal) { 
        
    // Inisiasi data dummy satu kali saja
    initializeKatalog();
}

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
        cout << "Login berhasil! Selamat datang di TUGAS" << username << "!\n";
        return true;
    } else {
        cout << "Password salah! Coba lagi ya!!!!!\n";
        return false;
    }
}

void Person::logout() {
    loggedIn = false;
    cout << "Logout berhasil. Sampai jumpa di run yang akan datang" << username << "!\n";
}

// === INI YANG BELI ===
Pembeli::Pembeli(const string& uname, const string& mail, const string& pwd)
    : Person(uname, mail, pwd) {}

void Pembeli::cariProduk() {
    if (!sudahLoggedIn()) {
        cout << "Silakan login terlebih dahulu!\n";
        return;
    }
    
    int pilihan;
    cout << "\n=== CARI PRODUK ===\n";
    cout << "1. Cari berdasarkan kategori\n";
    cout << "2. Lihat semua produk\n";
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
        
        string namaKategori;
        if (kategori == 1) namaKategori = "Elektronik";
        else if (kategori == 2) namaKategori = "Kebutuhan Pokok";
        else if (kategori == 3) namaKategori = "Fashion";
        else {
            cout << "Kategori tidak valid!\n";
            return;
        }
        
        cout << "\n=== PRODUK " << namaKategori << " ===\n";
        int nomor = 1;
        bool found = false;
        for (size_t i = 0; i < katalogProduk.size(); i++) {
            if (katalogProduk[i][3] == namaKategori) {
                cout << nomor++ << ". " << katalogProduk[i][0] << endl;
                cout << "   Harga: Rp " << katalogProduk[i][1] << endl;
                cout << "   Stok: " << katalogProduk[i][2] << " unit" << endl;
                cout << "   Kategori: " << katalogProduk[i][3] << endl << endl;
                found = true;
            }
        }
        if (!found) {
            cout << "Tidak ada produk dalam kategori " << namaKategori << ".\n";
        }
    } else if (pilihan == 2) {
        tampilkanKatalog();
    } else {
        cout << "Pilihan tidak valid!\n";
    }
}

void Pembeli::lihatDetailProduk() {
    if (!sudahLoggedIn()) {
        cout << "Silakan login terlebih dahulu!\n";
        return;
    }
    
    cout << "\n=== LIHAT DETAIL PRODUK ===\n";
    tampilkanKatalog();
    
    int pilihan;
    cout << "Pilih nomor produk: ";
    cin >> pilihan;
    
    if (pilihan < 1 || pilihan > (int)katalogProduk.size()) {
        cout << "Nomor produk tidak valid!\n";
        return;
    }
    
    int idx = pilihan - 1;
    cout << "\n================================\n";
    cout << "Nama     : " << katalogProduk[idx][0] << endl;
    cout << "Harga    : Rp " << katalogProduk[idx][1] << endl;
    cout << "Stok     : " << katalogProduk[idx][2] << " unit" << endl;
    cout << "Kategori : " << katalogProduk[idx][3] << endl;
    cout << "================================\n";
}

void Pembeli::tambahKeKeranjang() {
    if (!sudahLoggedIn()) {
        cout << "Silakan login terlebih dahulu!\n";
        return;
    }
    
    cout << "\n=== TAMBAH KE KERANJANG ===\n";
    tampilkanKatalog();
    
    int pilihan;
    cout << "Pilih nomor produk: ";
    cin >> pilihan;
    
    if (pilihan < 1 || pilihan > (int)katalogProduk.size()) {
        cout << "Nomor produk tidak valid!\n";
        return;
    }
    
    int idx = pilihan - 1;
    int stok = stoi(katalogProduk[idx][2]);
    
    if (stok > 0) {
        keranjang.push_back(katalogProduk[idx]);
        cout << "Produk '" << katalogProduk[idx][0] << "' berhasil ditambahkan ke keranjang!\n";
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
            double harga = stod(keranjang[i][1]);
            cout << i+1 << ". " << keranjang[i][0] << " - Rp " << fixed << setprecision(0) << harga << "\n";
            total += harga;
        }
        cout << "\nTotal: Rp " << fixed << setprecision(0) << total << "\n";
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
    
    // Tampilkan item di keranjang
    for (size_t i = 0; i < keranjang.size(); i++) {
        double harga = stod(keranjang[i][1]);
        cout << i+1 << ". " << keranjang[i][0] 
             << " - Rp " << fixed << setprecision(0) << harga << "\n";
        total += harga;
        
        // Kurangi stok di katalog global
        for (size_t j = 0; j < katalogProduk.size(); j++) {
            if (keranjang[i][0] == katalogProduk[j][0]) {
                int stokSekarang = stoi(katalogProduk[j][2]);
                if (stokSekarang > 0) {
                    katalogProduk[j][2] = to_string(stokSekarang - 1);
                }
                break;
            }
        }
    }
    
    cout << "\nTotal: Rp " << fixed << setprecision(0) << total << "\n";
    cout << "Checkout berhasil!\n";
    
    // Simpan ke riwayat pesanan
    for (size_t i = 0; i < keranjang.size(); i++) {
        riwayatPesanan.push_back(keranjang[i][0]);
    }
    
    // Kosongkan keranjang
    keranjang.clear();
}

void Pembeli::lakukanPembayaran() {
    if (!sudahLoggedIn()) {
        cout << "Silakan login terlebih dahulu!\n";
        return;
    }
    
    cout << "\n=== PEMBAYARAN ===\n";
    cout << "1. Transfer Bank\n";
    cout << "2. Kartu Kredit\n";
    cout << "3. E-Wallet\n";
    
    int metode;
    cout << "Pilih metode pembayaran: ";
    cin >> metode;
    
    if (metode >= 1 && metode <= 3) {
        cout << "Pembayaran berhasil!\n";
    } else {
        cout << "Metode pembayaran tidak valid!\n";
    }
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
    cout << "Item di keranjang: " << keranjang.size() << "\n";
    cout << "Total pesanan: " << riwayatPesanan.size() << "\n";
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

// === YANG JUALAN ===
Penjual::Penjual(const string& uname, const string& mail, const string& pwd, const string& toko)
    : Person(uname, mail, pwd), namaToko(toko) {}

void Penjual::tambahProduk() {
    if (!sudahLoggedIn()) {
        cout << "Silakan login terlebih dahulu!\n";
        return;
    }
    
    cout << "\n=== TAMBAH PRODUK ===\n";
    string nama, kategori;
    double harga;
    int stok;
    
    cout << "Nama Produk: ";
    cin.ignore();
    getline(cin, nama);

    cout << "Harga: ";
    cin >> harga;

    cout << "Stok: ";
    cin >> stok;

    cout << "Pastikan penulisan kategori benar, kalau tidak benar nanti error!!!" << endl;
    cout << "Kategori (Elektronik/Kebutuhan Pokok/Fashion): ";
    cin.ignore();
    getline(cin, kategori);

    vector<string> produkBaru = {nama, to_string(harga), to_string(stok), kategori};
    katalogProduk.push_back(produkBaru);
    
    cout << "Produk berhasil ditambahkan!\n";
}

void Penjual::aturStokProduk() {
    if (!sudahLoggedIn()) {
        cout << "Silakan login terlebih dahulu!\n";
        return;
    }
    
    cout << "\n=== ATUR STOK PRODUK ===\n";
    if (katalogProduk.empty()) {
        cout << "Belum ada produk di katalog.\n";
        return;
    }
    
    for (size_t i = 0; i < katalogProduk.size(); i++) {
        cout << i+1 << ". " << katalogProduk[i][0] << " (Stok: " << katalogProduk[i][2] << ")\n";
    }
    
    int pilihan, stok;
    cout << "Pilih produk: ";
    cin >> pilihan;
    
    if (pilihan < 1 || pilihan > (int)katalogProduk.size()) {
        cout << "Pilihan tidak valid!\n";
        return;
    }
    
    cout << "Masukkan stok baru: ";
    cin >> stok;
    
    if (stok >= 0) {
        katalogProduk[pilihan-1][2] = to_string(stok);
        cout << "Stok " << katalogProduk[pilihan-1][0] << " diatur menjadi " << stok << "\n";
    } else {
        cout << "Stok tidak valid!\n";
    }
}

void Penjual::lihatKatalog() {
    if (!sudahLoggedIn()) {
        cout << "Silakan login terlebih dahulu!\n";
        return;
    }
    
    cout << "\n=== KATALOG TOKO " << namaToko << " ===\n";
    if (katalogProduk.empty()) {
        cout << "Katalog kosong.\n";
    } else {
        for (size_t i = 0; i < katalogProduk.size(); i++) {
            cout << "\n[" << i+1 << "] " << katalogProduk[i][0] << "\n";
            cout << "    Kategori: " << katalogProduk[i][3] << "\n";
            cout << "    Harga: Rp " << katalogProduk[i][1] << "\n";
            cout << "    Stok: " << katalogProduk[i][2] << " unit\n";
        }
    }
}

void Penjual::terimaPesanan() {
    if (!sudahLoggedIn()) {
        cout << "Silakan login terlebih dahulu!\n";
        return;
    }
    
    cout << "Menerima pesanan baru...\n";
    daftarPesanan.push_back("Pesanan #" + to_string(daftarPesanan.size() + 1));
    cout << "Pesanan diterima!\n";
}

void Penjual::prosesPesanan() {
    if (!sudahLoggedIn()) {
        cout << "Silakan login terlebih dahulu!\n";
        return;
    }
    
    cout << "Memproses pesanan...\n";
    cout << "Pesanan sedang diproses!\n";
}

void Penjual::aturPengiriman() {
    if (!sudahLoggedIn()) {
        cout << "Silakan login terlebih dahulu!\n";
        return;
    }
    
    cout << "\n=== ATUR PENGIRIMAN ===\n";
    cout << "1. JNE Reguler\n";
    cout << "2. JNT Express\n";
    cout << "3. SiCepat\n";
    
    int metode;
    cout << "Pilih metode pengiriman: ";
    cin >> metode;
    
    if (metode >= 1 && metode <= 3) {
        cout << "Pengiriman berhasil diatur!\n";
    } else {
        cout << "Metode tidak valid!\n";
    }
}

void Penjual::lihatDaftarPesanan() {
    if (!sudahLoggedIn()) {
        cout << "Silakan login terlebih dahulu!\n";
        return;
    }
    
    cout << "\n=== DAFTAR PESANAN ===\n";
    if (daftarPesanan.empty()) {
        cout << "Belum ada pesanan.\n";
    } else {
        for (size_t i = 0; i < daftarPesanan.size(); i++) {
            cout << i+1 << ". " << daftarPesanan[i] << " - Status: Diproses\n";
        }
    }
}

void Penjual::konfirmasiPengiriman() {
    if (!sudahLoggedIn()) {
        cout << "Silakan login terlebih dahulu!\n";
        return;
    }
    
    cout << "Mengonfirmasi pengiriman...\n";
    cout << "Pengiriman telah dikonfirmasi!\n";
}

void Penjual::tampilkanInfo() const {
    cout << "\n=== INFO PENJUAL ===\n";
    cout << "Username: " << username << "\n";
    cout << "Email: " << email << "\n";
    cout << "Nama Toko: " << namaToko << "\n";
    cout << "Status: " << (loggedIn ? "Online" : "Offline") << "\n";
    cout << "Total produk: " << katalogProduk.size() << "\n";
    cout << "Total pesanan: " << daftarPesanan.size() << "\n";
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
    } while (pilihan != 0 && sudahLoggedIn());
}