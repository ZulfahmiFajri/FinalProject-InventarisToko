#include <stdio.h>
#include "inventaris.h"
#include "main.h"

void menu() {
    int pilihan;
    do {
        printf("\n===== SISTEM INVENTARIS TOKO =====\n");
        printf("1. Tambah Barang\n");
        printf("2. Tampilkan Daftar Barang\n");
        printf("3. Hapus Barang\n");
        printf("4. Urutkan Barang\n");
        printf("5. Keluar\n");
        pilihan = inputValidInt("Pilih menu: ", 1, 5);

        switch (pilihan) {
            case 1: tambahBarang(); break;
            case 2: tampilkanBarang(); break;
            case 3: hapusBarang(); break;
            case 4: urutkanBarang(); break;
            case 5: printf("Terima kasih!\n"); break;
        }
    } while (pilihan != 5);
}

int main(){
    menu();
    bebasMemori();
    return 0;
}
