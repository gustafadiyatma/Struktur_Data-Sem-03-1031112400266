#include<iostream>
#include<string>

using namespace std;

float hitungRataRata(int nilaiTugas,int nilaiUTS){
    return(nilaiTugas + nilaiUTS)/2.0f;
}
voidcetakProfil(string nama,float nilai){
    cout<<"Nama:"<<nama<<endl;
    cout<<"Nilai:"<<nilai<<endl;
}

void beriNilaiBonus(float &nilai){
    nilai +=5.0f;

}
int main(){
    string NamaSiswa ="Budi";
    int tugas = 80,uts = 90;

    float nilaiAkhir = hitungRataRata(tugas,uts);

    cout<<"\nMemberikan nilai bonus..."<<endl;
    beriNilaiBonus(nilaiAkhir);0

    cout<<"\nProfil setelah Bonus"<<endl;
    voidcetakProfil(NamaSiswa,nilaiAkhir);

    return 0;
}