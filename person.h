#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <iostream>
#include <vector>

class Person {
protected:
    std::string username;
    std::string email;
    std::string password;
    bool loggedIn;
    
public:
    Person(const std::string& uname, const std::string& mail, const std::string& pwd);
    virtual ~Person() = default;
    
    std::string getUsername() const;
    std::string getEmail() const;
    bool isLoggedIn() const;
    bool login(const std::string& inputPassword);
    void logout();
    virtual void displayInfo() const = 0;
    virtual void showMenu() = 0;
};

class Pembeli : public Person {
private:
    std::vector<std::string> keranjang;
    std::vector<std::string> riwayatPesanan;
    
public:
    Pembeli(const std::string& uname, const std::string& mail, const std::string& pwd);
    
    // Use case methods
    void mencariProduk();
    void melihatDetailProduk();
    void menambahkanKeKeranjang();
    void melihatKeranjang();
    void checkout();
    void melakukanPembayaran();
    void melihatStatusPesanan();
    void menerimaBarang();
    
    void displayInfo() const override;
    void showMenu() override;
};

class Penjual : public Person {
private:
    std::string namaToko;
    std::vector<std::string> katalogProduk;
    std::vector<std::string> daftarPesanan;
    
public:
    Penjual(const std::string& uname, const std::string& mail, const std::string& pwd, const std::string& toko);
    
    // Use case methods
    void mengunggahProduk();
    void mengaturStokProduk();
    void melihatKatalog();
    void menerimaPesanan();
    void memprosesPesanan();
    void mengaturPengiriman();
    void melihatDaftarPesanan();
    void mengonfirmasiPengiriman();
    
    void displayInfo() const override;
    void showMenu() override;
};

#endif