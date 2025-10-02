#include<iostream>

using namespace std;

int main(){
    double total_pembelian, diskon;
    cout<<"berapa kamu belanja : rp. ";
    cin>>total_pembelian;
    if(total_pembelian > 30000){
        diskon = 0.1 * total_pembelian;
        cout<<"kamu dapat diskon sebesar" << diskon << "orang kaya lu";
    }else {
        cout<<"kamu belanjanya masih sedikit, tambahlah biar aku kaya ";

    }
  return 0;

}