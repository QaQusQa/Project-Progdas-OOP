#include "person.h"
#include <iostream>
#include <limits>

using namespace std;

// Person class implementation
orang::orang(const std::string& uname, const std::string& mail, const std::string& pwd)
    : username(uname), email(mail), password(pwd), loggedIn(false) {}

string orang::melihat_nama() const {
    return username;
}

string orang::email_akun() const {
    return email;
}

bool orang::sudah_login() const {
    return loggedIn;
}

bool orang::login(const std::string& inputPassword) {
    if (inputPassword == password) {
        loggedIn = true;
        cout << "Login berhasil! Selamat datang " << username << "!\n";
        return true;
    } else {
        cout << "Password salah!\n";
        return false;
    }
}

void orang::logout() {
    loggedIn = false;
    cout << "Logout berhasil. Sampai jumpa " << username << "!\n";
}

// Pembeli class implementation
pembeli::pembeli(const std::string& uname, const std::string& mail, const std::string& pwd)
    : orang(uname, mail, pwd) {}

void pembeli::mencari_produk() {
    if (!sudah_login()) {
        cout << "Silakan login terlebih dahulu!\n";
        return;
    }
    
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

void pembeli::detail_produk() {
    if (!sudah_login()) {
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

void pembeli::masukkan_ke_keranjang() {
    if (!sudah_login()) {
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

void pembeli::isi_keranjang() {
    if (!sudah_login()) {
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

void pembeli::checkout() {
    if (!sudah_login()) {
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

void pembeli::membayaran() {
    if (!sudah_login()) {
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

void pembeli::status_pesanan() {
    if (!sudah_login()) {
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

void pembeli::terima_barang() {
    if (!sudah_login()) {
        cout << "Silakan login terlebih dahulu!\n";
        return;
    }
    
    cout << "Barang telah diterima. Terima kasih!\n";
}

void pembeli::info() const {
    cout << "=== INFO PEMBELI ===\n";
    cout << "Username: " << username << "\n";
    cout << "Email: " << email << "\n";
    cout << "Status: " << (loggedIn ? "Online" : "Offline") << "\n";
    cout << "Item di keranjang: " << keranjang.size() << "\n";
    cout << "Total pesanan: " << riwayatPesanan.size() << "\n";
}

void pembeli::menu() {
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
            case 1: mencari_produk(); break;
            case 2: detail_produk(); break;
            case 3: masukkan_ke_keranjang(); break;
            case 4: isi_keranjang(); break;
            case 5: checkout(); break;
            case 6: membayaran(); break;
            case 7: status_pesanan(); break;
            case 8: terima_barang(); break;
            case 9: info(); break;
            case 0: logout(); break;
            default: cout << "Pilihan tidak valid!\n";
        }
    } while (pilihan != 0 && sudah_login());
}

// Penjual class implementation
Penjual::Penjual(const std::string& uname, const std::string& mail, const std::string& pwd, const std::string& toko)
    : orang(uname, mail, pwd), namaToko(toko) {}

void Penjual::menambahkan_produk() {
    if (!sudah_login()) {
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

void Penjual::stok_produk() {
    if (!sudah_login()) {
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

void Penjual::katalog() {
    if (!sudah_login()) {
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

void Penjual::menerima_pesanan() {
    if (!sudah_login()) {
        cout << "Silakan login terlebih dahulu!\n";
        return;
    }
    
    cout << "Menerima pesanan baru...\n";
    daftarPesanan.push_back("Pesanan #" + to_string(daftarPesanan.size() + 1));
    cout << "Pesanan diterima!\n";
}

void Penjual::memproses_pesanan() {
    if (!sudah_login()) {
        cout << "Silakan login terlebih dahulu!\n";
        return;
    }
    
    cout << "Memproses pesanan...\n";
    cout << "Pesanan sedang diproses!\n";
}

void Penjual::pengiriman() {
    if (!sudah_login()) {
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

void Penjual::daftar_pesanan() {
    if (!sudah_login()) {
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

void Penjual::konfirmasi_pengiriman() {
    if (!sudah_login()) {
        cout << "Silakan login terlebih dahulu!\n";
        return;
    }
    
    cout << "Mengonfirmasi pengiriman...\n";
    cout << "Pengiriman telah dikonfirmasi!\n";
}

void Penjual::info() const {
    cout << "=== INFO PENJUAL ===\n";
    cout << "Username: " << username << "\n";
    cout << "Email: " << email << "\n";
    cout << "Nama Toko: " << namaToko << "\n";
    cout << "Status: " << (loggedIn ? "Online" : "Offline") << "\n";
    cout << "Total produk: " << katalogProduk.size() << "\n";
    cout << "Total pesanan: " << daftarPesanan.size() << "\n";
}

void Penjual::menu() {
    int pilihan;
    do {
        cout << "\n=== MENU PENJUAL ===\n";
        cout << "1. Menambahkan Produk\n";
        cout << "2. Stok Produk\n";
        cout << "3. Lihat Katalog\n";
        cout << "4. Terima Pesanan\n";
        cout << "5. Proses Pesanan\n";
        cout << "6. Pengiriman\n";
        cout << "7. Lihat Daftar Pesanan\n";
        cout << "8. Konfirmasi Pengiriman\n";
        cout << "9. Lihat Info Akun\n";
        cout << "0. Logout\n";
        cout << "Pilihan: ";
        cin >> pilihan;
        
        switch(pilihan) {
            case 1: menambahkan_produk(); break;
            case 2: stok_produk(); break;
            case 3: katalog(); break;
            case 4: menerima_pesanan(); break;
            case 5: memproses_pesanan(); break;
            case 6: pengiriman(); break;
            case 7: daftar_pesanan(); break;
            case 8: konfirmasi_pengiriman(); break;
            case 9: info(); break;
            case 0: logout(); break;
            default: cout << "Pilihan tidak valid!\n";
        }
    } while (pilihan != 0 && sudah_login());
}