#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <vector>

using namespace std;

// Deklarasi katalog global
extern vector<vector<string>> katalogGlobal;

class Person {
protected:
    string username;
    string email;
    string password;
    bool loggedIn;
    vector<vector<string>>& katalogProduk;  // Reference ke katalog global

public:
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
    vector<vector<string>> keranjang;
    vector<string> riwayatPesanan;

public:
    Pembeli(const string& uname, const string& mail, const string& pwd);
    
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
    vector<string> daftarPesanan;

public:
    Penjual(const string& uname, const string& mail, const string& pwd, const string& toko);
    
    void tambahProduk();
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