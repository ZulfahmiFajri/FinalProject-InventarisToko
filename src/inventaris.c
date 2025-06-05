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

void tambahBarang() {
    if (jumlah_barang == kapasitas_inventaris) {
        
        int kapasitas_baru = (kapasitas_inventaris == 0) ? 10 : kapasitas_inventaris * 2;
        struct Barang *inventaris_baru = realloc(inventaris, kapasitas_baru * sizeof(struct Barang));

        if (inventaris_baru == NULL) {
            printf("Gagal mengalokasikan memori! Program akan berhenti.\n");
            bebasMemori();
            exit(1);
        }
        inventaris = inventaris_baru;
        kapasitas_inventaris = kapasitas_baru;
        printf("Kapasitas inventaris ditingkatkan menjadi %d\n", kapasitas_inventaris);
    }

    int idx = jumlah_barang;
    printf("Masukkan Nama Barang: ");
    fgets(inventaris[idx].nama, sizeof(inventaris[idx].nama), stdin);
    inventaris[idx].nama[strcspn(inventaris[idx].nama, "\n")] = 0;

    inventaris[idx].jumlah = inputValidInt("Masukkan Jumlah: ", 1, 1000000);
    inventaris[idx].harga = inputValidFloat("Masukkan Harga: ", 0.01f, 1000000000.0f);
    
    printf("Pilih Kategori:\n");
    for(int i = 0; i <= LAINNYA; i++) {
        printf("%d. %s\n", i, getNamaKategori(i));
    }
    inventaris[idx].kategori = (Kategori)inputValidInt("Pilihan Kategori: ", 0, LAINNYA);

    printf("Ada promo untuk barang ini? (1 = Diskon Persen, 2 = Bonus Item, 0 = Tidak Ada): ");
    inventaris[idx].tipe_promo = inputValidInt("", 0, 2);
    if(inventaris[idx].tipe_promo == 1) {
        inventaris[idx].promo.diskon_persen = inputValidFloat("Masukkan Diskon (%): ", 0.1f, 100.0f);
    } else if (inventaris[idx].tipe_promo == 2) {
        printf("Masukkan Nama Bonus Item: ");
        fgets(inventaris[idx].promo.bonus_item, sizeof(inventaris[idx].promo.bonus_item), stdin);
        inventaris[idx].promo.bonus_item[strcspn(inventaris[idx].promo.bonus_item, "\n")] = 0;
    }

    inventaris[idx].id = jumlah_barang + 1;
    jumlah_barang++;
    printf("Barang berhasil ditambahkan!\n");
}

void tampilkanBarang() {
    if (jumlah_barang == 0) {
        printf("Belum ada barang dalam inventaris.\n");
        return;
    }

    printf("\n%-5s %-25s %-15s %-10s %-15s %-25s\n", "ID", "Nama Barang", "Kategori", "Jumlah", "Harga (Rp)", "Promo");
    printf("--------------------------------------------------------------------------------------------------\n");
    
    for (int i = 0; i < jumlah_barang; i++) {
        char string_promo[100];
        if (inventaris[i].tipe_promo == 1) {
            snprintf(string_promo, sizeof(string_promo), "Diskon %.1f%%", inventaris[i].promo.diskon_persen);
        } else if (inventaris[i].tipe_promo == 2) {
            snprintf(string_promo, sizeof(string_promo), "Bonus: %s", inventaris[i].promo.bonus_item);
        } else {
            strcpy(string_promo, "-");
        }

        printf("%-5d %-25s %-15s %-10d %-15.2f %-25s\n",
               inventaris[i].id,
               inventaris[i].nama,
               getNamaKategori(inventaris[i].kategori),
               inventaris[i].jumlah,
               inventaris[i].harga,
               string_promo);
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
