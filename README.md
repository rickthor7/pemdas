# 📚 SISMAN PERON: Sistem Manajemen Perpustakaan Online

Dibuat oleh: 
1. M. Thoriq Dhiyaulhaq 24051204170
2. Moch Mufid 24051204149
3. M. Ilham Jazuli 24051204154

Selamat datang di proyek kita **Sistem Manajemen Perpustakaan Online**! 🚀 Aplikasi ini dirancang untuk mempermudah pengelolaan data buku di perpustakaan dengan fitur-fitur sederhana namun fungsional. Dibangun menggunakan **C++**, aplikasi ini cocok untuk belajar dan mengembangkan kemampuan programming Anda. 😎

## ✨ Fitur Utama

### Fitur Buku:
1. 🆕 **Tambah Buku**: Tambahkan buku baru ke perpustakaan dengan mudah.
2. 🔍 **Cari Buku**: Temukan buku berdasarkan ID.
3. 🗑️ **Hapus Buku**: Hapus data buku yang tidak diperlukan.
4. 📜 **Tampilkan Semua Buku**: Lihat semua buku yang tersimpan di sistem.
5. 💾 **Simpan dan Keluar**: Simpan data buku ke file agar tetap aman setelah program ditutup.

### Fitur Admin:
1. 🛠️ **Login Admin**: Admin dapat login menggunakan username dan password yang telah terdaftar untuk mengakses menu admin.
2. 🔑 **Kelola Akun Admin**: Admin dapat menambah atau menghapus akun admin lain untuk memberikan akses kepada pihak yang berwenang.
3. 💼 **Kelola Data Buku**: Admin dapat menambah, menghapus, atau memperbarui informasi buku dalam sistem.
4. 🗂️ **Lihat Statistik Buku**: Admin dapat melihat statistik jumlah buku berdasarkan kategori tertentu, seperti tahun atau pengarang.

---

## 🛠️ Teknologi yang Digunakan

- **Bahasa Pemrograman**: C++
- **Library yang Digunakan**:
  - `<iostream>`: Untuk input/output data.
  - `<string>`: Untuk memproses teks seperti judul dan nama pengarang.
  - `<fstream>`: Untuk membaca dan menulis file.

---

## 📂 Struktur Data

Setiap buku disimpan dalam bentuk **struct** dengan atribut:

- `id` (int): ID unik buku.
- `judul` (string): Judul buku.
- `pengarang` (string): Nama pengarang buku.
- `tahun` (int): Tahun terbit buku.

Admin juga disimpan dalam struktur terpisah untuk menyimpan informasi login:

- `username` (string): Username admin.
- `password` (string): Password admin yang terenkripsi.

---

## 🚀 Cara Menjalankan Program

1. **Kompilasi Program**
   ```bash
   g++ -o perpustakaan perpustakaan.cpp
   ```

2. **Jalankan Program**
   ```bash
   ./perpustakaan
   ```

3. Ikuti menu interaktif yang muncul di terminal! 😄

---

## 🗂️ Menu Program

Ketika Anda menjalankan program, menu berikut akan muncul:
```
📚 Sistem Manajemen Perpustakaan Online 📚
1. Login Admin
2. Tambah Buku
3. Tampilkan Semua Buku
4. Cari Buku
5. Hapus Buku
6. Simpan dan Keluar
Pilih menu: 
```
Masukkan angka sesuai menu yang ingin digunakan.

---

## 🛠️ Penjelasan Setiap Fitur

### Fitur Admin:
### 1. 🛠️ **Login Admin**: 
Admin dapat login menggunakan username dan password yang telah terdaftar untuk mengakses menu admin.
### 2. 🔑 **Kelola Akun Admin**:
Admin dapat menambah atau menghapus akun admin lain untuk memberikan akses kepada pihak yang berwenang.
### 3. 💼 **Kelola Data Buku**: 
Admin dapat menambah, menghapus, atau memperbarui informasi buku dalam sistem.
### 4. 🗂️ **Lihat Statistik Buku**:
Admin dapat melihat statistik jumlah buku berdasarkan kategori tertentu, seperti tahun atau pengarang.

### Fitur Perpus:
### 1. 🆕 Tambah Buku
- Memasukkan ID, judul, pengarang, dan tahun buku.
- Data ditambahkan ke array yang menyimpan buku.

### 2. 📜 Tampilkan Semua Buku
- Menampilkan daftar semua buku yang tersimpan di perpustakaan.
- Informasi yang ditampilkan: ID, judul, pengarang, dan tahun.

### 3. 🔍 Cari Buku
- Masukkan ID buku untuk mencari.
- Jika ditemukan, data buku akan ditampilkan.

### 4. 🗑️ Hapus Buku
- Masukkan ID buku untuk menghapusnya dari perpustakaan.

### 5. 💾 Simpan dan Keluar
- Data buku disimpan ke file `perpustakaan.txt` agar tidak hilang.
- Program ditutup setelah data berhasil disimpan.

---

## 📂 File Penyimpanan

Data buku disimpan di file `perpustakaan.txt` dengan format berikut:
```
<ID>|<Judul>|<Pengarang>|<Tahun>
```
Contoh:
```
1|Pemrograman Dasar|John Doe|2024
2|Algoritma dan Struktur Data|Jane Smith|2023
```

Data admin disimpan di file `admin.txt` dengan format berikut:
```
<Username>|<Password>
```
Contoh:
```
admin1|password123
admin2|securepass
admin3|adminpass2024
```

---

## 🚧 Batasan Program

- Maksimal buku yang dapat disimpan: **100 buku**.
- maksimal akun atmin ada **5 orang**
- Format file harus sesuai agar dapat dibaca program.

---

## 💡 Penjelasan Kode

### 1. Percabangan

Program menggunakan percabangan (if-else) untuk memeriksa kondisi tertentu, seperti saat login admin, memilih menu, atau mengecek apakah buku ditemukan.

Contoh:

```
if (*jumlah >= MAX_BUKU) {
    cout << "Perpustakaan penuh!\n";
}
```
### 2. Perulangan

Perulangan digunakan untuk menjalankan proses berulang, seperti menampilkan daftar buku atau mencari buku berdasarkan ID.

Contoh:
```
for (int i = 0; i < jumlah; i++) {
    cout << "Buku ke-" << i + 1 << ":\n";
}
```
### 3. Array

Program menggunakan array untuk menyimpan data buku dan admin. Array memiliki ukuran tetap dan memungkinkan kita untuk mengakses data buku berdasarkan indeks.

Contoh:
```
Buku perpustakaan[MAX_BUKU];
Admin admins[MAX_ADMIN];
```
### 4. String

String digunakan untuk menyimpan data teks seperti judul buku, pengarang, dan username/password admin.

Contoh:
```
string judul;
string pengarang;
```
### 5. Fungsi Scope/Rekursif

Program ini menggunakan fungsi rekursif untuk mencari buku berdasarkan ID. Fungsi ini akan memanggil dirinya sendiri untuk melanjutkan pencarian buku di dalam array.

Contoh:
```
void cariBukuRekursif(const Buku* perpustakaan, int jumlah, int index, int idCari) {
    if (index >= jumlah) {
        cout << "Buku tidak ditemukan.\n";
        return;
    }
    if (perpustakaan[index].id == idCari) {
        cout << "Buku ditemukan: " << perpustakaan[index].judul << " oleh " << perpustakaan[index].pengarang << endl;
        return;
    }
    cariBukuRekursif(perpustakaan, jumlah, index + 1, idCari);
}
```
### 6. Pointer

Pointer digunakan untuk memanipulasi data secara langsung melalui alamat memori. Dalam program ini, pointer digunakan untuk mengubah nilai dalam array buku dan admin.

Contoh:
```
void tambahBuku(Buku* perpustakaan, int* jumlah) {
    // Menggunakan pointer untuk mengakses dan mengubah jumlah buku
}
```
### 7. Struktur

Struktur digunakan untuk mendefinisikan tipe data yang kompleks, seperti data buku dan admin, yang memiliki beberapa atribut.

Contoh:
```
struct Buku {
    int id;
    string judul;
    string pengarang;
    int tahun;
};

struct Admin {
    string username;
    string password;
};
```
### 8. File

Program ini menggunakan file untuk menyimpan dan membaca data buku dan admin, menggunakan fstream (<fstream>). File digunakan agar data tidak hilang saat program ditutup.

Contoh:
```
ofstream file(namaFile);
ifstream file(namaFile);
```
---

## 🎉 Terima Kasih!
Terima kasih telah menggunakan **Sistem Manajemen Perpustakaan Online**! Jika Anda memiliki ide, saran, atau ingin berkontribusi, jangan ragu untuk berdiskusi. 💡
