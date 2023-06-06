// Yêu cầu:
// 1. nhập vào số nguyên n
// 2. nhập vào n phần tử
// 3. tính tổng các số dương trong dãy

#include <iostream>
#include <cmath>
#define SIZE 500
using namespace std;

// hàm kiểm tra số chính phương
bool KiemTra_SoDuong(int thamSo){
    bool ketQua;
    
    if (thamSo > 0)
    {
        ketQua = true;
    }else{
        ketQua = false;
    }

    return ketQua;
}

int main(){
    int n;
    cin >> n;

    int v1[SIZE];

    for (int i = 0; i < n; i++)
    {
        cin >> v1[i];
    }
    
    int tong = 0;

    for (int i = 0; i < n; i++)
    {
        if (KiemTra_SoDuong(v1[i]) == true)
        {
            tong = tong + v1[i];
        }
        
    }
    
    cout << tong << endl;    

    return 0;
}