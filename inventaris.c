#include <stdio.h>
#include <string.h>
#include "inventaris.h"

struct Barang inventaris[MAX];
int jumlah_barang = 0;

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
    printf("ID\tNama\t\tJumlah\tHarga\n");
    for(int i = 0; i < jumlah_barang; i++){
        printf("%d\t%s\t\t%d\t%.2f\n", inventaris[i].id, inventaris[i].nama, inventaris[i].jumlah, inventaris[i].harga);
    }
}

void updateID(){
    for(int i = 0; i < jumlah_barang; i++){
        inventaris[i].id = i + 1;
    }
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
