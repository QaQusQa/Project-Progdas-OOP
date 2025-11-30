#ifndef KATALOGMANAGER_H
#define KATALOGMANAGER_H

#include "produk.h"
#include <vector>
#include <string>

class KatalogManager {
private:
    Katalog katalog;
    static KatalogManager* instance;
    KatalogManager();

public:
    static KatalogManager* getInstance();
    
    void inisialisasiData();
    void tampilkanSemuaProduk();
    void tampilkanProdukByKategori(int kategori);
    void cariDanTampilkanProduk(const std::string& keyword);
    void tampilkanDetailProduk(int index);
    Produk* getProdukByIndex(int index);
    vector<Produk*> cariProduk(const std::string& keyword);
    int getJumlahProduk();
};

#endif