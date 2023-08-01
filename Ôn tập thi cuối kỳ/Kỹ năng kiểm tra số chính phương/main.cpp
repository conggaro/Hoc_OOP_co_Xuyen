// Yêu cầu:
// 1. nhập vào n
// 2. kiểm tra n có phải số chính phương không

// số chính phương kiểu:
// 1, 4, 9, 16, 25, 36, ...

#include <iostream>
#include <cmath>
using namespace std;

// hàm kiểm tra số chính phương
bool Ham_KiemTra_SCP(int thamSo){
    bool ketQua = false;

    // tạo biến kiểm tra
    int kiemTra = sqrt(thamSo);

    if (pow(kiemTra, 2) == thamSo)
    {
        ketQua = true;
    }
    else
    {
        ketQua = false;
    }

    return ketQua;
}

int main(){
    // nhập n
    cout << "Nhap n: ";
    int n = 0;
    cin >> n;

    if (Ham_KiemTra_SCP(n) == true)
    {
        cout << "Ket qua: " << n << " la so chinh phuong\n\n";
    }
    else
    {
        cout << "Ket qua: " << n << " khong phai so chinh phuong\n\n";
    }

    return 0;
}