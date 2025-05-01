#include <iostream>
using namespace std;

// batas maksimal bulan
#define MAX 12

class KeuanganAndi {
    private:
        double uangSaku;
        string bulan[MAX];
        double keluar[MAX];
        double nabung[MAX];
        int jmlBulan;
    
    public:
        
        KeuanganAndi() {
            jmlBulan = 0;
        }
        
        void isiUangSaku(double uang) {
            uangSaku = uang;
        }
        
        void tambahData(string bln, double pengeluaran) {
            bulan[jmlBulan] = bln;
            keluar[jmlBulan] = pengeluaran;
            nabung[jmlBulan] = uangSaku - pengeluaran;
            jmlBulan++;
        }
        
        void lihatDataIterasi() {
            cout << "\n===== DATA KEUANGAN ANDI =====" << endl;
            cout << "Bulan\t\tKeluar\t\tNabung" << endl;
            cout << "--------------------------------------" << endl;
            
            double totalKeluar = 0;
            double totalNabung = 0;
            
            for(int i = 0; i < jmlBulan; i++) {
                cout << bulan[i] << "\t\t" << keluar[i] << "\t\t" << nabung[i] << endl;
                totalKeluar += keluar[i];
                totalNabung += nabung[i];
            }
            
            cout << "--------------------------------------" << endl;
            cout << "TOTAL\t\t" << totalKeluar << "\t\t" << totalNabung << endl;
        }
        
        void tampilDataRekursif(int i) {
            if(i == jmlBulan) {
                return;
            }
            
            cout << bulan[i] << "\t\t" << keluar[i] << "\t\t" << nabung[i] << endl;
            
            tampilDataRekursif(i + 1);
        }
        
        double totalKeluarRekursif(int i) {
            if(i == jmlBulan) {
                return 0;
            }
            
            return keluar[i] + totalKeluarRekursif(i + 1);
        }
        
        double totalNabungRekursif(int i) {
            if(i == jmlBulan) {
                return 0;
            }
            
            return nabung[i] + totalNabungRekursif(i + 1);
        }
        
        void lihatDataRekursif() {
            cout << "\n===== DATA KEUANGAN ANDI (REKURSIF) =====" << endl;
            cout << "Bulan\t\tKeluar\t\tNabung" << endl;
            cout << "--------------------------------------" << endl;
            
            tampilDataRekursif(0);
            
            double totalKeluar = totalKeluarRekursif(0);
            double totalNabung = totalNabungRekursif(0);
            
            cout << "--------------------------------------" << endl;
            cout << "TOTAL\t\t" << totalKeluar << "\t\t" << totalNabung << endl;
        }
};

int main() {

    KeuanganAndi andi;
    double uang;
    int n;
    
    cout << "===== PROGRAM KEUANGAN ANDI =====" << endl;
    cout << "Dibuat oleh: Kelompok 5" << endl << endl;
    
    cout << "Uang saku bulanan: ";
    cin >> uang;
    andi.isiUangSaku(uang);
    
    cout << "Jumlah bulan yang mau diinput: ";
    cin >> n;
    
    for(int i = 0; i < n; i++) {
        string namaBulan;
        double pengeluaran;
        
        cout << "\nInput data bulan ke-" << (i+1) << endl;
        cout << "Nama bulan: ";
        cin >> namaBulan;
        
        cout << "Pengeluaran: ";
        cin >> pengeluaran;
        
        while(pengeluaran > uang) {
            cout << "ERROR: Pengeluaran gak boleh lebih dari uang saku!" << endl;
            cout << "Pengeluaran: ";
            cin >> pengeluaran;
        }
        
        andi.tambahData(namaBulan, pengeluaran);
    }
    
    andi.lihatDataIterasi();
    andi.lihatDataRekursif();
    
    cout << "\nProgram selesai. Terima kasih!" << endl;
    return 0;
}
