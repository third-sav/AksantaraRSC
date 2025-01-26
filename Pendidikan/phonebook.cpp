#include <iostream>
#include <string>
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
        cout << "Nama :" << nama << endl;
        cout << "Tempat Tinggal :" << tempat << endl;
        cout << "Alamat :" << alamat << endl;
        cout << "Kekuatan :" << kekuatan << endl;
    }

};

class PhoneBook{
    public:
    string nama;
};


int main(){
    cout << "Hello World!";
    return 0;
}
