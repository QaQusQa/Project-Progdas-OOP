#ifndef ECOMMERCE_H
#define ECOMMERCE_H

#include "person.h"
#include <vector>
#include <iostream>
using namespace std;
class ECommerceSystem {
private:
    vector<Pembeli*> daftarPembeli;
    vector<Penjual*> daftarPenjual;
    
public:
    ECommerceSystem();
    ~ECommerceSystem();
    
    void tampilkanMenuUtama();
    void daftarAkun();
    void loginAkun();
    Pembeli* findPembeli(const string& username, const string& password);
    Penjual* findPenjual(const string& username, const string& password);
};

#endif