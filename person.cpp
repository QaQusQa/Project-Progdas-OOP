#include "person.h"
#include <iostream>
#include <limits>

using namespace std;

// Person class implementation
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

// Pembeli class implementation
Pembeli::Pembeli(const string& uname, const string& mail, const string& pwd)
    : Person(uname, mail, pwd) {}

void Pembeli::cariProduk() {
    if (!sudahLoggedIn()) {
        cout << "Silakan login terlebih dahulu!\n";
        return;
    }
    
    int kategori;
    cout << "=== KATEGORI PRODUK ===\n";
    cout << "Masukkan kategori yang dipilih? ";
    
    cout << "1. Elektronik" << endl;
    cout << "2. Komputer dan Aksesoris" << endl;
    cout << "3. Fashion" << endl;
    cout << "4. Kesehatan" << endl;
    cout << "5. Hobi dan Koleksi" << endl;
    cout << "6. Perlengkapan Rumah Tangga" << endl;
    cout << "7. Perawatan dan Kosmetik" << endl;
    cout << "8. Olahraga" << endl;
    cout << "9. Makanan dan Minuman" << endl;
    cout << "10. Buku dan Alat Tulis" << endl;
    cin >> kategori;
    switch (kategori)
    {
    case 1:
        
        break;
    case 2: 
        
        break;
    case 3: 
        
        break;
    case 4: 
        
        break;
    case 5: 
        
        break;
    case 6: 
        
        break;
    case 7: 
        
        break;
    case 8: 
        
        break;
    case 9: 
        
        break;
    default:    
        cout << "Pilihan tidak valid!\n";
    }



    cin >> kategori;
    string keyword;
    cout << "Masukkan kata kunci produk: ";
    cin.ignore();
    getline(cin, keyword);
    cout << "Mencari produk: " << keyword << "\n";
    cout << "Hasil pencarian:\n";
    cout << "1. Smartphone " << keyword << " - Rp 5.000.000\n";
    cout << "2. Case " << keyword << " - Rp 100.000\n";
    cout << "3. Charger " << keyword << " - Rp 150.000\n";
}

void Pembeli::lihatDetailProduk() {
    if (!sudahLoggedIn()) {
        cout << "Silakan login terlebih dahulu!\n";
        return;
    }
    
    int pilihan;
    cout << "Pilih produk untuk dilihat detail:\n";
    cout << "1. Smartphone Samsung S23\n";
    cout << "2. Case HP Premium\n";
    cout << "3. Charger Fast Charging\n";
    cout << "Pilihan: ";
    cin >> pilihan;
    
    switch(pilihan) {
        case 1:
            cout << "Detail Smartphone Samsung S23:\n";
            cout << "Harga: Rp 5.000.000\n";
            cout << "Stok: 10\n";
            cout << "Deskripsi: Smartphone flagship dengan kamera 108MP\n";
            break;
        case 2:
            cout << "Detail Case HP Premium:\n";
            cout << "Harga: Rp 100.000\n";
            cout << "Stok: 50\n";
            cout << "Deskripsi: Case anti gores dengan bahan premium\n";
            break;
        case 3:
            cout << "Detail Charger Fast Charging:\n";
            cout << "Harga: Rp 150.000\n";
            cout << "Stok: 30\n";
            cout << "Deskripsi: Charger 25W dengan fast charging technology\n";
            break;
        default:
            cout << "Pilihan tidak valid!\n";
    }
}

void Pembeli::tambahKeKeranjang() {
    if (!sudahLoggedIn()) {
        cout << "Silakan login terlebih dahulu!\n";
        return;
    }
    
    string produk;
    cout << "Masukkan nama produk yang ingin ditambahkan: ";
    cin.ignore();
    getline(cin, produk);
    keranjang.push_back(produk);
    cout << "Produk '" << produk << "' berhasil ditambahkan ke keranjang!\n";
}

void Pembeli::lihatKeranjang() {
    if (!sudahLoggedIn()) {
        cout << "Silakan login terlebih dahulu!\n";
        return;
    }
    
    cout << "=== KERANJANG BELANJA ===\n";
    if (keranjang.empty()) {
        cout << "Keranjang kosong.\n";
    } else {
        for (int i = 0; i < keranjang.size(); i++) {
            cout << i+1 << ". " << keranjang[i] << "\n";
        }
    }
}

void Pembeli::prosesCheckout() {
    if (!sudahLoggedIn()) {
        cout << "Silakan login terlebih dahulu!\n";
        return;
    }
    
    if (keranjang.empty()) {
        cout << "Keranjang kosong, tidak bisa checkout!\n";
        return;
    }
    
    cout << "Checkout berhasil!\n";
    cout << "Total item: " << keranjang.size() << "\n";
    cout << "Total harga: Rp " << keranjang.size() * 100000 << "\n";
    
    // Pindahkan ke riwayat pesanan
    for (const auto& item : keranjang) {
        riwayatPesanan.push_back(item);
    }
    keranjang.clear();
}

void Pembeli::lakukanPembayaran() {
    if (!sudahLoggedIn()) {
        cout << "Silakan login terlebih dahulu!\n";
        return;
    }
    
    cout << "Simulasi pembayaran...\n";
    cout << "1. Transfer Bank\n";
    cout << "2. Kartu Kredit\n";
    cout << "3. E-Wallet\n";
    
    int metode;
    cout << "Pilih metode pembayaran: ";
    cin >> metode;
    
    cout << "Pembayaran berhasil!\n";
}

void Pembeli::lihatStatusPesanan() {
    if (!sudahLoggedIn()) {
        cout << "Silakan login terlebih dahulu!\n";
        return;
    }
    
    cout << "=== STATUS PESANAN ===\n";
    if (riwayatPesanan.empty()) {
        cout << "Belum ada pesanan.\n";
    } else {
        for (int i = 0; i < riwayatPesanan.size(); i++) {
            cout << i+1 << ". " << riwayatPesanan[i] << " - Status: Dikirim\n";
        }
    }
}

void Pembeli::terimaBarang() {
    if (!sudahLoggedIn()) {
        cout << "Silakan login terlebih dahulu!\n";
        return;
    }
    
    cout << "Barang telah diterima. Terima kasih!\n";
}

void Pembeli::tampilkanInfo() const {
    cout << "=== INFO PEMBELI ===\n";
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
    } while (pilihan != 0 && sudahLoggedIn());
}

// Penjual class implementation
Penjual::Penjual(const string& uname, const string& mail, const string& pwd, const string& toko)
    : Person(uname, mail, pwd), namaToko(toko) {}

void Penjual::tambahProduk() {
    if (!sudahLoggedIn()) {
        cout << "Silakan login terlebih dahulu!\n";
        return;
    }
    
    string produk;
    cout << "Masukkan nama produk: ";
    cin.ignore();
    getline(cin, produk);
    katalogProduk.push_back(produk);
    cout << "Produk '" << produk << "' berhasil diunggah!\n";
}

void Penjual::aturStokProduk() {
    if (!sudahLoggedIn()) {
        cout << "Silakan login terlebih dahulu!\n";
        return;
    }
    
    cout << "Mengatur stok produk...\n";
    if (katalogProduk.empty()) {
        cout << "Belum ada produk di katalog.\n";
        return;
    }
    
    for (int i = 0; i < katalogProduk.size(); i++) {
        cout << i+1 << ". " << katalogProduk[i] << "\n";
    }
    
    int pilihan, stok;
    cout << "Pilih produk: ";
    cin >> pilihan;
    cout << "Masukkan stok baru: ";
    cin >> stok;
    
    if (pilihan > 0 && pilihan <= katalogProduk.size()) {
        cout << "Stok " << katalogProduk[pilihan-1] << " diatur menjadi " << stok << "\n";
    }
}

void Penjual::lihatKatalog() {
    if (!sudahLoggedIn()) {
        cout << "Silakan login terlebih dahulu!\n";
        return;
    }
    
    cout << "=== KATALOG TOKO " << namaToko << " ===\n";
    if (katalogProduk.empty()) {
        cout << "Katalog kosong.\n";
    } else {
        for (int i = 0; i < katalogProduk.size(); i++) {
            cout << i+1 << ". " << katalogProduk[i] << " - Stok: 10 - Harga: Rp 100.000\n";
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
    
    cout << "Mengatur pengiriman...\n";
    cout << "1. JNE Reguler\n";
    cout << "2. JNT Express\n";
    cout << "3. SiCepat\n";
    
    int metode;
    cout << "Pilih metode pengiriman: ";
    cin >> metode;
    
    cout << "Pengiriman berhasil diatur!\n";
}

void Penjual::lihatDaftarPesanan() {
    if (!sudahLoggedIn()) {
        cout << "Silakan login terlebih dahulu!\n";
        return;
    }
    
    cout << "=== DAFTAR PESANAN ===\n";
    if (daftarPesanan.empty()) {
        cout << "Belum ada pesanan.\n";
    } else {
        for (int i = 0; i < daftarPesanan.size(); i++) {
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
    cout << "=== INFO PENJUAL ===\n";
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