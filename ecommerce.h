#ifndef ECOMMERCE_H
#define ECOMMERCE_H

#include "person.h"
#include <vector>
#include <iostream>

class ECommerceSystem {
private:
    std::vector<pembeli*> daftarPembeli;
    std::vector<Penjual*> daftarPenjual;
    
public:
    ECommerceSystem();
    ~ECommerceSystem();
    
    void tampilkanMenuUtama();
    void daftarAkun();
    void loginAkun();
    pembeli* findPembeli(const std::string& username, const std::string& password);
    Penjual* findPenjual(const std::string& username, const std::string& password);
};

#endif