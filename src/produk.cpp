#include "../headers/produk.h"
#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;

// ============================================
// Implementasi Produk (Base Class)
// ============================================
Produk::Produk(string nama, string mrk, double hrg, int stk, string kat, string desk)
    : namaProduk(nama), merk(mrk), harga(hrg), stok(stk), kategori(kat), deskripsi(desk) {}

void Produk::tampilkanDetail() const {
    cout << "================================\n";
    cout << "Nama     : " << namaProduk << endl;
    cout << "Merk     : " << merk << endl;
    cout << "Kategori : " << kategori << endl;
    cout << "Harga    : Rp " << fixed << setprecision(0) << harga << endl;
    cout << "Stok     : " << stok << " unit" << endl;
    cout << "Deskripsi: " << deskripsi << endl;
}

// ============================================
// Implementasi Elektronik
// ============================================
Elektronik::Elektronik(string nama, string mrk, double hrg, int stk, string desk, int gar, int daya)
    : Produk(nama, mrk, hrg, stk, "Elektronik", desk), garansi(gar), dayaWatt(daya) {}

void Elektronik::tampilkanDetail() const {
    Produk::tampilkanDetail();
    cout << "Garansi  : " << garansi << " bulan" << endl;
    cout << "Daya     : " << dayaWatt << " Watt" << endl;
}

Smartphone::Smartphone(string nama, string mrk, double hrg, int stk, string desk,
                       string proc, int r, int stor, string layar)
    : Elektronik(nama, mrk, hrg, stk, desk, 12, 10),
      processor(proc), ram(r), storage(stor), ukuranLayar(layar) {}

void Smartphone::tampilkanDetail() const {
    Elektronik::tampilkanDetail();
    cout << "Processor: " << processor << endl;
    cout << "RAM      : " << ram << " GB" << endl;
    cout << "Storage  : " << storage << " GB" << endl;
    cout << "Layar    : " << ukuranLayar << endl;
    cout << "================================\n";
}

Laptop::Laptop(string nama, string mrk, double hrg, int stk, string desk,
               string proc, int r, int stor, string layar, string gpu)
    : Elektronik(nama, mrk, hrg, stk, desk, 24, 65),
      processor(proc), ram(r), storage(stor), ukuranLayar(layar), kartuGrafis(gpu) {}

void Laptop::tampilkanDetail() const {
    Elektronik::tampilkanDetail();
    cout << "Processor: " << processor << endl;
    cout << "RAM      : " << ram << " GB" << endl;
    cout << "Storage  : " << storage << " GB" << endl;
    cout << "Layar    : " << ukuranLayar << endl;
    cout << "GPU      : " << kartuGrafis << endl;
    cout << "================================\n";
}

Televisi::Televisi(string nama, string mrk, double hrg, int stk, string desk,
                   int ukuran, string res, string panel)
    : Elektronik(nama, mrk, hrg, stk, desk, 12, 150),
      ukuranInch(ukuran), resolusi(res), jenisPanel(panel) {}

void Televisi::tampilkanDetail() const {
    Elektronik::tampilkanDetail();
    cout << "Ukuran   : " << ukuranInch << " inch" << endl;
    cout << "Resolusi : " << resolusi << endl;
    cout << "Panel    : " << jenisPanel << endl;
    cout << "================================\n";
}

AC::AC(string nama, string mrk, double hrg, int stk, string desk, double p, string j)
    : Elektronik(nama, mrk, hrg, stk, desk, 12, 900), pk(p), jenis(j) {}

void AC::tampilkanDetail() const {
    Elektronik::tampilkanDetail();
    cout << "PK       : " << pk << " PK" << endl;
    cout << "Jenis    : " << jenis << endl;
    cout << "================================\n";
}

MesinCuci::MesinCuci(string nama, string mrk, double hrg, int stk, string desk,
                     int kap, string jenis)
    : Elektronik(nama, mrk, hrg, stk, desk, 12, 350), kapasitasKg(kap), jenisLoading(jenis) {}

void MesinCuci::tampilkanDetail() const {
    Elektronik::tampilkanDetail();
    cout << "Kapasitas: " << kapasitasKg << " kg" << endl;
    cout << "Jenis    : " << jenisLoading << " loading" << endl;
    cout << "================================\n";
}

// ============================================
// Implementasi Kebutuhan Pokok
// ============================================
KebutuhanPokok::KebutuhanPokok(string nama, string mrk, double hrg, int stk, string desk,
                               string expired, bool hl)
    : Produk(nama, mrk, hrg, stk, "Kebutuhan Pokok", desk), 
      tanggalKadaluarsa(expired), halal(hl) {}

void KebutuhanPokok::tampilkanDetail() const {
    Produk::tampilkanDetail();
    cout << "Kadaluarsa: " << tanggalKadaluarsa << endl;
    cout << "Halal     : " << (halal ? "Ya" : "Tidak") << endl;
}

Beras::Beras(string nama, string mrk, double hrg, int stk, string desk,
             string expired, string jen, int berat)
    : KebutuhanPokok(nama, mrk, hrg, stk, desk, expired, true),
      jenis(jen), beratKg(berat) {}

void Beras::tampilkanDetail() const {
    KebutuhanPokok::tampilkanDetail();
    cout << "Jenis    : " << jenis << endl;
    cout << "Berat    : " << beratKg << " kg" << endl;
    cout << "================================\n";
}

MinyakGoreng::MinyakGoreng(string nama, string mrk, double hrg, int stk, string desk,
                           string expired, string jen, double liter)
    : KebutuhanPokok(nama, mrk, hrg, stk, desk, expired, true),
      jenis(jen), literCapacity(liter) {}

void MinyakGoreng::tampilkanDetail() const {
    KebutuhanPokok::tampilkanDetail();
    cout << "Jenis    : " << jenis << endl;
    cout << "Volume   : " << literCapacity << " liter" << endl;
    cout << "================================\n";
}

Gula::Gula(string nama, string mrk, double hrg, int stk, string desk,
           string expired, string jen, int berat)
    : KebutuhanPokok(nama, mrk, hrg, stk, desk, expired, true),
      jenis(jen), beratGram(berat) {}

void Gula::tampilkanDetail() const {
    KebutuhanPokok::tampilkanDetail();
    cout << "Jenis    : " << jenis << endl;
    cout << "Berat    : " << beratGram << " gram" << endl;
    cout << "================================\n";
}

Telur::Telur(string nama, string mrk, double hrg, int stk, string desk,
             string expired, string jen, int jml)
    : KebutuhanPokok(nama, mrk, hrg, stk, desk, expired, true),
      jenis(jen), jumlahButir(jml) {}

void Telur::tampilkanDetail() const {
    KebutuhanPokok::tampilkanDetail();
    cout << "Jenis    : " << jenis << endl;
    cout << "Jumlah   : " << jumlahButir << " butir" << endl;
    cout << "================================\n";
}

Susu::Susu(string nama, string mrk, double hrg, int stk, string desk,
           string expired, string jen, int vol)
    : KebutuhanPokok(nama, mrk, hrg, stk, desk, expired, true),
      jenis(jen), volumeMl(vol) {}

void Susu::tampilkanDetail() const {
    KebutuhanPokok::tampilkanDetail();
    cout << "Jenis    : " << jenis << endl;
    cout << "Volume   : " << volumeMl << " ml" << endl;
    cout << "================================\n";
}

// ============================================
// Implementasi Fashion
// ============================================
Fashion::Fashion(string nama, string mrk, double hrg, int stk, string desk,
                 string ukr, string wrn, string bahan)
    : Produk(nama, mrk, hrg, stk, "Fashion", desk),
      ukuran(ukr), warna(wrn), bahanMaterial(bahan) {}

void Fashion::tampilkanDetail() const {
    Produk::tampilkanDetail();
    cout << "Ukuran   : " << ukuran << endl;
    cout << "Warna    : " << warna << endl;
    cout << "Bahan    : " << bahanMaterial << endl;
}

Baju::Baju(string nama, string mrk, double hrg, int stk, string desk,
           string ukr, string wrn, string bahan, string jen, string gen)
    : Fashion(nama, mrk, hrg, stk, desk, ukr, wrn, bahan),
      jenis(jen), gender(gen) {}

void Baju::tampilkanDetail() const {
    Fashion::tampilkanDetail();
    cout << "Jenis    : " << jenis << endl;
    cout << "Gender   : " << gender << endl;
    cout << "================================\n";
}

Celana::Celana(string nama, string mrk, double hrg, int stk, string desk,
               string ukr, string wrn, string bahan, string jen, string model)
    : Fashion(nama, mrk, hrg, stk, desk, ukr, wrn, bahan),
      jenis(jen), modelPotongan(model) {}

void Celana::tampilkanDetail() const {
    Fashion::tampilkanDetail();
    cout << "Jenis    : " << jenis << endl;
    cout << "Model    : " << modelPotongan << endl;
    cout << "================================\n";
}

Sepatu::Sepatu(string nama, string mrk, double hrg, int stk, string desk,
               string wrn, string bahan, string jen, int nomor)
    : Fashion(nama, mrk, hrg, stk, desk, to_string(nomor), wrn, bahan),
      jenis(jen), nomorSepatu(nomor) {}

void Sepatu::tampilkanDetail() const {
    Fashion::tampilkanDetail();
    cout << "Jenis    : " << jenis << endl;
    cout << "Nomor    : " << nomorSepatu << endl;
    cout << "================================\n";
}

Tas::Tas(string nama, string mrk, double hrg, int stk, string desk,
         string wrn, string bahan, string jen, int kap)
    : Fashion(nama, mrk, hrg, stk, desk, "-", wrn, bahan),
      jenis(jen), kapasitasLiter(kap) {}

void Tas::tampilkanDetail() const {
    Fashion::tampilkanDetail();
    cout << "Jenis    : " << jenis << endl;
    cout << "Kapasitas: " << kapasitasLiter << " liter" << endl;
    cout << "================================\n";
}

Aksesoris::Aksesoris(string nama, string mrk, double hrg, int stk, string desk,
                     string wrn, string bahan, string jen)
    : Fashion(nama, mrk, hrg, stk, desk, "-", wrn, bahan), jenis(jen) {}

void Aksesoris::tampilkanDetail() const {
    Fashion::tampilkanDetail();
    cout << "Jenis    : " << jenis << endl;
    cout << "================================\n";
}

// ============================================
// Implementasi Katalog
// ============================================
Katalog::Katalog() {}

Katalog::~Katalog() {
    for (auto produk : daftarProduk) {
        delete produk;
    }
}

void Katalog::inisialisasiProdukDummy() {
    // ELEKTRONIK
    tambahProduk(new Smartphone("Samsung Galaxy S23", "Samsung", 12000000, 15, 
        "Smartphone flagship dengan kamera 108MP", "Snapdragon 8 Gen 2", 8, 256, "6.1 inch"));
    tambahProduk(new Laptop("ASUS ROG Strix G15", "ASUS", 18000000, 10,
        "Gaming laptop dengan performa tinggi", "AMD Ryzen 9", 16, 512, "15.6 inch", "RTX 3070"));
    tambahProduk(new Televisi("LG OLED C2", "LG", 25000000, 8,
        "Smart TV OLED 4K", 55, "4K UHD", "OLED"));
    tambahProduk(new AC("Daikin Inverter", "Daikin", 5500000, 20,
        "AC hemat energi dengan teknologi inverter", 1.5, "Split"));
    tambahProduk(new MesinCuci("Sharp Top Loading", "Sharp", 3200000, 12,
        "Mesin cuci kapasitas besar", 10, "Top"));
    
    // KEBUTUHAN POKOK
    tambahProduk(new Beras("Beras Ramos Premium", "Ramos", 85000, 100,
        "Beras premium kualitas terbaik", "31-12-2025", "Premium", 5));
    tambahProduk(new MinyakGoreng("Minyak Bimoli", "Bimoli", 28000, 150,
        "Minyak goreng kelapa sawit", "30-06-2025", "Kelapa Sawit", 2));
    tambahProduk(new Gula("Gula Gulaku", "Gulaku", 15000, 200,
        "Gula pasir berkualitas", "31-12-2025", "Pasir", 1000));
    tambahProduk(new Telur("Telur Omega", "Omega", 32000, 80,
        "Telur ayam omega 3", "15-12-2024", "Ayam", 10));
    tambahProduk(new Susu("Susu Ultra Milk", "Ultra", 18000, 120,
        "Susu UHT full cream", "20-03-2025", "UHT", 1000));
    
    // FASHION
    tambahProduk(new Baju("Kaos Polos Premium", "Uniqlo", 150000, 50,
        "Kaos katun premium nyaman dipakai", "L", "Hitam", "Cotton", "Kaos", "Unisex"));
    tambahProduk(new Celana("Jeans Slim Fit", "Levi's", 650000, 30,
        "Celana jeans berkualitas tinggi", "32", "Biru", "Denim", "Jeans", "Slim Fit"));
    tambahProduk(new Sepatu("Nike Air Max", "Nike", 1200000, 25,
        "Sepatu sneakers casual", "Putih", "Synthetic", "Sneakers", 42));
    tambahProduk(new Tas("Tas Ransel Laptop", "Eiger", 450000, 40,
        "Tas ransel untuk laptop hingga 15 inch", "Hitam", "Polyester", "Ransel", 25));
    tambahProduk(new Aksesoris("Jam Tangan Casio", "Casio", 800000, 20,
        "Jam tangan digital water resistant", "Silver", "Stainless Steel", "Jam Tangan"));
}

void Katalog::tambahProduk(Produk* produk) {
    daftarProduk.push_back(produk);
}

void Katalog::tampilkanSemuaProduk() const {
    cout << "\n=== KATALOG SEMUA PRODUK ===\n";
    for (size_t i = 0; i < daftarProduk.size(); i++) {
        cout << "\n[" << i + 1 << "] " << daftarProduk[i]->getNama() 
             << " - " << daftarProduk[i]->getKategori() 
             << " - Rp " << fixed << setprecision(0) << daftarProduk[i]->getHarga()
             << " (Stok: " << daftarProduk[i]->getStok() << ")" << endl;
    }
}

void Katalog::tampilkanProdukKategori(const string& kategori) const {
    cout << "\n=== KATALOG " << kategori << " ===\n";
    int nomor = 1;
    for (const auto& produk : daftarProduk) {
        if (produk->getKategori() == kategori) {
            cout << "[" << nomor++ << "] " << produk->getNama() 
                 << " - Rp " << fixed << setprecision(0) << produk->getHarga() 
                 << " (Stok: " << produk->getStok() << ")" << endl;
        }
    }
    if (nomor == 1) {
        cout << "Tidak ada produk dalam kategori ini.\n";
    }
}

vector<Produk*> Katalog::cariProduk(const string& keyword) const {
    vector<Produk*> hasil;
    string keywordLower = keyword;
    transform(keywordLower.begin(), keywordLower.end(), keywordLower.begin(), ::tolower);
    
    for (auto produk : daftarProduk) {
        string namaLower = produk->getNama();
        transform(namaLower.begin(), namaLower.end(), namaLower.begin(), ::tolower);
        
        if (namaLower.find(keywordLower) != string::npos) {
            hasil.push_back(produk);
        }
    }
    return hasil;
}

Produk* Katalog::getProdukByIndex(int index) {
    if (index >= 0 && static_cast<size_t>(index) < daftarProduk.size()) {
        return daftarProduk[index];
    }
    return nullptr;
}

Produk* Katalog::getProdukByNama(const string& nama) {
    for (auto produk : daftarProduk) {
        if (produk->getNama() == nama) {
            return produk;
        }
    }
    return nullptr;
}
