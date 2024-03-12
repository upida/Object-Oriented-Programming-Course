#include <iostream>
#include <iomanip>
#include <map>

using namespace std;

class Karyawan {
private:
    int golongan;
    int lemburan_jam;

    map<int, double> data_gaji = {{1, 5000000}, {2, 4000000}, {3, 3000000}, {4, 2000000}};
    
    map<int, double> data_pajak = {{1, 0.05}, {2, 0.04}, {3, 0.03}, {4, 0.02}};
    
    map<int, double> data_lemburan = {{1, 0}, {2, 0}, {3, 100000}, {4, 150000}};

public:
    Karyawan(int gol, int lemb) : golongan(gol), lemburan_jam(lemb) {}

    double hitungGaji() {
        double nilai_gaji = data_gaji[golongan];
        double nilai_pajak = data_pajak[golongan];
        double nilai_lemburan = data_lemburan[golongan] * lemburan_jam;

        if (lemburan_jam > 3) {
            nilai_lemburan += (lemburan_jam - 3) * 50000;
        }

        double gaji_bersih = nilai_gaji + nilai_lemburan - (nilai_gaji + nilai_lemburan) * nilai_pajak;
        return gaji_bersih;
    }
};

int main() {
    Karyawan karyawan1(1, 3); // Golongan 1, lemburan 3 jam
    Karyawan karyawan2(3, 4); // Golongan 3, lemburan 4 jam

    cout << "Golongan : 1" << endl;
    cout << "Lemburan : 3 Jam" << endl;
    cout << "Gaji     : " << fixed << setprecision(2) << karyawan1.hitungGaji() << endl;

    cout << "\nGolongan : 3" << endl;
    cout << "Lemburan : 4 Jam" << endl;
    cout << "Gaji     : " << fixed << setprecision(2) << karyawan2.hitungGaji() << endl;

    return 0;
}
