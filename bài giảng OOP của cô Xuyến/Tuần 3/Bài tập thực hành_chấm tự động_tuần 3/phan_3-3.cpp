// Yêu cầu:
// 1. nhập vào số nguyên n
// 2. nhập vào n phần tử
// 3. đếm số lượng các số chẵn
// 4. đếm số lượng các số lẻ

#include <iostream>
#include <cmath>
#define SIZE 500
using namespace std;

// hàm kiểm tra số chẵn
bool KiemTra_SoChan(int thamSo){
    bool ketQua;
    
    if (thamSo % 2 == 0)
    {
        ketQua = true;
    }else{
        ketQua = false;
    }

    return ketQua;
}

// hàm kiểm tra số lẻ
bool KiemTra_SoLe(int thamSo){
    bool ketQua;
    
    if (thamSo % 2 != 0)
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
    
    int dem_chan = 0;
    int dem_le = 0;

    for (int i = 0; i < n; i++)
    {
        if (KiemTra_SoChan(v1[i]) == true)
        {
            dem_chan ++;
        }
        
        if (KiemTra_SoLe(v1[i]) == true)
        {
            dem_le ++;
        }
    }
    
    cout << dem_chan << " " << dem_le << endl;    

    return 0;
}