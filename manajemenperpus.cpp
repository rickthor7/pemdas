#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Struktur untuk data buku
struct Buku {
    int id;
    string judul;
    string pengarang;
    int tahun;
};

// Maksimal jumlah buku
const int MAX_BUKU = 100;

// Fungsi untuk menambahkan buku (dengan pointer)
void tambahBuku(Buku* perpustakaan, int* jumlah) {
    if (*jumlah >= MAX_BUKU) {
        cout << "Perpustakaan penuh!\n";
        return;
    }

    cout << "Masukkan ID buku: ";
    cin >> perpustakaan[*jumlah].id;
    cin.ignore();
    cout << "Masukkan judul buku: ";
    getline(cin, perpustakaan[*jumlah].judul);
    cout << "Masukkan pengarang buku: ";
    getline(cin, perpustakaan[*jumlah].pengarang);
    cout << "Masukkan tahun terbit: ";
    cin >> perpustakaan[*jumlah].tahun;

    (*jumlah)++;
    cout << "Buku berhasil ditambahkan!\n";
}

// Fungsi untuk menampilkan semua buku
void tampilkanBuku(const Buku* perpustakaan, int jumlah) {
    if (jumlah == 0) {
        cout << "Tidak ada buku di perpustakaan.\n";
        return;
    }

    for (int i = 0; i < jumlah; i++) {
        cout << "Buku ke-" << i + 1 << ":\n";
        cout << "ID: " << perpustakaan[i].id << endl;
        cout << "Judul: " << perpustakaan[i].judul << endl;
        cout << "Pengarang: " << perpustakaan[i].pengarang << endl;
        cout << "Tahun: " << perpustakaan[i].tahun << endl;
        cout << "-----------------------------\n";
    }
}

// Fungsi untuk mencari buku berdasarkan ID (dengan pointer)
Buku* cariBuku(Buku* perpustakaan, int jumlah, int id) {
    for (int i = 0; i < jumlah; i++) {
        if (perpustakaan[i].id == id) {
            return &perpustakaan[i];
        }
    }
    return nullptr;
}

// Fungsi rekursif untuk menghitung jumlah buku dengan tahun tertentu
int hitungBukuTahun(const Buku* perpustakaan, int jumlah, int tahun, int indeks = 0) {
    if (indeks == jumlah) return 0;
    return (perpustakaan[indeks].tahun == tahun ? 1 : 0) +
           hitungBukuTahun(perpustakaan, jumlah, tahun, indeks + 1);
}

// Fungsi untuk menyimpan data ke file
void simpanKeFile(const Buku* perpustakaan, int jumlah, const string& namaFile) {
    ofstream file(namaFile);
    if (!file) {
        cout << "Gagal membuka file untuk menulis.\n";
        return;
    }

    for (int i = 0; i < jumlah; i++) {
        file << perpustakaan[i].id << "|" 
             << perpustakaan[i].judul << "|"
             << perpustakaan[i].pengarang << "|"
             << perpustakaan[i].tahun << "\n";
    }
    file.close();
    cout << "Data berhasil disimpan ke file.\n";
}

// Fungsi untuk membaca data dari file
void bacaDariFile(Buku* perpustakaan, int* jumlah, const string& namaFile) {
    ifstream file(namaFile);
    if (!file) {
        cout << "Gagal membuka file untuk membaca.\n";
        return;
    }

    *jumlah = 0;
    while (file >> perpustakaan[*jumlah].id) {
        file.ignore(); // Abaikan pemisah
        getline(file, perpustakaan[*jumlah].judul, '|');
        getline(file, perpustakaan[*jumlah].pengarang, '|');
        file >> perpustakaan[*jumlah].tahun;
        file.ignore(); // Abaikan akhir baris
        (*jumlah)++;
    }
    file.close();
    cout << "Data berhasil dibaca dari file.\n";
}

// Program utama
int main() {
    Buku perpustakaan[MAX_BUKU];
    int jumlah = 0;
    const string namaFile = "perpustakaan.txt";

    int pilihan;
    do {
        cout << "\nMenu Perpustakaan:\n";
        cout << "1. Tambah Buku\n";
        cout << "2. Tampilkan Buku\n";
        cout << "3. Cari Buku\n";
        cout << "4. Hitung Buku per Tahun\n";
        cout << "5. Simpan Data ke File\n";
        cout << "6. Baca Data dari File\n";
        cout << "7. Keluar\n";
        cout << "Pilihan Anda: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                tambahBuku(perpustakaan, &jumlah);
                break;
            case 2:
                tampilkanBuku(perpustakaan, jumlah);
                break;
            case 3: {
                int id;
                cout << "Masukkan ID buku yang dicari: ";
                cin >> id;
                Buku* buku = cariBuku(perpustakaan, jumlah, id);
                if (buku) {
                    cout << "Buku ditemukan:\n";
                    cout << "ID: " << buku->id << endl;
                    cout << "Judul: " << buku->judul << endl;
                    cout << "Pengarang: " << buku->pengarang << endl;
                    cout << "Tahun: " << buku->tahun << endl;
                } else {
                    cout << "Buku tidak ditemukan.\n";
                }
                break;
            }
            case 4: {
                int tahun;
                cout << "Masukkan tahun: ";
                cin >> tahun;
                int jumlahTahun = hitungBukuTahun(perpustakaan, jumlah, tahun);
                cout << "Jumlah buku dengan tahun " << tahun << ": " << jumlahTahun << endl;
                break;
            }
            case 5:
                simpanKeFile(perpustakaan, jumlah, namaFile);
                break;
            case 6:
                bacaDariFile(perpustakaan, &jumlah, namaFile);
                break;
            case 7:
                cout << "Keluar dari program.\n";
                break;
            default:
                cout << "Pilihan tidak valid.\n";
        }
    } while (pilihan != 7);

    return 0;
}
