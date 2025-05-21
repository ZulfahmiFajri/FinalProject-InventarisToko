#ifndef INVENTARIS_H
#define INVENTARIS_H

#define MAX 100

struct Barang {
    int id;
    char nama[50];
    int jumlah;
    float harga;
};

extern struct Barang inventaris[MAX];
extern int jumlah_barang;

void tambahBarang();
void tampilkanBarang();
void hapusBarang();
void updateID();

#endif
