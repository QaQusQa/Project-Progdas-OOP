// ============================================
// FILE: produk.h
// ============================================
#ifndef PRODUK_H
#define PRODUK_H

#include <string>
#include <vector>
using namespace std;

// Kelas dasar Produk
class Produk {
protected:
    string namaProduk;
    string merk;
    double harga;
    int stok;
    string kategori;
    string deskripsi;

public:
    Produk(string nama, string mrk, double hrg, int stk, string kat, string desk);
    virtual ~Produk() {}
    
    virtual void tampilkanDetail() const;
    virtual string getKategori() const { return kategori; }
    
    string getNama() const { return namaProduk; }
    double getHarga() const { return harga; }
    int getStok() const { return stok; }
    void kurangiStok(int jumlah) { stok -= jumlah; }
    void tambahStok(int jumlah) { stok += jumlah; }
};

// ============================================
// KATEGORI 1: ELEKTRONIK
// ============================================
class Elektronik : public Produk {
protected:
    int garansi;
    int dayaWatt;

public:
    Elektronik(string nama, string mrk, double hrg, int stk, string desk, int gar, int daya);
    void tampilkanDetail() const override;
};

class Smartphone : public Elektronik {
private:
    string processor;
    int ram;
    int storage;
    string ukuranLayar;

public:
    Smartphone(string nama, string mrk, double hrg, int stk, string desk, 
               string proc, int r, int stor, string layar);
    void tampilkanDetail() const override;
};

class Laptop : public Elektronik {
private:
    string processor;
    int ram;
    int storage;
    string ukuranLayar;
    string kartuGrafis;

public:
    Laptop(string nama, string mrk, double hrg, int stk, string desk,
           string proc, int r, int stor, string layar, string gpu);
    void tampilkanDetail() const override;
};

class Televisi : public Elektronik {
private:
    int ukuranInch;
    string resolusi;
    string jenisPanel;

public:
    Televisi(string nama, string mrk, double hrg, int stk, string desk,
             int ukuran, string res, string panel);
    void tampilkanDetail() const override;
};

class AC : public Elektronik {
private:
    double pk;
    string jenis;

public:
    AC(string nama, string mrk, double hrg, int stk, string desk, double p, string j);
    void tampilkanDetail() const override;
};

class MesinCuci : public Elektronik {
private:
    int kapasitasKg;
    string jenisLoading;

public:
    MesinCuci(string nama, string mrk, double hrg, int stk, string desk,
              int kap, string jenis);
    void tampilkanDetail() const override;
};

// ============================================
// KATEGORI 2: KEBUTUHAN POKOK
// ============================================
class KebutuhanPokok : public Produk {
protected:
    string tanggalKadaluarsa;
    bool halal;

public:
    KebutuhanPokok(string nama, string mrk, double hrg, int stk, string desk,
                   string expired, bool hl);
    void tampilkanDetail() const override;
};

class Beras : public KebutuhanPokok {
private:
    string jenis;
    int beratKg;

public:
    Beras(string nama, string mrk, double hrg, int stk, string desk,
          string expired, string jen, int berat);
    void tampilkanDetail() const override;
};

class MinyakGoreng : public KebutuhanPokok {
private:
    string jenis;
    double literCapacity;

public:
    MinyakGoreng(string nama, string mrk, double hrg, int stk, string desk,
                 string expired, string jen, double liter);
    void tampilkanDetail() const override;
};

class Gula : public KebutuhanPokok {
private:
    string jenis;
    int beratGram;

public:
    Gula(string nama, string mrk, double hrg, int stk, string desk,
         string expired, string jen, int berat);
    void tampilkanDetail() const override;
};

class Telur : public KebutuhanPokok {
private:
    string jenis;
    int jumlahButir;

public:
    Telur(string nama, string mrk, double hrg, int stk, string desk,
          string expired, string jen, int jml);
    void tampilkanDetail() const override;
};

class Susu : public KebutuhanPokok {
private:
    string jenis;
    int volumeMl;

public:
    Susu(string nama, string mrk, double hrg, int stk, string desk,
         string expired, string jen, int vol);
    void tampilkanDetail() const override;
};

// ============================================
// KATEGORI 3: FASHION
// ============================================
class Fashion : public Produk {
protected:
    string ukuran;
    string warna;
    string bahanMaterial;

public:
    Fashion(string nama, string mrk, double hrg, int stk, string desk,
            string ukr, string wrn, string bahan);
    void tampilkanDetail() const override;
};

class Baju : public Fashion {
private:
    string jenis;
    string gender;

public:
    Baju(string nama, string mrk, double hrg, int stk, string desk,
         string ukr, string wrn, string bahan, string jen, string gen);
    void tampilkanDetail() const override;
};

class Celana : public Fashion {
private:
    string jenis;
    string modelPotongan;

public:
    Celana(string nama, string mrk, double hrg, int stk, string desk,
           string ukr, string wrn, string bahan, string jen, string model);
    void tampilkanDetail() const override;
};

class Sepatu : public Fashion {
private:
    string jenis;
    int nomorSepatu;

public:
    Sepatu(string nama, string mrk, double hrg, int stk, string desk,
           string wrn, string bahan, string jen, int nomor);
    void tampilkanDetail() const override;
};

class Tas : public Fashion {
private:
    string jenis;
    int kapasitasLiter;

public:
    Tas(string nama, string mrk, double hrg, int stk, string desk,
        string wrn, string bahan, string jen, int kap);
    void tampilkanDetail() const override;
};

class Aksesoris : public Fashion {
private:
    string jenis;

public:
    Aksesoris(string nama, string mrk, double hrg, int stk, string desk,
              string wrn, string bahan, string jen);
    void tampilkanDetail() const override;
};

// ============================================
// Kelas Katalog untuk mengelola produk
// ============================================
class Katalog {
private:
    vector<Produk*> daftarProduk;

public:
    Katalog();
    ~Katalog();
    void inisialisasiProdukDummy();
    void tambahProduk(Produk* produk);
    void tampilkanSemuaProduk() const;
    void tampilkanProdukKategori(const string& kategori) const;
    vector<Produk*> cariProduk(const string& keyword) const;
    Produk* getProdukByIndex(int index);
    Produk* getProdukByNama(const string& nama);
    int jumlahProduk() const { return daftarProduk.size(); }
    vector<Produk*> getDaftarProduk() const { return daftarProduk; }
};

#endif // PRODUK_H