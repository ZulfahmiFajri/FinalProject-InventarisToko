#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "inventaris.h"

struct Barang *inventaris = NULL;
int jumlah_barang = 0;
int kapasitas_inventaris = 0;


int inputValidInt(const char *prompt, int min, int max) {
    char buffer[100]; 
    int val;
    int status;

    while (1) { 
        printf("%s", prompt);
        
        if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
            printf("End of input. Exiting.\n");
            exit(1);
        }

        status = sscanf(buffer, "%d", &val);

        if (status != 1) {
            printf("Input tidak valid! Harus berupa angka.\n");
            continue; 
        }

        if (val < min || val > max) {
            printf("Input harus antara %d dan %d.\n", min, max);
            continue; 
        }

        break;
    }
    return val;
}

float inputValidFloat(const char *prompt, float min, float max) {
    char buffer[100];
    float val;
    int status;

    while (1) {
        printf("%s", prompt);

        if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
            printf("End of input. Exiting.\n");
            exit(1);
        }
        
        status = sscanf(buffer, "%f", &val);

        if (status != 1) {
            printf("Input tidak valid! Harus berupa angka desimal.\n");
            continue;
        }

        if (val < min || val > max) {
            printf("Input harus antara %.2f dan %.2f.\n", min, max);
            continue;
        }

        break;
    }
    return val;
}
const char* getNamaKategori(Kategori k) {
    switch (k) {
        case ELEKTRONIK: return "Elektronik";
        case MAKANAN_MINUMAN: return "Makanan/Minuman";
        case PAKAIAN: return "Pakaian";
        case PERALATAN_RUMAH_TANGGA: return "Peralatan RT";
        case LAINNYA: return "Lainnya";
        default: return "Tidak Diketahui";
    }
}
void tambahBarang(){
    if(jumlah_barang < MAX){
        inventaris[jumlah_barang].id = jumlah_barang + 1;
        printf("Masukkan Nama Barang: ");
        scanf(" %[^\n]", inventaris[jumlah_barang].nama);
        printf("Masukkan Jumlah: ");
        scanf("%d", &inventaris[jumlah_barang].jumlah);
        printf("Masukkan Harga: ");
        scanf("%f", &inventaris[jumlah_barang].harga);
        jumlah_barang++;
        printf("Barang berhasil ditambahkan dengan ID %d!\n", inventaris[jumlah_barang - 1].id);
    }else printf("Inventaris penuh!\n");
}

void tampilkanBarang(){
    if(jumlah_barang == 0){
        printf("Belum ada barang dalam inventaris.\n");
        return;
    }
    printf("\nDaftar Barang:\n");
    printf("ID\tNama\t\tJumlah\t\tHarga\n");
    for(int i = 0; i < jumlah_barang; i++){
        printf("%-2d\t%-15s %-15d %-15.2f\n", inventaris[i].id, inventaris[i].nama, inventaris[i].jumlah, inventaris[i].harga);
    }
}

void urutkanBarang() {
    if (jumlah_barang < 2) {
        printf("Butuh minimal 2 barang untuk diurutkan.\n");
        return;
    }
    printf("Urutkan berdasarkan:\n1. Nama\n2. Harga\n");
    int pilihan = inputValidInt("Pilihan: ", 1, 2);

    if (pilihan == 1) {
        qsort(inventaris, jumlah_barang, sizeof(struct Barang), compareByName);
    } else {
        qsort(inventaris, jumlah_barang, sizeof(struct Barang), compareByPrice);
    }

    printf("Inventaris berhasil diurutkan.\n");
    tampilkanBarang();
}


int compareByName(const void *a, const void *b) {
    struct Barang *barangA = (struct Barang *)a;
    struct Barang *barangB = (struct Barang *)b;
    return strcmp(barangA->nama, barangB->nama);
}

int compareByPrice(const void *a, const void *b) {
    struct Barang *barangA = (struct Barang *)a;
    struct Barang *barangB = (struct Barang *)b;
    if (barangA->harga < barangB->harga) return -1;
    if (barangA->harga > barangB->harga) return 1;
    return 0;
}

void hapusBarang(){
    int id;
    printf("Masukkan ID barang yang ingin dihapus: ");
    scanf("%d", &id);
    int index = -1;
    for(int i = 0; i < jumlah_barang; i++){
        if(inventaris[i].id == id){
            index = i;
            break;
        }
    }
    if(index != -1){
        for(int i = index; i < jumlah_barang - 1; i++){
            inventaris[i] = inventaris[i + 1];
        }
        jumlah_barang--;
        updateID();
        printf("Barang berhasil dihapus.\n");
    }else printf("Barang dengan ID tersebut tidak ditemukan.\n");
}
