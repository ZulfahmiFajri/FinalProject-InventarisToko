# FinalProject-InventarisToko

---

*Sistem Inventaris Toko sederhana berbasis bahasa C untuk mengelola data barang secara efektif dan efisien.*

### Kelompok Kurma:

| Nama                  | NPM        |
|-----------------------|------------|
| M. Hashif Jade        | 2406396786 |
| Marshal Aufa Diliyana | 2406346913 |
| M. Zaki Al Khairi     | 2406432375 |
| Zulfahmi Fajri        | 2406345425 |

---

## Fungsi Program

Program ini dirancang untuk membantu pengguna dalam mengelola inventaris toko dengan fitur-fitur berikut:

- Menambahkan barang baru dengan ID otomatis dan input data lengkap (nama, jumlah, harga).
- Menampilkan daftar barang secara terstruktur dan mudah dibaca.
- Menghapus barang berdasarkan ID dengan pembaruan otomatis ID barang lain.
- Mempermudah pengelolaan stok dan informasi barang dalam toko secara sederhana namun efektif.

---

## Cara Menjalankan Program

### Clone
```bash
git clone https://github.com/ZulfahmiFajri/FinalProject-InventarisToko.git
```

### Compile
```bash
gcc menu.c inventaris.c -o menu
```

### Run
```bash
menu.exe
```
---

## Program Berjalan
```
===== SISTEM INVENTARIS TOKO =====
1. Tambah Barang
2. Tampilkan Daftar Barang
3. Hapus Barang
4. Keluar
Pilih menu: 1

Masukkan Nama Barang: Pensil
Masukkan Jumlah: 50
Masukkan Harga: 1500
Barang berhasil ditambahkan dengan ID 1!
```
```
===== SISTEM INVENTARIS TOKO =====
1. Tambah Barang
2. Tampilkan Daftar Barang
3. Hapus Barang
4. Keluar
Pilih menu: 1

Masukkan Nama Barang: Buku Tulis
Masukkan Jumlah: 30
Masukkan Harga: 7500
Barang berhasil ditambahkan dengan ID 2!
```
```
===== SISTEM INVENTARIS TOKO =====
1. Tambah Barang
2. Tampilkan Daftar Barang
3. Hapus Barang
4. Keluar
Pilih menu: 2

Daftar Barang:
ID Nama            Jumlah     Harga
1  Pensil              50     1500.00
2  Buku Tulis          30     7500.00
```
```
===== SISTEM INVENTARIS TOKO =====
1. Tambah Barang
2. Tampilkan Daftar Barang
3. Hapus Barang
4. Keluar
Pilih menu: 3

Masukkan ID barang yang ingin dihapus: 1
Barang berhasil dihapus.
```
```
===== SISTEM INVENTARIS TOKO =====
1. Tambah Barang
2. Tampilkan Daftar Barang
3. Hapus Barang
4. Keluar
Pilih menu: 2

Daftar Barang:
ID Nama            Jumlah     Harga
1  Buku Tulis          30     7500.00
```
```
===== SISTEM INVENTARIS TOKO =====
1. Tambah Barang
2. Tampilkan Daftar Barang
3. Hapus Barang
4. Keluar
Pilih menu: 4

Terima kasih!
```
