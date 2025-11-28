#include "produk.h"
#include <iostream>
#include <limits>

using namespace std;

// produk class implementation
produk::produk(const std::string& nama, double hrga, int stk, const std::string& ktrg)
    : orang(username, email, password), namaProduk(nama), harga(hrga), stok(stk), kategory(ktrg) {
    }

void produk::info_produk() const {
    cout << "=== INFO PRODUK ===\n";
    cout << "Nama Produk: " << namaProduk << "\n";
    cout << "Harga: Rp " << harga << "\n";
    cout << "Stok: " << stok << "\n";
    cout << "Kategori: " << kategory << "\n";
}

void produk::set_semuanya(const std::string& nama, double hrga, int stk, const std::string& ktrg) {
    namaProduk = nama;
    harga = hrga;
    stok = stk;
    kategory = ktrg;
}

void produk::ganti_nama_produk(const std::string& nama) {
    namaProduk = nama;
}

std::string produk::melihat_nama_produk() const {
    return namaProduk;
}

void produk::menentukan_harga(double hrg) {
    harga = hrg;
}

double produk::melihat_harga() const {
    return harga;
}

void produk::menentukan_stok(int stk) {
    stok = stk;
}

int produk::melihat_stok() const {
    return stok;
}

void produk::menentukan_kategory(const std::string& ktrg) {
    kategory = ktrg;
}

std::string produk::melihat_kategory() const {
    return kategory;
}

