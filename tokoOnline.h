#ifndef TOKOONLINE_H
#define TOKOONLINE_H

#include "pengguna.h"
#include <vector>
#include <iostream>

using namespace std;

class SistemTokoOnline {
private:
    vector<Pembeli*> daftarPembeli;
    vector<Penjual*> daftarPenjual;
    
public:
    SistemTokoOnline();
    ~SistemTokoOnline();
    
    void tampilkanMenuUtama();
    void daftarAkun();
    void loginAkun();
    Pembeli* findPembeli(const string& username, const string& password);
    Penjual* findPenjual(const string& username, const string& password);
};

#endif