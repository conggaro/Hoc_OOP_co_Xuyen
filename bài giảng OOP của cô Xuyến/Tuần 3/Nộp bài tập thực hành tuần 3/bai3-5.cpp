// Yêu cầu:

// 1. viết hàm lowercase(s)
// nhận vào 1 xâu s
// chuyển tất cả chữ hoa thành chữ thường

// 1. viết hàm uppercase(s)
// nhận vào 1 xâu s
// chuyển tất cả chữ thường thành chữ hoa

#include <iostream>
using namespace std;

// hàm chuyển chữ hoa thành chữ thường
string Function_Lowercase(string thamSo){
    for (int i = 0; i < thamSo.length(); i++)
    {
        char kyTu = thamSo[i];
        int soThapPhan = (int)kyTu;

        if (soThapPhan >= 65 && soThapPhan <=90)
        {
            soThapPhan = soThapPhan + 32;
            kyTu = (char)soThapPhan;
            thamSo[i] = kyTu;
        }
        
    }

    return thamSo;
}

// hàm chuyển chữ thường thành chữ hoa
string Function_Uppercase(string thamSo){
    for (int i = 0; i < thamSo.length(); i++)
    {
        char kyTu = thamSo[i];
        int soThapPhan = (int)kyTu;

        if (soThapPhan >= 97 && soThapPhan <=122)
        {
            soThapPhan = soThapPhan - 32;
            kyTu = (char)soThapPhan;
            thamSo[i] = kyTu;
        }
        
    }

    return thamSo;
}

int main(){
    // chuỗi chữ thường
    string lowercase1 = "abcd";

    // chuỗi chữ hoa
    string uppercase1 = "XYZ";

    cout << "xau \"uppercase1\" ban dau: " << uppercase1 << endl;
    cout << "xau \"uppercase1\" luc sau: " << Function_Lowercase(uppercase1) << endl;

    cout << "\nxau \"lowercase1\" ban dau: " << lowercase1 << endl;
    cout << "xau \"lowercase1\" luc sau: " << Function_Uppercase(lowercase1) << endl;

    return 0;
}