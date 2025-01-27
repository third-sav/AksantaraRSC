#include <iostream>
#include <string>
#include <algorithm> // Untuk fungsi swap jika kontak sudah melebihi 8 slot, harusnya bisa pakai define operator= untuk ngeswap , tapi biar cepat saja
using namespace std;


class Contact{
    //Informasi yang ada dalam kontak
    public:
    string nama;
    string tempat;
    string alamat;
    string kekuatan;

    void swapper(Contact& other) {
        swap(nama, other.nama);
        swap(tempat, other.tempat);
        swap(alamat, other.alamat);
        swap(kekuatan, other.kekuatan);
    }

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

    PhoneBook() : count(0) {} // setup, semua 0

    

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
            //Swap kontak agar kontak lama naik keatas semua
            for (int i=0; i<7; i++){
                contacts[i].swapper(contacts[i+1]);
            }

            //Tambahkan kontak baru ke slot terakhir
            contacts[7].nama = nama;
            contacts[7].tempat = tempat;
            contacts[7].alamat = alamat;
            contacts[7].kekuatan = kekuatan;
            //Kalau slotnya udah penuh, replace data lama, var terlama pindah ke indeks terlama selanjutnya.
            /*contacts[terlama].nama = nama;
            contacts[terlama].tempat = tempat;
            contacts[terlama].alamat = alamat;
            contacts[terlama].kekuatan = kekuatan;
            terlama = (terlama+1) % 8 ;// %8 biar pas terlamanya di indeks terakhir, selanjutnya balik lagi ke 0 karena 8%8 = 0*/
        }
    }

    void listkontak() const {
        if (count==0) {
            cout << "Belum ada kontak dalam PhoneBook." << endl;
            
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
            
        }
    }

    int countNow() const{
        return count;
    }
    
};

void spacing() {
        cout << "\n"; 
        // Asalnya memakai ANSI escape untuk clearscreen, tetapi ternyata tidak universal, jadinya memakai new line saja untuk ngerapihin
};


int main(){
    PhoneBook phonebook;
    int pilihan;

    while(true) {
        spacing();
        cout << "===PhoneBook Pak Bell===" << endl;
        cout << "1. ADD, tambah kontak" << endl;
        cout << "2. SEARCH, cari kontak"<< endl;
        cout << "3. EXIT, keluar" << endl;
        cout << "Pilih opsi anda: ";
        cin >> pilihan;
        cin.ignore(); // ignore \n

        if (pilihan == 1) {
            //ADD
            spacing();
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
            
        } 
        
        else if (pilihan == 2) {
            //SEARCH
            spacing();
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
            spacing();
            cout << "Program keluar, semua data dihapus," << endl;
            
            break;
        }

        else {
            spacing();
            cout << "Pilihan tidak valid! tolong coba lagi." << endl;
            
            continue;
        }

    }
}
