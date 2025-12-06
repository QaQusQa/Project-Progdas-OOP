#include "tokoOnline.h"
#include <iostream>
#include <limits>

using namespace std;

SistemTokoOnline::SistemTokoOnline() { // Data dummy untuk test akun, sebelum buat ya kan biar testingnya enak
    daftarPembeli.push_back(new Pembeli("pembeli1", "pembeli1@email.com", "123"));
    daftarPembeli.push_back(new Pembeli("john", "john@email.com", "123"));
    daftarPenjual.push_back(new Penjual("penjual1", "penjual1@email.com", "123", "Toko Elektronik"));
    daftarPenjual.push_back(new Penjual("toko_abc", "toko@abc.com", "123", "Toko ABC"));
    
    cout << "Sistem E-Commerce diinisialisasi\n";

    cout << "=== TUGAS PEMROGRAMAN DASAR ===\n";
    cout << "= TEKNOLOGI INFORMASI 2025 =\n";
    cout << "==============================\n";

}

SistemTokoOnline::~SistemTokoOnline() {
    for (auto pembeli : daftarPembeli) delete pembeli;
    for (auto penjual : daftarPenjual) delete penjual;
}

void SistemTokoOnline::tampilkanMenuUtama() {
    int pilihan;
    do {
        cout << "\n=== SISTEM E-COMMERCE ===\n";
        cout << "1. Daftar Akun Baru\n";
        cout << "2. Login\n";
        cout << "3. Keluar\n";
        cout << "Pilihan: ";
        cin >> pilihan;
        
        switch(pilihan) {
            case 1: daftarAkun(); break;
            case 2: loginAkun(); break;
            case 3: cout << "Terima kasih telah menggunakan layanan kami!\n"; 
                cout << "Sampai Jumpa lagi!!!!!" << endl;
                cout << "==============================\n";
                cout << "Salam dari Ramadhani Fadlurahmman dan Qaqa Qushayyi Qatrunnada\n";
                break;
            default: cout << "Pilihan tidak valid!\n";
        }
    } while (pilihan != 3);
}

void SistemTokoOnline::daftarAkun() {
    int tipeAkun;
    cout << "\n=== DAFTAR AKUN BARU ===\n";
    cout << "1. Daftar sebagai Pembeli\n";
    cout << "2. Daftar sebagai Penjual\n";
    cout << "Pilihan: ";
    cin >> tipeAkun;
    
    string username, email, password, namaToko;
    cout << "Username: ";
    cin >> username;
    cout << "Email: ";
    cin >> email;
    cout << "Password: ";
    cin >> password;
    
    if (tipeAkun == 1) {
        daftarPembeli.push_back(new Pembeli(username, email, password));
        cout << "Akun pembeli berhasil dibuat! Silakan login.\n";
    } else if (tipeAkun == 2) {
        cout << "Nama Toko: ";
        cin.ignore();
        getline(cin, namaToko);
        daftarPenjual.push_back(new Penjual(username, email, password, namaToko));
        cout << "Akun penjual berhasil dibuat! Silakan login.\n";
    } else {
        cout << "Pilihan tidak valid!\n";
    } 
}

void SistemTokoOnline::loginAkun() {
    int tipeAkun;
    cout << "\n=== LOGIN ===\n";
    cout << "1. Login sebagai Pembeli\n";
    cout << "2. Login sebagai Penjual\n";
    cout << "Pilihan: ";
    cin >> tipeAkun;
    
    string username, password;
    cout << "Username: ";
    cin >> username;
    cout << "Password: ";
    cin >> password;
    
    if (tipeAkun == 1) {
        Pembeli* pembeli = findPembeli(username, password);
        if (pembeli) {
            pembeli->login(password);
            pembeli->tampilkanMenu();
        } else {
            cout << "Username atau password salah!\n";
        }
    } else if (tipeAkun == 2) {
        Penjual* penjual = findPenjual(username, password);
        if (penjual) {
            penjual->login(password);
            penjual->tampilkanMenu();
        } else {
            cout << "Username atau password salah!\n";
        }
    } else {
        cout << "Pilihan tidak valid!\n";
    }
}

Pembeli* SistemTokoOnline::findPembeli(const string& username, const string& password) {
    for (Pembeli* pembeli : daftarPembeli) {
        if (pembeli->cariUsername() == username) {
            return pembeli;
        }
    }
    return nullptr;
}

Penjual* SistemTokoOnline::findPenjual(const string& username, const string& password) {
    for (Penjual* penjual : daftarPenjual) {
        if (penjual->cariUsername() == username) {
            return penjual;
        }
    }
    return nullptr;
}