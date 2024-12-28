# 📚 Penjelasan kode 
**Header File dan Namespace**
```
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
```
#include <iostream>: Digunakan untuk operasi input/output (seperti cin dan cout).
#include <fstream>: Memungkinkan operasi file (membaca/menulis file).
#include <string>: Menyediakan dukungan untuk tipe data string.
using namespace std;: Menghindari penulisan std:: sebelum fungsi library standar.

**Struktur Data**
```
struct Buku {
    int id;
    string judul;
    string pengarang;
    int tahun;
};
```
_5-9. struct Buku: Struktur data untuk menyimpan informasi buku:_

id: Nomor identitas buku.
judul: Nama buku.
pengarang: Penulis buku.
tahun: Tahun terbit.

```
struct Admin {
    string username;
    string password;
};
```
_10-14. struct Admin: Struktur data untuk menyimpan informasi admin:_

username: Nama pengguna.
password: Kata sandi pengguna.

**Konstanta Maksimum**
```
const int MAX_BUKU = 100;
const int MAX_ADMIN = 100;
```
_15-16. Konstanta:_

MAX_BUKU: Maksimum jumlah buku yang dapat disimpan.
MAX_ADMIN: Maksimum jumlah admin yang dapat disimpan.

**Fungsi Tambah Buku**
```
void tambahBuku(Buku* perpustakaan, int* jumlah) {
    if (*jumlah >= MAX_BUKU) {
        cout << "Perpustakaan penuh!\n";
        return;
    }
```

_17-21. Logika Awal:_
Mengecek apakah jumlah buku saat ini mencapai batas maksimum. Jika ya, tampilkan pesan dan keluar dari fungsi.
```
    cout << "Masukkan ID buku: ";
    cin >> perpustakaan[*jumlah].id;
    cin.ignore();
    cout << "Masukkan judul buku: ";
    getline(cin, perpustakaan[*jumlah].judul);
    cout << "Masukkan pengarang buku: ";
    getline(cin, perpustakaan[*jumlah].pengarang);
    cout << "Masukkan tahun terbit: ";
    cin >> perpustakaan[*jumlah].tahun;
```

_22-29. Input Data Buku:_
Meminta user memasukkan ID, judul, pengarang, dan tahun buku.
```
    (*jumlah)++;
    cout << "Buku berhasil ditambahkan!\n";
}
```
_30-32. Update Jumlah Buku:_
Menambahkan jumlah buku dan memberikan pesan sukses.

**Fungsi Tampilkan Buku**
```
void tampilkanBuku(Buku* perpustakaan, int jumlah) {
    if (jumlah == 0) {
        cout << "Tidak ada buku dalam perpustakaan.\n";
        return;
    }
```
_33-37. Logika Awal:_
Mengecek apakah perpustakaan kosong. Jika ya, tampilkan pesan dan keluar dari fungsi.
```
    for (int i = 0; i < jumlah; i++) {
        cout << "ID: " << perpustakaan[i].id << "\n";
        cout << "Judul: " << perpustakaan[i].judul << "\n";
        cout << "Pengarang: " << perpustakaan[i].pengarang << "\n";
        cout << "Tahun: " << perpustakaan[i].tahun << "\n";
        cout << "---------------------------\n";
    }
}
```
_38-45. Menampilkan Data Buku:_
Mengiterasi setiap buku yang ada di perpustakaan dan menampilkan detailnya (ID, judul, pengarang, tahun).

**Fungsi Menyimpan Buku ke File**
```
void simpanKeFile(Buku* perpustakaan, int jumlah, const string& namaFile) {
    ofstream file(namaFile);
    if (!file) {
        cout << "Gagal membuka file untuk menyimpan data.\n";
        return;
    }
```
_46-51. Logika Awal:_
Membuka file untuk ditulis menggunakan ofstream.
Jika file gagal dibuka, tampilkan pesan kesalahan dan keluar dari fungsi.
```
    for (int i = 0; i < jumlah; i++) {
        file << perpustakaan[i].id << "\n";
        file << perpustakaan[i].judul << "\n";
        file << perpustakaan[i].pengarang << "\n";
        file << perpustakaan[i].tahun << "\n";
    }
    file.close();
    cout << "Data berhasil disimpan ke file " << namaFile << "\n";
}
```

_52-60. Proses Menyimpan Data Buku:_
Mengiterasi setiap buku yang ada di perpustakaan.
Menulis data buku ke file dalam format
```
ID
Judul
Pengarang
Tahun
```
Menutup file setelah selesai dan menampilkan pesan sukses.

**Fungsi Membaca Buku dari File**
```
void bacaDariFile(Buku* perpustakaan, int* jumlah, const string& namaFile) {
    ifstream file(namaFile);
    if (!file) {
        cout << "Gagal membuka file untuk membaca data.\n";
        return;
    }
```
**61-66. Logika Awal:**
Membuka file untuk dibaca menggunakan ifstream.
Jika file gagal dibuka, tampilkan pesan kesalahan dan keluar dari fungsi.

    *jumlah = 0;
    while (file >> perpustakaan[*jumlah].id) {
        file.ignore();
        getline(file, perpustakaan[*jumlah].judul);
        getline(file, perpustakaan[*jumlah].pengarang);
        file >> perpustakaan[*jumlah].tahun;
        file.ignore();
        (*jumlah)++;
    }
    file.close();
    cout << "Data berhasil dibaca dari file " << namaFile << "\n";
}

_67-77. Proses Membaca Data Buku:_
Menginisialisasi jumlah buku ke 0.
Membaca data buku satu per satu dari file.
Data yang dibaca meliputi ID, judul, pengarang, dan tahun terbit.
Setelah membaca satu buku, jumlah buku diperbarui.

**Fungsi Utama (main)**
```
int main() {
    Buku perpustakaan[MAX_BUKU];
    int jumlahBuku = 0;
    string namaFile = "perpustakaan.txt";
```
_78-81. Inisialisasi Program:_
Membuat array perpustakaan untuk menyimpan data buku.
Menginisialisasi jumlah buku ke 0.
Menetapkan nama file default untuk menyimpan data (perpustakaan.txt).

    bacaDariFile(perpustakaan, &jumlahBuku, namaFile);
_82. Memuat Data Buku:_
Membaca data dari file saat program dimulai, jika file ada.
    
    int pilihan;
    do {
        cout << "1. Tambah Buku\n";
        cout << "2. Tampilkan Buku\n";
        cout << "3. Simpan dan Keluar\n";
        cout << "Masukkan pilihan: ";
        cin >> pilihan;

_83-89. Menu Utama:_
Menampilkan menu pilihan:
1: Menambah buku.
2: Menampilkan daftar buku.
3: Menyimpan data dan keluar.
Meminta input pilihan dari user.

        switch (pilihan) {
            case 1:
                tambahBuku(perpustakaan, &jumlahBuku);
                break;
            case 2:
                tampilkanBuku(perpustakaan, jumlahBuku);
                break;
            case 3:
                simpanKeFile(perpustakaan, jumlahBuku, namaFile);
                cout << "Program selesai.\n";
                break;
            default:
                cout << "Pilihan tidak valid.\n";
        }
    } while (pilihan != 3);
_90-103. Logika Pemrosesan Menu:_
case 1: Memanggil fungsi tambahBuku untuk menambah data buku.
case 2: Memanggil fungsi tampilkanBuku untuk menampilkan daftar buku.
case 3: Memanggil fungsi simpanKeFile untuk menyimpan data buku ke file dan mengakhiri program.
default: Menampilkan pesan jika input tidak valid.

    return 0;
}
104-105. Akhir Program:

Mengembalikan nilai 0 sebagai tanda bahwa program berhasil dijalankan.
