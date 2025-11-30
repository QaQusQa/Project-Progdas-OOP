#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <iostream>
#include <vector>
using namespace std;

namespace ktlg{
    extern vector<string> katalogLokal;
}
class Person {
protected:
    string username;
    string email;
    string password;
    bool loggedIn;
    
public:
    vector <vector<string>> katalogProduk;
    Person(const string& uname, const string& mail, const string& pwd);
    virtual ~Person() = default;
    
    string cariUsername() const;
    string cariEmail() const;
    bool sudahLoggedIn() const;
    bool login(const string& inputPassword);
    void logout();
    virtual void tampilkanInfo() const = 0;
    virtual void tampilkanMenu() = 0;
};

class Pembeli : public Person {
private:
    vector<string> keranjang;
    vector<string> riwayatPesanan;
    
public:
    Pembeli(const string& uname, const string& mail, const string& pwd);
    
    // Use case methods
    void cariProduk();
    void lihatDetailProduk();
    void tambahKeKeranjang();
    void lihatKeranjang();
    void prosesCheckout();
    void lakukanPembayaran();
    void lihatStatusPesanan();
    void terimaBarang();
    
    void tampilkanInfo() const override;
    void tampilkanMenu() override;
};

class Penjual : public Person {
private:
    string namaToko;
    // vector<string> katalogProduk;
    vector<string> daftarPesanan;
    
public:
    Penjual(const string& uname, const string& mail, const string& pwd, const string& toko);
    
    // Use case methods

    virtual vector <std::string> tambahProduk();
    void aturStokProduk();
    void lihatKatalog();
    void terimaPesanan();
    void prosesPesanan();
    void aturPengiriman();
    void lihatDaftarPesanan();
    void konfirmasiPengiriman();
    
    void tampilkanInfo() const override;
    void tampilkanMenu() override;
};

#endif