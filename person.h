#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <iostream>
#include <vector>
using namespace std;

class orang {
protected:
    string username;
    string email;
    string password;
    bool loggedIn;
    
public:
    orang(const std::string& uname, const std::string& mail, const std::string& pwd);
    virtual ~orang() = default;
    
    std::string melihat_nama() const;
    std::string email_akun() const;
    bool sudah_login() const;
    bool login(const std::string& inputPassword);
    void logout();
    virtual void info() const = 0;
    virtual void menu() = 0;
};

class pembeli : public orang {
private:
    vector<string> keranjang;
    vector<string> riwayatPesanan;
    
public:
    pembeli(const std::string& uname, const std::string& mail, const std::string& pwd);
    
    // Use case methods
    void mencari_produk();
    void detail_produk();
    void masukkan_ke_keranjang();
    void isi_keranjang();
    void checkout();
    void membayaran();
    void status_pesanan();
    void terima_barang();
    
    void info() const override;
    void menu() override;
};

class Penjual : public orang {
private:
    string namaToko;
    vector<string> katalogProduk;
    vector<string> daftarPesanan;
    
public:
    Penjual(const string& uname, const string& mail, const string& pwd, const string& toko);
    
    // Use case methods
    void menambahkan_produk();
    void stok_produk();
    void katalog();
    void menerima_pesanan();
    void memproses_pesanan();
    void pengiriman();
    void daftar_pesanan();
    void konfirmasi_pengiriman();
    
    void info() const override;
    void menu() override;
};

// class produk : public orang {
//     private:
//         std::string namaProduk;
//         double harga;
//         int stok;
//         std::string kategory;
//     public:
//         produk(const std::string& nama, double hrga, int stk, const std::string& ktrg);
//         void info_produk() const;

// };

#endif