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

// Struktur untuk data admin
struct Admin {
    string username;
    string password;
};

// Maksimal jumlah buku dan admin
const int MAX_BUKU = 100;
const int MAX_ADMIN = 100;

// Fungsi untuk menambahkan buku
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

// Fungsi untuk menyimpan data buku ke file
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

// Fungsi untuk membaca data buku dari file
void bacaDariFile(Buku* perpustakaan, int* jumlah, const string& namaFile) {
    ifstream file(namaFile);
    if (!file) {
        cout << "Gagal membuka file untuk membaca.\n";
        return;
    }

    *jumlah = 0;
    while (file >> perpustakaan[*jumlah].id) {
        file.ignore();
        getline(file, perpustakaan[*jumlah].judul, '|');
        getline(file, perpustakaan[*jumlah].pengarang, '|');
        file >> perpustakaan[*jumlah].tahun;
        file.ignore();
        (*jumlah)++;
    }
    file.close();
    cout << "Data berhasil dibaca dari file.\n";
}

// Fungsi membaca data admin dari file
void bacaDataAdmin(Admin* admins, int* jumlahAdmin, const string& namaFile) {
    ifstream file(namaFile);
    if (!file) {
        cout << "File admin tidak ditemukan. Silakan tambahkan data admin di file 'admin.txt'.\n";
        return;
    }

    string line;
    while (getline(file, line) && *jumlahAdmin < MAX_ADMIN) {
        size_t pos = line.find('|');
        if (pos != string::npos) {
            admins[*jumlahAdmin].username = line.substr(0, pos);
            admins[*jumlahAdmin].password = line.substr(pos + 1);
            (*jumlahAdmin)++;
        }
    }
    file.close();
}

// Fungsi login admin
bool loginAdmin(const Admin* admins, int jumlahAdmin) {
    string username, password;
    int attempts = 3;

    while (attempts > 0) {
        cout << "Masukkan username: ";
        cin >> username;
        cout << "Masukkan password: ";
        cin >> password;

        for (int i = 0; i < jumlahAdmin; i++) {
            if (admins[i].username == username && admins[i].password == password) {
                cout << "Login berhasil! Selamat datang, " << username << ".\n";
                return true;
            }
        }

        attempts--;
        cout << "Login gagal. Anda memiliki " << attempts << " kesempatan lagi.\n";
    }

    cout << "Login gagal. Program akan keluar.\n";
    return false;
}

// Fungsi rekursif untuk pencarian buku berdasarkan ID
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

// Menu utama perpustakaan
void menuPerpustakaan() {
    Buku perpustakaan[MAX_BUKU];
    int jumlah = 0;
    const string namaFile = "perpustakaan.txt";

    int pilihan;
    do {
        cout << "\nMenu Perpustakaan:\n";
        cout << "1. Tambah Buku\n";
        cout << "2. Tampilkan Buku\n";
        cout << "3. Simpan Data ke File\n";
        cout << "4. Baca Data dari File\n";
        cout << "5. Cari Buku\n";
        cout << "6. Keluar\n";
        cout << "Pilihan Anda: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                tambahBuku(perpustakaan, &jumlah);
                break;
            case 2:
                tampilkanBuku(perpustakaan, jumlah);
                break;
            case 3:
                simpanKeFile(perpustakaan, jumlah, namaFile);
                break;
            case 4:
                bacaDariFile(perpustakaan, &jumlah, namaFile);
                break;
            case 5: {
                int idCari;
                cout << "Masukkan ID Buku yang dicari: ";
                cin >> idCari;
                cariBukuRekursif(perpustakaan, jumlah, 0, idCari);
                break;
            }
            case 6:
                cout << "Keluar dari program.\n";
                break;
            default:
                cout << "Pilihan tidak valid.\n";
        }
    } while (pilihan != 6);
}

// Program utama
int main() {
    Admin admins[MAX_ADMIN];
    int jumlahAdmin = 0;
    const string namaFileAdmin = "admin.txt";

    // Membaca data admin dari file
    bacaDataAdmin(admins, &jumlahAdmin, namaFileAdmin);

    // Pastikan ada data admin sebelum melanjutkan
    if (jumlahAdmin == 0) {
        cout << "Tidak ada data admin yang tersedia. Tambahkan data admin ke file 'admin.txt'.\n";
        return 0;
    }

    // Login admin
    if (!loginAdmin(admins, jumlahAdmin)) {
        return 0;
    }

    // Masuk ke menu perpustakaan
    menuPerpustakaan();

    return 0;
}
