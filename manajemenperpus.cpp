#include <iostream>
#include <string>
#include <fstream>
using namespace std;

// Struktur untuk menyimpan informasi buku
struct Buku {
    int id;
    string judul;
    string pengarang;
    int tahun;
};

// Maksimal jumlah buku
const int MAX_BUKU = 100;

// Fungsi untuk menambahkan buku baru
void tambahBuku(Buku perpustakaan[], int &jumlah) {
    if (jumlah >= MAX_BUKU) {
        cout << "Perpustakaan penuh!" << endl;
        return;
    }

    cout << "Masukkan ID buku: ";
    cin >> perpustakaan[jumlah].id;
    cin.ignore(); // Membersihkan buffer
    cout << "Masukkan judul buku: ";
    getline(cin, perpustakaan[jumlah].judul);
    cout << "Masukkan pengarang buku: ";
    getline(cin, perpustakaan[jumlah].pengarang);
    cout << "Masukkan tahun terbit: ";
    cin >> perpustakaan[jumlah].tahun;

    jumlah++;
    cout << "Buku berhasil ditambahkan!" << endl;
}

// Fungsi untuk menampilkan semua buku
void tampilkanBuku(const Buku perpustakaan[], int jumlah) {
    if (jumlah == 0) {
        cout << "Belum ada buku dalam perpustakaan." << endl;
        return;
    }

    cout << "Daftar Buku:" << endl;
    for (int i = 0; i < jumlah; i++) {
        cout << "ID: " << perpustakaan[i].id
             << ", Judul: " << perpustakaan[i].judul
             << ", Pengarang: " << perpustakaan[i].pengarang
             << ", Tahun: " << perpustakaan[i].tahun << endl;
    }
}

// Fungsi untuk mencari buku berdasarkan ID
void cariBuku(const Buku perpustakaan[], int jumlah) {
    if (jumlah == 0) {
        cout << "Tidak ada buku dalam perpustakaan." << endl;
        return;
    }

    int id;
    cout << "Masukkan ID buku yang dicari: ";
    cin >> id;

    for (int i = 0; i < jumlah; i++) {
        if (perpustakaan[i].id == id) {
            cout << "Buku ditemukan!" << endl;
            cout << "Judul: " << perpustakaan[i].judul
                 << ", Pengarang: " << perpustakaan[i].pengarang
                 << ", Tahun: " << perpustakaan[i].tahun << endl;
            return;
        }
    }

    cout << "Buku dengan ID " << id << " tidak ditemukan." << endl;
}

// Fungsi untuk menghapus buku berdasarkan ID
void hapusBuku(Buku perpustakaan[], int &jumlah) {
    if (jumlah == 0) {
        cout << "Tidak ada buku yang dapat dihapus." << endl;
        return;
    }

    int id;
    cout << "Masukkan ID buku yang ingin dihapus: ";
    cin >> id;

    for (int i = 0; i < jumlah; i++) {
        if (perpustakaan[i].id == id) {
            for (int j = i; j < jumlah - 1; j++) {
                perpustakaan[j] = perpustakaan[j + 1];
            }
            jumlah--;
            cout << "Buku berhasil dihapus." << endl;
            return;
        }
    }

    cout << "Buku dengan ID " << id << " tidak ditemukan." << endl;
}

// Fungsi untuk menyimpan data ke file
void simpanData(const Buku perpustakaan[], int jumlah) {
    ofstream file("perpustakaan.txt");
    if (!file) {
        cout << "Gagal membuka file." << endl;
        return;
    }

    for (int i = 0; i < jumlah; i++) {
        file << perpustakaan[i].id << "|"
             << perpustakaan[i].judul << "|"
             << perpustakaan[i].pengarang << "|"
             << perpustakaan[i].tahun << endl;
    }

    file.close();
    cout << "Data berhasil disimpan ke file." << endl;
}

// Fungsi untuk membaca data dari file
void bacaData(Buku perpustakaan[], int &jumlah) {
    ifstream file("perpustakaan.txt");
    if (!file) {
        cout << "Gagal membuka file atau file belum ada." << endl;
        return;
    }

    jumlah = 0;
    while (!file.eof()) {
        file >> perpustakaan[jumlah].id;
        file.ignore();
        getline(file, perpustakaan[jumlah].judul, '|');
        getline(file, perpustakaan[jumlah].pengarang, '|');
        file >> perpustakaan[jumlah].tahun;
        file.ignore();
        jumlah++;
    }

    file.close();
    cout << "Data berhasil dibaca dari file." << endl;
}

// Fungsi utama
int main() {
    Buku perpustakaan[MAX_BUKU];
    int jumlah = 0;

    // Membaca data dari file saat program dimulai
    bacaData(perpustakaan, jumlah);

    int pilihan;
    do {
        cout << "\nSistem Manajemen Perpustakaan Online" << endl;
        cout << "1. Tambah Buku" << endl;
        cout << "2. Tampilkan Semua Buku" << endl;
        cout << "3. Cari Buku" << endl;
        cout << "4. Hapus Buku" << endl;
        cout << "5. Simpan dan Keluar" << endl;
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                tambahBuku(perpustakaan, jumlah);
                break;
            case 2:
                tampilkanBuku(perpustakaan, jumlah);
                break;
            case 3:
                cariBuku(perpustakaan, jumlah);
                break;
            case 4:
                hapusBuku(perpustakaan, jumlah);
                break;
            case 5:
                simpanData(perpustakaan, jumlah);
                cout << "Keluar dari program." << endl;
                break;
            default:
                cout << "Pilihan tidak valid." << endl;
        }
    } while (pilihan != 5);

    return 0;
}
