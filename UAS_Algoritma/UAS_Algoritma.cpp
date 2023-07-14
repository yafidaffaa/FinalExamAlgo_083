#include <iostream>
#include <string>

using namespace std;
const int MAX_MAHASISWA = 100;
int NIM[MAX_MAHASISWA];
string nama[MAX_MAHASISWA];
string jurusan[MAX_MAHASISWA];
int tahunMasuk[MAX_MAHASISWA];
int jumlahMahasiswa = 0;

void tambahMahasiswa() {
	if (jumlahMahasiswa < MAX_MAHASISWA) {
		cout << "========== TAMBAH MAHASISWA ==========" << endl;
		cout << "NIM: ";
		cin >> NIM[jumlahMahasiswa];
		cin.ignore();
		cout << "Nama: ";
		getline(cin, nama[jumlahMahasiswa]);
		cout << "Jurusan: ";
		getline(cin, jurusan[jumlahMahasiswa]);
		cout << "Tahun Masuk: ";
		cin >> tahunMasuk[jumlahMahasiswa];
		cin.ignore();
		jumlahMahasiswa++;
		cout << "Mahasiswa berhasil ditambahkan!" << endl;
	}
	else {
		cout << "Kapasitas maksimum mahasiswa telah tercapai." << endl;
	}
};

void tampilkanSemuaMahasiswa() {
	cout << "========== DAFTAR MAHASISWA ==========" << endl;
	if (jumlahMahasiswa > 0) {
		for (int i = 0; i < jumlahMahasiswa; i++) {
			cout << "NIM		:" << NIM[i] << endl;
			cout << "Nama		:" << nama[i] << endl;
			cout << "Jurusan		:" << jurusan[i] << endl;
			cout << "Tahun Masuk	:" << tahunMasuk[i] << endl;
			cout << endl;
		}
	}
	else
	{
		cout << "Belum ada data mahasiswa." << endl;
	}
};

void algorithmacariMahasiswaByNIM() {
	int targetNIM;
	bool found = false;
	cout << "========== CARI MAHASISWA BERDASARKAN NIM ==========" << endl;
	cout << "Masukkan NIM yang dicari: ";
	cin >> targetNIM;
	cin.ignore();
	for (int i = 0; i < jumlahMahasiswa; i++) {
		if (NIM[i] == targetNIM) {
			cout << "NIM      : " << NIM[i] << endl;
			cout << "Nama     : " << nama[i] << endl;
			cout << "Jurusan  : " << jurusan[i] << endl;
			cout << "Tahun    : " << tahunMasuk[i] << endl;
			found = true;
		}
		if (!found) {
			cout << endl;
			cout << "Mahasiswa dengan NIM tersebut tidak ditemukan." << endl;
		}	
	}
}

void algorithmaSortByTahunMasuk() {
	cout << "========== DAFTAR MAHASISWA BERDASARKAN TAHUN MASUK ==========" << endl;
	if (jumlahMahasiswa > 0) {
		for (int i = 0; i < jumlahMahasiswa - 1; i++) {
			for (int j = 0; j < jumlahMahasiswa - i - 1; j++) {
				if (tahunMasuk[j] > tahunMasuk[j + 1]) {
					swap(NIM[j], NIM[j + 1]);
					swap(nama[j], nama[j + 1]);
					swap(jurusan[j], jurusan[j + 1]);
					swap(tahunMasuk[j], tahunMasuk[j + 1]);
				}
			}
		}

		for (int i = 0; i < jumlahMahasiswa; i++) {
			cout << "NIM      : " << NIM[i] << endl;
			cout << "Nama     : " << nama[i] << endl;
			cout << "Jurusan  : " << jurusan[i] << endl;
			cout << "Tahun    : " << tahunMasuk[i] << endl;
			cout << "=====================================" << endl;
		}
	}
	else {
		cout << "Belum ada data mahasiswa." << endl;
	}
}

int main() {
	int pilihan;
	do {
		cout << "========== MENU MANAJEMEN DATA MAHASISWA ==========" << endl;
		cout << "1. Tambah Mahasiswa" << endl;
		cout << "2. Tampilkan Semua Mahasiswa" << endl;
		cout << "3. Cari Mahasiswa berdasarkan NIM" << endl;
		cout << "4. Tampilkan Mahasiswa berdasarkan Tahun Masuk" << endl;
		cout << "5. Keluar" << endl;
		cout << "Pilihan: ";
		cin >> pilihan;
		cin.ignore();
		switch (pilihan) {
		case 1:
			tambahMahasiswa();
			break;
		case 2:
			tampilkanSemuaMahasiswa();
			break;
		case 3:
			algorithmacariMahasiswaByNIM();
			break;
		case 4:
			algorithmaSortByTahunMasuk();
			break;
		case 5:
			cout << "Terima kasih! Program selesai." << endl;
			break;
		default:
			cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
		}
		cout << endl;
	} while (pilihan != 5);
	return 0;
}

/* 2. Berdasarkan studi kasus diatas, algoritma apa saja yang anda gunakan ? (10 Poin)
		- algoritma perulangan dengan FOR unttuk menampilkan.
		- algoritma bubbleSort untuk mengurutkan.
		- IF ELSE.
		- algoritma DO WHILE.
		- SWITCH CASE.

	3. Jelaskan perbedaan mendasar antara algorithma stack dan queue! (15 Poin)
		- Stack itu algoritma untuk menumpuk jadi yang pertama masuk menjadi yang terakhir keluar.
		- Queue itu algoritma antrian jadi yang pertama masuk dia juga yang pertama keluar.

	4. Jelaskan pada saat bagaimana harus menggunakan algorithma stack?(15 poin)
		ketika kita ingin membuat fitur untuk mengetik seperti microsoft word diamana
		kita dapat menghapus kata kemudian dapat mengembalikan kata yang sudah dihapus.

	5. a. Seberapa banyak kedalaman yang dimiliki struktur tersebut?
			4 kedalaman.
	   b. Tentukan Benar atau salah cara membaca struktur pohon di atas?
			salah.	
*/	


