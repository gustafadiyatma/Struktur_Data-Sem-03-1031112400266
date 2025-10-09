#include<iostream>

using namespace std;

int main(){
    float hargaProduk=50000.0f;

    float*ptrHarga;
    ptrHarga=&hargaProduk;

    cout<<"Haraga Awal Produk:Rp"<<hargaProduk<<endl;
    cout<<"Alamat Aemori Harga:"<<ptrHarga<<endl;

    cout<<"\n...memberikan diskon 10% melalui Pointer..."<<endl;
    *ptrHarga=*ptrHarga*0.9;
    cout<<"Harga Setelah diskon:Rp"<<"hargaProduk"<<endl;
    return 0;
}