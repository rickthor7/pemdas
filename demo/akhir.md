Berikut adalah penjelasan rinci kode terakhir:


---

Fungsi Menu Perpustakaan

void menuPerpustakaan() {

1. menuPerpustakaan: Fungsi utama untuk menampilkan menu dan mengelola perpustakaan.



Buku perpustakaan[MAX_BUKU];
int jumlah = 0;
const string namaFile = "perpustakaan.txt";

2. Deklarasi variabel:

perpustakaan[MAX_BUKU]: Array untuk menyimpan data buku.

jumlah: Variabel untuk melacak jumlah buku saat ini.

namaFile: Nama file tempat menyimpan data buku.




int pilihan;
do {

3. pilihan: Variabel untuk menyimpan input pilihan menu dari pengguna. do-while digunakan untuk terus menampilkan menu hingga pengguna memilih keluar (pilihan 6).



cout << "\nMenu Perpustakaan:\n";
cout << "1. Tambah Buku\n";
cout << "2. Tampilkan Buku\n";
cout << "3. Simpan Data ke File\n";
cout << "4. Baca Data dari File\n";
cout << "5. Cari Buku\n";
cout << "6. Keluar\n";
cout << "Pilihan Anda: ";
cin >> pilihan;

4. Menampilkan menu kepada pengguna dan meminta input pilihan.



switch (pilihan) {

5. switch: Struktur untuk menangani berbagai opsi menu berdasarkan input pengguna.



Case 1: Tambah Buku

case 1:
    tambahBuku(perpustakaan, &jumlah);
    break;

6. Memanggil fungsi tambahBuku untuk menambahkan buku ke array perpustakaan.



Case 2: Tampilkan Buku

case 2:
    tampilkanBuku(perpustakaan, jumlah);
    break;

7. Memanggil fungsi tampilkanBuku untuk mencetak daftar buku yang ada.



Case 3: Simpan Data ke File

case 3:
    simpanKeFile(perpustakaan, jumlah, namaFile);
    break;

8. Memanggil fungsi simpanKeFile untuk menyimpan data buku ke file.



Case 4: Baca Data dari File

case 4:
    bacaDariFile(perpustakaan, &jumlah, namaFile);
    break;

9. Memanggil fungsi bacaDariFile untuk memuat data buku dari file.



Case 5: Cari Buku

case 5: {
    int idCari;
    cout << "Masukkan ID Buku yang dicari: ";
    cin >> idCari;
    cariBukuRekursif(perpustakaan, jumlah, 0, idCari);
    break;
}

10. Meminta pengguna memasukkan idCari (ID buku yang dicari), lalu memanggil fungsi cariBukuRekursif untuk mencari buku tersebut.



Case 6: Keluar

case 6:
    cout << "Keluar dari program.\n";
    break;

11. Mencetak pesan dan keluar dari loop saat pengguna memilih opsi 6.



Default: Pilihan Tidak Valid

default:
    cout << "Pilihan tidak valid.\n";

12. Menangani input tidak valid dengan mencetak pesan kesalahan.



} while (pilihan != 6);

13. Loop akan berjalan hingga pengguna memilih opsi 6.




---

Program Utama (main)

int main() {

14. Fungsi main: Titik awal eksekusi program.



Admin admins[MAX_ADMIN];
int jumlahAdmin = 0;
const string namaFileAdmin = "admin.txt";

15. Deklarasi variabel:



admins[MAX_ADMIN]: Array untuk menyimpan data admin.

jumlahAdmin: Variabel untuk melacak jumlah admin.

namaFileAdmin: Nama file tempat menyimpan data admin.


Membaca Data Admin dari File

bacaDataAdmin(admins, &jumlahAdmin, namaFileAdmin);

16. Memanggil fungsi bacaDataAdmin untuk memuat data admin dari file.



Cek Data Admin

if (jumlahAdmin == 0) {
    cout << "Tidak ada data admin yang tersedia. Tambahkan data admin ke file 'admin.txt'.\n";
    return 0;
}

17. Jika tidak ada data admin di file, mencetak pesan dan keluar dari program.



Login Admin

if (!loginAdmin(admins, jumlahAdmin)) {
    return 0;
}

18. Memanggil fungsi loginAdmin untuk melakukan autentikasi admin. Jika login gagal, program keluar.



Masuk ke Menu Perpustakaan

menuPerpustakaan();

19. Jika login berhasil, memanggil fungsi menuPerpustakaan untuk menampilkan dan mengelola menu perpustakaan.



return 0;

20. Program berakhir dengan nilai kembalian 0, menandakan eksekusi selesai tanpa error.




---

Kode ini mencakup semua fitur inti:

1. Manajemen Buku: Menambah, menampilkan, mencari, menyimpan, dan membaca data buku.


2. Autentikasi Admin: Membatasi akses hanya untuk admin yang terdaftar.


3. Penggunaan File: Menyimpan dan membaca data secara persisten.



Jika ada bagian yang masih kurang jelas, beri tahu saya!

