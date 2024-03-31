#include <iostream>
using namespace std;

struct karyawan {
    string nama;
    string ktp;
    string alamat;
    karyawan* next;
};

karyawan* head = NULL;

string idkaryawan[99999];
int id = 0;

void tambah() {
    karyawan* newkaryawan = new karyawan;
    cout << "Masukkan Nomor KTP: ";
    getline(cin, newkaryawan->ktp);
    cout << "Masukkan Nama Karyawan: ";
    getline(cin >> ws, newkaryawan->nama);
    cout << "Masukkan Alamat Karyawan: ";
    getline(cin >> ws, newkaryawan->alamat);
    newkaryawan->next = NULL;

    string idbaru = "NO" + to_string(id + 1);
    idkaryawan[id] = idbaru;
    id++;

    if (head == NULL) {
        head = newkaryawan;
    } else {
        karyawan* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newkaryawan;
    }

    cout << "Data Karyawan Berhasil Ditambahkan!" << endl;
    cout << "ID Karyawan: " << idbaru << endl;
}

void edit() {
    string cari;
    cout << "Masukkan ID Karyawan atau Nomor KTP: ";
    getline(cin, cari);

    karyawan* current = head;
    bool found = false;

    while (current != NULL) {
        for (int i = 0; i < id; i++) {
            if (idkaryawan[i] == cari || current->ktp == cari) {
                found = true;
                cout << "Data Karyawan Ditemukan!" << endl;
                cout << "Nama Karyawan: " << current->nama << endl;
                cout << "ID Karyawan: " << idkaryawan[i] << endl;
                cout << "Nomor KTP: " << current->ktp << endl;

                cout << "Masukkan Nomor KTP Baru: ";
                getline(cin, current->ktp);
                cout << "Masukkan Nama Karyawan Baru: ";
                getline(cin >> ws, current->nama);
                cout << "Masukkan Alamat Karyawan: ";
                getline(cin >> ws, current->alamat);

                cout << "Data Karyawan Berhasil Diubah!" << endl;
                break;
            }
        }
        current = current->next;
    }

    if (!found) {
        cout << "Data Karyawan Tidak Ditemukan!" << endl;
    }
}

void hapus() {
    string cari;
    cout << "Masukkan ID Karyawan atau Nomor KTP: ";
    getline(cin, cari);

    karyawan* current = head;
    karyawan* prev = NULL;
    bool found = false;
    int index = -1;

    while (current != NULL) {
        for (int i = 0; i < id; i++) {
            if (idkaryawan[i] == cari || current->ktp == cari) {
                found = true;
                index = i;

                if (prev == NULL) {
                    head = current->next;
                } else {
                    prev->next = current->next;
                }

                cout << "Data Karyawan Berhasil Dihapus!" << endl;
                delete current;
                break;
            }
        }

        if (found) {
            break;
        }

        prev = current;
        current = current->next;
    }

    if (found) {
        for (int i = index; i < id - 1; i++) {
            idkaryawan[i] = idkaryawan[i + 1];
        }
        id--;
    } else {
        cout << "Data Karyawan Tidak Ditemukan!" << endl;
    }
}

void cari() {
    string cari;
    cout << "Masukkan ID Karyawan atau Nomor KTP: ";
    getline(cin, cari);

    karyawan* current = head;
    bool found = false;

    while (current != NULL) {
        for (int i = 0; i < id; i++) {
            if (idkaryawan[i] == cari || current->ktp == cari) {
                found = true;
                cout << "Data Karyawan Ditemukan!" << endl;
                cout << "Nomor KTP: " << current->ktp << endl;
                cout << "Nama Karyawan: " << current->nama << endl;
                cout << "Alamat Karyawan: " << current->alamat << endl;
                cout << "ID Karyawan: " << idkaryawan[i] << endl;
                break;
            }
        }
        current = current->next;
    }

    if (!found) {
        cout << "Data Karyawan Tidak Ditemukan!" << endl;
    }
}

int main() {
    int pilih;

    do {
        cout << "===== Sistem Manajemen Data Karyawan =====" << endl;
        cout << "1. Tambah Data Karyawan" << endl;
        cout << "2. Edit Data Karyawan" << endl;
        cout << "3. Hapus Data Karyawan" << endl;
        cout << "4. Cari Data Karyawan" << endl;
        cout << "Masukkan Pilihan Anda: ";
        cin >> pilih;
        cin.ignore();

        switch (pilih) {
            case 1:
                tambah();
                break;
            case 2:
                edit();
                break;
            case 3:
                hapus();
                break;
            case 4:
                cari();
                break;
        }

        cout << endl;
    } while (pilih);

    return 0;
}