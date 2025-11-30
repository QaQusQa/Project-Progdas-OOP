#ifndef PRODUK_H
#define PRODUK_H

#include "person.h"
#include <string>
#include <iostream>
#include <vector>

namespace ktlg{
    extern std::vector<std::string> katalogLokal;
}
class produk : public Penjual{
private:
    std::string namaProduk;
    double harga;
    int stok;
    std::string kategory;
public:
    produk(const std::string& nama, double hrga, int stk, const std::string& ktrg);
    void info_produk() const;

    vector <std::string> tambahProduk() override;
    
    void ganti_nama_produk(const std::string& nama);
    std::string melihat_nama_produk() const;
    void menentukan_harga(double hrg);
    double melihat_harga() const;
    void menentukan_stok(int stk);
    int melihat_stok() const;
    void menentukan_kategory(const std::string& ktrg);
    std::string melihat_kategory() const;
};

// akses helper untuk katalog lokal
std::vector<std::string> getKatalogLokal();

#endif // PRODUK_H