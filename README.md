# 📚 Sistem Manajemen Perpustakaan Online

Dibuat oleh: 
1. M. Thoriq Dhiya ul haq
24081204170
2. Moch Mufid
24051204149
3. M. Ilham Jazuli
240512041
   
Selamat datang di proyek kita **Sistem Manajemen Perpustakaan Online**! 🚀 Aplikasi ini dirancang untuk mempermudah pengelolaan data buku di perpustakaan dengan fitur-fitur sederhana namun fungsional. Dibangun menggunakan **C++**, aplikasi ini cocok untuk belajar dan mengembangkan kemampuan programming Anda. 😎

## ✨ Fitur Utama

1. 🆕 **Tambah Buku**: Tambahkan buku baru ke perpustakaan dengan mudah.
2. 🔍 **Cari Buku**: Temukan buku berdasarkan ID.
3. 🗑️ **Hapus Buku**: Hapus data buku yang tidak diperlukan.
4. 📜 **Tampilkan Semua Buku**: Lihat semua buku yang tersimpan di sistem.
5. 💾 **Simpan dan Keluar**: Simpan data buku ke file agar tetap aman setelah program ditutup.

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
1. Tambah Buku
2. Tampilkan Semua Buku
3. Cari Buku
4. Hapus Buku
5. Simpan dan Keluar
Pilih menu: 
```
Masukkan angka sesuai menu yang ingin digunakan.

---

## 🛠️ Penjelasan Setiap Fitur

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

---

## 🚧 Batasan Program

- Maksimal buku yang dapat disimpan: **100 buku**.
- Format file harus sesuai agar dapat dibaca program.

---

## 📝 Pengembangan Selanjutnya

Berikut adalah ide pengembangan fitur tambahan:

1. Statistik buku berdasarkan pengarang atau tahun. 📊
2. Sistem login untuk admin. 🔐
3. Penyimpanan berbasis database (MySQL atau SQLite). 💾
4. Integrasi dengan GUI menggunakan Qt atau Electron.js. 🖥️

---

## 🎉 Terima Kasih!
Terima kasih telah menggunakan **Sistem Manajemen Perpustakaan Online**! Jika Anda memiliki ide, saran, atau ingin berkontribusi, jangan ragu untuk berdiskusi. 💡
