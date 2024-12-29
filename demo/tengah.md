Baris Tengah:


---

Fungsi untuk Membaca Data Buku dari File
```
void bacaDariFile(Buku* perpustakaan, int* jumlah, const string& namaFile) {
```
1. bacaDariFile: Fungsi untuk membaca data buku dari file dan menyimpannya ke array perpustakaan.

Buku* perpustakaan: Pointer ke array struktur buku.

int* jumlah: Pointer ke jumlah buku yang akan diperbarui.

const string& namaFile: Nama file tempat data buku disimpan.



```
ifstream file(namaFile);
if (!file) {
    cout << "Gagal membuka file untuk membaca.\n";
    return;
}
```
2. Membuka file menggunakan ifstream. Jika gagal, mencetak pesan kesalahan dan keluar dari fungsi.



*jumlah = 0;

3. Mengatur jumlah buku ke 0 sebelum membaca data baru.


```
while (file >> perpustakaan[*jumlah].id) {
```
4. Membaca ID buku dari file. Loop ini berjalan selama file memiliki data buku untuk dibaca.


```
file.ignore();
getline(file, perpustakaan[*jumlah].judul, '|');
getline(file, perpustakaan[*jumlah].pengarang, '|');
file >> perpustakaan[*jumlah].tahun;
file.ignore();
(*jumlah)++;
```
5. Membaca data buku:

file.ignore(): Mengabaikan karakter pemisah (misalnya, newline atau delimiter).

getline: Membaca string (judul dan pengarang) hingga delimiter |.

file >>: Membaca tahun penerbitan.

Menambah jumlah buku setelah selesai membaca satu buku.



```
file.close();
cout << "Data berhasil dibaca dari file.\n";
```
6. Menutup file setelah selesai membaca dan mencetak pesan sukses.




---

Fungsi Membaca Data Admin dari File
```
void bacaDataAdmin(Admin* admins, int* jumlahAdmin, const string& namaFile) {
```
7. bacaDataAdmin: Fungsi untuk membaca data admin dari file admin.txt.

Admin* admins: Pointer ke array data admin.

int* jumlahAdmin: Pointer ke jumlah admin yang akan diperbarui.

const string& namaFile: Nama file yang menyimpan data admin.



```
ifstream file(namaFile);
if (!file) {
    cout << "File admin tidak ditemukan. Silakan tambahkan data admin di file 'admin.txt'.\n";
    return;
}
```
8. Membuka file admin. Jika gagal, mencetak pesan dan keluar.


```
string line;
while (getline(file, line) && *jumlahAdmin < MAX_ADMIN) {
```
9. Membaca setiap baris file hingga batas maksimum admin (MAX_ADMIN).


```
size_t pos = line.find('|');
if (pos != string::npos) {
    admins[*jumlahAdmin].username = line.substr(0, pos);
    admins[*jumlahAdmin].password = line.substr(pos + 1);
    (*jumlahAdmin)++;
}
```
10. Memisahkan data admin berdasarkan karakter |:

find('|'): Menemukan posisi karakter |.

substr(0, pos): Mengambil username sebelum |.

substr(pos + 1): Mengambil password setelah |.



```
file.close();
```
11. Menutup file setelah selesai membaca.




---

Fungsi Login Admin
```
bool loginAdmin(const Admin* admins, int jumlahAdmin) {
```
12. loginAdmin: Fungsi untuk melakukan autentikasi admin.



const Admin* admins: Pointer ke array data admin.

int jumlahAdmin: Jumlah admin yang terdaftar.

```
string username, password;
int attempts = 3;
```
13. Mendeklarasikan variabel untuk menyimpan username, password, dan batas percobaan login (3 kali).


```
while (attempts > 0) {
```
14. Looping selama percobaan login masih tersedia.


```
cout << "Masukkan username: ";
cin >> username;
cout << "Masukkan password: ";
cin >> password;
```
15. Meminta username dan password dari pengguna.


```
for (int i = 0; i < jumlahAdmin; i++) {
    if (admins[i].username == username && admins[i].password == password) {
        cout << "Login berhasil! Selamat datang, " << username << ".\n";
        return true;
    }
}
```
16. Membandingkan username dan password dengan data admin yang ada. Jika cocok, login berhasil.


```
attempts--;
cout << "Login gagal. Anda memiliki " << attempts << " kesempatan lagi.\n";
```
17. Jika login gagal, mengurangi jumlah percobaan dan mencetak pesan.


```
cout << "Login gagal. Program akan keluar.\n";
return false;
```
18. Jika semua percobaan habis, login gagal sepenuhnya dan program keluar.




---

Fungsi Rekursif untuk Pencarian Buku
```
void cariBukuRekursif(const Buku* perpustakaan, int jumlah, int index, int idCari) {
```
19. cariBukuRekursif: Fungsi untuk mencari buku berdasarkan ID menggunakan rekursi.



const Buku* perpustakaan: Pointer ke array buku.

int jumlah: Jumlah total buku.

int index: Indeks saat ini dalam pencarian.

int idCari: ID buku yang dicari.

```
if (index >= jumlah) {
    cout << "Buku tidak ditemukan.\n";
    return;
}
```
20. Basis rekursi: Jika indeks mencapai jumlah buku, cetak bahwa buku tidak ditemukan dan keluar dari fungsi.


```
if (perpustakaan[index].id == idCari) {
    cout << "Buku ditemukan: " << perpustakaan[index].judul << " oleh " << perpustakaan[index].pengarang << endl;
    return;
}
```
21. Jika ID buku pada indeks saat ini cocok dengan idCari, cetak informasi buku dan keluar.


```
cariBukuRekursif(perpustakaan, jumlah, index + 1, idCari);
```
22. Memanggil fungsi secara rekursif dengan indeks yang bertambah (index + 1) untuk mencari di elemen berikutnya.




---

Jika ada yang kurang jelas, cp mimin uy!

