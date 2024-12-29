Berikut adalah penjelasan kode tersebut per baris:

Header dan Namespace

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

1. #include <iostream>: Untuk input/output standar seperti cin dan cout.


2. #include <fstream>: Untuk operasi file seperti membaca atau menulis ke file.


3. #include <string>: Untuk menggunakan tipe data string.


4. using namespace std;: Mempermudah penggunaan fungsi dari namespace std tanpa harus menulis std:: di depannya.




---

Struktur Data

struct Buku {
    int id;
    string judul;
    string pengarang;
    int tahun;
};

5. struct Buku: Mendefinisikan struktur data untuk menyimpan informasi tentang buku.

int id: ID unik untuk buku.

string judul: Menyimpan judul buku.

string pengarang: Menyimpan nama pengarang.

int tahun: Tahun penerbitan buku.




struct Admin {
    string username;
    string password;
};

6. struct Admin: Struktur data untuk menyimpan data admin.

string username: Nama pengguna admin.

string password: Kata sandi admin.





---

Konstanta

const int MAX_BUKU = 100;
const int MAX_ADMIN = 100;

7. MAX_BUKU: Batas maksimal jumlah buku yang dapat disimpan.


8. MAX_ADMIN: Batas maksimal jumlah admin yang dapat disimpan.




---

Fungsi untuk Menambahkan Buku

void tambahBuku(Buku* perpustakaan, int* jumlah) {

9. tambahBuku: Fungsi untuk menambahkan buku ke perpustakaan.

Buku* perpustakaan: Array pointer ke struktur buku.

int* jumlah: Pointer ke jumlah buku saat ini.




if (*jumlah >= MAX_BUKU) {
    cout << "Perpustakaan penuh!\n";
    return;
}

10. Mengecek apakah jumlah buku sudah mencapai batas maksimum. Jika iya, cetak pesan dan keluar dari fungsi.



cout << "Masukkan ID buku: ";
cin >> perpustakaan[*jumlah].id;
cin.ignore();

11. Meminta input ID buku dari pengguna dan menyimpannya di indeks jumlah pada array perpustakaan.
cin.ignore(): Mengabaikan newline karakter agar input berikutnya tidak terlewat.



cout << "Masukkan judul buku: ";
getline(cin, perpustakaan[*jumlah].judul);

12. Meminta input judul buku menggunakan getline untuk menangkap string lengkap.



cout << "Masukkan pengarang buku: ";
getline(cin, perpustakaan[*jumlah].pengarang);

13. Meminta input pengarang buku.



cout << "Masukkan tahun terbit: ";
cin >> perpustakaan[*jumlah].tahun;

14. Meminta input tahun terbit buku.



(*jumlah)++;
cout << "Buku berhasil ditambahkan!\n";

15. Menambah jumlah buku setelah data berhasil dimasukkan.




---

Fungsi untuk Menampilkan Buku

void tampilkanBuku(const Buku* perpustakaan, int jumlah) {

16. tampilkanBuku: Fungsi untuk menampilkan semua buku di perpustakaan.

const Buku* perpustakaan: Array pointer ke data buku (konstan untuk mencegah modifikasi).

int jumlah: Jumlah buku saat ini.




if (jumlah == 0) {
    cout << "Tidak ada buku di perpustakaan.\n";
    return;
}

17. Jika tidak ada buku, cetak pesan dan keluar dari fungsi.



for (int i = 0; i < jumlah; i++) {
    cout << "Buku ke-" << i + 1 << ":\n";
    cout << "ID: " << perpustakaan[i].id << endl;
    cout << "Judul: " << perpustakaan[i].judul << endl;
    cout << "Pengarang: " << perpustakaan[i].pengarang << endl;
    cout << "Tahun: " << perpustakaan[i].tahun << endl;
    cout << "-----------------------------\n";
}

18. Looping untuk mencetak data setiap buku berdasarkan indeks array perpustakaan.




---

Fungsi untuk Menyimpan Buku ke File

void simpanKeFile(const Buku* perpustakaan, int jumlah, const string& namaFile) {

19. simpanKeFile: Fungsi untuk menyimpan data buku ke dalam file.

const Buku* perpustakaan: Array pointer ke buku (konstan).

int jumlah: Jumlah buku.

const string& namaFile: Nama file tujuan (konstan untuk efisiensi).




ofstream file(namaFile);
if (!file) {
    cout << "Gagal membuka file untuk menulis.\n";
    return;
}

20. Membuka file untuk ditulis menggunakan ofstream. Jika gagal, cetak pesan dan keluar dari fungsi.



for (int i = 0; i < jumlah; i++) {
    file << perpustakaan[i].id << "|"
         << perpustakaan[i].judul << "|"
         << perpustakaan[i].pengarang << "|"
         << perpustakaan[i].tahun << "\n";
}

21. Looping untuk menulis data setiap buku ke file dalam format tertentu.



file.close();
cout << "Data berhasil disimpan ke file.\n";

22. Menutup file setelah selesai dan memberi pesan sukses.




---

Jika ada bagian yang kurang jelas atau ingin penjelasan tambahan, beri tahu saya!

