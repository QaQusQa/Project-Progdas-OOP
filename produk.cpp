#include "produk.h"
#include <iostream>
#include <limits>
#include <vector>

using namespace std;
namespace ktlg{
    extern vector<string> katalogLokal;
}
// produk class implementation
produk::produk(const std::string& nama, double hrga, int stk, const std::string& ktrg)
    : Penjual(username, email, password, nama), namaProduk(nama), harga(hrga), stok(stk), kategory(ktrg) {
    }

void produk::info_produk() const {
    cout << "=== INFO PRODUK ===\n";
    cout << "Nama Produk: " << namaProduk << "\n";
    cout << "Harga: Rp " << harga << "\n";
    cout << "Stok: " << stok << "\n";
    cout << "Kategori: " << kategory << "\n";
    
    
}

vector <std::string> produk::tambahProduk() {
    cout<<"Masukkan detail produk yang akan ditambahkan:\n";
    cout<<"Nama Produk: ";
    std::string nama;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, nama);

    cout<<"Harga: ";
    double hrga;
    cin>>hrga;

    cout<<"Stok: ";
    int stk;
    cin>>stk;

    cout<<"Kategori (Elektronik/Kebutuhan Pokok/Fashion): ";
    std::string ktrg;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, ktrg);

    namaProduk = nama;
    harga = hrga;
    stok = stk;
    kategory = ktrg;

    ktlg::katalogLokal.push_back(namaProduk);
    ktlg::katalogLokal.push_back(to_string(harga));
    ktlg::katalogLokal.push_back(to_string(stok));
    ktlg::katalogLokal.push_back(kategory);

    return ktlg::katalogLokal;
}

void produk::ganti_nama_produk(const std::string& nama) {
    namaProduk = nama;
    ktlg::katalogLokal.push_back(namaProduk);

}

std::string produk::melihat_nama_produk() const {
    return namaProduk;
}

void produk::menentukan_harga(double hrg) {
    harga = hrg;
    ktlg::katalogLokal.push_back(to_string(harga));

}

double produk::melihat_harga() const {
    return harga;
}

void produk::menentukan_stok(int stk) {
    stok = stk;
    ktlg::katalogLokal.push_back(to_string(stok));

}

int produk::melihat_stok() const {
    return stok;
}

void produk::menentukan_kategory(const std::string& ktrg) {
    kategory = ktrg;
    ktlg::katalogLokal.push_back(kategory);

}

std::string produk::melihat_kategory() const {
    return kategory;
}

std::vector<std::string> getKatalogLokal() {
    return ktlg::katalogLokal;
}