#ifndef INVENTARIS_H
#define INVENTARIS_H

typedef enum {
    ELEKTRONIK,
    MAKANAN_MINUMAN,
    PAKAIAN,
    PERALATAN_RUMAH_TANGGA,
    LAINNYA
} Kategori;


typedef union {
    float diskon_persen;
    char bonus_item[50];
} InfoPromo;

struct Barang {
    int id;
    char nama[50];
    int jumlah;
    float harga;
    Kategori kategori; 
    InfoPromo promo;
    int tipe_promo; 
};

extern struct Barang *inventaris;
extern int jumlah_barang;


int inputValidInt(const char *prompt, int min, int max);
float inputValidFloat(const char *prompt, float min, float max);
const char* getNamaKategori(Kategori k);

void tambahBarang();
void tampilkanBarang();
void hapusBarang();
void urutkanBarang();
void updateID();

#endif
