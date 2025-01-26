#include <iostream>
#include <string>
#include <chrono> 
#include <thread>
using namespace std;

class Contact{
    //Informasi yang ada dalam kontak
    public:
    string nama;
    string tempat;
    string alamat;
    string kekuatan;

    //Menampilkan informasi
    void detail() {
        cout << "Nama           : " << nama << endl;
        cout << "Tempat Tinggal : " << tempat << endl;
        cout << "Alamat         : " << alamat << endl;
        cout << "Kekuatan       : " << kekuatan << endl;
    }

};

class PhoneBook{
    private:
    Contact contacts[8]; // Maks 8 kontak
    int count; // Untuk mengecek ada berapa kontak sekarang
    int terlama; // Identifikasi kontak mana sekarang yang terlama dari index

    public:

    PhoneBook() : count(0), terlama(0) {} // setup, semua 0

    void ADD(const string& nama, const string& tempat, const string& alamat, const string& kekuatan) {
        if (count < 8) {
            //Jika masih ada slot buat kontak
            contacts[count].nama = nama;
            contacts[count].tempat = tempat;
            contacts[count].alamat = alamat;
            contacts[count].kekuatan = kekuatan;
            count++;
            //tambah berapa kontak yang ada sekarang
        }
        else {
            //Kalau slotnya udah penuh, replace data lama, var terlama pindah ke indeks terlama selanjutnya.
            contacts[terlama].nama = nama;
            contacts[terlama].tempat = tempat;
            contacts[terlama].alamat = alamat;
            contacts[terlama].kekuatan = kekuatan;
            terlama = (terlama+1) % 8 ;// %8 biar pas terlamanya di indeks terakhir, selanjutnya balik lagi ke 0 karena 8%8 = 0
        }
    }

    void listkontak() const {
        if (count==0) {
            cout << "Belum ada kontak dalam PhoneBook." << endl;
            this_thread::sleep_for(chrono::seconds(3));
            return;
        }

        cout << "List kontak yang tersedia:" << endl;
        int i = 0; 
        for (i; i< count; i++){
            
            cout << i+1 << ". "<< contacts[i].nama << endl;
        }
    }

    void SEARCH(int index)  {
        if (index >= 0 && index < count){
            cout << "Informasi detail: " << endl;
            contacts[index].detail();
        } else {
            cout << "Indeks Kontak Invalid." << endl;
            this_thread::sleep_for(chrono::seconds(3));
        }
    }

    int countNow() const{
        return count;
    }
    
};

void clearScreen() {
    for (int i = 0; i < 100; i++) {
        cout << "\n"; // Asalnya memakai ANSI escape, tetapi ternyata tidak universal, jadinya memakai new line saja
}
}


int main(){
    PhoneBook phonebook;
    int pilihan;

    while(true) {
        clearScreen();
        cout << "===PhoneBook Pak Bell===" << endl;
        cout << "1. ADD, tambah kontak" << endl;
        cout << "2. SEARCH, cari kontak"<< endl;
        cout << "3. EXIT, keluar" << endl;
        cout << "Pilih opsi anda: ";
        cin >> pilihan;
        cin.ignore(); // ignore \n

        if (pilihan == 1) {
            //ADD
            clearScreen();
            string nama, tempat, alamat, kekuatan;
            cout << "Masukkan nama: ";
            getline(cin, nama); // masuk ke variabel
            cout << "Masukkan tempat tinggal: ";
            getline(cin,tempat);
            cout << "Masukkan alamat: ";
            getline(cin,alamat);
            cout << "Masukkan kekuatan: ";
            getline(cin,kekuatan);

            phonebook.ADD(nama, tempat, alamat, kekuatan);
            cout << "Kontak berhasil ditambahkan!" << endl;
            this_thread::sleep_for(chrono::seconds(2));
        } 
        
        else if (pilihan == 2) {
            //SEARCH
            clearScreen();
            phonebook.listkontak();
            if (phonebook.countNow() > 0){
                int index;
                string back;
                cout << "Masukkan indeks kontak yang detailnya ingin dilihat: ";
                cin >> index;
                phonebook.SEARCH(index-1); //Index dimulai dari 0
                cout << "Input Y untuk kembali ke menu utama. ";
                cin >> back;
            }
        }

        else if (pilihan == 3){
            //EXIT
            clearScreen();
            cout << "Program keluar, semua data dihapus," << endl;
            this_thread::sleep_for(chrono::seconds(3));
            break;
        }

        else {
            clearScreen();
            cout << "Pilihan tidak valid! tolong coba lagi." << endl;
            this_thread::sleep_for(chrono::seconds(3));
            continue;
        }

    }
}
