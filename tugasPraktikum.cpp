#include <iostream>
#include <vector>
using namespace std;

// Abstract Base Class
class RekeningBank {
protected:
    double saldo;

public:
    // Constructor
    RekeningBank(double s) {
        saldo = s;
    }

    // Pure Virtual Function
    virtual void potongAdmin() = 0;

    // Method tampil saldo
    void tampilSaldo() {
        cout << "Saldo akhir : Rp " << saldo << endl;
    }

    // Virtual Destructor
    virtual ~RekeningBank() {}
};

// Class Rekening Syariah
class RekeningSyariah : public RekeningBank {
public:
    RekeningSyariah(double s) : RekeningBank(s) {}

    void potongAdmin() override {
        cout << "Rekening Syariah bebas biaya admin." << endl;
    }
};

// Class Rekening Konvensional
class RekeningKonvensional : public RekeningBank {
public:
    RekeningKonvensional(double s) : RekeningBank(s) {}

    void potongAdmin() override {
        saldo -= 15000;
        cout << "Biaya admin Rp 15.000 dipotong." << endl;
    }
};

// Class Rekening Premium
class RekeningPremium : public RekeningBank {
public:
    RekeningPremium(double s) : RekeningBank(s) {}

    void potongAdmin() override {

        if (saldo > 10000000) {
            cout << "Saldo di atas Rp 10.000.000, bebas biaya admin." << endl;
        }
        else {
            saldo -= 50000;
            cout << "Biaya admin Rp 50.000 dipotong." << endl;
        }
    }
};

int main() {

    // Polymorphism menggunakan pointer base class
    vector<RekeningBank*> daftarRekening;

    // Menambahkan berbagai jenis rekening
    daftarRekening.push_back(new RekeningSyariah(5000000));

    daftarRekening.push_back(new RekeningKonvensional(3000000));

    daftarRekening.push_back(new RekeningPremium(15000000));

    daftarRekening.push_back(new RekeningPremium(7000000));

    cout << "===== PROSES AKHIR BULAN BANK GIBRAN JAYA =====\n" << endl;

    // Proses semua rekening
    for (int i = 0; i < daftarRekening.size(); i++) {

        daftarRekening[i]->potongAdmin();

        daftarRekening[i]->tampilSaldo();

        cout << "----------------------------------" << endl;
    }

    // Menghapus memory
    for (int i = 0; i < daftarRekening.size(); i++) {
        delete daftarRekening[i];
    }

    return 0;
}