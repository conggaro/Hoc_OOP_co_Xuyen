// Yêu cầu:
// 1. nhập vào số nguyên n
// 2. nhập vào n phần tử
// 3. đếm số lượng số chính phương

#include <iostream>
#include <cmath>
#define SIZE 500
using namespace std;

// hàm kiểm tra số chính phương
bool KiemTra_SCP(int thamSo){
    bool ketQua;

    int data = sqrt(thamSo);

    if (pow(data, 2) == thamSo)
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
    
    int dem = 0;

    for (int i = 0; i < n; i++)
    {
        if (KiemTra_SCP(v1[i]) == true)
        {
            dem = dem + 1;
        }
        
    }
    
    cout << dem << endl;

    return 0;
}